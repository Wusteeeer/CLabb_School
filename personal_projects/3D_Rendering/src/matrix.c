#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "matrix.h"


struct matrix{

    int xSize, ySize;

    float **mat;


};

const float projectionMatrix[][3] = {

    {1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0}

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

Matrix *vect2DToMat(Vector2D *vect)
{

    Matrix *mat = malloc(sizeof(struct matrix));

    mat->mat = malloc(sizeof(float*));
    mat->mat[0] = malloc(sizeof(float) * 2);

    mat->mat[0][0] = vect->x; 
    mat->mat[0][1] = vect->y;

    mat->xSize = 2;
    mat->ySize = 1;


    return mat;   
}

Matrix *vect3DToMat(Vector3D *vect)
{
    Matrix *mat = malloc(sizeof(struct matrix));

    mat->mat = malloc(sizeof(float*));
    mat->mat[0] = malloc(sizeof(float) * 3);

    mat->mat[0][0] = vect->x; 
    mat->mat[0][1] = vect->y;
    mat->mat[0][2] = vect->z;

    mat->xSize = 3;
    mat->ySize = 1;


    return mat;   

}

Matrix *matrixMult(Matrix *mat1, Matrix *mat2)
{

    Matrix *multMat = malloc(sizeof(struct matrix));

    float current = 0;

    if(mat1->xSize != mat2->ySize){
        printf("Rows of first matrix don't match columns of second matrix\n");
        return NULL;
    }

    for (int i = 0; i < mat1->ySize; i++)
    {
        
        for (int j = 0; j < mat2->xSize; j++)
        {
            
            for (int k = 0; k < mat1->xSize; k++)
            {
                
                current += mat1->mat[i][k] * mat2->mat[k][j];
                

            }
            
            

        }
        printf("%.2f\n", current);
        

    }
    
    
    return NULL;


}