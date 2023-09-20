#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "bullet.h"


struct bullet{

    float x, y, vel, dy, dx, screenW, screenH;
    double angle, *dir;

    SDL_Renderer *bulletRenderer;
    SDL_Texture *bulletTexture;
    SDL_Rect bulletRect;

};

Bullet *createBullet(float x, float y, float vel, double *dir, double angle, float screenW, float screenH, SDL_Renderer *renderer){
    
    Bullet *bullet = malloc(sizeof(struct bullet));

    bullet->bulletRect.x = x;
    bullet->bulletRect.y = y;

    bullet->dir = dir;
    bullet->vel = vel;
    bullet->dx = bullet->dy = 0;
    bullet->angle = angle;

    bullet->screenW = screenW;
    bullet->screenH = screenH;

    bullet->bulletRenderer = renderer;

    SDL_Surface *surface = IMG_Load("bullet.png");
    if(!surface){
        printf("ERROR: %s\n", SDL_GetError());
        return NULL;
    }

    bullet->bulletTexture = SDL_CreateTextureFromSurface(bullet->bulletRenderer, surface);
    SDL_FreeSurface(surface);

    if(!bullet->bulletTexture){
        printf("ERROR: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_QueryTexture(bullet->bulletTexture, NULL, NULL, &(bullet->bulletRect.w), &(bullet->bulletRect.h));

    bullet->bulletRect.w *= 2;
    bullet->bulletRect.h *= 2;

    bullet->x = x - bullet->bulletRect.w / 2;
    bullet->y = y - bullet->bulletRect.h / 2;

}

void drawBullet(Bullet *bullet){
    SDL_RenderCopyEx(bullet->bulletRenderer, bullet->bulletTexture, NULL, &(bullet->bulletRect), bullet->angle, NULL, SDL_FLIP_NONE);
}

void moveBullet(Bullet *bullet){

    bullet->dx = bullet->dir[0] * bullet->vel;
    bullet->dy = bullet->dir[1] * bullet->vel;

    bullet->x += bullet->dx;
    bullet->y += bullet->dy;

}


void updateBullet(Bullet *bullet){


    bullet->bulletRect.x = bullet->x;
    bullet->bulletRect.y = bullet->y;

}