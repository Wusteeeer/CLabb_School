#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct position{

    int x, y;

}Pos;

typedef struct field{

    char layout[7][13];
    
    Pos playerPos, footBallPos;    


}Field;

Field createField();
void printField(Field f);
void movePlayer(Field *f, Pos dir);
void moveBall(Field *f, Pos dir);

int main(){

    Field f = createField();

    printField(f);

    bool goal = false;

    char wasd = ' ';
    Pos dir = {0, 0};

    while(!goal)
    {




        printf("wasd? ");
        scanf("%c%*c", &wasd);

        switch(wasd){
            case 'w':
                dir.y = -1;
            break;
            case 'a':
                dir.x = -1;
            break;
            case 's':
                dir.y = 1;
            break;
            case 'd':
                dir.x = 1;
            break;
        }

        movePlayer(&f, dir);

        printField(f);
        dir.y = 0;
        dir.x = 0;

        if(f.footBallPos.x >= 5 &&  f.footBallPos.x <= 7 && f.footBallPos.y == 5){
            printf("GOAL!!!\n");
            goal = true;
        }

    }


    return 0;
}

void movePlayer(Field *f, Pos dir){

    char nextChar = f->layout[f->playerPos.y + dir.y][f->playerPos.x + dir.x];
    if(nextChar == 'X')
    {
        return;
    }

    
    if(f->layout[f->footBallPos.y + dir.y][f->footBallPos.x + dir.x] == 'X' && nextChar == 'o'){
        return;
    }

    if(nextChar == 'o')
    {

        moveBall(f, dir);

    }


    f->layout[f->playerPos.y][f->playerPos.x] = ' ';

    f->playerPos.x += dir.x;
    f->playerPos.y += dir.y;

    f->layout[f->playerPos.y][f->playerPos.x] = 'k';

}

void moveBall(Field *f, Pos dir){

    if(f->layout[f->footBallPos.y + dir.y][f->footBallPos.x + dir.x] == 'X')
    {
        return;
    }

    f->layout[f->footBallPos.y][f->footBallPos.x] = ' ';

    f->footBallPos.x += dir.x;
    f->footBallPos.y += dir.y;

    f->layout[f->footBallPos.y][f->footBallPos.x] = 'o';

    
    

}


Field createField(){


    Field f;
    for (int i = 0; i < 7; i++)
    {

        for (int j = 0; j < 13; j++)
        {

            if(i == 0 || i == 6 || j == 0 || j == 12 || (i == 5 && j == 4) || (i == 5 && j == 8))
            {

                f.layout[i][j] = 'X';

            }
            else if(j == 6 && i == 1)
            {

                f.layout[i][j] = 'k';
                f.playerPos.x = j;
                f.playerPos.y = i;

                printf("%d, %d\n", f.playerPos.x, f.playerPos.y);

            }
            else if(j == 6 && i == 3)
            {

                f.layout[i][j] = 'o';
                f.footBallPos.x = j;
                f.footBallPos.y = i;

            }
            else
            {
                f.layout[i][j] = ' ';
            }

        }

        
    }
    

    return f;


}


void printField(Field f){


    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            printf("%c", f.layout[i][j]);
        }

        printf("\n");
        
    }
    

}