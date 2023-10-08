#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix Matrix;


Matrix *createMatrix(float **arr, int xSize, int ySize);

void printMatrix(Matrix *mat);

Matrix *matrixMult(Matrix *mat1, Matrix *mat2);

Matrix *vect2DToMat(Vector2D *vect);
Matrix *vect3DToMat(Vector3D *vect);


#endif