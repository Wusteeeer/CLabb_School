#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "Ship.h"
#include "asteroid.h"
#include "labMath.h"
#include "bullet.h"
#include "score.h"
#define ASTEROIDAMOUNT 15
#define MAXBULLETAMOUNT 2
#define FONTSIZE 50
#define NO_STDIO_REDIRECT


void shipHandler(Ship *ship, SDL_Renderer *renderer, float acc, float friction);

void asteroidHandler(Asteroid **asteroid, SDL_Renderer *renderer, int windowW, int windowH, int *currentAsteroidAmount);

void bulletHandler(Bullet **bullets, int *currentBulletAmount, bool *shot, SDL_Renderer *renderer, int windowW, int windowH, Ship *ship);

void collisionHandler(Ship *ship, Bullet **bullets, Asteroid **asteroids, Score *score, float *points, SDL_Renderer *renderer, int *currentAsteroidAmount, int *currentBulletAmount, bool *isRunning);

int main(int argv, char** args)
{      

    TTF_Init();

  

    time_t t;
    srand((unsigned)time(&t));

    int windowH = 700, windowW = 900;

    #pragma region SDL_Init
    
    SDL_Init(SDL_INIT_EVERYTHING);
    

    SDL_Window *window = SDL_CreateWindow("Lab2HardV", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowW, windowH, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Event event;

    #pragma endregion

    #pragma region shipVars

    int startX = windowW / 2, startY = windowH / 2;
    float vel = 0.0f, acc = 0.00015f, friction = 0.0001f;
    
    Ship *ship = createShip(startX, startY, windowW, windowH, renderer);

    #pragma endregion

    bool isRunning = true;

    Asteroid *asteroids[ASTEROIDAMOUNT];

    int currentAsteroidAmount = 0;



    int currentBulletAmount = 0;

    bool shot = false;
    
    Bullet *bullets[MAXBULLETAMOUNT];

    SDL_Color color = {255, 255, 255};

    Score *score = createScore(windowW / 2, 10, renderer, color, 0, FONTSIZE);

    float points = 0;


    do
    {

        // printf("%d\n", SDL_GetPerformanceCounter());

        spawnContinuousAsteroids(asteroids, renderer, 0.15f, 0.05f, &currentAsteroidAmount, ASTEROIDAMOUNT, windowW, windowH);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        while (SDL_PollEvent(&event))
        {
            switch (event.type){
                case SDL_QUIT:

                    isRunning = false;

                break;
                case SDL_KEYDOWN:

                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        isRunning = false;
                    }            
                    
                    
                break;

            }

        }
   
        //"Draw loop"
        SDL_RenderClear(renderer);

        asteroidHandler(asteroids, renderer, windowW, windowH, &currentAsteroidAmount);
        shipHandler(ship, renderer, acc, friction);
        bulletHandler(bullets, &currentBulletAmount, &shot, renderer, windowW, windowH, ship);

        printScore(score);


        SDL_RenderPresent(renderer);
        
        if(SDL_GetPerformanceCounter() % 10 == 0){
            
            collisionHandler(
                ship, 
                bullets, 
                asteroids, 
                score, 
                &points, 
                renderer, 
                &currentAsteroidAmount, 
                &currentBulletAmount, 
                &isRunning
            );
        }
     

        SDL_Delay(0.1f);

    }while(isRunning);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();


    return 0;
}

void shipHandler(Ship *ship, SDL_Renderer *renderer, float acc, float friction){


    const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);
    if(keyboard_state_array[SDL_SCANCODE_SPACE])
    {

        thrusters(ship, acc, friction);

    }else
    {

        thrusters(ship, 0, friction);

    }


    if(keyboard_state_array[SDL_SCANCODE_A]){
        rotateShip(ship, -0.1f);
    }

    if(keyboard_state_array[SDL_SCANCODE_D]){
        rotateShip(ship, 0.1f);
    }


    drawShip(ship, renderer);

    moveShip(ship);
    updateShip(ship);

    drawShip(ship, renderer);


}

void bulletHandler(Bullet **bullets, int *currentBulletAmount, bool *shot, SDL_Renderer *renderer, int windowW, int windowH, Ship *ship){

    const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);

    SDL_Rect shipRect = getShipRect(ship);

    if(keyboard_state_array[SDL_SCANCODE_E] && !(*shot))
    {

        spawnBullet(
            bullets, 
            currentBulletAmount, 
            MAXBULLETAMOUNT, 
            shipRect.x + shipRect.w / 2, 
            shipRect.y + shipRect.h / 2, 
            windowW, 
            windowH, 
            1, 
            getMoveDir(ship), 
            renderer
            );
    
        *shot = true;

    }
    else if(!keyboard_state_array[SDL_SCANCODE_E])
    {

        *shot = false;

    }



    for (int i = 0; i < *currentBulletAmount; i++)
    {
        

        if(bullets[i]){

            updateBullet(bullets[i], bullets, currentBulletAmount, i);

            drawBullet(bullets[i]);
            moveBullet(bullets[i]);
            drawBullet(bullets[i]);

        }

    }

}

void asteroidHandler(Asteroid **asteroids, SDL_Renderer *renderer, int windowW, int windowH, int *currentAsteroidAmount)
{

    for (int i = 0; i < *currentAsteroidAmount; i++)
    {   

        updateAsteroid(asteroids[i], asteroids, currentAsteroidAmount, i);

        drawAsteroid(asteroids[i], renderer);

        moveAsteroid(asteroids[i]);

        drawAsteroid(asteroids[i], renderer);

    }
    



}

void collisionHandler(Ship *ship, Bullet **bullets, Asteroid **asteroids, Score *score, float *points, SDL_Renderer *renderer, int *currentAsteroidAmount, int *currentBulletAmount, bool *isRunning)
{

    for (int i = 0; i < *currentAsteroidAmount; i++)
    {


        if(collision(getShipRect(ship), getAstRect(asteroids[i]))){

            gameOver(ship);
            *isRunning = false;

        }

        for (int j = 0; j < *currentBulletAmount; j++)
        {
        
            if(collision(getBulletRect(bullets[j]), getAstRect(asteroids[i]))){
                
                changeScore(score, 20.0f + getAstRect(asteroids[i]).w);
                (*points) += 20.0f + getAstRect(asteroids[i]).w;

                destroyAsteroid(asteroids[i]);

                updateAsteroidArray(asteroids, i, *currentAsteroidAmount);


                (*currentAsteroidAmount)--;
                    
            }
        }
            

    }

    
 
}