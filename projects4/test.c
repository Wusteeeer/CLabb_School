#include <stdio.h>

int main(){

    char ch='a',ch_tmp;
    while(ch!='P')
    {
        printf("Ange bokstav:");
        scanf("%c",&ch);

        //tmp is used because when reading in ch and pressing enter \n gets read the next time
        //which would mean that it will immidietly print out a space.
        scanf("%c",&ch_tmp);
        if('a' <= ch && ch <= 'z')
        {
            ch = ch - 'a' + 'A';
        }

        printf("%c\n",ch);
    }
    return 0;
}