#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector.h"
#include "matrix.h"

Vector2 *createVector2(float x, float y){

    Vector2 *v = malloc(sizeof(struct vector2));

    v->x = x;
    v->y = y;


    v->len = calcLength2(*v);

    return v;


}

Vector2 *addVect2(Vector2 v1, Vector2 v2){

    Vector2 *addV = createVector2(v1.x + v2.x, v1.y + v2.y);

    return addV;
    
    
}

void printVector2(Vector2 *v){

    printf("%.2f, %.2f\n%.2f\n", v->x, v->y, v->len);

}

float calcLength2(Vector2 v)
{
    
    return sqrt(pow(v.x, 2) + pow(v.y, 2));

}

