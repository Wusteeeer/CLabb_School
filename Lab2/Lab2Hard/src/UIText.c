#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "score.h"
#include "text.h"

#pragma region Score

struct score{

    float points;

    char text[100];

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

    printf("%.2f\n", score->points);

    score->font = TTF_OpenFont("C:/Cprogram/Lab2/Lab2Hard/PixelFont.ttf", fontSize);

    if(!score->font){
        printf("Could not find font!\n");
        return NULL;
    }

    createScoreTexture(score, score->points);

 
    if(!score->texture){
        printf("%s\n", SDL_GetError());
        return NULL;
    }

    return score;

}

void createScoreTexture(Score *score, int points){
    
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
    
    if(score != NULL)
        SDL_RenderCopyEx(score->renderer, score->texture, NULL, &(score->rect), 0, NULL, SDL_FLIP_NONE);

}

void changeScore(Score *score, float points){
    
    score->points += points;

    createScoreTexture(score, score->points);
    
}

void setScore(Score *score, float points){
    
    score->points = points;

    createScoreTexture(score, score->points);
    
}

void destroyScore(Score *score){
    SDL_DestroyTexture(score->texture);
    free(score);
}

#pragma endregion

struct text{

    char text[100];
    
    SDL_Renderer *renderer;
    SDL_Rect rect;
    SDL_Color color;
    SDL_Texture *texture;   


    TTF_Font *font;  

};


Text *createText(float x, float y, SDL_Renderer *renderer, char str[], int fontSize, SDL_Color color){

    Text *text = malloc(sizeof(struct text));

    text->rect.x = x;
    text->rect.y = y;

    text->renderer = renderer;

    text->color = color;
    text->font = TTF_OpenFont("C:/Cprogram/Lab2/Lab2Hard/PixelFont.ttf", fontSize);

    if(!text->font){
        return NULL;
    }
    
    createTextTexture(text, str);

    if(!text->texture){
        return NULL;
    }

    return text;

}


void createTextTexture(Text *text, char str[]){

    strcpy(text->text, str);

    SDL_Surface *surface;
    surface = TTF_RenderUTF8_Blended(text->font, text->text, text->color);

    if(!surface){
        printf("%s\n", SDL_GetError());
        return;
    }

    text->texture = SDL_CreateTextureFromSurface(text->renderer, surface);
    SDL_FreeSurface(surface);

    if(!text->texture){

        printf("%s\n", SDL_GetError());
        return;
    }

    SDL_QueryTexture(text->texture, NULL, NULL, &(text->rect.w), &(text->rect.h));


}


void printText(Text *text){

    if(text != NULL)
        SDL_RenderCopyEx(text->renderer, text->texture, NULL, &(text->rect), 0, NULL, SDL_FLIP_NONE);


}


void destroyText(Text *text){

    SDL_DestroyTexture(text->texture);
    free(text);

}