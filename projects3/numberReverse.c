#include <stdio.h>
#include <stdlib.h>

void reverse(int num){

   int *temp = (int*)malloc(sizeof(int)); 
   int iter = 0;
    while(num > 0){
      *(temp + iter) = num % 10;

      iter++;
      temp = (int*)realloc(temp, sizeof(int) * (iter + 1));

      num /= 10;
    }

    printf("Your number reversed is: ");
    //Check if first element is 0
    if(*temp == 0){

        for (int i = 0; i < iter; i++)
        {
            if(i == 1){
                printf(".");
            }
            printf("%d", *(temp + i));
        }
     
    }else{

        for (int i = 0; i < iter; i++)
        {
          
            printf("%d", *(temp + i));
        }
    }
   

}


int main(){

    int n = 0;
    printf("Input a number: ");
    scanf("%d", &n);
    reverse(n);
    return 0;
}