/* emitter.c */
#include "main.h"
#include <stdio.h>

void emit(TOKEN token) {

  switch (token.type) {
  case PLUS:
  case MINUS:
    printf("%c\n", token.type);
    break;
  case NUM:
    printf("%d\n", token.val);
    break;
  case IDENT:
    printf("%s\n", ((SYM_REC *)symtab->data[token.val])->lexptr);
    break;
  default:
    break;
  }
}

void emit3(char *str) { printf("%s", str); }
