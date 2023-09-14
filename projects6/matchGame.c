#include <stdio.h>


void printMatches(int amount){

    for (int i = 0; i < amount; i++)
    {
        printf("| ");
    }

    printf("\n");
    

}

void cStarts();
void uStarts();

int main(){

    int state = -1;
    printf("\nValkommen till tandsticksspelet!\n");
    printf("Vill du borja? (0 - nej, 1 - ja)");
    scanf("%d", &state);
    
    printf("\n15 tandstickor till att borja med\n");

    if(state == 1){
        uStarts();
        return 0;
    }
    
    cStarts();
        
    return 0;
}


void cStarts(){

    int matchAmount = 15, pickedAmount = 0;
    
    do{

        printMatches(matchAmount);

        //Makes the computer always win if there are between 5 and seven matches
        if(matchAmount <= 3){
            
            //Lets the computer win if there are 3 or less matches left
            pickedAmount = matchAmount;

        }else{

            pickedAmount = matchAmount % 4 == 0 ? 1 : matchAmount % 4;
        }



        printf("Datorn tog %d tandstickor\n", pickedAmount);
        matchAmount -= pickedAmount;

        if(matchAmount <= 0){
            
            //If the game ends here then the player has won
            printf("Datorn vann!");

            return;
        }

        printMatches(matchAmount);


        printf("Hur manga tandstickor vill du ta (1-3)?");
        scanf("%d", &pickedAmount);

        if(pickedAmount < 1 || pickedAmount > 3){
            printf("Valj ett nummer mellan 1-3\n");
            continue;
        }

        matchAmount -= pickedAmount;

    

       

    }while(matchAmount > 0);

    //If the loops ends here then the computer won
    printf("Grattis du vann mot datorn!");    
}

void uStarts(){
    
    int matchAmount = 15, pickedAmount = 0;
    
    do{

        printMatches(matchAmount);


        printf("Hur manga tandstickor vill du ta (1-3)?");
        scanf("%d", &pickedAmount);

        if(pickedAmount < 1 || pickedAmount > 3){
            printf("Valj ett nummer mellan 1-3\n");
            continue;
        }

        matchAmount -= pickedAmount;
        
                
        if(matchAmount <= 0){
            
            //If the game ends here then the player has won
            printf("Grattis du vann mot datorn!");

            return;
        }

        printMatches(matchAmount);

        
        //Makes the computer always win if there are between 5 and seven matches
        if(matchAmount <= 3){
            
            //Lets the computer win if there are 3 or less matches left
            pickedAmount = matchAmount;

        }else{

            pickedAmount = matchAmount % 4 == 0 ? 1 : matchAmount % 4;
        }



        printf("Datorn tog %d tandstickor\n", pickedAmount);
        matchAmount -= pickedAmount;
    

       

    }while(matchAmount > 0);

    //If the loops ends here then the computer won
    printf("Datorn vann!");    
}