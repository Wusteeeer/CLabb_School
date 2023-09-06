#include <stdio.h>


//OBS: Just nu omöjligt (antagligen) (extrauppgift)! ändra plats på om användaren eller datorn börjar för att göra det möjligt.
void printMatches(int amount){

    for (int i = 0; i < amount; i++)
    {
        printf("| ");
    }

    printf("\n");
    

}

int main(){

    int matchAmount = 15, pickedAmount = 0;

    printf("Valkommen till tandsticksspelet!\n");
    
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

            return 0;
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

    return 0;
}