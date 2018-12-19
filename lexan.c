#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "main.h"

#define NONE -1; // adhoc

int lineno = 1;

TOKEN lexan() {
  int c;
  TOKEN token;
  char buf[100];
  char *p;
  
  while(true) {
    p = buf;
    c = getc(yyin);
    if (c == ' ' || c == '\t')
      ;
    else if( c == '\n' )
      lineno++;
    else if( isdigit(c) ) {
      token.val = c - '0';
      c = getc(yyin);
      while( isdigit(c) ) {
	token.val = token.val*10 + c - '0';
	c = getc(yyin);
      }
      ungetc(c, yyin);
      token.type = NUM;
      return token;
    } else if( isalpha(c) ) {
      *p++ = c;
      c = getc(yyin);
      while( isalnum(c) ) {
	*p++ = c;
	c = getc(yyin);
      }
      ungetc(c, yyin);
      *p = '\0';

      token.type = IDENT;
      token.val = lookup(buf);
      if( token.val == -1 ) 
	token.val = insert(buf, IDENT);
      else
	token.type = ((SYM_REC*)symtab->data[token.val])->token;
      return token;
    } else {
      token.type = c;
      return token;
    }
  }
}
