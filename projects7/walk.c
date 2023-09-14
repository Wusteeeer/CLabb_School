#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define SIZE 10


int main(){

    char grid[SIZE][SIZE], currentChar = 'A';

    int dir = 0, currentX = 0, currentY = 0, currAttempts = 1;

    bool canWalk = true;
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            grid[i][j] = '.';
        }
    }

    //Generate walk
    while(canWalk){
        
        grid[currentX][currentY] = currentChar;

        dir = rand() % 4 + 1;


        if(currAttempts == 40 || currentChar == 'Z'){
            canWalk = false;
        }

        switch(dir){
            case 1:

                //DOWN
                if(currentY + 1 < 10 && grid[currentX][currentY + 1] == '.'){
                    
                    currentY++;

                    break;
                }


            case 2:

                //UP
                if(currentY - 1 >= 0 && grid[currentX][currentY - 1] == '.'){
                    
                    currentY--;

                    break;
                }


            case 3:

                //RIGHT
                if(currentX + 1 < 10 && grid[currentX + 1][currentY] == '.'){
                    
                    currentX++;
                    
                    break;
                }


            case 4:

                //LEFT
                if(currentX - 1 >= 0 && grid[currentX - 1][currentY] == '.'){
                    
                    currentX--;
                    
                    break;
                }

                currAttempts++;
            continue;        
        }

        currAttempts = 1;
        currentChar++;
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%c", grid[j][i]);
        }
        printf("\n");
    }

}