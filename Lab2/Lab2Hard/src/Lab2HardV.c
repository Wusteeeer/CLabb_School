#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "Ship.h"
#include "asteroid.h"
#include "labMath.h"
#include "bullet.h"
#define ASTEROIDAMOUNT 10
#define NO_STDIO_REDIRECT

void shipHandler(Ship *ship, SDL_Renderer *renderer, float acc, float friction);

void asteroidHandler(Asteroid **asteroid, SDL_Renderer *renderer, int windowW, int windowH);

void bulletHandler(SDL_Renderer *renderer, int windowW, int windowH);



int main(int argv, char** args)
{      

    
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

    spawnAsteroids(asteroids, renderer, 0.15f, 0.05f, ASTEROIDAMOUNT, windowW, windowH);

    do
    {

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
        
        
      
        for (int i = 0; i < ASTEROIDAMOUNT; i++)
        {


            if(collision(getShipRect(ship), getAstRect(asteroids[i]))){

                gameOver(ship);
                isRunning = false;

            }

        }

        //"Draw loop"
        SDL_RenderClear(renderer);

        asteroidHandler(asteroids, renderer, windowW, windowH);
        shipHandler(ship, renderer, acc, friction);


        SDL_RenderPresent(renderer);


        

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

void bulletHandler(SDL_Renderer *renderer, int windowW, int windowH, Ship *ship){

    const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);


    if(keyboard_state_array[SDL_SCANCODE_E]){
        
    }


    Bullet *bullet = createBullet(100, 100, 0.01f, getMoveDir(ship), 0, windowW, windowH, renderer);

    
    drawBullet(bullet);
    moveBullet(bullet);
    updateBullet(bullet);
    drawBullet(bullet);
}


void asteroidHandler(Asteroid **asteroids, SDL_Renderer *renderer, int windowW, int windowH)
{


    for (int i = 0; i < ASTEROIDAMOUNT; i++)
    {   

        drawAsteroid(asteroids[i], renderer);

        moveAsteroid(asteroids[i]);
        updateAsteroid(asteroids[i]);

        drawAsteroid(asteroids[i], renderer);

    }
    



}