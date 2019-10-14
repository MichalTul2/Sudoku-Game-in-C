//Michal Tulowiecki

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SHUFFLES 20

int goodBoard[9][9] = {
    {2, 9, 5, 7, 4, 3, 8, 6, 1},
    {4, 3, 1, 8, 6, 5, 9, 2, 7},
    {8, 7, 6, 1, 9, 2, 5, 4, 3},
    {3, 8, 7, 4, 5, 9, 2, 1, 6},
    {6, 1, 2, 3, 8, 7, 4, 9, 5},
    {5, 4, 9, 2, 1, 6, 7, 3, 8},
    {7, 6, 3, 5, 2, 4, 1, 8, 9},
    {9, 2, 8, 6, 7, 1, 3, 5, 4},
    {1, 5, 4, 9, 3, 8, 6, 7, 2}};

int userBoard[9][9] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}};

int hearts = 3;

/*
 * function : isEnd
 * purpose  : coming soon :)
 * input    : coming soon :)
 * output   : coming soon :)
 */

bool isEnd()
{
    int madeCells = 0;
    if (hearts <= 0)
        return true;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            if (userBoard[i][j] == 0)
                return false;

    return true;
}

/*
 * function : printCell
 * purpose  : coming soon :)
 * input    : coming soon :)
 * output   : coming soon :)
 */

char *printCell(column, row)
{
    if (userBoard[column][row] == 0)
        return " ";

    int length = snprintf(NULL, 0, "%d", userBoard[column][row]);
    char *string = malloc(length + 1); //
    snprintf(string, length + 1, "%d", userBoard[column][row]);
    return string;
}

/*
 * function : printMenu
 * purpose  : coming soon :)
 * input    : coming soon :)
 * output   : coming soon :)
 */

void printMenu()
{
    printf("WCISNIJ H ZEBY DOSTAĆ WSKAZOWKE\n");
    printf("WCISNIJ J ZEBY ZGADYWAĆ\n");
    printf("WCISNIJ R ZEBY ZAKONCZYC\n");
}

/*
 * function : printBoard
 * purpose  : coming soon :)
 * input    : coming soon :)
 * output   : coming soon :)
 */

void printBoard()
{
    system("clear");
    printf("ZYCIA:");
    for (int i = 0; i < hearts; i++)
        printf(" <3 ");
    printf("\n| X | 1  2  3 | 4  5  6 | 7  8  9 |\n");
    printf("-----------------------------------\n");
    printf("| 1 | %s  %s  %s | %s  %s  %s | %s  %s  %s |\n",
           printCell(0, 0), printCell(0, 1), printCell(0, 2),
           printCell(0, 3), printCell(0, 4), printCell(0, 5),
           printCell(0, 6), printCell(0, 7), printCell(0, 8));
    printf("| 2 | %s  %s  %s | %s  %s  %s | %s  %s  %s |\n",
           printCell(1, 0), printCell(1, 1), printCell(1, 2),
           printCell(1, 3), printCell(1, 4), printCell(1, 5),
           printCell(1, 6), printCell(1, 7), printCell(1, 8));
    printf("| 3 | %s  %s  %s | %s  %s  %s | %s  %s  %s |\n",
           printCell(2, 0), printCell(2, 1), printCell(2, 2),
           printCell(2, 3), printCell(2, 4), printCell(2, 5),
           printCell(2, 6), printCell(2, 7), printCell(2, 8));
    printf("-----------------------------------\n");
    printf("| 4 | %s  %s  %s | %s  %s  %s | %s  %s  %s |\n",
           printCell(3, 0), printCell(3, 1), printCell(3, 2),
           printCell(3, 3), printCell(3, 4), printCell(3, 5),
           printCell(3, 6), printCell(3, 7), printCell(3, 8));
    printf("| 5 | %s  %s  %s | %s  %s  %s | %s  %s  %s |\n",
           printCell(4, 0), printCell(4, 1), printCell(4, 2),
           printCell(4, 3), printCell(4, 4), printCell(4, 5),
           printCell(4, 6), printCell(4, 7), printCell(5, 8));
    printf("| 6 | %s  %s  %s | %s  %s  %s | %s  %s  %s |\n",
           printCell(5, 0), printCell(5, 1), printCell(5, 2),
           printCell(5, 3), printCell(5, 4), printCell(5, 5),
           printCell(5, 6), printCell(5, 7), printCell(5, 8));
    printf("-----------------------------------\n");
    printf("| 7 | %s  %s  %s | %s  %s  %s | %s  %s  %s |\n",
           printCell(6, 0), printCell(6, 1), printCell(6, 2),
           printCell(6, 3), printCell(6, 4), printCell(6, 5),
           printCell(6, 6), printCell(6, 7), printCell(6, 8));
    printf("| 8 | %s  %s  %s | %s  %s  %s | %s  %s  %s |\n",
           printCell(7, 0), printCell(7, 1), printCell(7, 2),
           printCell(7, 3), printCell(7, 4), printCell(7, 5),
           printCell(7, 6), printCell(7, 7), printCell(7, 8));
    printf("| 9 | %s  %s  %s | %s  %s  %s | %s  %s  %s |\n",
           printCell(8, 0), printCell(8, 1), printCell(8, 2),
           printCell(8, 3), printCell(8, 4), printCell(8, 5),
           printCell(8, 6), printCell(8, 7), printCell(8, 8));
    printf("-----------------------------------\n");
}

