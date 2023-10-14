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
#include "text.h"
#define MAXBULLETAMOUNT 2
#define FONTSIZE 50
#define MAXASTEROIDAMOUNT 10
#define SCREENW 900
#define SCREENH 700
#define MAXHIGHSCORE 5

//TODO: Sometimes when you quit it doesnt actually quit all the way
//if time: make it juicy

void shipHandler(Ship *ship, SDL_Renderer *renderer, SDL_Event event, SDL_Window *window, float acc, float friction);

void asteroidHandler(Asteroid **asteroids, SDL_Renderer *renderer, int *currentasteroidAmount);

void bulletHandler(Bullet **bullets, int *currentBulletAmount, bool *shot, SDL_Renderer *renderer, Ship *ship);

void collisionHandler(Ship *ship, Bullet **bullets, Asteroid **asteroids, Score *score, float *points, SDL_Renderer *renderer, SDL_Window *window, int *currentasteroidAmount, int *currentBulletAmount, int *totalAsteroidAmount, bool *started, int *highscoreNumbers, Score **highscores);

void startMenu(bool *started, SDL_Event event, SDL_Renderer *renderer, SDL_Window *window, Ship *ship, float acc, float friction, Text *startText, Score **highScores, int *highScoreNumbers, bool *isRunning, bool *created, float points);
void restart(Ship *ship, int *currentAsteroidAmount, int *currentBulletAmount, int *totalAsteroidAmount, Bullet **bullets, Asteroid **asteroids, Score *score, bool *started, float points, int *highscoreNumbers, Score **highscores);
void gameOver(SDL_Renderer *renderer, SDL_Window *window, Ship *ship, bool *isRunning, int *highScoreNumbers, float points, Score **highscores);

void updateHighScore(int *highScoreNumbers, int points, Score **highscores);

void writeFile(int *highScoreNumbers);
void readFile(Score **highScores, SDL_Renderer *renderer, SDL_Color color, int *highScoreNumbers);

int main(int argv, char** args)
{      

    TTF_Init();

  

    time_t t;
    srand((unsigned)time(&t));

    #pragma region SDL_Init
    
    SDL_Init(SDL_INIT_EVERYTHING);
    

    SDL_Window *window = SDL_CreateWindow("Lab2HardV", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREENW, SCREENH, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Event event;

    #pragma endregion

    #pragma region shipVars

    int startX = SCREENW / 2, startY = SCREENH / 2;
    float vel = 0.0f, acc = 0.00015f, friction = 0.0001f;
    
    Ship *ship = createShip(startX, startY, SCREENW, SCREENH, renderer);
    
    #pragma endregion

    bool start = false;
    bool isRunning = true;
    bool create = true;
    SDL_Color color = {255, 255, 255};

    Asteroid *asteroids[100];

    int currentAsteroidAmount = 0;
    int totalAsteroidAmount = 0;


    int currentBulletAmount = 0;
   

    bool shot = false;
    
    Bullet *bullets[MAXBULLETAMOUNT];

    Text *startText;
    Score *score, *highScores[MAXHIGHSCORE];

    int *highScoreNumbers = malloc(sizeof(int) * MAXHIGHSCORE);
    for (int i = 0; i < MAXHIGHSCORE; i++)
    {
        highScoreNumbers[i] = 0;
    }
    

    
    float points = 0;



    readFile(highScores, renderer, color, highScoreNumbers);

  
    
    while(isRunning)
    {

        while(!start){  

            if(create){
                
                
                startText = createText(SCREENW / 2 - 175, SCREENH / 2 + 100, renderer, "Press [SPACE] to start", FONTSIZE - 10, color);    

                score = createScore(SCREENW / 2, 10, renderer, color, 0, FONTSIZE);


                create = false;
            }

            startMenu(&start, event, renderer, window, ship, acc, friction, startText, highScores, highScoreNumbers, &isRunning, &create, points);
        }
        

        while (SDL_PollEvent(&event))
        {

         

            switch (event.type){
                case SDL_QUIT:

                    gameOver(renderer, window, ship, &isRunning, highScoreNumbers, points, highScores);
                    return 0;

                break;
                case SDL_KEYDOWN:

                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        gameOver(renderer, window, ship, &isRunning, highScoreNumbers, points, highScores);
                        return 0;
                    }            
                    
                    
                break;

            }
        
        }


   
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

               


        spawnContinuousAsteroids(asteroids, renderer, 0.1f, 0.05f, &currentAsteroidAmount, MAXASTEROIDAMOUNT, SCREENW, SCREENH, &totalAsteroidAmount);
        


        SDL_RenderClear(renderer);

     
 

        asteroidHandler(asteroids, renderer, &currentAsteroidAmount);
       
        shipHandler(ship, renderer, event, window, acc, friction);
        bulletHandler(bullets, &currentBulletAmount, &shot, renderer, ship);

        printScore(score);


        SDL_RenderPresent(renderer);


        SDL_Delay(0.3f);

        
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
            &totalAsteroidAmount,
            &start,
            highScoreNumbers,
            highScores
        );

    
    }


}

