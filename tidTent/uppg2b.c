#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void readInput(char str[], bool *isRunning, int *currentTextSize, int *currentWordAmount);
void findWords(char str[], bool *isRunning, int *currentTextSize, int *currentWordAmount);

int main(){

    char str[600];
    bool isRunning = true;
    int currentTextSize = 0;
    int currentWordAmount = 0;


    readInput(str, &isRunning, &currentTextSize, &currentWordAmount);


    while(isRunning){

        findWords(str, &isRunning, &currentTextSize, &currentWordAmount);

    }


    

    return 0;
}

void readInput(char str[], bool *isRunning, int *currentTextSize, int *currentWordAmount){

    printf("Ange ord avsluta med *\n");
    
    char tempStr[600];

    scanf("%[^\n]%*c", tempStr);

    if(tempStr[0] == '*'){
        printf("Avslutar\n");
        *isRunning = false;
        return;
    }

    int i = 0;
    while(tempStr[i] != '*'){
        
        if(*currentWordAmount > 20){
            printf("Fullt inga fler ord kan adderas.\n");
            (*currentTextSize)--;
            break;
        }

        str[*currentTextSize] = tempStr[i];
        i++;   
        (*currentTextSize)++;

        if(tempStr[i] == ' '){
            (*currentWordAmount)++;
        }

    }

    str[*currentTextSize + 1] = ' ';

    
    

}

void findWords(char str[], bool *isRunning, int *currentTextSize, int *currentWordAmount)
{

    printf("Ange bokstav (* for nya ord)\n");
    char letter;

    scanf("%c%*c", &letter);

    if(letter == '*')
    {
        readInput(str, isRunning, currentTextSize, currentWordAmount);
        return;
    }


    for (int i = 0; i < *currentTextSize; i++)
    {
        if(letter == str[i] && str[i - 1] == ' '){
            
            while(str[i] != ' '){

                printf("%c", str[i]);
                i++;

            }

            printf(" ");

        }


    }

    printf("\n");
    


}