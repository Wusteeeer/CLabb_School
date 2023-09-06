#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 2

int main(){

    srand(time(NULL));
    //Skapar array med två slumpmässade nummer
    int rNums[LENGTH] = {rand() % 10 + 1, rand() % 10 + 1}, max = -1, min = 11;

    //Sorterar arrayen med minst nummer först
    for (int i = 0; i < LENGTH; i++)
    {
        
        if(max < rNums[i]){
            max = rNums[i];
        }

        if(min > rNums[i]){
            min = rNums[i];
        }
        
    }

    rNums[0] = min;
    rNums[1] = max;
    
    
    //Skriver ut arrayen
    for (int i = 0; i < LENGTH; i++)
    {
        printf("%d ", rNums[i]);
    }
    

    return 0;
}