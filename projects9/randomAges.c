#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


void sort(int ages[], int size);
void printAges(int ages[], int size);
void initAges(int ages[], int size);

void mode(int ages[], int size);

int median(int ages[], int size);

int mean(int ages[], int size);

int main(){

    srand(time(NULL));
    int size = 50;

    int ages[size];

    initAges(ages, size);
    // printAges(ages, size);

    sort(ages, size);
    // printAges(ages, size);
    mode(ages, size);


    return 0;
}

void initAges(int ages[], int size){

    for (int i = 0; i < size; i++)
    {
        ages[i] = rand() % 21 + 20;
    }

}

void printAges(int ages[], int size){

    for (int i = 0; i < size; i++)
    {
        printf("%d, ", ages[i]);
    }
    
    printf("\n");

}

void sort(int ages[], int size){

    int max = -INT_MAX, min = INT_MAX;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            
            if(ages[j] < ages[j + 1]){
                
                int temp = ages[j];

                ages[j] = ages[j + 1];

                ages[j + 1] = temp;

            }

        }
        
    }
    

}

void mode(int ages[], int size){
    
    int mode[size], biggestSequences[size], currentSeq = 1, biggestSeq = 1, modeIter = 0;

    for (int i = 0; i < size - 1; i++)
    {

        if(ages[i] == ages[i + 1]){

            currentSeq++;
            // printf("%d, %d\n", ages[i], ages[i + 1]);

        }else
        {

            if(currentSeq > biggestSeq){                

                biggestSeq = currentSeq;
                biggestSequences[modeIter] = biggestSeq;

                for (int i = 0; i < modeIter + 1; i++)
                {
                    if(biggestSeq < biggestSequences[i]){
                        mode[i] = ages[i];
                        break;
                    }else{
                        mode[modeIter] = ages[i];
                    }
                }
                

                modeIter++;
            }
            // printf("%d, %d\n", ages[i], ages[i + 1]);

            // if(currentSeq >= biggestSeq){

            //     modeArr = (int*)realloc(modeArr, modeIter);
            //     modeArr[modeIter] = ages[i];
            //     modeIter++;
            //     biggestSeq = currentSeq;
            // }

        }

    }

    printAges(mode, modeIter);
    // printAges(modeArr, modeIter);
    
    
    
}