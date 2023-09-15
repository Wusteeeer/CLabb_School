#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "Lab2Lib.h"

int main(int argv, char** args)
{   


    #pragma region SDL_Init
    SDL_Init(SDL_INIT_EVERYTHING);
    

    SDL_Window *window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Event event;

    #pragma endregion

    bool isRunning = true;

    do
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
                  
                break;
            }

        }

       

     
        SDL_Delay(40);

    }while(isRunning);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();


    return 0;
}
