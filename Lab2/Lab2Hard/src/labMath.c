#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdbool.h>
#include "labMath.h"


double *calcVectFromAngle(double angle){

    double *dir = malloc(sizeof(double) * 2);
    dir[0] = cos(angle * 0.017453f);
    dir[1] = sin(angle * 0.017453f);

    return dir;

}

int collision(SDL_Rect sourceRect, SDL_Rect checkRect){

    float rightX = checkRect.x + checkRect.w, rightY = checkRect.y + checkRect.h;

    float middleRect[2] = {sourceRect.w / 2, sourceRect.h / 2};
    float middlePos[2] = {sourceRect.x + middleRect[0], sourceRect.y + middleRect[1]};

    if(middlePos[0] <= rightX && middlePos[0] >= checkRect.x && middlePos[1] <= rightY && middlePos[1] >= checkRect.y){
        return 1;
    }

    return 0;
}