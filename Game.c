#include <stdio.h>

void printBoard(int ***array){
    printf("X |  A  B  C  D  E  F  G  H  I\n");
    printf("--|----------------------------|--\n");
    for (int i = 0; i < 9; i++)
    {
        printf("%d |", i);
        for (int j = 0; j < 9; j++)
        {
            if ( (*array)[i][j] != 0)
            {
                printf("%3d", (*array)[i][j]);
            }
            else printf("   ");
        }
        printf(" |\n");
    }
    printf("--|----------------------------|--\n");
}



void game (int ***userBoard, int game[][9])
{
    while (isEnd)
    {

    }
}