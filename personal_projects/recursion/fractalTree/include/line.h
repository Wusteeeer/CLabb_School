#ifndef LINE_H
#define LINE_H

typedef struct line{

    Vector2 *start, *end;
    Vector2 *center;

    SDL_Renderer *renderer;
    SDL_Color color;

}Line;

Line createLine(Vector2 *start, Vector2 *end, Vector2 *center, SDL_Renderer *renderer, SDL_Color color);

void drawLine(Line ln);


#endif