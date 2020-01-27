#include <stdio.h>
#include <stdlib.h>

#include "struct.h"

/*
* function  : startMenu
* purpose   : the function checks whether all fields on the board are uncovered or whether the user still has life
* input     : user array, game struct
* output    : 0 if it's not over, 1 if it's end
*/

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

/*
* function  : printHeader
* purpose   : the function prints a header containing game statistics
* input     : game struct
* output    : void
*/

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

/*
* function  : printBoard
* purpose   : the function prints user board in a nice way
* input     : user game array, game struct
* output    : void
*/

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

/*
* function  : guess
* purpose   : function that gives the user the ability to guess the value
* input     : userBoard, referenceBoard, game struct
* output    : void
*/

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
        if (system("cls || clear") == -1) {
            perror("Error. System method");
            exit(1);
        }
        printBoard(userBoard, game);
        printf("come on, you can see that\n");
        return;
    }
    else if (referenceBoard[row][column] == value)
    {
        game->turn++;
        (*userBoard)[row][column] = referenceBoard[row][column];
        if (system("cls || clear") == -1) {
            perror("Error. System method");
            exit(1);
        }
        printBoard(userBoard, game);
        printf("good game!\n\n");
    }
    else
    {
        game->turn++;
        game->hearts--;
        if (system("cls || clear") == -1) {
            perror("Error. System method");
            exit(1);
        }
        printBoard(userBoard, game);
        printf("ups :(\n");
    }
}

/*
* function  : takeHint
* purpose   : the function shows one value to the user
* input     : userBoard, referenceBoard, game struct
* output    : void
*/

void takeHint(int ***userBoard, int referenceBoard[][9], Game_Type *game)
{
    if(game->hints < 1)
    {
        if (system("cls || clear") == -1) {
            perror("Error. System method");
            exit(1);
        }
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
    if (system("cls || clear") == -1) {
            perror("Error. System method");
            exit(1);
        }
    printBoard(userBoard, game);
    return;

}

/*
* function  : startGame
* purpose   : main function of the game
* input     : userBoard, referenceBoard, game struct
* output    : void
*/

void startGame (int ***userBoard, int referenceBoard[][9], Game_Type *game)
{

    if (system("cls || clear") == -1) {
            perror("Error. System method");
            exit(1);
        }
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