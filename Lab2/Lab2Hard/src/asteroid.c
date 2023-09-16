#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "asteroid.h"
#include "labMath.h"

struct asteroid{

    float x, y, dx, dy, vel;
    int screenH, screenW;
    double *dir;

    SDL_Rect astRect;
    SDL_Texture *astTexture;
    SDL_Renderer *astRenderer;
    
};

Asteroid *createAsteroid(float x, float y, float vel, double angle, int screenW, int screenH, SDL_Renderer *renderer){

    Asteroid *ast = malloc(sizeof(struct asteroid));

    ast->astRect.x = x;
    ast->astRect.y = y;

    ast->vel = vel;
    ast->dx = ast->dy = 0;
    ast->dir = calcVectFromAngle(angle);

    ast->screenW = screenW;
    ast->screenH = screenH;

    ast->astRenderer = renderer;

    SDL_Surface *surface = IMG_Load("asteroid.png");
    if(!surface){
        printf("%s\n", SDL_GetError());
        return NULL;
    }

    ast->astTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if(!(ast->astTexture)){
        printf("%s\n", SDL_GetError());
        return NULL;
    }

    SDL_QueryTexture(ast->astTexture, NULL, NULL, &(ast->astRect.w), &(ast->astRect.h));

    ast->astRect.w *= 2;
    ast->astRect.h *= 2;

    ast->x = x - ast->astRect.w/2;
    ast->y = y - ast->astRect.h/2;

    return ast;

}

void drawAsteroid(Asteroid *ast, SDL_Renderer *renderer){

    SDL_RenderCopyEx(renderer, ast->astTexture, NULL, &(ast->astRect), 0, NULL, SDL_FLIP_NONE);

}

void moveAsteroid(Asteroid *ast){

    ast->dx = ast->vel * ast->dir[0];
    ast->dy = ast->vel * ast->dir[1];

    ast->x += ast->dx;
    ast->y += ast->dy;
}

void updateAsteroid(Asteroid *ast){

    ast->astRect.x = (int)ast->x;
    ast->astRect.y = (int)ast->y;
}

void destroyAsteroid(Asteroid *asteroid){
    SDL_DestroyTexture(asteroid->astTexture);
    free(asteroid);
}
