#include <stdio.h>
#include <stdlib.h>
#include "main.h"

TOKEN lookahead;

int main() {
  lookahead = lexan();
  expr();
  putchar('\n');
  
  return EXIT_SUCCESS;
}
