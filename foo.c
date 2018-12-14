#include <ctype.h>
#include <stdio.h>
#include "main.h"


/*
 * expr: term rest
 */
void expr() {
  term(); rest();
}

/*
 * rest: '+' term { print('+') } rest # (1)
 * rest: '-' term { print('-') } rest # (2)
 * rest: ε                            # (3)
 */
void rest() {
  if (lookahead == '+') { 
    match('+'); term(); putchar('+'); rest(); // (1)
  } else if (lookahead == '-') {
    match('-'); term(); putchar('-'); rest(); // (2)
  } else ;                                    // (3) 
}

/*
 * term: 0 { print('0') }
 * ...
 * term: 9 { print('9') }
 */
void term() {
  if (isdigit(lookahead)) {
    putchar(lookahead); match(lookahead);
  } else error();
}
