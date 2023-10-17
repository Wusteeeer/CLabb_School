#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void readInput(char str[], bool *isRunning, int *currentTextSize);
void findWords(char str[], bool *isRunning, int *currentTextSize);

int main(){

    char str[600];
    bool isRunning = true;
    int currentTextSize = 0;

    readInput(str, &isRunning, &currentTextSize);


    while(isRunning){

        findWords(str, &isRunning, &currentTextSize);

    }


    

    return 0;
}

void readInput(char str[], bool *isRunning, int *currentTextSize){

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
        
        str[*currentTextSize] = tempStr[i];
        i++;   
        (*currentTextSize)++;

    }

    
    

}

void findWords(char str[], bool *isRunning, int *currentTextSize)
{

    printf("Ange bokstav (* for nya ord)\n");
    char letter;

    scanf("%c%*c", &letter);

    if(letter == '*')
    {
        readInput(str, isRunning, currentTextSize);
        return;
    }


    for (int i = 0; i < *currentTextSize; i++)
    {
        if(letter == str[i] && str[i - 1] == ' '){
            
            puts(str);
            // printf("Hello World%c\n", str[i - 1]);
            while(str[i] != ' '){

                printf("%c", str[i]);
                i++;

            }

            printf(" ");

        }


    }

    printf("\n");
    


}

