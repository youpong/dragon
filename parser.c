/* parser.c */
#include "main.h"
#include "util.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

static void stmt();
static void expr();
static void term();
static void factor();

static void match(TOKEN_TYPE);

int newlabel = 0;

void parse() {
  lookahead = lexan();
  while (lookahead.type != DONE)
    stmt();
}

/*
 *
 */
static void stmt() {
  char buf[100];
  if (lookahead.type == IDENT) {
    emit3("lvalue ");
    emit(lookahead);
    match(IDENT);
    match('=');
    expr();
    emit3("=");
    match(';');
  } else if (lookahead.type == IF) {
    int out = newlabel++;
    match(IF);
    match('(');
    expr();
    match(')');
    sprintf(buf, "gofalse L%d", out);
    emit3(buf);
    expr();
    sprintf(buf, "L%d:", out);
    emit3(buf);
  } else
    error("syntax error");
}

/*
 * expr: term rest
 * rest: '+' term { print('+') } rest # (1)
 * rest: '-' term { print('-') } rest # (2)
 * rest: ε                            # (3)
 * --
 * expr: term ('+' term { print('+') } | '-' term { print('-') } )*
 */
static void expr() {
  TOKEN op;

  term();
  while (true)
    if (lookahead.type == '+' || lookahead.type == '-') { // (1), (2)
      op = lookahead;
      match(op.type);
      term();
      emit(op);
    } else // (3)
      break;
}

/*
 * term: '0' { print('0') }
 * ...
 * term: '9' { print('9') }
 */
static void term() {
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
static void factor() {
  if (lookahead.type == '(') {
    match('(');
    expr();
    match(')');
  } else if (lookahead.type == NUM) {
    emit(lookahead);
    match(NUM);
  } else if (lookahead.type == IDENT) {
    emit3("rvalue ");
    emit(lookahead);
    match(IDENT);
  } else
    error("syntax error");
}

static void match(TOKEN_TYPE c) {
  if (lookahead.type != c)
    error("syntax error");

  lookahead = lexan();
}
