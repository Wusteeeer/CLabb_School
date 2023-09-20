#ifndef BULLET_H
#define BULLET_H

typedef struct bullet Bullet;

Bullet *createBullet(float x, float y, float vel, double *dir, double angle, float screenW, float screenH, SDL_Renderer *renderer);

void drawBullet(Bullet *bullet);
void moveBullet(Bullet *bullet);
void updateBullet(Bullet *bullet);


#endif