#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SHUFFLES 20 /* how many times we shuffle goodBoard */

struct Game
{
    /* game variables */
    int hearts;
    int hints;
    int turn;  /* counter */
    int level; /* defines how hard the game is */
} game = {3, 10, 0};

int goodBoard[9][9] = {/* template, right solved sudoku board */
                       {2, 9, 5, 7, 4, 3, 8, 6, 1},
                       {4, 3, 1, 8, 6, 5, 9, 2, 7},
                       {8, 7, 6, 1, 9, 2, 5, 4, 3},
                       {3, 8, 7, 4, 5, 9, 2, 1, 6},
                       {6, 1, 2, 3, 8, 7, 4, 9, 5},
                       {5, 4, 9, 2, 1, 6, 7, 3, 8},
                       {7, 6, 3, 5, 2, 4, 1, 8, 9},
                       {9, 2, 8, 6, 7, 1, 3, 5, 4},
                       {1, 5, 4, 9, 3, 8, 6, 7, 2}};

int userBoard[9][9] = {/* the board we are working on */
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0}};

/*
 * function : isEnd
 * purpose  : check if its end of game depends on game stats
 * input    : no input
 * output   : return false if there is "unshown" cell, return true if user has no more hearts or there is no cell left
 */

bool isEnd()
{
    if (game.hearts <= 0)
    {
        printf("NO MORE LIVES :(\n");
        return true;
    }
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (userBoard[i][j] == 0)
                return false;
    printf("YOU WIN!\n");
    return true;
}

/*
 * function : printCell
 * purpose  : changes userBoard[column][row] intiger value to a char, if value != 0 function prints value in terminal
 * input    : int column, int row
 * output   : " " when userBoard[column][row] = 0, and char which contains userBoard   [column][row]integer value
 */

char *printCell(int column, int row)
{
    if (userBoard[column][row] == 0)
        return " ";
    int length = snprintf(NULL, 0, "%d", userBoard[column][row]);
    char *string = malloc(length + 1);
    if (string == NULL)
        exit(EXIT_FAILURE); /* handling malloc failure */
    snprintf(string, length + 1, "%d", userBoard[column][row]);
    return string;
}

/*
 * function : printBoard
 * purpose  : prints userBoard array using printCell function in terminal
 * input    : void
 * output   : nothing
 */

