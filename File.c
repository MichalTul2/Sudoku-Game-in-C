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
    char c; //dummy variable
    int chooseLine=1;
    int currentLine=1;
    FILE *file = fopen ( filename, "r" );
    FILE *binaryFile = fopen ( binaryFileName, "rb" );
    if ( file == NULL ){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    if ( binaryFile == NULL ){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    int fileSize = numOfFileLines(file);

    printf("I found:\n");
    for (int i=0; i < fileSize; i++){
        fread(game, sizeof(Game_Type), 1, binaryFile);
        printf("* Save %d: ", i+1);
        printHeader(game);
    }
    printf("Which one do you choose? ");
    scanf("%d", &chooseLine);

    while ( currentLine != chooseLine)
    {
        do {
            c = getc(file);
            fread(game, sizeof(Game_Type), 1, binaryFile);
        }
        while(c != '\n');
        currentLine++;
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            fscanf( file, "%1d", (*(*array + i) + j));
        }
    }
    fscanf( file, "%1c", &c); //get an "X" sign from file and move FILE pointer to next intiger
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            fscanf( file, "%1d", &referenceBoard[i][j]);
        }
    }
    fclose(file);
    fclose(binaryFile);

    return;
}


void saveGameToFile (int ***userBoard, int referenceBoard[][9], Game_Type *game){
    static const char fileName[] = "Board.txt";
    static const char binaryFileName[] = "Binary.bin";
    FILE *file = fopen ( fileName, "a" );
    FILE *binaryFile = fopen ( binaryFileName, "ab" );
    if ( file == NULL ){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    if ( binaryFile == NULL ){
        perror("Error opening file");
        exit(EXIT_FAILURE);
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
    fwrite(game, sizeof(Game_Type), 1, binaryFile);
    fprintf( file, "\n");
    fclose(file);
    fclose(binaryFile);

    return;
}