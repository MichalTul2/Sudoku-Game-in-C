#include <stdio.h>
#include "Struct.h"


int isEnd(int ***array, Game_Type *game)
{
    if(game->hearts<1){
        printf("no more lives </3");
        return 1;
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if ( (*array)[i][j] == 0)
            {
                return 0;
            }
        }
    }

    return 1;
}

void printHeader( Game_Type *game){
    switch (game->hearts)
    {
    case 3:
        printf("<3 <3 <3    TURNS : %d     HINTS: %d \n", game->turn, game->hints);
        break;
    case 2:
        printf("<3 <3       TURNS : %d     HINTS: %d \n", game->turn, game->hints);
        break;
    case 1:
        printf("<3          TURNS : %d     HINTS: %d \n", game->turn, game->hints);
        break;
    }
}

void printBoard(int ***array, Game_Type *game){
    printHeader(game);
    printf("X |  1  2  3  4  5  6  7  8  9\n");
    printf("--|----------------------------|--\n");
    for (int i = 0; i < 9; i++)
    {
        printf("%d |", i + 1);
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

void guess(int ***userBoard, int referenceBoard[][9], Game_Type *game)
{
    /* taking input  about guess */
    unsigned short column, row, value;
    printf("column: "); scanf("%hd", &column);
    printf("row: "); scanf("%hu", &row);
    printf("value: "); scanf("%hu", &value);
    --column;
    --row;
    /* check if input is correct */
    if ((*userBoard)[row][column] != 0)
    {
        game->turn++;
        system("cls || clear");
        printBoard(userBoard, game);
        printf("come on, you can see that\n");
        return;
    }
    else if (referenceBoard[row][column] == value)
    {
        game->turn++;
        (*userBoard)[row][column] = referenceBoard[row][column];
        system("cls || clear");
        printBoard(userBoard, game);
        printf("good game!\n\n");
    }
    else
    {
        game->turn++;
        game->hearts--;
        system("cls || clear");
        printBoard(userBoard, game);
        printf("ups :(\n");
    }
}

void takeHint(int ***userBoard, int referenceBoard[][9], Game_Type *game)
{
    if(game->hints < 1)
    {
        system("cls || clear");
        printBoard(userBoard, game);
        printf("no more hints\n");
        return;
    }
    game->hints--;
    game->turn++;
    int rndRow, rndCol;
    do {
    rndRow = rand() % 9;
    rndCol = rand() % 9;
    } while ((*userBoard)[rndRow][rndCol] != 0);

    (*userBoard)[rndRow][rndCol] = referenceBoard[rndRow][rndCol];
    system("cls || clear");
    printBoard(userBoard, game);
    return;

}



void startGame (int ***userBoard, int referenceBoard[][9], Game_Type *game)
{

    system("cls || clear");
    int option=-1;
    printBoard(userBoard, game);

    while(option!=0)
    {
        if(isEnd(userBoard, game)) return;
        printf("what you gonna do?\n");
        printf("1.  let me take a guess\n");
        printf("2.  give me a hint\n");
        printf("3.  im done. save and exit\n");
        printf("0.  exit\n\n");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                guess(userBoard, referenceBoard, game);
                break;
            case 2:
                takeHint(userBoard, referenceBoard, game);
                break;
            case 3:
                saveGameToFile(userBoard, referenceBoard, game);
                return;
            case 0:
                return;
        }
    }

}