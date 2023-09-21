#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "asteroid.h"
#include "labMath.h"

//TODO: Add a function that takes in the array of asteroids and creates new ones and adds them to the array
//It should also delete the ones that go offscreen, and create a new one after this.
//The function will need the array of asteroids, a max size, a screen width, height and everything that
//is needed to create a asteroid (some things will need to be calculated like in the spawnasteroid function) 
struct asteroid{

    float x, y, dx, dy, vel, radius;
    int screenH, screenW, boundingX, boundingY;
    double *dir, angle;

    SDL_Rect astRect;
    SDL_Texture *astTexture;
    SDL_Renderer *astRenderer;
    
};

SDL_Rect getAstRect(Asteroid *ast){
    return ast->astRect;
}

Asteroid *createAsteroid(float x, float y, float vel, double angle, int screenW, int screenH, SDL_Renderer *renderer){

    Asteroid *ast = malloc(sizeof(struct asteroid));

    ast->astRect.x = x;
    ast->astRect.y = y;

    ast->boundingX = ast->boundingY = 0;

    ast->vel = vel;
    ast->angle = 0;
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



    int sizeMult = rand() % 2 + 2;
    ast->astRect.w *= sizeMult;
    ast->astRect.h *= sizeMult;

    ast->radius = ast->astRect.w;

    ast->x = x - ast->astRect.w/2;
    ast->y = y - ast->astRect.h/2;

    return ast;

}


void spawnContinuousAsteroids(Asteroid **asteroids, SDL_Renderer *renderer, float maxVel, float minVel, int *currentAsteroidAmount, int maxAsteroidAmount, int windowW, int windowH){

    int index = *currentAsteroidAmount;

    for (int i = 0; i < *currentAsteroidAmount; i++)
    {
        
        if(outsideBounds(asteroids[i]->x, asteroids[i]->y, asteroids[i]->screenW, asteroids[i]->screenH)){
        
            destroyAsteroid(asteroids[i]);
            (*currentAsteroidAmount)--;

            //If we destroy an asteroid we need to create a new one at that spot at once
            index = i;

            break;
        }
    }


    if(*currentAsteroidAmount >= maxAsteroidAmount){
        return;
    }

    //Add functionality for creating new ones when old ones die (so call this in the draw loop)
    //But check if the currentAsteroidAmount is less than maxAsteroid amount before doing anything
    //If it is then create a new one, else do not. Then decrease the currentasteroidamount when destroying a asteroid
    //Make sure to destroy from the array of asteroids (else it will have a empty space left)
    asteroids[index] = malloc(sizeof(struct asteroid));

    float pos[] = {windowW / 2, windowH / 2}, vel = 0;
    int boundingX = 1100, boundingY = 900;
    double angle = 0, randAngle = 0;

    
    
    randAngle = rand()/(double)RAND_MAX * 360;
        

    pos[0] += calcVectFromAngle(randAngle)[0] * (windowW);
    pos[1] += calcVectFromAngle(randAngle)[1] * (windowH);

    vel = rand()/(float)RAND_MAX * (maxVel - minVel) + minVel;

    angle = atan2((windowH / 2) - pos[1], (windowW / 2) - pos[0]) * 180 / M_PI;

    asteroids[index] = createAsteroid(pos[0], pos[1], vel, angle + rand() % 20 - 10, windowW, windowH, renderer);

    (*currentAsteroidAmount)++;

    

}

void drawAsteroid(Asteroid *ast, SDL_Renderer *renderer){

    
    if(!ast){
        return;
    }

    SDL_RenderCopyEx(renderer, ast->astTexture, NULL, &(ast->astRect), 0, NULL, SDL_FLIP_NONE);

}


void moveAsteroid(Asteroid *ast){

    if(!ast){
        return;
    }

    ast->dx = ast->vel * ast->dir[0];
    ast->dy = ast->vel * ast->dir[1];

    ast->x += ast->dx;
    ast->y += ast->dy;
}



void updateAsteroid(Asteroid *ast){

    //Make the asteroid change to a random pos after it has left the screen
    ast->astRect.x = (int)ast->x;
    ast->astRect.y = (int)ast->y;



}

void destroyAsteroid(Asteroid *asteroid){
    SDL_DestroyTexture(asteroid->astTexture);
    free(asteroid);
}
