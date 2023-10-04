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

    char name[100];

    SDL_Rect astRect;
    SDL_Texture *astTexture;
    SDL_Renderer *astRenderer;
    
};

SDL_Rect getAstRect(Asteroid *ast){

    if(!ast->astTexture){

        SDL_Rect rect = {100, 100, 100, 100};
        return rect;
    }

    return ast->astRect;
}

Asteroid *createAsteroid(float x, float y, float vel, double angle, int screenW, int screenH, int sizeMult, SDL_Renderer *renderer, int *currentAsteroidAmount, int *totalAsteroidAmount){

    Asteroid *ast = malloc(sizeof(struct asteroid));

    if(!ast){
        printf("%s\n", SDL_GetError());
        return NULL;
    }

    ast->astRect.x = x;
    ast->astRect.y = y;

    char str[100];
    sprintf(str, "ast%d", *totalAsteroidAmount);

    strcpy(ast->name, str);


    // puts(ast->name);
 

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



    ast->astRect.w *= sizeMult;
    ast->astRect.h *= sizeMult;

    ast->radius = ast->astRect.w;

    ast->x = x - ast->astRect.w/2;
    ast->y = y - ast->astRect.h/2;

    
    (*currentAsteroidAmount)++;
    (*totalAsteroidAmount)++;

    return ast;

}


void spawnContinuousAsteroids(Asteroid **asteroids, SDL_Renderer *renderer, float maxVel, float minVel, int *currentAsteroidAmount, int maxAsteroidAmount, int windowW, int windowH, int *totalAsteroidAmount){

    if(*currentAsteroidAmount < maxAsteroidAmount){

        // printf("%d, %d\n", maxAsteroidAmount, *currentAsteroidAmount);
        float pos[] = {windowW / 2, windowH / 2}, vel = 0;
        int boundingX = 1100, boundingY = 900;
        double angle = 0, randAngle = 0;

    
    
        randAngle = rand()/(double)RAND_MAX * 360;
        

        pos[0] += calcVectFromAngle(randAngle)[0] * (windowW);
        pos[1] += calcVectFromAngle(randAngle)[1] * (windowH);

        vel = rand()/(float)RAND_MAX * (maxVel - minVel) + minVel;

        angle = atan2((windowH / 2) - pos[1], (windowW / 2) - pos[0]) * 180 / M_PI;

        asteroids[*currentAsteroidAmount] = malloc(sizeof(struct asteroid));
        asteroids[*currentAsteroidAmount] = createAsteroid(pos[0], pos[1], vel, angle + rand() % 20 - 10, windowW, windowH, rand() % 2 + 2, renderer, currentAsteroidAmount, totalAsteroidAmount);


    
    }

   
    

}

void drawAsteroid(Asteroid *ast, SDL_Renderer *renderer){

    
    if(!ast){
        return;
    }

    SDL_RenderCopyEx(renderer, ast->astTexture, NULL, &(ast->astRect), 0, NULL, SDL_FLIP_NONE);

}

void splitAsteroid(Asteroid *ast, Asteroid **asteroids, int *currentAsteroidAmount, SDL_Renderer *renderer, int *totalAsteroidAmount){

    for (int i = 0; i < 2; i++)
    {   
        asteroids[*currentAsteroidAmount] = malloc(sizeof(struct asteroid));
        asteroids[*currentAsteroidAmount] = createAsteroid(ast->astRect.x, ast->astRect.y, ast->vel + rand()/(float)RAND_MAX * 0.10f - 0.05f, rand() % 360, 1000, 1000, 2, renderer, currentAsteroidAmount, totalAsteroidAmount);

        
    }



    
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

void updateAsteroidArray(Asteroid **asteroids, int deleteIndex, int currentAsteroidAmount){
    
    for (int i = deleteIndex; i < currentAsteroidAmount - 1; i++) 
    {
        // printf("%d, %s = %s\n", deleteIndex, asteroids[i]->name, asteroids[i + 1]->name);
        asteroids[i] = asteroids[i + 1];
    
    }

    // SDL_DestroyTexture(asteroids[currentAsteroidAmount]->astTexture);
    // free(asteroids[currentAsteroidAmount]);

    //TODO: I need to figure out a way to free the last element. Otherwise the last one will be the same as the second-to-last one
    //Which makes the currentAsteroidAmount not the correct size. But when I try to free it the game crashes.
    
}

char *getAstName(Asteroid *ast){
    return ast->name;
}

void updateAsteroid(Asteroid **asteroids, int *currentAsteroidAmount, int deleteIndex){

    // printf("%d\n", *currentAsteroidAmount);
    // puts(asteroids[]->name);
    // for (int i = 0; i < *currentAsteroidAmount; i++)
    // {
    //     printf("%s\n", asteroids[i]->name);
    // }

    if(deleteIndex >= *currentAsteroidAmount){
        return;
    }

    // printf("%d, %d\n", *currentAsteroidAmount, deleteIndex);
    

    if(outsideBounds(asteroids[deleteIndex]->x, asteroids[deleteIndex]->y, asteroids[deleteIndex]->screenW, asteroids[deleteIndex]->screenH, 500)){

        // updateAsteroidArray(asteroids, deleteIndex, *currentAsteroidAmount);
        destroyAsteroid(asteroids[deleteIndex], asteroids, deleteIndex, currentAsteroidAmount);
        // (*currentAsteroidAmount)--;

        return;

    }
    
    // puts(asteroids[deleteIndex]->name);


    asteroids[deleteIndex]->astRect.x = (int)asteroids[deleteIndex]->x;
    asteroids[deleteIndex]->astRect.y = (int)asteroids[deleteIndex]->y;


}

void destroyAsteroid(Asteroid *asteroid, Asteroid **asteroids, int deleteIndex, int *currentasteroidAmount){

    // SDL_DestroyTexture(asteroids[deleteIndex]->astTexture);
    
    // printf("\n");
    // printf("%s\n", asteroids[deleteIndex]->name);
    // printf("\n");

    // printf("\n");
    

    free(asteroids[deleteIndex]);
    // asteroids[deleteIndex] = NULL;


    updateAsteroidArray(asteroids, deleteIndex, *currentasteroidAmount);

    (*currentasteroidAmount)--;

    // printf("\n");


    // for (int i = 0; i < *currentasteroidAmount; i++)
    // {

    //     puts(asteroids[i]->name);
    // }
    

    // printf("\n");

    // printf("Hello World\n");
    // for (int i = 0; i < *currentasteroidAmount; i++)
    // {
    //     puts(asteroids[i]->name);
    // }

}
