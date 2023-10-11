#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector.h"
#include "matrix.h"


struct matrix{

    int xSize, ySize;

    float **mat;


};


Matrix *createMatrix(float **arr, int xSize, int ySize)
{

    Matrix *mat = malloc(sizeof(struct matrix));

    mat->xSize = xSize;
    mat->ySize = ySize;

    
    mat->mat = malloc(sizeof(float*) * ySize);
    for (int i = 0; i < ySize; i++)
    {
        mat->mat[i] = malloc(sizeof(float) * xSize);
        for (int j = 0; j < xSize; j++)
        {
            mat->mat[i][j] = arr[i][j];
        }
        
    }

    return mat;
    

}

void printMatrix(Matrix *mat){

    for (int i = 0; i < mat->ySize; i++)
    {

        // printf("%d, %d", mat->xSize, mat->ySize);
        for (int j = 0; j < mat->xSize; j++)
        {
            printf("%.2f ", mat->mat[i][j]);
        }
        printf("\n");
        
    }
    

}

Matrix *vect2DToMat(Vector2D vect)
{

    Matrix *mat = malloc(sizeof(struct matrix));

    mat->mat = malloc(sizeof(float*) * 2);
    mat->mat[0] = malloc(sizeof(float));
    mat->mat[1] = malloc(sizeof(float));

    mat->mat[0][0] = vect.x; 
    mat->mat[1][0] = vect.y;

    mat->xSize = 1;
    mat->ySize = 2;


    return mat;   
}

Matrix *vect3DToMat(Vector3D vect)
{
    Matrix *mat = malloc(sizeof(struct matrix));

    mat->mat = malloc(sizeof(float*) * 3);
    mat->mat[0] = malloc(sizeof(float));
    mat->mat[1] = malloc(sizeof(float));
    mat->mat[2] = malloc(sizeof(float));

    mat->mat[0][0] = vect.x; 
    mat->mat[1][0] = vect.y;
    mat->mat[2][0] = vect.z;

    mat->xSize = 1;
    mat->ySize = 3;


    return mat;   

}

Vector3D matToVect3D(Matrix *mat){

    Vector3D vect = {mat->mat[0][0], mat->mat[1][0], mat->mat[2][0]};

    return vect;

}

Vector2D matToVect2D(Matrix *mat){

    Vector2D vect = {mat->mat[0][0], mat->mat[1][0]};

    return vect;
}


Matrix *matrixMult(Matrix *mat1, Matrix *mat2)
{

    Matrix *multMat = malloc(sizeof(struct matrix));

    float current = 0;

    if(mat1->xSize != mat2->ySize){
        printf("Rows of first matrix don't match columns of second matrix\n");
        return NULL;
    }

    
    float **newArr = malloc(sizeof(float*) * mat2->ySize);

    for (int i = 0; i < mat1->ySize; i++)
    {
        for (int j = 0; j < mat2->xSize; j++)
        {
            for (int k = 0; k < mat1->xSize; k++)
            {
                // printf("%.2f * %.2f\n", mat1->mat[i][k], mat2->mat[k][j]);
                current += mat1->mat[i][k] * mat2->mat[k][j];
            }

            // printf("\n");
            
            newArr[i] = malloc(sizeof(float));
            newArr[i][j] = current;

            // printf("%.2f\n", newArr[i][j]);
            current = 0;
        }

        // printf("\n");
        
    }

    multMat = createMatrix(newArr, mat2->xSize, mat1->ySize);
    
    
    return multMat;


}

Matrix *matrixAdd(Matrix *dest_mat, Matrix *src_mat){

    if(dest_mat->xSize != src_mat->xSize || dest_mat->ySize != src_mat->ySize){
        printf("ERROR: Matrixes of differing sizes!\n");
        return NULL;
    }

    Matrix *resMat = malloc(sizeof(struct matrix));
    resMat->mat = malloc(sizeof(float*) * dest_mat->ySize);

    resMat->xSize = dest_mat->xSize;
    resMat->ySize = dest_mat->ySize;

    for (int i = 0; i < dest_mat->ySize; i++)
    {

        resMat->mat[i] = malloc(sizeof(float) * dest_mat->xSize);

        for (int j = 0; j < dest_mat->xSize; j++)
        {

            
            resMat->mat[i][j] = dest_mat->mat[i][j] + src_mat->mat[i][j];

        }
        
    }
    
    return resMat;

}

float **arrToPByThree(float arr[][3], int ySize){

    float **pArr = malloc(sizeof(float*) * ySize);

    for (int i = 0; i < ySize; i++)
    {
        pArr[i] = malloc(sizeof(float) * 3);

        for (int j = 0; j < 3; j++)
        {

            pArr[i][j] = arr[i][j];

        }


    }

    return pArr;
}

float **arrToPByTwo(float arr[][2], int ySize){

    float **pArr = malloc(sizeof(float*) * ySize);

    for (int i = 0; i < ySize; i++)
    {
        pArr[i] = malloc(sizeof(float) * 2);

        for (int j = 0; j < 2; j++)
        {

            pArr[i][j] = arr[i][j];

        }

    }

    return pArr;

}

float **arrToPByOne(float arr[][1], int ySize){

    float **pArr = malloc(sizeof(float*) * ySize);

    for (int i = 0; i < ySize; i++)
    {
        pArr[i] = malloc(sizeof(float));

        for (int j = 0; j < 1; j++)
        {

            pArr[i][j] = arr[i][j];

        }

    }

    return pArr;

}


Matrix *rotateZ(Matrix *mat, float angle){

    float rotationArr[][3] = {
        {cos(angle), -sin(angle), 0},
        {sin(angle), cos(angle), 0},
        {0, 0, 1}
    };

    float **pRotationArr = arrToPByThree(rotationArr, 3);

    Matrix *rotationMatrix = createMatrix(pRotationArr, 3, 3);

    Matrix *multRotMat = matrixMult(rotationMatrix, mat);

    return multRotMat;


}

Matrix *rotateX(Matrix *mat, float angle){

    float rotationArr[][3] = {
        {1, 0, 0},
        {0, cos(angle), -sin(angle)},
        {0, sin(angle), cos(angle)}
    };

    float **pRotationArr = arrToPByThree(rotationArr, 3);

    Matrix *rotationMatrix = createMatrix(pRotationArr, 3, 3);

    Matrix *multRotMat = matrixMult(rotationMatrix, mat);

    return multRotMat;
}

Matrix *rotateY(Matrix *mat, float angle){

    float rotationArr[][3] = {
        {cos(angle), 0, sin(angle)},
        {0, 1, 0},
        {-sin(angle), 0, cos(angle)}
    };

    float **pRotationArr = arrToPByThree(rotationArr, 3);

    Matrix *rotationMatrix = createMatrix(pRotationArr, 3, 3);

    Matrix *multRotMat = matrixMult(rotationMatrix, mat);

    return multRotMat;

}
