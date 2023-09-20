#include <stdio.h>
#define SIZE 5


void readInput(int grid[][SIZE]);

void calcRowColSum(int grid[][SIZE], int colsSum[], int rowsSum[]);

void writeOutput(int colsSum[], int rowsSum[]);

int main(){

    int grid[SIZE][SIZE] = {0}, rowsSum[SIZE] = {0}, colsSum[SIZE] = {0};
    
    readInput(grid);
    calcRowColSum(grid, colsSum, rowsSum);
    writeOutput(colsSum, rowsSum);
    

    return 0;

}

void readInput(int grid[][SIZE]){


    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter row %d: ", i + 1);

        scanf("%d %d %d %d %d", &grid[0][i], &grid[1][i], &grid[2][i], &grid[3][i], &grid[4][i]);
    
    }
}


void calcRowColSum(int grid[][SIZE], int colsSum[], int rowsSum[]){

    for (int i = 0; i < SIZE; i++)
    { 
        

        for (int j = 0; j < SIZE; j++)
        {
            
            colsSum[i] += grid[i][j];
            rowsSum[j]  += grid[i][j];

        }
        
    }
    

}


void writeOutput(int colsSum[], int rowsSum[]){

    printf("Row totals: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", rowsSum[i]);
    }

    printf("\n");

    printf("Column totals: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", colsSum[i]);
    }
    

}