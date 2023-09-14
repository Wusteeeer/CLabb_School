#include <stdio.h>


int numDigits(int num);

int main(){

    int num = 0;
    printf("Input a number: ");
    scanf("%d", &num);

    printf("Number of digits in number %d = %d", num, numDigits(num));

    return 0;
}

int numDigits(int num){

    int iter;
    do{

        num /= 10;
        iter++;

    }while(num > 0);

    return iter;
}