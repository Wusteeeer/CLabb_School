#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10


void repDig(int arr[], long num);

int main(){

    long num = -1, iter = 0, lastDigit = 0, temp = 0;
    int arr[LENGTH] = {0};

    while(1)
    {

        

        printf("Please enter a number: ");
        scanf("%d", &num);
        
        if(num <= 0){

            printf("Terminating...");
            break;
        }

        repDig(arr, num);

    }
    

    return 0;
}

void repDig(int arr[], long num){

    int temp = 0, iter = 0, lastDigit = 0;

    temp = num;

    do{

        lastDigit = temp % 10;

        arr[lastDigit]++;

        temp /= 10;

    }while(temp > 0);

    printf("Digit:        0   1   2   3   4   5   6   7   8   9\n");
    printf("Occurence:    ");
    for(iter = 0; iter < LENGTH; iter++){
        
        //FOR TASK 1: Check if arr[iter] > 1 if it is then print iter
        printf("%d   ", arr[iter]);

        arr[iter] = 0;
    }

    printf("\n");
}