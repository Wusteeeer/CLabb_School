#include <stdio.h>
#include <SDL2/SDL.h>
#include "vector.h"
#include "matrix.h"

int main(int argv, char** args){

    // int xSize = 2, ySize = 3;
    // float arr[][3] = {

    //     {1.0, 2.0},
    //     {3.4, 2.5},
    //     {0.1, 5.6}

    // };

    // Matrix *mat = createMatrix(arr, xSize, ySize);

    // printMatrix(mat);      

    // Vector2D *vect2D = createVector2D(1.2, 3.4);
    // Vector3D *vect3D = createVector3D(2.5, 2.3, 5.6);

    // printVector2D(vect2D);
    // printVector3D(vect3D);

    // printMatrix(vect2DToMat(vect2D));
    // printMatrix(vect3DToMat(vect3D));

    // float arr1[][3] = {
    //     {1, 2, 3}
    // };

    //TODO: Need to figure out how to be able to make a matrix of any size. Migh need to write a function to convert a
    //2D array to a pointer to pointer
    // float **arr2;
    // arr2 = malloc(sizeof(float) * 3);
    // arr2[0][0] = 1;
    // arr2[0][1] = 2;
    // arr2[0][2] = 3;

    float arr[][3] = {

        {2, 3, 4},
        {5, 6, 7}
    };

    float **pArr = malloc(sizeof(float*) * 2);

    for (int i = 0; i < 2; i++)
    {
        pArr[i] = malloc(sizeof(float) * 3);

        for (int j = 0; j < 3; j++)
        {

            pArr[i][j] = arr[i][j];

        }

    }
    
    

    Matrix *mat1 = createMatrix(pArr, 3, 2);
    printMatrix(mat1);

    printf("\n");

    float arr2[][1] = {

        {5},
        {6},
        {7}
    };

    float **pArr2 = malloc(sizeof(float*) * 3);

    for (int i = 0; i < 3; i++)
    {
        pArr2[i] = malloc(sizeof(float));
        pArr2[i][0] = arr2[i][0];

    }
    Matrix *mat2 = createMatrix(pArr2, 1, 3);
    printMatrix(mat2);
    
    printf("\n");

    Matrix *multMat = matrixMult(mat1, mat2);
    printMatrix(multMat);

    return 0;
}