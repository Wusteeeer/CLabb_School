#include <stdio.h>


int main(){

    float max = 0, n = 0;
    do{ 
        
        printf("Enter a number: ");
        scanf("%f", &n);

        if(max < n){
            max = n;
        }

    }while(n > 0);

    printf("Max number was %5.2f", max);

    return 0;
}