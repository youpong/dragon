CC = gcc
CFLAGS = -g -Wall -std=c11 --coverage
# LIBS = -lefence -lgcov
LIBS = -lgcov

TARGET = calc
SRCS = main.c parser.c util.c lexer.c emitter.c symbol.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)
clean:
	rm -f $(TARGET) $(OBJS) *.gcov *.gcda *.gcno *~
gcov:
	gcov $(SRCS)
TAGS: $(SRCS) main.h util.h
	etags $^

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LIBS)

$(OBJS): main.h util.h

format:
	clang-format -i $(SRCS) *.h
