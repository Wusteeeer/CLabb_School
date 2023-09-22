#ifndef SCORE_H
#define SCORE_H


typedef struct score Score;

Score *createScore(float x, float y, SDL_Renderer *renderer, SDL_Color color, float points, int fontSize);
void createTextTexture(Score *score, int points);
void printScore(Score *score);
void changeScore(Score *score, float points);
void destroyScore(Score *score);


#endif