#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void DeciToBin(int deci){
    
    //TODO: Something happenes between binary convertion and adding it to the padding array, 
    //that somehow messes with the bin array debug more and figure it out, it probably has to do with saving over
    //memory addresses or something

    //Initializes pointers by allocating some memory to it (to be precise, 4 bits or the size of an int)
    int *padding = (int*)malloc(sizeof(int));
    int *bin = (int*)malloc(sizeof(int));

    #pragma region binary
    
    int binIter = -1;

    //Checks if allocation has gone wrong or not
    if(bin == NULL){
        return;
    }

    while( deci > 0 ){

        //increases iter by 1: 0, 1, 2, 3
        binIter++;

        //checks if deci is a even number, if it is then add 0 to bin if it isn't then add 1 to bin
        bin[binIter] = deci % 2 == 0 ? 0 : 1;
        //printf("%d", bin[binIter]);
        //reallocates some memory to bin to make sure it gets bigger with each iteration
        bin = (int*)realloc(bin, binIter + 1);

        //divides deci by 2
        deci /= 2;
    }
    #pragma endregion

    #pragma region padding

    //Checks if allocation has gone wrong or not
    if(padding == NULL){
        return;
    }

    //Formula: abs((binIter + 1) - ceil((binIter + 1) / 8) * 8), will get the distance to the closest product of 8 from binIter
    int ceilIter = ceil((float)(binIter + 1) / (float)8);
    int additionalZeros = abs((binIter + 1) - (ceilIter * 8));

    int paddingIter = -1;
    
    //The same idea as bin
    while(additionalZeros > 0){

        paddingIter++;

        padding[paddingIter] = 0;

        padding = (int*)realloc(padding, paddingIter + 1);
        additionalZeros--;
    }
    #pragma endregion
    
    printf("\n");
    //Start by looping through padding to add that at the beginning
    while(binIter >= 0){



        paddingIter++;
        padding[paddingIter] = bin[binIter];
        printf("%d\n", padding[paddingIter]);


        padding = (int*)realloc(padding, paddingIter);

        binIter--;

    }


    /*for (int i = 0; i <= paddingIter; i++)
    {
        printf("%d", padding[i]);

    }*/
    




   
    

}
int main(){

    DeciToBin(300);
    return 0;
}