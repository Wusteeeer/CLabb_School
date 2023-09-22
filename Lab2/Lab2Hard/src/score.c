#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "score.h"

struct score{

    float points;

    char text[10];

    SDL_Renderer *renderer;
    SDL_Color color;
    SDL_Texture *texture;
    SDL_Rect rect;

    TTF_Font *font;


};

Score *createScore(float x, float y, SDL_Renderer *renderer, SDL_Color color, float points, int fontSize){

    Score *score = malloc(sizeof(struct score));

    score->rect.x = x;
    score->rect.y = y;

    score->renderer = renderer;
    score->color = color;

    score->points = points;

    score->font = TTF_OpenFont("PixelFont.ttf", fontSize);

    createTextTexture(score, score->points);

    if(!score->texture){
        printf("%s\n", SDL_GetError());
        return NULL;
    }

    return score;

}

void createTextTexture(Score *score, int points){
    
    sprintf(score->text, "%d", points);

    SDL_Surface *surface;
    surface = TTF_RenderUTF8_Blended(score->font, score->text, score->color);

    if(!surface){
        printf("%s\n", SDL_GetError());
        return;
    }

    score->texture = SDL_CreateTextureFromSurface(score->renderer, surface);
    SDL_FreeSurface(surface);

    if(!score->texture){

        printf("%s\n", SDL_GetError());
        return;
    }

    SDL_QueryTexture(score->texture, NULL, NULL, &(score->rect.w), &(score->rect.h));

}

void printScore(Score *score){
    
    SDL_RenderCopyEx(score->renderer, score->texture, NULL, &(score->rect), 0, NULL, SDL_FLIP_NONE);

}

void changeScore(Score *score, float points){
    
    score->points += points;

    createTextTexture(score, score->points);
    
}

void destroyScore(Score *score){
    SDL_DestroyTexture(score->texture);
    free(score);
}