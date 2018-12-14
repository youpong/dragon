all: calc
clean:
	rm -f *.o
calc: main.o parse.o
	$(CC) -o calc main.o parse.o
