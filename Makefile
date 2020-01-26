CC=clang
SOURCE := $(wildcard *.c)
OBJS = ${SOURCE:.c=.o}
TARGET=main.out
CFLAGS= -Wall
LDFLAGS= -lm

main.out: main.o board.o menu.o file.o game.o
	$(CC) -o $(LDFLAGS) main.out main.o board.o menu.o file.o game.o

main.o: main.c board.c game.c file.c struct.h
	$(CC) -c main.c

board.o: board.c struct.h
	$(CC) -c board.c

menu.o: menu.c
	$(CC) -c menu.c

file.o: file.c struct.h
	$(CC) -c file.c

game.o: game.c struct.h
	$(CC) -c game.c

.PHONY: clean

clean:
	rm -f *.o