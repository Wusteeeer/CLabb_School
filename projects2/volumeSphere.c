#include <stdio.h>
#include <math.h>

float volume(float radius){

    float vol = (4.0f / 3.0f) * pow(radius, 3) * M_PI;
    return vol;
}

int main(){

    float r = 0;
    printf("Input radius of sphere: ");
    scanf("%f", &r);
    printf("The spheres volume is: %6.5f cubic meters", volume(r));
    return 0;
}