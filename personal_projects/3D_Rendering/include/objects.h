#ifndef OBJECTS_H
#define OBJECTS_H

typedef struct plane Plane;

Plane *createPlane(Vector3D origin, Matrix *topRight, Matrix *topLeft, Matrix *bottomRight, Matrix *bottomLeft, SDL_Renderer *renderer);

void drawPlane(Plane *pl);
void rotatePlaneX(Plane *pl, float angle);
void rotatePlaneY(Plane *pl, float angle);
void rotatePlaneZ(Plane *pl, float angle);


typedef struct square Square;

Square *createSquare(float radius, Vector3D origin, SDL_Renderer *renderer);

void drawSquare(Square *sq);
void rotateSquareX(Square *sq, float angle);
void rotateSquareY(Square *sq, float angle);
void rotateSquareZ(Square *sq, float angle);


#endif