void printBoard(void)
{
    system("clear || cls");
    /* printing game stats */
    switch (game.hearts)
    {
    case 3:
        printf("<3 <3 <3    TURN : %d     HINTS: %d \n", game.turn, game.hints);
        break;
    case 2:
        printf("<3 <3       TURN : %d     HINTS: %d \n", game.turn, game.hints);
        break;
    case 1:
        printf("<3          TURN : %d     HINTS: %d \n", game.turn, game.hints);
        break;
    }
    /* printing game board */
    printf("-----------------------------------\n");
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
 * function : guess
 * purpose  : allows user to take a guess, takes user input from keyboard and checks if the guess was right
 * input    : void
 * output   : nothing
 */

void guess(void)
{
    /* taking input  about guess */
    int column, row, value;
    printf("COLUMN: ");
    scanf("%d", &column);
    printf("ROW: ");
    scanf("%d", &row);
    printf("VALUE: ");
    scanf("%d", &value);
    column--;
    row--;
    /* check if input is correct */
    if (column * row * value < 0 || column > 9 || row > 9 || value > 9)
    {
        printf("INVALID INPUT\n");
        return;
    }
    if (userBoard[row][column] != 0)
    {
        game.turn++;
        printBoard();
        printf("DONT LIE! YOU CAN SEE THAT\n");

        return;
    }
    else if (goodBoard[row][column] == value)
    {
        game.turn++;
        userBoard[row][column] = goodBoard[row][column];
        printBoard();
        printf("GOOD GAME!\n\n");
    }
    else
    {
        game.turn++;
        game.hearts--;
        printBoard();
        printf("TRY AGAIN\n");
    }
}

/*
 * function : showRandomCell
 * purpose  : changes "random" userBoard cell from 0 to right value
 * input    : void
 * output   : void
 */

void showRandomCell(void)
{
    int rndRow = rand() % 9;
    int rndCol = rand() % 9;
    if (userBoard[rndRow][rndCol] != 0)
    {
        /* if cell is already shown repeat showRandomCell*/
        showRandomCell();
        return;
    }
    else
        userBoard[rndRow][rndCol] = goodBoard[rndRow][rndCol];
    return;
}

/*
 * function : loadMenu
 * purpose  : prints user menu, event listener for a keyboard click to run a function
 * input    : void
 * output   : nothing
 */

void loadMenu(void)
{
    int choice;
    printf("Menu\n");
    printf("1. HINT\n");
    printf("2. GUESS\n");
    printf("3. EXIT\n");
    printf("YOUR CHOICE:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        if (game.hints > 0)
        {
            showRandomCell();
            game.hints--;
            game.turn++;
            printBoard();
        }
        else
        {
            printBoard();
            printf("HINTS: 0\n");
        }
        break;
    case 2:
        guess();
        break;
    case 3:
        printf("See you soon :)\n");
        exit(EXIT_SUCCESS);
        break;
    default:
        /* if input is correct */
        printBoard();
        printf("Invalid input!\n");
        break;
    }
    return;
}

/*
 * function : chooseLevel
 * purpose  : event listener for keyboard click, sets game stats like dificulty level and number of hints
 * input    : void
 * output   : nothing
 */

void chooseLevel(void)
{
    system("clear || cls");
    int choice;
    printf("Choose your difficulty level\n");
    printf("1. EASY\n");
    printf("2. MEDIUM\n");
    printf("3. HARD\n");
    printf("YOUR CHOICE:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        game.level = 57;
        game.hints = 10;
        break;
    case 2:
        game.level = 39;
        game.hints = 6;
        break;
    case 3:
        game.level = 24;
        game.hints = 3;
        break;
    default:
        /* if input is correct */
        chooseLevel();
        break;
    }
    for (int i = 0; i < game.level; i++)
        showRandomCell();
    printBoard();
    return;
}

/*
 * function : swap
 * purpose  : the function replaces column (ifColumn = true) or row from num1 to num2
 * input    : int num1, int num2, bool ifColumn
 * output   : nothing
 */

void swap(int num1, int num2, bool ifColumn)
{

    int temporary = 0;
    for (int i = 0; i < 9; i++)
    {
        if (ifColumn == 1)
        {
            temporary = goodBoard[num1][i];
            goodBoard[num1][i] = goodBoard[num2][i];
            goodBoard[num2][i] = temporary;
        }
        else
        {
            temporary = goodBoard[i][num1];
            goodBoard[i][num1] = goodBoard[i][num2];
            goodBoard[i][num2] = temporary;
        }
    }
    return;
}

/*
 * function : generateBoard
 * purpose  : algorithm which edits goodBoard array to give at every game diffrent sudoku board
 * input    : void
 * output   : nothing
 */

void generateBoard(void)
{
    srand(time(NULL));
    int n, m;
    n = (rand() % 3) * 3;
    m = rand() % 1;
    for (int i = 0; i < SHUFFLES; i++)
    {
        switch (rand() % 6)
        {
        case 0:
            swap(n + 0, m ? n + 1 : n + 2, false);
            break;
        case 1:
            swap(n + 1, m ? n + 0 : n + 2, false);
            break;
        case 2:
            swap(n + 2, m ? n + 0 : n + 1, false);
            break;
        case 3:
            swap(n + 0, m ? n + 1 : n + 2, true);
            break;
        case 4:
            swap(n + 1, m ? n + 0 : n + 2, true);
            break;
        case 5:
            swap(n + 2, m ? n + 0 : n + 1, true);
            break;
        }
    }
}

/*
 * function : boardFromFile
 * purpose  : check if there is Board.txt, reads numbers from a text file into an array
 * input    : void
 * output   : nothing
 */

void boardFromFile(void)
{
    FILE *f;
    if ((f = fopen("Board.txt", "r")) == NULL)
    {
        printf("FILE ERROR");
        exit(1);
    }
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (fscanf(f, "%d", &goodBoard[i][j]) != 1)
                exit(1);

    fclose(f);
}

/*
 * function : picBoardSource
 * purpose  : allows user to choose board destination beetwen build in gooodBoard array or board from file
 * input    : void
 * output   : nothing
 */

void pickBoardSource(void)
{
    int choice;
    system("clear || cls");
    printf("MENU\n");
    printf("1.BOARD GENERATOR\n");
    printf("2.BOARD FROM FILE\n");
    printf("YOUR CHOICE:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        generateBoard();
        return;
    case 2:
        boardFromFile();
        return;
    default:
        /* if input is correct */
        pickBoardSource();
        break;
    }
}

int main()
{
    system("clear || cls");
    pickBoardSource();
    chooseLevel();
    do
        loadMenu();
    while (!isEnd());
    return 0;
}