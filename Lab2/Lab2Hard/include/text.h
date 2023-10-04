#ifndef TEXT_H
#define TEXT_H

typedef struct text Text;

Text *createText(float x, float y, SDL_Renderer *renderer, char str[], int fontSize, SDL_Color color);
void createTextTexture(Text *text, char str[]);
void printText(Text *text);
void destroyText(Text *text);

#endif