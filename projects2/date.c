#include <stdio.h>


void dateOut(int year, int month, int day){

 
    printf("You entered the date: %d, %.2d, %.2d", year, month, day);
}

int main(){

    int day = 0, month = 0, year = 0;
    printf("Input a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);
    dateOut(year, month, day);
    return 0;
}