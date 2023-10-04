#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct complex{

    float real, imaginary;

}Complex;

void printComplex(Complex comp);
void multComplex(Complex *comp1, float mult);

int main(){


    Complex c1 = {3.0, 2.0}, c2 = {2.0, -3.0};

    printComplex(c1);
    printComplex(c2);

    multComplex(&c1, -2.5);
    multComplex(&c2, -1.0);

    printComplex(c1);
    printComplex(c2);

    return 0;
}

void printComplex(Complex comp){

    if(comp.imaginary > 0){

        printf("%.4f + %.4fi\n", comp.real, comp.imaginary);

    }else{
        printf("%.4f - %.4fi\n", comp.real, comp.imaginary * -1);
    }

}


void multComplex(Complex *comp, float mult){

    comp->real *= mult;
    comp->imaginary *= mult;

}