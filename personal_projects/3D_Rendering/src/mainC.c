#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <math.h>
#include "vector.h"
#include "matrix.h"
#include "objects.h"
#define SCREENW 1000
#define SCREENH 1000

int main(int argv, char** args){


    float angle = 0;
    float angle1 = 0;
    float angle2 = 0;

    Vector3D v = {100, -200, 0};
    Vector3D v2 = {-100, -200, 0};

    Vector3D v3 = {100, 0, 0};
    Vector3D v4 = {-100, 0, 0};


    Matrix *vectorMatrix1 = vect3DToMat(v);
    Matrix *vectorMatrix2 = vect3DToMat(v2);
    Matrix *vectorMatrix3 = vect3DToMat(v3);
    Matrix *vectorMatrix4 = vect3DToMat(v4);




    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("cube", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREENW, SCREENH, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Event event;

    SDL_Color color = {255, 255, 255, 255};

    float scale = 10;

    bool isRunning = true;

    Vector3D origin = {SCREENW / 2, SCREENH / 2, 0};
    Plane *pl = createPlane(origin, vectorMatrix1, vectorMatrix2, vectorMatrix3, vectorMatrix4, renderer);

    Square *sq = createSquare(100, origin, renderer);

    Square *sq1 = createSquare(50, origin, renderer);

    Square *sq2 = createSquare(25, origin, renderer);

    while(isRunning){
        
        angle += 0.001;
        angle1 += 0.002;
        angle2 -= 0.003;
        printf("%.2f\n", angle);

    
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        // SDL_RenderSetScale(renderer, scale, scale);

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


               
        SDL_SetRenderDrawColor(renderer, 0, 155, 0, 255);
        
        // rotatePlaneY(pl, angle);
        // drawPlane(pl);
        rotateSquareX(sq, angle);
        rotateSquareY(sq, angle);
        rotateSquareZ(sq, angle);
        drawSquare(sq);

        SDL_SetRenderDrawColor(renderer, 0, 0, 155, 255);

        rotateSquareX(sq1, angle1);
        rotateSquareY(sq1, angle1);
        rotateSquareZ(sq1, angle1);
        drawSquare(sq1);

        SDL_SetRenderDrawColor(renderer, 155, 0, 0, 255);

        rotateSquareX(sq2, angle2);
        rotateSquareY(sq2, angle2);
        rotateSquareZ(sq2, angle2);
        drawSquare(sq2);


        SDL_RenderPresent( renderer );

    }



    return 0;
}