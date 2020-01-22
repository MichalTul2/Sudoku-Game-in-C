#include <stdio.h>
#include <time.h>

#define SHUFFLES 20


void swapColumn(int array[][9], int num1, int num2)
{

    unsigned short temporary = 0;
    for (int i = 0; i < 9; i++)
    {
            temporary = array[num1][i];
            array[num1][i] = array[num2][i];
            array[num2][i] = temporary;
    }
    return;
}

void swapRow(int array[][9], int num1, int num2)
{
    unsigned short temporary = 0;
    for (int i = 0; i < 9; i++)
    {
            temporary = array[i][num1];
            array[i][num1] = array[i][num2];
            array[i][num2] = temporary;
    }
    return;
}

void showRandomCell(int fromArray[][9], int **toArray)
{

    int rndRow, rndCol;
    do {
    rndRow = rand() % 9;
    rndCol = rand() % 9;
    } while (toArray[rndRow][rndCol] != 0);

    toArray[rndRow][rndCol] = fromArray[rndRow][rndCol];

    return;

}


void generateBoard(int **userBoard, int goodBoard[][9], int level)
{
    srand(time(NULL));
    unsigned short n, m;
    n = (rand() % 3) * 3;
    m = rand() % 1;
    for (int i = 0; i < SHUFFLES ; i++)
    {
        switch (rand() % 6)
        {
        case 0:
            swapRow(goodBoard, n + 0, m ? n + 1 : n + 2);
            break;
        case 1:
            swapRow(goodBoard, n + 1, m ? n + 0 : n + 2);
            break;
        case 2:
            swapRow(goodBoard, n + 2, m ? n + 0 : n + 1);
            break;
        case 3:
            swapColumn(goodBoard, n + 0, m ? n + 1 : n + 2);
            break;
        case 4:
            swapColumn(goodBoard, n + 1, m ? n + 0 : n + 2);
            break;
        case 5:
            swapColumn(goodBoard, n + 2, m ? n + 0 : n + 1);
            break;
        }
    }

    for (int i = 0; i < level; i++)
        showRandomCell(goodBoard, userBoard);

    return;
}

void allocateArray( int ***array, int rows, int columns) //pointer to pointer of pointers pogJUMP
{
    if (((*array) = (int **)calloc(rows, sizeof(int *))) != NULL)
    {
        for (int i = 0; i < 9; i++)
            *((*array) + i) = (int *)calloc(columns, sizeof(int));
    }
}

void deallocateArray(int ***array, int columns){
    for (int i=0; i < columns; i++)
        free(*((*array)+i));
    free(*array);
}