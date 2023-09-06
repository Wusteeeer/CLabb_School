#include <stdio.h>

static int twenty = 0, ten = 0, five = 0, one = 0;

void converter(int amount){

    if(amount == 0){

        printf("$20 bills: %d\n$10 bills: %d\n$5 bills: %d\n$1 bills: %d\n", twenty, ten, five, one);
        return;
    }
    
    if(amount % 20 == 0){
        twenty++;
        converter(amount - 20);
    }else if(amount % 10 == 0){
        ten++;
        converter(amount - 10);
    }else if(amount % 5 == 0){
        five++;
        converter(amount - 5);
    }else{
        one++;
        converter(amount - 1);
    }




}

int main(){

    int dollar = 0;
    printf("Enter a dollar amount: ");
    scanf("%d", &dollar);
    converter(dollar);
    return 0;
}