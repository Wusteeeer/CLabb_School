#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix Matrix;

Matrix *createMatrix(float **arr, int xSize, int ySize);

void printMatrix(Matrix *mat);

float **arrToPByThree(float arr[][3], int ySize);
float **arrToPByTwo(float arr[][2], int ySize);
float **arrToPByOne(float arr[][1], int ySize);

Matrix *matrixMult(Matrix *mat1, Matrix *mat2);
Matrix *matrixAdd(Matrix *dest_mat, Matrix *src_mat);

Matrix *rotateZ(Matrix *mat, float angle);
Matrix *rotateX(Matrix *mat, float angle);
Matrix *rotateY(Matrix *mat, float angle);

Vector2 *rotateVect2(Vector2 v, float angle);

Matrix *vect2DToMat(Vector2 vect);
Matrix *vect3DToMat(Vector3 vect);

Vector3 matToVect3D(Matrix *mat);
Vector2 *matToVect2D(Matrix *mat);


#endif