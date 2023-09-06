#include <stdio.h>


void printCalender(int startingDay, int amountOfDays);

int main(){

    int startDay = 0, amountOfDays = 0;

    printf("Ange startdatum (1 = mandag, 2 - tisdag ... 7 - sondag): ");
    scanf("%d", &startDay);

    printf("Ange mangd dagar: ");
    scanf("%d", &amountOfDays);

    printCalender(startDay, amountOfDays);

    return 0;
}

void printCalender(int startingDay, int amountOfDays){
    
    printf("M  T  O  T  F  L  S\n");

    for (int i = -startingDay; i <= amountOfDays; i++)
    {
        
        if(i > 0){
            printf("%d   ", i);
        }else{
            printf("   ");
        }
        
        if((i + startingDay) % 7 == 0){
           printf("\n");
        }
    }
    


}