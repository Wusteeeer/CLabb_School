#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>


void initArr(int arr[], int size);

void shuffle(int numArr[], int size);

void biggestSequence(int numArr[], int size);

int getSize();

int main(){

    srand(time(NULL));
    int size = getSize();

    int numArr[size];

    initArr(numArr, size);

    shuffle(numArr, size);
    
    biggestSequence(numArr, size);
    

}

void biggestSequence(int numArr[], int size){

    int biggestSeq = 1, currSeq = 1;
    
    
    for (int i = 0; i < size - 1; i++)
    {
        
        if(numArr[i] < numArr[i + 1]){
            currSeq++;
        }else{

            if(currSeq > biggestSeq){
                biggestSeq = currSeq;
            }

            currSeq = 1;
        }


    }

    printf("Langsta talfoljden ar: %d", biggestSeq);
    
}

int getSize(){
    
    int size = 0;


    while(1){

        printf("Vilket ar det hogsta heltal du vill ha med (1-1000)? ");
        scanf("%d", &size);

        if(size > 1000 || size < 1){
            printf("Du maste valja mellan 1 och 1000!\n");
            continue;
        }

        return size;

    }

}

void shuffle(int numArr[], int size){
    
    int randomIndex = 0;
    int temp = 0;

    for (int i = 0; i < size; i++)
    {

        randomIndex = rand() % (size - i) + i;

        temp = numArr[randomIndex];

        numArr[randomIndex] = numArr[i];
        numArr[i] = temp;

  

        
        printf("%d, ", numArr[i]);

    }

    printf("\n");
}

void initArr(int arr[], int size){
    
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }
}