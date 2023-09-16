#ifndef SHIP_H
#define SHIP_H


//Definition needs to be in header file, otherwise it does not work correctly in multiple C-files
typedef struct ship Ship;

Ship *createShip(float x, float y, int screenWidth, int screenHeight, SDL_Renderer *renderer);
void updateShip(Ship *ship);
void drawShip(Ship *ship, SDL_Renderer *renderer);
void rotateShip(Ship *ship, float rotation);
void moveShip(Ship *ship);
void thrusters(Ship *ship, float acc, float fric);
void deleteShip(Ship *ship);

double *calcVectFromAngle(double angle);

#endif