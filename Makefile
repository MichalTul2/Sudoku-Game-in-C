CC=clang
SOURCE := $(wildcard *.c)
OBJS = ${SOURCE:.c=.o}
TARGET=main.out
CFLAGS= -Wall
LDFLAGS=-lm
$(TARGET): $(OBJS)
	$(CC) -o $@ $(LDFLAGS) $(OBJS)
%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@
.PHONY: clean

clean:
	rm -f *.o

run:
	./main.out

reset:
	rm -f Binary.bin Board.txt
