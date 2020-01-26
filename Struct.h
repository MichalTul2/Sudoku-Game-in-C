#ifndef STRUCT_H
#define STRUCT_H

typedef struct Game
{
    /* game variables */
    unsigned short hearts;
    unsigned short turn;
    unsigned short hints;
    unsigned short level;  /* counter */

} Game_Type;

int startMenu();
int levelMenu();
void printLogo( FILE *fptr);
void arrowHere(int realPosition, int arrowPosition);

void allocateArray( int ***array, int rows, int columns);
void deallocateArray(int ***array, int columns);
void generateBoard(int **userBoard, int goodBoard[][9], Game_Type *game);

void loadGameFromFile (int ***array, int referenceBoard[][9], Game_Type *game);
void saveGameToFile (int ***userBoard, int referenceBoard[][9], Game_Type *game);


void startGame (int ***userBoard, int referenceBoard[][9], Game_Type *game);
void printHeader( Game_Type *game);

#endif