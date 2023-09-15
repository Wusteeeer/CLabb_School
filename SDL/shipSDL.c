#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "rocketMath.h"

float calcVelocity(float pVel, float throttle);


int main(int argv, char** args)
{   

    //Variables used for ship
    int yPos = 100, xPos = 750;
    float vel = -1.0f, throttle = 0;

    #pragma region SDL_Init
    SDL_Init(SDL_INIT_EVERYTHING);
    

    SDL_Window *window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    bool isRunning = true, won = false;
    SDL_Event event;

    #pragma endregion

    while (isRunning)
    {

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
                    
                    if(event.key.keysym.sym == SDLK_UP){
                        
                        vel += 5;

                    }
                break;
            }

        }

        if(!won){

            SDL_RenderClear(renderer);
        }

        #pragma region drawShip


        yPos -= vel;
        vel = calcVelocity(vel, throttle);

        SDL_Rect ship = {xPos / 2, yPos, 50, 50};
        //Sets active color to blue as to render the square thus
        SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );

        // Render rect
        SDL_RenderFillRect( renderer, &ship );

        //Sets the color back to black
        SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );

        #pragma endregion

        int screenW, screenH;
        SDL_GetRendererOutputSize(renderer, &screenW, &screenH);

        SDL_Rect moonFloor = {0, 550, 1000, 50};


        SDL_SetRenderDrawColor( renderer, 99, 99, 99, 255);

        SDL_RenderFillRect(renderer, &moonFloor);

        SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );


        if(yPos >= 500){
            
            SDL_Rect winBox = {0, 0, 100, 100};

            if(vel < -6){
                //SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255);
                SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255);

            }else{
                SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255);
            }
            
            SDL_RenderFillRect(renderer, &winBox);

            SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
            SDL_RenderPresent(renderer);

            won = true;

            break;

        }
        
        if(!won){
            
            SDL_RenderPresent(renderer);

        }


     
        SDL_Delay(40);
    }

    SDL_Delay(5000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();


    return 0;
}


float calcVelocity(float pVel, float throttle){
    return pVel + ((0.1f * throttle) - 1.0f);
}