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

    printf("Ange start (* for nya ord)\n");
    char letters[30];

    scanf("%[^\n]%*c", letters);

    if(letters[0] == '*')
    {
        readInput(str, isRunning, currentTextSize, currentWordAmount);
        return;
    }
    
    char temp[30];
    int index = 0;
    for (int i = 0; i < strlen(str); i++)
    {


                        
        for (int j = 0; j < strlen(letters); j++)
        {
            
            // printf("%c, %c %d, %d\n", str[i], letters[j], i, j);

            if(str[i - 1] != ' ' && temp[i - 1] == ' '){
                break;
            }

            if(str[i] == ' '){
                break;
            }

            if(letters[j] != str[i]){
                
                break;
            }

            if(letters[j] == str[i]){

                temp[i] = str[i];
                i++;

            }
        }


   
        printf("%s\n", temp);
            

        strcpy(temp, "");


    }
    


}