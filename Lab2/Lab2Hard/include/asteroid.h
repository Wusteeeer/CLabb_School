#ifndef ASTEROID_H
#define ASTEROID_H


typedef struct asteroid Asteroid;

Asteroid *createAsteroid(float x, float y, float vel, double angle, int screenW, int screenH, SDL_Renderer *renderer);

void spawnAsteroids(Asteroid **asteroids, SDL_Renderer *renderer, float maxVel, float minVel, int currentAsteroidAmount, int windowW, int windowH);
void drawAsteroid(Asteroid *ast, SDL_Renderer *renderer);
void changeAsteroid(Asteroid *ast, float x, float y, float vel, double angle, float size);
void outSideBounds(Asteroid *ast);
void moveAsteroid(Asteroid *ast);
void updateAsteroid(Asteroid *ast);
SDL_Rect getAstRect(Asteroid *ast);
void destroyAsteroid(Asteroid *asteroid);



#endif