#include <stdio.h>

void priceCalc(int amount){

    float basePrice = 9.9f;
    int sale = 0;
    
    if(amount > 50){
        sale = 10;
    }else if(amount > 10){
        sale = 5;
    }


    basePrice -= ((float)basePrice * ((float)sale / (float)100));

    printf("You need to pay: %.2f", basePrice);
}

int main(){

    //priceCalc(21);

    int i = 1, j = 2, k = 3;
    printf("%d", (i + 5) % (j + 2) / k);
    return 0;
}