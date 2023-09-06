#include <stdio.h>

int main(){
    int a = 100, b = 1;

    while(a > b){
        
        printf("%d, %d\n", a, b);

        if(a / b > 20){


            a /= 2;


        }else{


            while(b < a/2){

                b++;
                printf("%d\n", b);

            }

            b++;
        }

    }

    printf("%d, %d", a, b);
    return 0;
}