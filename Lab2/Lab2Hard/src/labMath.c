#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "labMath.h"


double *calcVectFromAngle(double angle){

    double *dir = malloc(sizeof(double) * 2);
    dir[0] = cos(angle * 0.017453f);
    dir[1] = sin(angle * 0.017453f);

    return dir;

}