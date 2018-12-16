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
    c = getchar();
    if (c == ' ' || c == '\t')
      ;
    else if( c == '\n' )
      lineno++;
    else if( isdigit(c) ) {
      token.val = c - '0';
      c = getchar();
      while( isdigit(c) ) {
	token.val = token.val*10 + c - '0';
	c = getchar();
      }
      ungetc(c, stdin);
      token.type = NUM;
      return token;
    } else if( isalpha(c) ) {
      *p++ = c;
      c = getchar();
      while( isalnum(c) ) {
	*p++ = c;
	c = getchar();
      }
      ungetc(c, stdin);
      *p = '\0';

      token.type = IDENT;
      token.val = lookup(buf);
      if( token.val == 0 )
	token.val = insert(buf);
    } else {
      token.type = c;
      return token;
    }
  }
}
