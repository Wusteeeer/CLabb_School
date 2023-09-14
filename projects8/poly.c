#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int polynomial(int x);

int main(){

    int x = 0;
    printf("Please input a number: ");
    scanf("%d", &x);

    printf("%d", polynomial(x));

    return 0;
}

int polynomial(int x){

    return (3 * pow(x, 5)) + (2 * pow(x, 4)) - (5 * pow(x, 3)) - (pow(x, 2)) + (7 * x) - 6;

}

