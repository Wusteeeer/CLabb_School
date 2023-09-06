#include <stdio.h>


float dist(float speed, float time);
int main(){

    float time = 0, speed = 0;

    printf("Ange Hastighet (km/h): ");
    scanf("%f", &speed);

    printf("Ange tid (h): ");
    scanf("%f", &time);

    printf("Du kommer fardas %g km\nLycka till pa farden", dist(speed, time));
    return 0;
}

float dist(float speed, float time){
    return speed * time;
}