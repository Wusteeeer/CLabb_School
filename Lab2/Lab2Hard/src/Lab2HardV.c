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
#define MAXBULLETAMOUNT 2
#define FONTSIZE 50
#define MAXASTEROIDAMOUNT 10

//TODO: Make main menu (make a function to reset everything, and one to start everything then just call them (just make the player press space to start)), 
//make highscore (this includes file stuff (spooky)), 
//if time: make it juicy

void shipHandler(Ship *ship, SDL_Renderer *renderer, SDL_Event event, SDL_Window *window, float acc, float friction, bool *isRunning);

void asteroidHandler(Asteroid **asteroid, SDL_Renderer *renderer, int windowW, int windowH, int *currentasteroidAmount);

void bulletHandler(Bullet **bullets, int *currentBulletAmount, bool *shot, SDL_Renderer *renderer, int windowW, int windowH, Ship *ship);

void collisionHandler(Ship *ship, Bullet **bullets, Asteroid **asteroids, Score *score, float *points, SDL_Renderer *renderer, SDL_Window *window, int *currentasteroidAmount, int *currentBulletAmount, int *totalAsteroidAmount);

void gameOver(SDL_Renderer *renderer, SDL_Window *window, Ship *ship);

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

    Asteroid *asteroids[MAXASTEROIDAMOUNT];

    int currentAsteroidAmount = 0;
    int totalAsteroidAmount = 0;


    int currentBulletAmount = 0;
   

    bool shot = false;
    
    Bullet *bullets[MAXBULLETAMOUNT];


    SDL_Color color = {255, 255, 255};
    Score *score = createScore(windowW / 2, 10, renderer, color, 0, FONTSIZE);
    float points = 0;

    while(1)
    {
        



        collisionHandler(
            ship, 
            bullets, 
            asteroids, 
            score, 
            &points, 
            renderer,
            window, 
            &currentAsteroidAmount, 
            &currentBulletAmount, 
            &totalAsteroidAmount
        );

   
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

               


        spawnContinuousAsteroids(asteroids, renderer, 0.1f, 0.05f, &currentAsteroidAmount, MAXASTEROIDAMOUNT, windowW, windowH, &totalAsteroidAmount);
        


        SDL_RenderClear(renderer);

     
 

        asteroidHandler(asteroids, renderer, windowW, windowH, &currentAsteroidAmount);
       
        shipHandler(ship, renderer, event, window, acc, friction, &isRunning);
        bulletHandler(bullets, &currentBulletAmount, &shot, renderer, windowW, windowH, ship);

        printScore(score);


        SDL_RenderPresent(renderer);


        SDL_Delay(0.3f);

    
    }


}

void gameOver(SDL_Renderer *renderer, SDL_Window *window, Ship *ship){


    deleteShip(ship);


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

void shipHandler(Ship *ship, SDL_Renderer *renderer, SDL_Event event, SDL_Window *window, float acc, float friction, bool *isRunning){

    while (SDL_PollEvent(&event))
    {

         

        switch (event.type){
            case SDL_QUIT:

                gameOver(renderer, window, ship);
                return;

            break;
            case SDL_KEYDOWN:

                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    gameOver(renderer, window, ship);
                    return;
                }            
                    
                    
            break;

        }
        
    }
  
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
        
      

        if(bullets[i] != NULL){

            updateBullet(bullets[i], bullets, currentBulletAmount, i);

            if(*currentBulletAmount == 0){
                continue;
            }

            drawBullet(bullets[i], *currentBulletAmount);
            moveBullet(bullets[i]);
            drawBullet(bullets[i], *currentBulletAmount);

        }

    }

}

void asteroidHandler(Asteroid **asteroids, SDL_Renderer *renderer, int windowW, int windowH, int *currentasteroidAmount)
{

    // printf("Hello World\n");
    for (int i = 0; i < *currentasteroidAmount; i++)
    {   

        // printf("Hello World");
        // printf("%s\n", getAstName(asteroids[i]));

        updateAsteroid(asteroids, currentasteroidAmount, i);

        drawAsteroid(asteroids[i], renderer);

        moveAsteroid(asteroids[i]);

        drawAsteroid(asteroids[i], renderer);



    }
    
    



}

void collisionHandler(Ship *ship, Bullet **bullets, Asteroid **asteroids, Score *score, float *points, SDL_Renderer *renderer, SDL_Window *window, int *currentasteroidAmount, int *currentBulletAmount, int *totalAsteroidAmount)
{

    for (int i = 0; i < *currentasteroidAmount; i++)
    {
        
        if(collision(getShipRect(ship), getAstRect(asteroids[i]))){

            gameOver(renderer, window, ship);
               
                
            return;

        }
    }

    for (int i = 0; i < *currentasteroidAmount; i++)
    {   


        for (int j = 0; j < *currentBulletAmount; j++)
        {



            if(collision(getBulletRect(bullets[j]), getAstRect(asteroids[i]))){
                

                SDL_Rect asteroidRect = getAstRect(asteroids[i]);


                changeScore(score, 100.0f - asteroidRect.w);
                (*points) += 100.0f - asteroidRect.w;

                deleteBullet(bullets[j]);
                updateBulletArray(bullets, j, *currentBulletAmount);
                (*currentBulletAmount)--;

                Asteroid *temp = asteroids[i];
                
                destroyAsteroid(asteroids[i], asteroids, i, currentasteroidAmount);
                
                if(asteroidRect.w > 40){
                    
                   splitAsteroid(temp, asteroids, currentasteroidAmount, renderer, totalAsteroidAmount);


                }                

                return;



                    
            }


        }
            

    }

    
 
}