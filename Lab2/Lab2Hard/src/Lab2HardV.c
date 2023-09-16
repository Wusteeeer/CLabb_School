#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "Ship.h"
#include "asteroid.h"

void shipHandler(Ship *ship, SDL_Renderer *renderer, float acc, float friction);
void asteroidHandler(Asteroid *asteroid, SDL_Renderer *renderer, int windowW, int windowH);

int main(int argv, char** args)
{      

    srand(1);
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

    //TODO: Make asteroids spawn outside and fly in
    //If they leave the screen, make them respawn on a delay
    //Make the player die if he touches any of them.
    int randX = rand() % (windowW / 2) + 50;
    int randY = rand() % (windowH / 2) + 50;
    int randAngle = rand() % 360;
    Asteroid* asteroid = createAsteroid((int)randX, (int)randY, 0.5f, (int)randAngle, windowW, windowH, renderer);

    srand(2);
    randX = (windowW / 2) + 50;
    randY = rand() % 200;
    randAngle = rand() % 360;
    Asteroid* asteroid2 = createAsteroid((int)randX, (int)randY, 0.5f, (int)randAngle, windowW, windowH, renderer);

    srand(3);
    randX = (windowW / 2) + 50;
    randY = (windowH / 2) + 50;
    randAngle = rand() % 360;
    Asteroid* asteroid3 = createAsteroid((int)randX, (int)randY, 0.5f, (int)randAngle, windowW, windowH, renderer);

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
        

        //"Draw loop"
        SDL_RenderClear(renderer);

                
        shipHandler(ship, renderer, acc, friction);

        asteroidHandler(asteroid, renderer, windowW, windowH);
        asteroidHandler(asteroid2, renderer, windowW, windowH);
        asteroidHandler(asteroid3, renderer, windowW, windowH);

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



    // SDL_RenderClear(renderer);

    drawShip(ship, renderer);

    moveShip(ship);
    updateShip(ship);

    drawShip(ship, renderer);

    // SDL_RenderPresent(renderer);

}


void asteroidHandler(Asteroid *asteroid, SDL_Renderer *renderer, int windowW, int windowH)
{

    drawAsteroid(asteroid, renderer);

    moveAsteroid(asteroid);
    updateAsteroid(asteroid);

    drawAsteroid(asteroid, renderer);


}