#include <stdio.h>

void generateSquare(int size);

int main(){

    int size = 0;
    printf("Storlek: ");
    scanf("%d", &size);

    generateSquare(size);    

    return 0;
}

void generateSquare(int size){

    
    int diagonalStart = 0, diagonalEnd = (size - 1);
    for (int i = 0; i < size; i++)
    {
        
        //This loop is for the height
        for (int j = 0; j < size; j++)
        {
            //This loop is for the length
            if( j == diagonalStart || j == diagonalEnd )
            {
                printf("*");
            }
            else
            {
                printf("+");
            }

        }
        
        printf("\n");
        diagonalStart++;
        diagonalEnd--;
        
    }
    


}