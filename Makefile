CC = clang
CFLAGS= -g -Wall -std=c11
SRCS = main.c parser.c util.c lexer.c emitter.c symbol.c
OBJS =$(SRCS:.c=.o)

all: calc
clean:
	rm -f *.o calc
calc: $(OBJS)
	$(CC) -o calc $(OBJS)

$(OBJS): main.h util.h

format:
	clang-format -i $(SRCS) *.h
