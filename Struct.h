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

void saveGameToFile (int ***userBoard, int referenceBoard[][9], Game_Type *game);
void printHeader( Game_Type *game);

#endif