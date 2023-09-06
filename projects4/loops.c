#include <stdio.h>


void whileLoop();

void forLoop();

int main(){

    whileLoop();
    forLoop();

    return 0;
}

void forLoop(){

    int maxLoop = 10;
   
    
    for (int n = 1; n <= maxLoop; n++)
    {
        if(n == maxLoop){

            printf("%d\n", n);
            break;

        }

        printf("%d, ", n);
    }

    maxLoop = 0;
    for (int n = 10; n >= maxLoop; n -= 2)
    {
        if(n == maxLoop){

            printf("%d\n", n);
            break;

        }

        printf("%d, ", n);
    }
    

    maxLoop = 32;
    for (int n = 1; n <= maxLoop; n *= 2)
    {
        if(n == maxLoop){

            printf("%d\n", n);
            break;

        }

        printf("%d, ", n);
    }
}

void whileLoop(){
    int n = 1, maxLoop = 10;

    do{

        if(n == maxLoop){

            printf("%d\n", n);
            break;

        }

        printf("%d, ", n);
        n++;

    }while(n <= maxLoop);


    n = 10;
    maxLoop = 0;
    do{

        if(n == maxLoop){

            printf("%d\n", n);
            break;

        }

        printf("%d, ", n);
        n -= 2;

    }while(n >= maxLoop);

    maxLoop = 32;
    n = 1;
    do{

        if(n == maxLoop){

            printf("%d\n", n);
            break;

        }

        printf("%d, ", n);
        n *= 2;

    }while(n <= maxLoop);
}