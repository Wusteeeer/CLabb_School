#include <stdio.h>
#include <stdlib.h>

int main(){

    int *numbers = (int*)malloc(sizeof(int) * 4);

    printf("Enter four integers: ");
    scanf("%d %d %d %d", &numbers[0], &numbers[1], &numbers[2], &numbers[3]);

    int currMax = -100000, currSmall = 100000;

    for (int i = 0; i < 4; i++)
    {   
        if(currMax < *(numbers + i)){
            currMax = *(numbers + i);
        }

        if(currSmall > *(numbers + i)){
            currSmall = *(numbers + i);
        }
    }

    printf("Largest: %d\n", currMax);
    printf("Smallest: %d\n", currSmall);
    

    return 0;
}