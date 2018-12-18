#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "util.h"

FILE *yyin;
TOKEN lookahead;
Vector *symtab;
Vector *lexemes;

int main(int argc, char **argv) {
  symtab = new_vector();
  lexemes = new_vector();

  //  insert("div", div);
  //  insert("mod", mod);

  switch (argc) {
  case 1:
    yyin = stdin; break;
  case 2:
    yyin = fopen(argv[1], "r");
    if(yyin == NULL) {
      error("file cannot open");
    }
  default:
    fprintf(stderr, "Usage: %s [FILE]\n", argv[0]);
    return EXIT_FAILURE;
  }
  
  lookahead = lexan();

  stmt();
  putchar('\n');
  
  return EXIT_SUCCESS;
}
