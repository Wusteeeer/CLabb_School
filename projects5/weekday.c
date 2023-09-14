#include <stdio.h>


int main(){


    int currWeekDay = 0, calcWeekDay = 0, dayAmount = 0;

    //Takes input from user
    printf("Vilken dag ar det idag (1-man, 2-tis, ..., 7-son): ");
    scanf("%d", &currWeekDay);
    printf("Ange antal dagar: ");
    scanf("%d", &dayAmount);

    //Calculations. Ex: It it is Wed (3) we want to check what day it is tomorrow (1) then we would take:
    //1 + 3 = 4 => 4 % 7 = 4 or Thu (4)
    calcWeekDay = (dayAmount + currWeekDay) % 7;   

    //Prints the results 
    printf("Om %d dagar ar det ", dayAmount);

    switch(calcWeekDay){
        case 0:

            printf("Sondag");

        break;
        case 1:

            printf("Mandag");
            
        break;
        case 2:

            printf("Tisdag");
            
        break;
        case 3:

            printf("Onsdag");

        break;
        case 4:

            printf("Torsdag");
            
        break;
        case 5:

            printf("Fredag");

        break;
        case 6:

            printf("Lordag");

        break;

    }


    return 0;
}