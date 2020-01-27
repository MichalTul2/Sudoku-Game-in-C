#include <stdio.h>
#include <stdlib.h>

#include "struct.h"

/*
* function  : numOfFileLines
* purpose   : returns the number of "\n" in the opened text file
* input     : pointer to opened text file
* output    : number of lines
*/

int numOfFileLines( FILE *fileName){
    int counter = 0;
    int character;
    for ( ;; ){
        character = fgetc(fileName);
        if( character == EOF )
            break;
        if (character == '\n')
            ++counter;
    }
    return counter;

}

/*
* function  : loadGameFromFile
* purpose   : loads a game save selected by the user from Board.txt and Board.bin
* input     : user game board, well-filled pattern, game struct
* output    : void
*/

void loadGameFromFile (int ***array, int referenceBoard[][9], Game_Type *game){
    static const char filename[] = "Board.txt";
    static const char binaryFileName[] = "Binary.bin";
    FILE *file = fopen ( filename, "r" );
    FILE *binaryFile = fopen ( binaryFileName, "rb" );
    int fileSize = numOfFileLines(file);
    int saveChoose = 1;

    if ( file == NULL ){
        perror("Error opening file");
        exit(1);
    }
    if ( binaryFile == NULL ){
        perror("Error opening binary file");
        exit(1);
    }

    printf("SAVE SLOTS:\n");
    for (int i = 1; i <= fileSize; i++){
            fread(game, sizeof(Game_Type), 1, binaryFile);
            printf("%d  ", i); printHeader(game);
    }
    printf("Which one do you choose? ");
    scanf("%d", &saveChoose);
    saveChoose--;
    fseek(file, 16*saveChoose, SEEK_SET);
    fseek(binaryFile,sizeof(Game_Type)*saveChoose, SEEK_SET);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            fscanf( file, "%1d", (*(*array + i) + j));
        }
    }
    if (fseek(file, 0, 1) != 0){ //fseek to skip "x" separator
        perror("Error while reading a file");
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            fscanf( file, "%1d", &referenceBoard[i][j]);
        }
    }
    if (fread(game, sizeof(Game_Type), 1, binaryFile) < 1){
        perror("Error while reading a binary file");
                exit(1);
    }

    if (fclose(file) == EOF){
        perror("Eroor while closing a file");
        exit(1);
    }

    if (fclose(binaryFile) == EOF){
        perror("Eroor while closing a file");
        exit(1);
    }

    return;
}

/*
* function  : saveGameToFile
* purpose   : saves a game to Board.txt and Board.bin
* input     : user game board, well-filled pattern, game struct
* output    : void
*/

void saveGameToFile (int ***userBoard, int referenceBoard[][9], Game_Type *game){
    static const char fileName[] = "Board.txt";
    static const char binaryFileName[] = "Binary.bin";
    FILE *file = fopen ( fileName, "a+" );
    FILE *binaryFile = fopen ( binaryFileName, "a+b" );

    if ( file == NULL ){
        perror("Error opening file");
        exit(1);
    }
    if ( binaryFile == NULL ){
        perror("Error opening binary file");
        exit(1);
    }

    //first the entire userBoard character by character
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (fprintf( file, "%1d", *(*(*userBoard + i) + j)) < 0){
                perror("Error. Save to file is incomplete");
                exit(1);
            }
        }
    }
    // "X" as separator between userBoard and referenceBoard
    fprintf( file, "X");

    //entire referenceBoard character by character
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (fprintf( file, "%1d", referenceBoard[i][j]) < 0){
                perror("Error. Save to file is incomplete");
                exit(1);
            };
        }
    }
    //new line as separator between saves
    fprintf( file, "\n");

    // append user game struct to binary file
    if (fwrite(game, sizeof(Game_Type), 1, binaryFile) < 0){
        perror("Error. Save to binaryfile is incomplete");
        exit(1);
    }
    if (fclose(file) == EOF){
        perror("Error. Changes not saved ");
        exit(1);
    }
    if (fclose(binaryFile) == EOF){
        perror("Eroor. Changes not saved");
        exit(1);
    }
    printf("Saved successfully!\n");

    return;
}