#include <stdio.h>
#include <stdbool.h>

void printTri(int side);

int main(){

    int side;

    while(true){

        printf("Ange sida (2-30)\n");

        scanf("%d", &side);

        if(side < 2 || side > 30){
            printf("Felaktig Sida.\n");
            continue;

        }

        break;


    }

    printTri(side);

    return 0;
}


void printTri(int side){

    int index = 0;
    for (int i = 0; i < side; i++)
    {   


        for (int j = 0; j < side; j++)
        {
            if(i >= side - 1){

                printf("*");
                continue;

            }else if(j == 0)
            {

                printf("*");
                continue;

            }else if(j == index){
                
                printf("*");
                continue;

            }

            printf(" ");

            
        }

        index++;
        
        printf("\n");

    }
    

}