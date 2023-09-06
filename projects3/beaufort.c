#include <stdio.h>

int main(){

    char *descArr[6] = {"Calm", "Light air", "Breeze", "Gale", "Storm", "Hurricane"};

    int speed = 0;
    printf("Enter wind speed (knots): ");
    scanf("%d", &speed);

    if(speed < 1)
    {
        printf("Description of weather: %s", descArr[0]);

    }else if(speed >= 1 && speed <= 3)
    {
        printf("Description of weather: %s", descArr[1]);

    }else if(speed >= 4 && speed <= 27)
    {
        printf("Description of weather: %s", descArr[2]);

    }else if(speed >= 28 && speed <= 47)
    {
        printf("Description of weather: %s", descArr[3]);

    }else if(speed >= 48 && speed <= 63)
    {
        printf("Description of weather: %s", descArr[4]);

    }else if(speed > 63)
    {
        printf("Description of weather: %s", descArr[5]);

    }

    return 0;
}