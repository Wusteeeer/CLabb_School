#include <stdio.h>
#include <SDL2/SDL.h>
#include "vector.h"
#include "line.h"


Line createLine(Vector2 *start, Vector2 *end, Vector2 *center, SDL_Renderer *renderer, SDL_Color color){

    Line ln = {start, end, center, renderer, color};

    return ln;

}

void drawLine(Line ln){

    SDL_SetRenderDrawColor(ln.renderer, ln.color.r, ln.color.g, ln.color.b, ln.color.a);

    // printf("%.2f, %.2f ; %.2f, %.2f\n", ln.start->x, ln.start->y, ln.end->x, ln.end->y);
    SDL_RenderDrawLine(ln.renderer, ln.start->x + ln.center->x, ln.start->y + ln.center->y, ln.end->x + ln.center->x, ln.end->y + ln.center->y);
}