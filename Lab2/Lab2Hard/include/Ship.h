#ifndef SHIP_H
#define SHIP_H


typedef struct ship Ship;

Ship *createShip(float x, float y, int screenWidth, int screenHeight, SDL_Renderer *renderer);

void updateShip(Ship *ship);
void drawShip(Ship *ship, SDL_Renderer *renderer);
void rotateShip(Ship *ship, float rotation);
void moveShip(Ship *ship);
void thrusters(Ship *ship, float acc, float fric);

SDL_Rect getShipRect(Ship *ship);
double *getMoveDir(Ship *ship);
void gameOver(Ship *ship);
void deleteShip(Ship *ship);

#endif