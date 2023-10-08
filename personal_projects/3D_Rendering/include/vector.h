#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector2D {

    float x, y;

}Vector2D;

typedef struct vector3D {

    float x, y, z;

}Vector3D;

Vector2D *createVector2D(float x, float y);
Vector3D *createVector3D(float x, float y, float z);

void printVector2D(Vector2D *vect);
void printVector3D(Vector3D *vect);

void getLength2D(Vector2D *vect);
void getLength3D(Vector3D *vect);



#endif