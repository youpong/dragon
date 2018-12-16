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
