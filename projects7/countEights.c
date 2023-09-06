#include <stdio.h>
#define LENGTH 10

int main(){


    int nums[LENGTH] = {0}, nbOfEights = 0;

    //Reads data from user
    for (int i = 0; i < LENGTH; i++)
    {
        printf("Please input a number: ");
        scanf("%d", &nums[i]);
    }
    
    //Finds amount of eights
    for (int i = 0; i < LENGTH; i++)
    {
        while(nums[i] > 0){
            
            if(nums[i] % 10 == 8){
                nbOfEights++;
            }

            nums[i] /= 10;
        }
    }
    

    //Outputs amount of eights
    printf("The amount of eights is: %d", nbOfEights);

    return 0;
}