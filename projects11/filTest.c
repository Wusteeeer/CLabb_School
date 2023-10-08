#include <stdio.h>
#include <stdlib.h>


int main(){

    FILE *fp;
    fp = fopen("test", "rb");

    float helloWorld = 0;

    if(fp == NULL){
        printf("Could not open file\n");
        return 0;
    }

    // fwrite(&helloWorld, sizeof(helloWorld), 1, fp);
    fread(&helloWorld, sizeof(helloWorld), 1, fp);

    printf("%.2f\n", helloWorld);

    fclose(fp);

    return 0;
}