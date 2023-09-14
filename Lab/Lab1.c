#include <stdio.h>

float calcVelocity(float pVel, float throttle);

float calcHeight(float pHeight, float throttle, float vel);

float calcFuel(float pFuel, float throttle);

void init(){

    printf("\n");
    printf("Lunar decent challange!\n");
    printf("You will pilot a lunar decent the last 250m.\n");
    printf("Each turn represents 1-second decent time.\n");
    printf("Set the throttle for each turn (0-100).\n");
    printf("Time Height Velocity Fuel Throttle\n");
}

int main(){

    float height = 250.0f, velocity = -25.0f, throttle = 0.0f, fuel = 500.0f;
    int iter = 0;
    init();

    do{

        printf("%d    %.1f    %.1f  %.1f   ", iter, height, velocity, fuel);
        scanf("%f", &throttle);

        if(throttle > 100 || throttle < 0){
            printf("Please input a number between 0-100!\n");
            continue;
        }

        height = calcHeight(height, throttle, velocity);
        velocity = calcVelocity(velocity, throttle);

        fuel = calcFuel(fuel, throttle);

        iter++;

    }while(height > 0 && fuel > 0);


    if( velocity < -2 ){
        printf("FAILED! Crash landing at %.1fm/s", velocity);
        return 0;
    }
    
    if(fuel <= 0){
        printf("FAILED! you have no more fuel and crashed with a speed of %.1fm/s onto the moon", velocity);
        return 0;
    }


    printf("CONGRATULATIONS! You landed on the moon successfully!");
    
    return 0;
}


float calcFuel(float pFuel, float throttle){
    return pFuel - throttle;
}

float calcHeight(float pHeight, float throttle, float vel){
    return (pHeight + vel) + (((throttle * 0.1f) - 1.5f) / 2.0f);
}

float calcVelocity(float pVel, float throttle){
    return pVel + ((0.1f * throttle) - 1.5f);
}