/*
 * function : endGame
 * purpose  : coming soon :)
 * input    : coming soon :)
 * output   : coming soon :)
 */

void endGame()
{
    printBoard();
    printf("Brawo, udalo Ci sie!");
}

/*
 * function : giveHint
 * purpose  : coming soon :)
 * input    : coming soon :)
 * output   : coming soon :)
 */

void giveHint()
{
    int rndRow = rand() % 9;
    int rndCol = rand() % 9;
    if (userBoard[rndRow][rndCol] != 0)
    {
        giveHint();
        return;
    }
    else
        userBoard[rndRow][rndCol] = goodBoard[rndRow][rndCol];
    printBoard();
    printMenu();
}

/*
 * function : guess
 * purpose  : coming soon :)
 * input    : coming soon :)
 * output   : coming soon :)
 */

void guess()
{
    int column, row, value;
    printBoard();
    printf("A WIEC ZGADUJ\n");
    printf("[WIERSZ] [KOLUMNA] [WARTOSC]:\n");
    scanf("%d %d %d", &row, &column, &value);
    row--;
    column--;
    if (userBoard[row][column] != 0)
    {
        printBoard();
        printf("TE POLE JEST JUZ ODKRYTE GLUPTASIE\n");
        printMenu();
        return;
    }
    if (goodBoard[row][column] == value)
    {
        userBoard[row][column] = goodBoard[row][column];
        printBoard();
        printf("GOOD GAME!\nGRAJ DALEJ!\n");
        printMenu();
    }
    else
    {
        hearts--;
        printBoard();
        printf("NIE UDALO SIE :(\nZOSTALO CI %d ZYCIA\n", hearts);
        printMenu();
    }
}

/*
 * function : nextTurn
 * purpose  : coming soon :)
 * input    : coming soon :)
 * output   : coming soon :)
 */

void nextTurn()
{
    int keyPress;
    keyPress = getchar();
    putchar(keyPress);
    switch (keyPress)
    {
    case 'h':
    case 'H':
        giveHint();
        break;

    case 'j':
    case 'J':
        guess();
        break;

    case 'r':
    case 'R':
        exit(EXIT_SUCCESS);
        break;
    }
}

/*
 * function : startGame
 * purpose  : coming soon :)
 * input    : coming soon :)
 * output   : coming soon :)
 */

void startGame()
{
    system("clear");
    int hardnessLevel = 0;
    int cellStart = 0;
    printf("WYBIERZ POZIOM TRUDNOSCI\n");
    printf("1. LATWY\n");
    printf("2. SREDNI\n");
    printf("3. TRUDNY\n");
    scanf("%d", &hardnessLevel);
    switch (hardnessLevel)
    {
    case 1:
        cellStart = 50;
        break;
    case 2:
        cellStart = 30;
        break;
    case 3:
        cellStart = 15;
        break;
    }

    for (int i = 0; i < cellStart; i++)
        giveHint();
}

/*
 * function : swap
 * purpose  : coming soon :)
 * input    : coming soon :)
 * output   : coming soon :)
 */

void swap(int num1, int num2, bool ifColumn)
{
    int temp = 0;
    for (int i = 0; i < 9; i++)
    {
        if (ifColumn == 1)
        {
            temp = goodBoard[num1][i];
            goodBoard[num1][i] = goodBoard[num2][i];
            goodBoard[num2][i] = temp;
        }
        else
        {
            temp = goodBoard[i][num1];
            goodBoard[i][num1] = goodBoard[i][num2];
            goodBoard[i][num2] = temp;
        }
    }
}

/*
 * function : generateBoard
 * purpose  : coming soon :)
 * input    : coming soon :)
 * output   : coming soon :)
 */

void generateBoard()
{
    srand(time(NULL));
    for (int i = 0; i < SHUFFLES; i++)
    {
        swap(rand() % 9, rand() % 9, false);
        swap(rand() % 9, rand() % 9, true);
    }
}

/*
 * function : main
 * purpose  : coming soon :)
 * input    : coming soon :)
 * output   : coming soon :)
 */

int main()
{
    generateBoard();
    startGame();
    do
    {
        nextTurn();
        isEnd();
    } while (!isEnd());
    endGame();

    return 0;
}