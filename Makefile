CFLAGS= -g -Wall -std=c11

all: calc
clean:
	rm -f *.o
calc: main.o parse.o util.o
	$(CC) -o calc main.o parse.o util.o
