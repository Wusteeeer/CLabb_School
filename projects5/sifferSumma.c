#include <stdio.h>

int main(){

    int num = 0, res = 0, cur = 0;

    printf("Mata in ett tal: ");
    scanf("%d", &num);

    do{

        cur = num % 10;

        res += cur;

        num /= 10;

    }while(num > 0);

    printf("Siffersumman ar: %d\n", res);

    return 0;
}