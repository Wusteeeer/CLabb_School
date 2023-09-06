#include <stdio.h>

int main(){

    int m = 0, n = 0, remainder = 0;

    printf("Please enter two numbers: ");
    scanf("%d %d", &m, &n);

    //First loop: m = 28, n = 12, remainder = 4
    //Second loop: m = 12, n = 4, remainder = 0
    //Third loop: m = 4, n = 0 Stops.
    while( n > 0 ){

        remainder = m % n;

        m = n;
        
        n = remainder;
    }

    
    
    printf("The greatest common denominator is: %d", m);


    return 0;
}