#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 20

void printArr(int arr[], int len);
void declareArr(int arr[], int len);
void sortArr(int arr[], int len);

int main(){

    srand(time(NULL));
    int arr[LENGTH] = {0};
    
    declareArr(arr, LENGTH);
    sortArr(arr, LENGTH);
    printArr(arr, LENGTH);
}

void declareArr(int arr[], int len){

    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % 21 - 10;
    }
    

}

void sortArr(int arr[], int len){
    
    int temp = 0;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            
            if(arr[j] < arr[j + 1]){
                
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

            }

        }
        
    }
    

}

void printArr(int arr[], int len){

    for (int i = 0; i < len; i++)
    {

        if(i < len - 1){
            printf("%d, ", arr[i]);
            continue;

        }
        printf("%d\n", arr[i]);

    }

}