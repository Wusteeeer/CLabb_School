#include <stdio.h>


void rectangle(int w, int h){

    for (int i = 0; i < h; i++)
    {
        
        for (int j = 0; j < w; j++)
        {

            if((j > 0 && j < w - 1) && (i != 0 && i != h - 1)){
                printf(" ");
            }else{
                printf("*");
            }
            
        }

        printf("\n");
        
    }
    

}


void flowChart(){
    int a = 100;
    int b = 1;

    while( a > b ){

        printf("%d, %d\n", a, b);

        if( a / b > 20 ){
            a /= 2;
        }else{
            
            if( a / 2 > b ){
                b += 2;
            }else{
                b++;
            }

            printf("%d\n", b);
        }

    }

    printf("%d, %d\n", a, b);

    return;
}

int main(){

    /*int h = 0;
    int w = 0;

    printf("Input height: ");
    scanf("%d", &h);
    printf("Input width: ");
    scanf("%d", &w);

    rectangle(w, h);*/

    flowChart();

    printf("Avslutar");

    return 0;
}