#include <stdio.h>
#include "Lab2Lib.h"

float *nextPos(float *pPos, float speed, float *velNorm){

    float xPos = pPos[0] + (speed * velNorm[0]);
    float yPos = pPos[1] + (speed * velNorm[1]);

    float *pos;
    pos[0] = xPos;
    pos[1] = yPos;

    return pos;
    
    
}

void test(){
    printf("Hello World");
}
