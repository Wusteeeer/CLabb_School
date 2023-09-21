#ifndef LABMATH_H
#define LABMATH_H


double *calcVectFromAngle(double angle);

int collision(SDL_Rect sourceRect, SDL_Rect checkRect);

int outsideBounds(float x, float y, int screenW, int screenH);

#endif