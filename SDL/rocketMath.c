#include <stdio.h>
#include "rocketMath.h"


float calcFuel(float pFuel, float throttle){
    return pFuel - throttle;
}

float calcHeight(float pHeight, float throttle, float vel){
    return (pHeight + vel) + (((throttle * 0.1f) - 1.5f) / 2.0f);
}
