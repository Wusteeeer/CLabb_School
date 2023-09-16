#ifndef ASTEROID_H
#define ASTEROID_H


typedef struct asteroid Asteroid;

Asteroid *createAsteroid(float x, float y, float vel, double angle, int screenW, int screenH, SDL_Renderer *renderer);

void drawAsteroid(Asteroid *ast, SDL_Renderer *renderer);
void moveAsteroid(Asteroid *ast);
void updateAsteroid(Asteroid *ast);

void destroyAsteroid(Asteroid *asteroid);



#endif