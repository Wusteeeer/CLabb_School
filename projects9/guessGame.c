#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

void generateCode(int code[]);
int howManyRight(int code[], int guessCode[]);
void guess(int guessCode[]);

int main(){

    time_t t;

    srand(time(&t));

    int code[3] = {0}, guessCode[3] = {0}, guessAmount = 0;
    generateCode(code);

    bool correctGuess = false;

    for (int i = 0; i < 3; i++)
    {
        printf("%d, ", code[i]);
    }
    
    printf("\n");

    while(!correctGuess){

        guessAmount++;
        guess(guessCode);
       
        if( howManyRight(code, guessCode) == 3){
            printf("Ratt kod. Du behovde %d gissningar\n", guessAmount);
            correctGuess = true;
        }else{
            printf("Fel kod. Du hade %d ratt\n", howManyRight(code, guessCode));

        }


    }


}

void generateCode(int code[]){

    for (int i = 0; i < 3; i++)
    {
        
        code[i] = rand() % 9;

    }
    

}

void guess(int guessCode[]){

    printf("Gissa koden: ");
    scanf("%d %d %d", &guessCode[0], &guessCode[1], &guessCode[2]);

}

int howManyRight(int code[], int guessCode[]){

    int right = 0;
    for (int i = 0; i < 3; i++)
    {
        
        if(code[i] == guessCode[i]){
            right++;
        }

    }

    return right;
    


}