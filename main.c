#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int lookahead;

int main() {
  lookahead = getchar();
  expr();
  putchar('\n');
  
  return EXIT_SUCCESS;
}