void writeFile(int *highScoreNumbers){

    FILE *fp;
    fp = fopen("C:/Cprogram/Lab2/Lab2Hard/highscores", "wb");
    if(fp == NULL){
        printf("Could not open file of name highscores\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MAXHIGHSCORE; i++)
    {
        fwrite(&(highScoreNumbers[i]), sizeof(highScoreNumbers[i]), MAXHIGHSCORE, fp);
    }
    
    fclose(fp);
    

}

void readFile(Score **highScores, SDL_Renderer *renderer, SDL_Color color, int *highScoreNumbers){
    
    FILE *fp;
    fp = fopen("C:/Cprogram/Lab2/Lab2Hard/highscores", "rb");

    if(fp != NULL){
        
        
        for (int i = 0; i < MAXHIGHSCORE; i++)
        {

            fread(&highScoreNumbers[i], sizeof(int), MAXHIGHSCORE, fp);
            highScores[i] = createScore(SCREENW / 2, 50 * i, renderer, color, highScoreNumbers[i], FONTSIZE - 10);
            
        }
    

        printf("No file existed\n");
        return;
    }

    for (int i = 0; i < MAXHIGHSCORE; i++)
    {
        highScores[i] = createScore(SCREENW / 2, 50 * i, renderer, color, 0, FONTSIZE - 10);
    }

    fclose(fp);

}

void updateHighScore(int *highScoreNumbers, int points, Score **highscores){

    printf("\n");
    for (int i = 0; i < MAXHIGHSCORE; i++)
    {  

        if(points > highScoreNumbers[i]){

            
            
            for (int j = MAXHIGHSCORE - 1; j > i; j--)
            {
                highScoreNumbers[j] = highScoreNumbers[j - 1];

            }

            highScoreNumbers[i] = points;
            
            break;
        }
    }


    for (int i = 0; i < MAXHIGHSCORE; i++)
    {
       
       setScore(highscores[i], highScoreNumbers[i]);
       printf("%d\n", highScoreNumbers[i]);
    }
    

    printf("\n");
    

}

void gameOver(SDL_Renderer *renderer, SDL_Window *window, Ship *ship, bool *isRunning, int *highScoreNumbers, float points, Score **highscores){

  
    
    updateHighScore(highScoreNumbers, points, highscores);

    writeFile(highScoreNumbers);
    deleteShip(ship);
    *isRunning = false;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

void restart(Ship *ship, int *currentAsteroidAmount, int *currentBulletAmount, int *totalAsteroidAmount, Bullet **bullets, Asteroid **asteroids, Score *score, bool *started, float points, int *highscoreNumbers, Score **highscores){

    updateHighScore(highscoreNumbers, points, highscores);

    for (int i = 0; i < *currentAsteroidAmount; i++)
    {
        destroyAsteroid(asteroids[i], asteroids, i, currentAsteroidAmount);
    }

    (*totalAsteroidAmount) = 0;
    (*currentAsteroidAmount) = 0;
    
    for (int i = 0; i < *currentBulletAmount; i++)
    {
        deleteBullet(bullets[i]);
        updateBulletArray(bullets, i, *currentBulletAmount);
        (*currentBulletAmount)--;
    }

    setPosition(ship, SCREENW / 2, SCREENH / 2);
    stopShip(ship);
    destroyScore(score);

    *started = false;
    


}

void startMenu(bool *started, SDL_Event event, SDL_Renderer *renderer, SDL_Window *window, Ship *ship, float acc, float friction, Text *startText, Score **highScores, int *highScoreNumbers, bool *isRunning, bool *created, float points){

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_RenderClear(renderer);

    printText(startText);

    for (int i = 0; i < MAXHIGHSCORE; i++)
    {
        printScore(highScores[i]);
    }
    

    // shipHandler(ship, renderer, event, window, acc, friction);


    while(SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_QUIT:

                gameOver(renderer, window, ship, isRunning, highScoreNumbers, points, highScores);
                return;

            break;
            case SDL_KEYDOWN:

                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    gameOver(renderer, window, ship, isRunning, highScoreNumbers, points, highScores);
                    return;
                }

                if(event.key.keysym.sym == SDLK_SPACE){
                    destroyText(startText);
                    *created = true;
                    *started = true;
                    return;
                }            
                    
                    
            break;

        }
            
    }

    const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);

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
    
    SDL_RenderPresent(renderer);

}

void shipHandler(Ship *ship, SDL_Renderer *renderer, SDL_Event event, SDL_Window *window, float acc, float friction){

    
  
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

void bulletHandler(Bullet **bullets, int *currentBulletAmount, bool *shot, SDL_Renderer *renderer, Ship *ship)
{

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
            SCREENW, 
            SCREENH, 
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

void asteroidHandler(Asteroid **asteroids, SDL_Renderer *renderer, int *currentasteroidAmount)
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

void collisionHandler(Ship *ship, Bullet **bullets, Asteroid **asteroids, Score *score, float *points, SDL_Renderer *renderer, SDL_Window *window, int *currentasteroidAmount, int *currentBulletAmount, int *totalAsteroidAmount, bool *started, int *highscoreNumbers, Score **highscores)
{

    for (int i = 0; i < *currentasteroidAmount; i++)
    {
        
        if(collision(getShipRect(ship), getAstRect(asteroids[i]))){

            restart(ship, currentasteroidAmount, currentBulletAmount, totalAsteroidAmount, bullets, asteroids, score, started, *points, highscoreNumbers, highscores);
            (*points) = 0;
                
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