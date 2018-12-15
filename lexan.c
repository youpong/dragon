#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "main.h"

#define NONE -1; // adhoc

int lineno = 1;
int tokenval; // = NONE;

int lexan() {
  int t;
  while(true) {
    t = getchar();
    if (t == ' ' || t == '\t')
      ;
    else if( t == '\n' )
      lineno++;
    else if( isdigit(t) ) {
      tokenval = t - '0';
      t = getchar();
      while( isdigit(t) ) {
	tokenval = tokenval*10 + t - '0';
	t = getchar();
      }
      ungetc(t, stdin);
      return NUM;
    } else {
      //tokenval = NONE;
      return t;
    }
  }
}
