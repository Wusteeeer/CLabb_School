#ifndef BULLET_H
#define BULLET_H

typedef struct bullet Bullet;

Bullet *createBullet(float x, float y, float vel, double *dir, double angle, float screenW, float screenH, SDL_Renderer *renderer);

void drawBullet(Bullet *bullet);
void moveBullet(Bullet *bullet);
void updateBullet(Bullet *bullet, Bullet **bullets, int *currentBulletAmount, int deleteIndex);
void updateBulletArray(Bullet **bullets, int deleteIndex, int currentBulletAmount);
void spawnBullet(Bullet **bullets, int *currentBulletAmount, int maxBulletAmount, float x, float y, int screenW, int screenH, float vel, double *dir, SDL_Renderer *renderer);
void deleteBullet(Bullet *bullet);
SDL_Rect getBulletRect(Bullet *bullet);

#endif