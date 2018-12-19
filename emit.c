#include "main.h"
#include <stdio.h>

void emit(TOKEN_TYPE type) {
  switch(type) {
  case PLUS:
  case MINUS:
    putchar(type);
    break;
  default:
    break;
  }
}

void emit_NUM(int val) {
  printf(" %d ", val);
}

void emit_lvalue(int val) {
}

void emit2(char *str, int n) {
  printf("%s %d\n", str, n);
}

void emit3(char *str) {
  printf("%s\n", str);
}
