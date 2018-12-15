#include <ctype.h>
#include <stdio.h>
#include "main.h"
#include "util.h"

/*
 * 最適化: rest() 内での尾部再帰を繰り返しで置き換えたら、
 * rest() の呼び出しは expr からのみとなるため、 expr() 内に
 * rest() の処理を統合することができる。
 * expr: term rest
 */
void expr() {
  term(); rest();
}

/*
 * 最適化: 尾部再帰を繰り返しで置き換えられる。
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
 * term: '0' { print('0') }
 * ...
 * term: '9' { print('9') }
 */
void term() {
  factor();
  /*
  if (isdigit(lookahead)) {
    putchar(lookahead); match(lookahead);
  } else error("syntax error");
  */
}

/*
 * factor: '(' expr ')'
 *       | num { print(num.value) }
 */
void factor() {
  if (lookahead == '(') {
    match('('); expr(); match(')');
  } else if (lookahead == NUM) {
    printf(" %d ", tokenval); match(NUM);
  } else error("syntax error");
}

void match(const int c) {
  if(lookahead == c)
    lookahead = lexan();
  else
    error("syntax error");
}
