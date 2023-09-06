#include <stdio.h>

int main(){

    int a = 0, b = 0, temp = 0;

    printf("Input value for a: ");
    scanf("%d", &a);

    printf("Input value for b: ");
    scanf("%d", &b);

    temp = b;
    b = a;
    a = temp;

    printf("a: %d, b: %d", a, b);
    
    return 0;
}