#include <stdio.h>

void priceCalc(int amount){

    float basePrice = 9.9f;
    int sale = 0;
    
    if(amount > 50)
    {
        sale = 10;
    }
    else if(amount > 10)
    {
        sale = 5;
    }


    basePrice -= ((float)basePrice * ((float)sale / (float)100));

    printf("You need to pay: %.2f\n", basePrice * amount);
}

int main(){


    int true = 1;
    char yesNo;

    do{
        
        int numOfRec = 0;
        printf("Hur manga skivor vill du kopa? ");
        scanf("%d", &numOfRec);
        priceCalc(numOfRec);

        printf("Do you want to make another purchase? (y/n): ");
        //The space is there because the previous scanf saves the enter (\n) and enters it here instead
        scanf(" %c", &yesNo);

        if(yesNo != 'y' && yesNo != 'n' && yesNo != 'N' && yesNo != 'Y'){
            printf("THROWING EXCEPTION: Invalid answer, please input y or n");
            break;
        }

        true = (yesNo == 'y' || yesNo == 'Y') ? 1 : 0;

    }while(true);
  

    return 0;
}