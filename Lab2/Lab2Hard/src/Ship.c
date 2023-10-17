#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include <string.h>
#include "Ship.h"
#include "labMath.h"
#define NO_STDIO_REDIRECT

const char *dir = "C:/Cprogram/Lab2/Lab2Hard/";

struct ship{

    float x, y, dx, dy, velocity;
    int mass; 
    double angle, *moveVect;

    SDL_Renderer *shipRender;
    SDL_Rect shipRect;
    SDL_Texture *shipTexture;

    //Will be used for screenwrapping
    float ScreenWidth, ScreenHeight;
    
};


Ship *createShip(float x, float y, int screenWidth, int screenHeight, SDL_Renderer *renderer){

    Ship *shp = malloc(sizeof(struct ship));

    //Sets init values
    shp->shipRect.x = x;
    shp->shipRect.y = y;
    shp->dx = shp->dy = 0;
    shp->angle = 0;
    shp->shipRender = renderer;
    shp->mass = 1;
    shp->velocity = 0;

    shp->moveVect = malloc(sizeof(double) * 2);

    shp->moveVect = calcVectFromAngle(shp->angle);


    shp->ScreenHeight = screenHeight;
    shp->ScreenWidth = screenWidth;

    
    #pragma region TextureStuff

    //Loads a image
    SDL_Surface *surface = IMG_Load("./Spaceship.png");

    //Makes sure the png exists and that there was enough memory
    if(!surface){
        printf("Could Not create Ship surface:%s\n", SDL_GetError());
        return NULL;
    }
    
    //Creates a texture from the image
    shp->shipTexture = SDL_CreateTextureFromSurface(renderer, surface);

    //So that it doesn't hang around taking up space
    SDL_FreeSurface(surface);

    //To make sure that enough memory existed for the texture and that the conversion went well
    if(!shp->shipTexture){
        printf("Could Not create Ship texture:%s\n", SDL_GetError());
        return NULL;
    }

    //I think it basically initializes the texture
    SDL_QueryTexture(shp->shipTexture, NULL, NULL, &(shp->shipRect.w), &(shp->shipRect.h));

    //Resizes it
    shp->shipRect.w *= 1.5f;
    shp->shipRect.h *= 1.5f;

    //Centers it
    shp->x = x - shp->shipRect.w/2;
    shp->y = y - shp->shipRect.h/2;
    #pragma endregion

    return shp;
}

//Allowes us to draw with rotation (and also a texture)
void drawShip(Ship *ship, SDL_Renderer *renderer){

    SDL_RenderCopyEx(renderer, ship->shipTexture, NULL, &(ship->shipRect), ship->angle, NULL, SDL_FLIP_NONE);
}

void rotateShip(Ship *ship, float rotation){

    if(ship->angle >= 360.0f){
        ship->angle = 0;
    }
    ship->angle += rotation;
}

void thrusters(Ship *ship, float acc, float fric){
    
    
    float tempFric = 0;
    if(ship->velocity < 0)
    {
        ship->velocity = 0;

    }
    
    if(ship->velocity > 0)
    {
        tempFric = fric;

    }else
    {
        tempFric = 0;
    }

    ship->velocity += (acc / ship->mass) - tempFric;
    


}

void moveShip(Ship *ship){

    ship->dx = ship->moveVect[0] * ship->velocity;
    ship->dy = ship->moveVect[1] * ship->velocity;

    ship->x += ship->dx;
    ship->y += ship->dy;


}


SDL_Rect getShipRect(Ship *ship){
    return ship->shipRect;    
}

void setPosition(Ship *ship, float x, float y){
    
    ship->x = x;
    ship->y = y;

    updateShip(ship);

}

void stopShip(Ship *ship){

    ship->velocity = 0;

    ship->moveVect[0] = ship->moveVect[1] = 0;

    ship->dx = ship->dy = 0;
    
    ship->angle = 0;
}

double *getMoveDir(Ship *ship){
    return ship->moveVect;
}


void updateShip(Ship *ship){


    #pragma region ScreenWrapping

    if(ship->x >= ship->ScreenWidth){
        ship->x = 0;
    }

    if(ship->y >= ship->ScreenHeight){
        ship->y = 0;
    }

    if(ship->x < 0){
        ship->x = ship->ScreenWidth;
    }

    if(ship->y < 0){
        ship->y = ship->ScreenHeight;
    }

    #pragma endregion
    
    ship->moveVect = calcVectFromAngle(ship->angle);

    ship->shipRect.x = (int)ship->x;
    ship->shipRect.y = (int)ship->y;


}


void deleteShip(Ship *ship){

    SDL_DestroyTexture(ship->shipTexture);
    free(ship);

}