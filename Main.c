#include <stdio.h>
#include <stdlib.h>

#include "Menu.c"
#include "Board.c"
#include "Game.c"


#define CONTINUE 0
#define NEW_GAME 1


int main() {
    int level = 0;
    int goodBoard[9][9] = {/* template, right solved sudoku board */
                       {2, 9, 5, 7, 4, 3, 8, 6, 1},
                       {4, 3, 1, 8, 6, 5, 9, 2, 7},
                       {8, 7, 6, 1, 9, 2, 5, 4, 3},
                       {3, 8, 7, 4, 5, 9, 2, 1, 6},
                       {6, 1, 2, 3, 8, 7, 4, 9, 5},
                       {5, 4, 9, 2, 1, 6, 7, 3, 8},
                       {7, 6, 3, 5, 2, 4, 1, 8, 9},
                       {9, 2, 8, 6, 7, 1, 3, 5, 4},
                       {1, 5, 4, 9, 3, 8, 6, 7, 2}
    };

    int **userBoard;
    allocateArray(&userBoard, 9, 9);


    switch (startMenu())
    {
        case CONTINUE:
        printf("");
        return 0;
        break;

        case NEW_GAME:
        level = levelMenu();
        generateBoard(userBoard, goodBoard, level);
        game(&userBoard, goodBoard);
        break;
    }

    //memory deallocation
    deallocateArray(&userBoard, 9);

    return 0;
}


