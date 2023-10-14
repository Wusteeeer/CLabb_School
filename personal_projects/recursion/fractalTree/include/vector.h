#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector2 {

    float x, y, len;

}Vector2;

Vector2 *createVector2(float x, float y);

Vector2 *addVect2(Vector2 v1, Vector2 v2);

void printVector2(Vector2 *v);

float calcLength2(Vector2 v);


typedef struct vector3{
    float x, y, z, len;
}Vector3;


#endif