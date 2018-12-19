#include <stdio.h>
#include "util.h"


/* parse.c */
void stmt();
void expr();
void rest();
void term();
void factor();

void match(const int);

/* lexan.c */
typedef enum {
  PLUS = '+',
  MINUS = '-',
  NUM = 256,
  IDENT,
  IF,
  THEN,
} TOKEN_TYPE;

typedef struct {
  TOKEN_TYPE type;
  int val;
} TOKEN;

TOKEN lexan();

extern TOKEN lookahead;
extern FILE *yyin;

/* emit */
void emit(TOKEN_TYPE);
void emit_NUM(int);
void emit2(char *, int);
void emit3(char *);

/* var_tab */
int insert(char *, TOKEN_TYPE);
int lookup(char *);

extern Vector *symtab;
extern char *lexemes;

typedef struct {
  char *lexptr;
  TOKEN_TYPE token;
} SYM_REC;

