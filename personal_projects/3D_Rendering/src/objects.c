#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "vector.h"
#include "matrix.h"
#include "objects.h"


struct plane{
    
    Vector3D origin;

    Matrix *tpR, *tpL, *btR, *btL;
    Matrix *tpRS, *tpLS, *btRS, *btLS;

    SDL_Renderer *renderer;

};

Plane *createPlane(Vector3D origin, Matrix *topRight, Matrix *topLeft, Matrix *bottomRight, Matrix *bottomLeft, SDL_Renderer *renderer){

    Plane *pl = malloc(sizeof(struct plane));

    pl->origin = origin;

    pl->tpR = topRight;
    pl->tpL = topLeft;

    pl->btR = bottomRight;
    pl->btL = bottomLeft;

    pl->tpRS = topRight;
    pl->tpLS = topLeft;

    pl->btRS = bottomRight;
    pl->btLS = bottomLeft;

    pl->renderer = renderer;

    return pl;

}

void drawPlane(Plane *pl){
    
    float arr[][3] = {

        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    Matrix *projectionMat = createMatrix(arrToPByThree(arr, 3), 3, 3);
    


    Matrix *resMat1 = matrixMult(projectionMat, pl->tpR);
    Vector3D vect = matToVect3D(resMat1);


    Matrix *resMat2 = matrixMult(projectionMat, pl->tpL);
    Vector3D vect2 = matToVect3D(resMat2);


    Matrix *resMat3 = matrixMult(projectionMat, pl->btR);
    Vector3D vect3 = matToVect3D(resMat3);

    Matrix *resMat4 = matrixMult(projectionMat, pl->btL);
    Vector3D vect4 = matToVect3D(resMat4);


    SDL_Rect r1;
    r1.x = vect.x + pl->origin.x;
    r1.y = vect.y + pl->origin.y;
    r1.w = 10;
    r1.h = 10;

    SDL_Rect r2;
    r2.x = vect2.x + pl->origin.x;
    r2.y = vect2.y + pl->origin.y;
    r2.w = 10;
    r2.h = 10;

    SDL_Rect r3;
    r3.x = vect3.x + pl->origin.x;
    r3.y = vect3.y + pl->origin.y;
    r3.w = 10;
    r3.h = 10;

    SDL_Rect r4;
    r4.x = vect4.x + pl->origin.x;
    r4.y = vect4.y + pl->origin.y;
    r4.w = 10;
    r4.h = 10;

    SDL_RenderFillRect(pl->renderer, &r1);
    SDL_RenderFillRect(pl->renderer, &r2);
    SDL_RenderFillRect(pl->renderer, &r3);
    SDL_RenderFillRect(pl->renderer, &r4);

    SDL_RenderDrawLine(pl->renderer, r1.x, r1.y, r2.x, r2.y);
    SDL_RenderDrawLine(pl->renderer, r1.x, r1.y, r3.x, r3.y);
    SDL_RenderDrawLine(pl->renderer, r2.x, r2.y, r4.x, r4.y);
    SDL_RenderDrawLine(pl->renderer, r3.x, r3.y, r4.x, r4.y);

    pl->btL = pl->btLS;
    pl->btR = pl->btRS;
    pl->tpL = pl->tpLS;
    pl->tpR = pl->tpRS;
}

void rotatePlaneX(Plane *pl, float angle)
{

    //TODO: Figure out a way to rotate along all axises at once
    pl->tpR = rotateX(pl->tpR, angle);
    pl->tpL = rotateX(pl->tpL, angle);
    pl->btR = rotateX(pl->btR, angle);
    pl->btL = rotateX(pl->btL, angle);
}

void rotatePlaneY(Plane *pl, float angle){
    pl->tpR = rotateY(pl->tpR, angle);
    pl->tpL = rotateY(pl->tpL, angle);
    pl->btR = rotateY(pl->btR, angle);
    pl->btL = rotateY(pl->btL, angle);
}

void rotatePlaneZ(Plane *pl, float angle){
    pl->tpR = rotateZ(pl->tpR, angle);
    pl->tpL = rotateZ(pl->tpL, angle);
    pl->btR = rotateZ(pl->btR, angle);
    pl->btL = rotateZ(pl->btL, angle);
}


struct square{

    Matrix *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8;
    Matrix *p1S, *p2S, *p3S, *p4S, *p5S, *p6S, *p7S, *p8S;
    Vector3D origin;

    SDL_Renderer *renderer;
    float r;

};

Square *createSquare(float radius, Vector3D origin, SDL_Renderer *renderer){

    Square *sq = malloc(sizeof(struct square));

    sq->renderer = renderer;
    sq->r = radius;
    sq->origin = origin;

    Vector3D vect1 = {radius, radius, radius};
    Vector3D vect2 = {-radius, radius, radius};
    Vector3D vect3 = {-radius, radius, -radius};
    Vector3D vect4 = {radius, radius, -radius};

    Vector3D vect5 = {radius, -radius, -radius};
    Vector3D vect6 = {-radius, -radius, -radius};
    Vector3D vect7 = {-radius, -radius, radius};
    Vector3D vect8 = {radius, -radius, radius};

    sq->p1 = vect3DToMat(vect1);
    sq->p2 = vect3DToMat(vect2);
    sq->p3 = vect3DToMat(vect3);
    sq->p4 = vect3DToMat(vect4);
    sq->p5 = vect3DToMat(vect5);
    sq->p6 = vect3DToMat(vect6);
    sq->p7 = vect3DToMat(vect7);
    sq->p8 = vect3DToMat(vect8);

    sq->p1S = vect3DToMat(vect1);
    sq->p2S = vect3DToMat(vect2);
    sq->p3S = vect3DToMat(vect3);
    sq->p4S = vect3DToMat(vect4);
    sq->p5S = vect3DToMat(vect5);
    sq->p6S = vect3DToMat(vect6);
    sq->p7S = vect3DToMat(vect7);
    sq->p8S = vect3DToMat(vect8);

    return sq;
    

}

void drawSquare(Square *sq){

    float arr[][3] = {

        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    Matrix *projectionMat = createMatrix(arrToPByThree(arr, 3), 3, 3);


    Matrix *resMat1 = matrixMult(projectionMat, sq->p1);
    Vector3D vect1 = matToVect3D(resMat1);

    Matrix *resMat2 = matrixMult(projectionMat, sq->p2);
    Vector3D vect2 = matToVect3D(resMat2);

    Matrix *resMat3 = matrixMult(projectionMat, sq->p3);
    Vector3D vect3 = matToVect3D(resMat3);

    Matrix *resMat4 = matrixMult(projectionMat, sq->p4);
    Vector3D vect4 = matToVect3D(resMat4);

    Matrix *resMat5 = matrixMult(projectionMat, sq->p5);
    Vector3D vect5 = matToVect3D(resMat5);

    Matrix *resMat6 = matrixMult(projectionMat, sq->p6);
    Vector3D vect6 = matToVect3D(resMat6);

    Matrix *resMat7 = matrixMult(projectionMat, sq->p7);
    Vector3D vect7 = matToVect3D(resMat7);

    Matrix *resMat8 = matrixMult(projectionMat, sq->p8);
    Vector3D vect8 = matToVect3D(resMat8);

    SDL_Rect r1;
    r1.x = vect1.x + sq->origin.x;
    r1.y = vect1.y + sq->origin.y;

    SDL_Rect r2;
    r2.x = vect2.x + sq->origin.x;
    r2.y = vect2.y + sq->origin.y;

    SDL_Rect r3;
    r3.x = vect3.x + sq->origin.x;
    r3.y = vect3.y + sq->origin.y;

    SDL_Rect r4;
    r4.x = vect4.x + sq->origin.x;
    r4.y = vect4.y + sq->origin.y;

    SDL_Rect r5;
    r5.x = vect5.x + sq->origin.x;
    r5.y = vect5.y + sq->origin.y;

    SDL_Rect r6;
    r6.x = vect6.x + sq->origin.x;
    r6.y = vect6.y + sq->origin.y;

    SDL_Rect r7;
    r7.x = vect7.x + sq->origin.x;
    r7.y = vect7.y + sq->origin.y;

    SDL_Rect r8;
    r8.x = vect8.x + sq->origin.x;
    r8.y = vect8.y + sq->origin.y;

    SDL_RenderDrawLine(sq->renderer, r1.x, r1.y, r2.x, r2.y);
    SDL_RenderDrawLine(sq->renderer, r2.x, r2.y, r3.x, r3.y);
    SDL_RenderDrawLine(sq->renderer, r1.x, r1.y, r4.x, r4.y);
    SDL_RenderDrawLine(sq->renderer, r3.x, r3.y, r4.x, r4.y);

    SDL_RenderDrawLine(sq->renderer, r5.x, r5.y, r6.x, r6.y);
    SDL_RenderDrawLine(sq->renderer, r6.x, r6.y, r7.x, r7.y);
    SDL_RenderDrawLine(sq->renderer, r5.x, r5.y, r8.x, r8.y);
    SDL_RenderDrawLine(sq->renderer, r7.x, r7.y, r8.x, r8.y);

    SDL_RenderDrawLine(sq->renderer, r1.x, r1.y, r8.x, r8.y);
    SDL_RenderDrawLine(sq->renderer, r2.x, r2.y, r7.x, r7.y);
    SDL_RenderDrawLine(sq->renderer, r3.x, r3.y, r6.x, r6.y);
    SDL_RenderDrawLine(sq->renderer, r4.x, r4.y, r5.x, r5.y);

    sq->p1 = sq->p1S;
    sq->p2 = sq->p2S;
    sq->p3 = sq->p3S;
    sq->p4 = sq->p4S;
    sq->p5 = sq->p5S;
    sq->p6 = sq->p6S;
    sq->p7 = sq->p7S;
    sq->p8 = sq->p8S;
}

void rotateSquareX(Square *sq, float angle){



    sq->p1 = rotateX(sq->p1, angle);
    sq->p2 = rotateX(sq->p2, angle);
    sq->p3 = rotateX(sq->p3, angle);
    sq->p4 = rotateX(sq->p4, angle);
    sq->p5 = rotateX(sq->p5, angle);
    sq->p6 = rotateX(sq->p6, angle);
    sq->p7 = rotateX(sq->p7, angle);
    sq->p8 = rotateX(sq->p8, angle);

}
void rotateSquareY(Square *sq, float angle){
    

    sq->p1 = rotateY(sq->p1, angle);
    sq->p2 = rotateY(sq->p2, angle);
    sq->p3 = rotateY(sq->p3, angle);
    sq->p4 = rotateY(sq->p4, angle);
    sq->p5 = rotateY(sq->p5, angle);
    sq->p6 = rotateY(sq->p6, angle);
    sq->p7 = rotateY(sq->p7, angle);
    sq->p8 = rotateY(sq->p8, angle);
}
void rotateSquareZ(Square *sq, float angle){

    sq->p1 = rotateZ(sq->p1, angle);
    sq->p2 = rotateZ(sq->p2, angle);
    sq->p3 = rotateZ(sq->p3, angle);
    sq->p4 = rotateZ(sq->p4, angle);
    sq->p5 = rotateZ(sq->p5, angle);
    sq->p6 = rotateZ(sq->p6, angle);
    sq->p7 = rotateZ(sq->p7, angle);
    sq->p8 = rotateZ(sq->p8, angle);
    
}
