#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "util.h"

int insert(char *str, TOKEN_TYPE type) {
  SYM_REC *rec = (SYM_REC *)malloc(sizeof(SYM_REC));

  // lexptr
  char *p;
  if ( symtab->len == 0 ) {
    p = lexemes;
  } else {
    SYM_REC *last = (SYM_REC *)symtab->data[symtab->len-1];    
    p = last->lexptr;
    p += strlen(p)+1;
  }
  strcpy(p, str);
  rec->lexptr = p;

  // token_type
  rec->token = type;

  // push rec to symtab 
  vec_push(symtab, rec);
  
  return symtab->len-1;
}

int lookup(char *str) {
  for(int i = 0; i < symtab->len; i++) {
    SYM_REC *rec = (SYM_REC *)symtab->data[i];
    if ( strcmp(rec->lexptr, str) == 0) {
      return i;
    }
  }
  return -1;
}

