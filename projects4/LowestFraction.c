#include <stdio.h>

int GDC(int n, int m);

int main(){

    int numerator = 0, denominator = 0;

    printf("Please input a fraction (x/y): ");
    scanf("%d/%d", &numerator, &denominator);


    int gdc = GDC(numerator, denominator);

    printf("The lowest terms are: %d/%d", numerator / gdc, denominator / gdc);

    return 0;
}

int GDC(int n, int m){

    int remainder = 0;
    while( n > 0 ){

        remainder = m % n;

        m = n;
        
        n = remainder;
    }

    return m;
}