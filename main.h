/* parse.c */
void expr();
void rest();
void term();
void factor();

void match(const int);

/* lexan.c */
int lexan();

extern int lookahead;
extern int tokenval;

typedef enum {
  NUM = 256,
} TOKEN_TYPE;
