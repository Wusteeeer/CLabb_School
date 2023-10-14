#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <math.h>
#include <time.h>
#include "vector.h"
#include "matrix.h"
#include "objects.h"
#define SCREENW 900
#define SCREENH 900

int main(int argv, char** args){

    srand(time(NULL));

    float angle = 0;
    float color = 0;
    float colorScale = 0.1;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("cube", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREENW, SCREENH, 1);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Event event;


    bool isRunning = true;

    Vector3D origin = {SCREENW / 2 + 200, SCREENH / 2, 0};
    Square *squares[100];
    int currentSize = 250;
    int index = 0;

    while(currentSize > 5){

        squares[index] = createSquare(currentSize, origin, renderer);

        currentSize /= 2;
        index++;
        
    }

    
    while(isRunning){
        
        angle += 0.001;
        color = sin(angle) * 120 + 120;


        //Could have been done with a simple modulo function (but apparently you cant with two doubles in C)
        if(angle >= M_PI * 2){
            angle = 0;
        }
    
        SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);

        while(SDL_PollEvent(&event)){

            switch (event.type)
            {
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

        SDL_RenderClear(renderer);


        for (int i = 0; i < index; i++)
        {

            int fact = abs((int)ceil(sin(angle) * 100) % 155);

            SDL_SetRenderDrawColor(renderer, color, 0, color, 255);
            rotateSquareX(squares[i], angle + i);
            rotateSquareY(squares[i], angle + i);
            rotateSquareZ(squares[i], angle + i);
            drawSquare(squares[i]);

        }
        

        SDL_RenderPresent( renderer );

    }



    return 0;
}