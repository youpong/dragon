#include <ctype.h>
#include <stdio.h>
#include "main.h"
#include "util.h"

int newlabel = 0;
/*
 *
 */
void stmt() {
  char buf[100];
  if (lookahead.type == IDENT) {
    emit2("lvalue", lookahead.val); match(IDENT);match('=');expr();emit('=');
    match(';');
  } else if(lookahead.type == IF) {
    int out = newlabel++;
    match(IF); match('('); expr(); match(')');
    sprintf(buf, "gofalse L%d", out);
    emit3(buf); 
    expr();
    sprintf(buf, "L%d:", out);
    emit3(buf);
  } else
    error("syntax error");
}

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
  if (lookahead.type == '+') { 
    match('+'); term(); emit('+'); rest(); // (1)
  } else if (lookahead.type == '-') {
    match('-'); term(); emit('-'); rest(); // (2)
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
  if (lookahead.type == '(') {
    match('('); expr(); match(')');
  } else if (lookahead.type == NUM) {
    emit_NUM(lookahead.val); match(NUM);
  } else if (lookahead.type == IDENT) {
    emit2("rvalue", lookahead.val); match(IDENT);
  } else
    error("syntax error");
}

void match(const int c) {
  if(lookahead.type == c)
    lookahead = lexan();
  else
    error("syntax error");
}
