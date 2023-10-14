#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <math.h>
#include "vector.h"
#include "matrix.h"
#include "line.h"
#define SCREENW 1280
#define SCREENH 720

int main(int argv, char** args){


    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("fractalTree", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREENW, SCREENH, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Event event;

    bool isRunning = true;

    
    SDL_Color color = {255, 255, 255, 255};

    float angle = M_PI / 4;

    Vector2 *start = createVector2(0, -100);
    Vector2 *end = createVector2(0, -200);
    Vector2 *center = createVector2(SCREENW / 2, SCREENH);

    // printVector2(end);


    Line ln = createLine(start, end, center, renderer, color);
    

    Vector2 *newEnd = rotateVect2(*end, angle);
    newEnd->y -= 200;

    Vector2 addVect = {0, -100};
    Vector2 *newStart = addVect2(*start, addVect);

    // printVector2(newEnd);

    Line ln2 = createLine(newStart, newEnd, center, renderer, color);
    
    while(isRunning){

        SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
        while(SDL_PollEvent(&event)){

            switch(event.type){

                case SDL_QUIT:
                    isRunning = false;
                break;
                case SDL_KEYDOWN:

                    if(event.key.keysym.sym == SDLK_ESCAPE){
                        isRunning = false;
                    }

                break;  
            }

        }


        drawLine(ln);
        drawLine(ln2);
        SDL_RenderPresent(renderer);
    }

    return 0;
}