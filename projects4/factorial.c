#include <stdio.h>


void fact(int num);

int main(){

    int num = 0;

    do{
        printf("Ange ett tal: ");
        scanf("%d", &num);
        if(num < 0)
        {

            printf("Talet ska vara positivt.\n");

        }
        else if(num != 0)
        {
            fact(num);
        }

    }while(num != 0);


    printf("Avslutar");

    return 0;
}

void fact(int num){

    int iter = num, res = 1;

    while(iter > 0){

        res *= iter;

        iter--;
    }

    printf("%d! = %d\n", num, res);

}