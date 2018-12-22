#include "main.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>

FILE *yyin;
TOKEN lookahead;
Vector *symtab;
char *lexemes;

int main(int argc, char **argv) {
  symtab = new_vector();
  lexemes = (char *)malloc(sizeof(char) * 100);

  //  insert("div", div);
  //  insert("mod", mod);
  insert("if", IF);

  switch (argc) {
  case 1:
    yyin = stdin;
    break;
  case 2:
    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
      error("file cannot open");
    }
    break;
  default:
    fprintf(stderr, "Usage: %s [FILE]\n", argv[0]);
    return EXIT_FAILURE;
  }

  parse();
  putchar('\n');

  return EXIT_SUCCESS;
}
