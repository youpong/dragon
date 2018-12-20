#include <stdio.h>
#include "util.h"

#define BSIZE  128
#define NONE    -1
#define EOS   '\0'

/* parse.c */
void parse();

/* lexan.c */
typedef enum {
  PLUS = '+',
  MINUS = '-',
  NUM = 256,
  IDENT,
  IF,
  THEN,
  DIV,
  MOD,
  DONE,
} TOKEN_TYPE;

typedef struct {
  TOKEN_TYPE type;
  int val;
} TOKEN;

TOKEN lexan();

extern int lineno;
extern TOKEN lookahead;
extern FILE *yyin;

/* emit */
void emit(TOKEN);
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

