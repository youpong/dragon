CFLAGS= -g -Wall -std=c11

all: calc
clean:
	rm -f *.o calc
calc: main.o parse.o util.o lexan.o
	$(CC) -o calc main.o parse.o util.o lexan.o
lexan.o main.o parse.o: main.h
parse.o util.o: util.h
