#include <stdio.h>


void boat(){
    printf("   *\n   **\n  ****\n ******\n*  *    *\n *******\n");
}

void weekday(int n){
    

    char motsvarar[] = "Det motsvarar";

    switch(n){
        case 0:
            printf("Ogiltigt tal");
        break;
        case 1:
            printf("%s Måndag", motsvarar);
        break;
        case 2:
            printf("%s Tisdag", motsvarar);
        break;
        case 3:
            printf("%s Onsdag", motsvarar);
        break;
        case 4:
            printf("%s Torsdag", motsvarar);
        break;
        case 5:
            printf("%s Fredag", motsvarar);
        break;
        case 6:
            printf("%s Lördag", motsvarar);
        break;
        case 7:
            printf("%s Söndag", motsvarar);
        break;
    }

    printf("\n");
}

void whileLoop(int max){
    
    while(max > 0){

        if( max > 1 ){
            printf("%d, ", max);
            
        }else{
            printf("%d ", max);
        }

        max--;

    }

    printf("\n");

}

void forLoop(int max){
    
    for (int i = max; i > 0; i--)
    {

        if( i > 1 ){
            printf("%d, ", i);
            continue;
        }

        printf("%d ", i);
    }

    printf("\n");

}

void factorial(int n){


    if(n < 0){
        printf("Talet ska vara positivt\n");
        return;
    }
    int fact = 1;

    for (int i = n; i > 0; i--)
    {
        fact *= i;
    }
    
    printf("%d! = %d\n", n, fact);

    return;
}

int main() {

# pragma region done

    //boat();



    /*int n = 0;

    printf("Ange Veckodag: ");
    scanf("%d", &n);

    weekday(n);*/




    /*printf("Ange maxtal: ");

    int max = 0;
    
    scanf("%d", &max);

    printf("\n");

    forLoop(max);
    
    return 0;*/





    int fact = 1;

    do{

            
        printf("Ange ett tal: ");

        scanf("%d", &fact);

        if(fact != 0)
            factorial(fact);

    }while(fact != 0);



#pragma endregion


    printf("Avslutar");
}

