#include <stdio.h>
#include "Struct.h"

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
    rewind(fileName);
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
        exit(EXIT_FAILURE);
    }
    if ( binaryFile == NULL ){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    printf("SAVE SLOTS:\n");
    for (int i = 1; i < 6; i++){
        if ( i <= fileSize){
            fread(game, sizeof(Game_Type), 1, binaryFile);
            printf("%d  ", i); printHeader(game);
        }
        else {
            printf("%d  Empty\n", i);
        };
    }
    printf("Which one do you choose? ");
    scanf("%d", &saveChoose);
    saveChoose--;
    fseek(file, 164*saveChoose, SEEK_SET);
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
    rewind(file);
    fclose(file);
    rewind(binaryFile);
    fclose(binaryFile);

    return;
}


void saveGameToFile (int ***userBoard, int referenceBoard[][9], Game_Type *game){
    static const char fileName[] = "Board.txt";
    static const char binaryFileName[] = "Binary.bin";
    FILE *file = fopen ( fileName, "a+" );
    FILE *binaryFileRead = fopen ( binaryFileName, "rb" );
    FILE *binaryFile = fopen ( binaryFileName, "a+b" );
    int fileSize = numOfFileLines(file);
    int saveChoose = 1;

    if ( file == NULL ){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    if ( binaryFileRead == NULL ){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    printf("SAVE SLOTS:\n");
    for (int i = 1; i < 6; i++){
        if ( i <= fileSize){
            fread(game, sizeof(Game_Type), 1, binaryFileRead);
            printf("%d  ", i); printHeader(game);
        }
        else {
            printf("%d  Empty\n", i);
        };
    }
    printf("Choose save slot: ");
    scanf("%d", &saveChoose);
    saveChoose--;
    fclose(binaryFileRead);
    
    if ( binaryFile == NULL ){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    rewind(file); 
    rewind(binaryFile); 
    fseek(file, 164*saveChoose, SEEK_SET);
    fseek(binaryFile, (sizeof(Game_Type))*saveChoose, SEEK_SET);
    
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
    fseek(binaryFile, 0, 0);
    fwrite(game, sizeof(Game_Type), 1, binaryFile);
    fclose(file);
    fclose(binaryFile);

    return;
}