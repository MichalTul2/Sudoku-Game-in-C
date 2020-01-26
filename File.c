#include <stdio.h>
#include "struct.h"

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
    fseek(file, 0, 1);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            fscanf( file, "%1d", &referenceBoard[i][j]);
        }
    }
    fread(game, sizeof(Game_Type), 1, binaryFile);

    if (fclose(file) == EOF){
        perror("Eroor. Changes not saved ");
        exit(1);
    }

    if (fclose(binaryFile) == EOF){
        perror("Eroor. Changes not saved");
        exit(1);
    }

    return;
}


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

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            fprintf( file, "%1d", *(*(*userBoard + i) + j));
        }
    }
    fprintf( file, "X");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            fprintf( file, "%1d", referenceBoard[i][j]);
        }
    }
    fprintf( file, "\n");
    fwrite(game, sizeof(Game_Type), 1, binaryFile);
    if (fclose(file) == EOF){
        perror("Eroor. Changes not saved ");
        exit(1);
    }
    if (fclose(binaryFile) == EOF){
        perror("Eroor. Changes not saved");
        exit(1);
    }
    printf("Saved successfully!\n");

    return;
}