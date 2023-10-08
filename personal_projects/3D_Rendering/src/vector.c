#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

Vector2D *createVector2D(float x, float y)
{   

    Vector2D *vect = malloc(sizeof(struct vector2D));

    if(!vect){
        return NULL;
    }

    vect->x = x;
    vect->y = y;

    return vect;

}

Vector3D *createVector3D(float x, float y, float z){

    Vector3D *vect = malloc(sizeof(struct vector3D));

    if(!vect){
        return NULL;
    }

    vect->x = x;
    vect->y = y;
    vect->z = z;

    return vect;

}

void printVector2D(Vector2D *vect)
{


    printf("(%.2f, %.2f)\n", vect->x, vect->y);
    

}

void printVector3D(Vector3D *vect)
{
    printf("(%.2f, %.2f, %.2f)\n", vect->x, vect->y, vect->z);
}

void getLength2D(Vector2D *vect);
void getLength3D(Vector3D *vect);