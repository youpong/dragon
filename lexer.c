/* lexer.c */
#include "main.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int lineno = 1;

TOKEN lexan() {
  int c;
  TOKEN token;
  char buf[100];

  while (true) {
    c = getc(yyin);
    if (c == ' ' || c == '\t') /* ignore white space */
      ;
    else if (c == '\n')
      lineno++;
    else if (isdigit(c)) { /* TOKEN_TYPE: NUM */
      token.val = c - '0';
      c = getc(yyin);
      while (isdigit(c)) {
        token.val = token.val * 10 + c - '0';
        c = getc(yyin);
      }
      ungetc(c, yyin);
      token.type = NUM;
      return token;
    } else if (isalpha(c)) { /* TOKEN_TYPE: IDENT */
      char *p = buf;
      *p++ = c;
      c = getc(yyin);
      while (isalnum(c)) {
        *p++ = c;
        c = getc(yyin);
      }
      ungetc(c, yyin);
      *p = '\0';

      token.val = lookup(buf);
      if (token.val == -1)
        token.val = insert(buf, IDENT);

      token.type = ((SYM_REC *)symtab->data[token.val])->token;

      return token;
    } else if (c == EOF) {
      token.type = DONE;
      return token;
    } else {
      token.type = c;
      return token;
    }
  }
}
