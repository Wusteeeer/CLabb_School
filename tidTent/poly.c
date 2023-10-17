#include <stdio.h>
#include <math.h>

typedef struct pol{

    float a, b, c;

}Pol;

Pol createPol(float a, float b, float c);
void printPol(Pol poly);
float value(Pol poly, float x);
void differentiate(Pol *poly);

int main(){

    Pol poly = createPol(2.0, -1.0, -3.0);

    printPol(poly);

    printf("%.3f\n", value(poly, 0.5));

    differentiate(&poly);
    printPol(poly);

    return 0;
}

Pol createPol(float a, float b, float c){

    Pol poly = {a, b, c};

    return poly;

}


void printPol(Pol poly){

    printf("(%.3f)x^2 + (%.3f)x + (%.3f)\n", poly.a, poly.b, poly.c);

}


float value(Pol poly, float x){

    float res = poly.a * pow(x, 2) + poly.b * x + poly.c;

    return res;

}

void differentiate(Pol *poly){

    poly->c = poly->b;
    poly->b = poly->a * 2;
    poly->a = 0;


}