#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int* reverse(int arr[], int size){

    int iter = 0;

    int temp[size];

    //Adds the last element of arr to the first element of temp
    for (int i = size - 1; i >= 0; i--)
    {

        temp[iter] = arr[i];

        iter++;
    }
    
    //Assigns all values of temp to arr
    for (int i = 0; i < size; i++)
    {
        arr[i] = temp[i];
    }
    
    return arr;

}

void NameAndAge(){

    char name[20];

    int age;

    //Stores inputted name at memory address
    printf("Input name: \n");
    scanf("%20s", &name);

    //Stores inputted age at memory address
    printf("Input Age: \n");
    scanf("%d", &age);

    //Prints inputted name and age as a string and decimal integer
    printf("Entered Name: %s\n", name);
    printf("Entered Age: %d\n", age);
}

void HelloWorld(){
    printf("Hello World");
}

static int *binary = NULL;

int* decimalToBinary(int deci, int isSigned){
    

    //Shows how many iterations the recursion has gone thru
    static int iter = 1;


    //Returns 0 if deci is even and 1 if it isn't
    int carry = deci % 2 == 0 ? 0 : 1;  

    //If binary is empty
    if( binary == NULL ){

        //Allocates some memory when it is empty
        binary = (int*)calloc(iter, sizeof(int));

    }else{

        //Reallocates memory if binary isn't empty
        binary = (int*)realloc(binary, iter);
    }

   
    //Fail safe if the computer couldn't allocate enough or any memory
    if( binary == NULL ){

        printf("Memory could not be allocated\n");
        exit(0);

    }else{

        printf("Memory successfully allocated\n");

    }

    //As long as the number is above zero we continue recursion
    if( deci > 0 ){

        //Sets current element to the carry
        *(binary + iter - 1) = carry;

        iter++;

        //Recursive method
        return decimalToBinary( deci / 2, isSigned );  

   
    }

    int additionalZero = 1;
    static int startingLength = 0;
    binary = reverse(binary, iter - 1);

    if( isSigned == 1 ){


        startingLength = iter;

        printf("Size of iter is: %d\n", iter);

        /*if( iter - 1 < 8 ){

            additionalZero = 8 - (iter - 1);

        }else{

            additionalZero = iter % 8;

        }*/

        printf("Additional zero is: %d\n", additionalZero);

        //TODO: iter needs to be increased to the correct multiple of 8
        iter += iter - 1 < 8 ? ((8 - (iter - 1))) : ((iter - 1) % 8); 

        printf("Size of binary is: %d\n", iter);

        //Reallocates the needed memory
        binary = (int*)realloc(binary, iter);

        for (int i = 0; i < additionalZero + startingLength; i++)
        {

            binary[i + startingLength] = 0;
            printf("%d, %d\n", binary[i], additionalZero + startingLength);

            //binary[i] = 0;

            //printf("Added 0 to position: %d, And the value: %d\n", i, binary[i]);
        }


    }

   


    printf("Your binary number is:\n");

    for (int i = 0; i < iter - 1; i++)
    {
        printf("%d\n", binary[i]);
    }
    
    
    printf("\n");
    
    return binary;

    //Empties the binary pointer array so that it doesn't just sit around gathering dust and making performance worse
    free( binary );
    
    
}

int main()
{

    //NameAndAge();

    //HelloWorld();

    int* bin = decimalToBinary( 2, 1 );

    //https://www.scaler.com/topics/length-of-an-array-in-c/
    /*int bin_length = (*(&bin + 1) - bin) * -1;
    
    for (int i = 0; i < bin_length - 1; i++)
    {
        printf("%d", bin[i]);
    }*/

    printf("\n");
    

    return 0;

}


