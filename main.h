void expr();
void rest();
void term();
void factor();

void match(const int);

extern int lookahead;

extern int tokenval;

typedef enum {
  NUM = 256,
} TOKEN_TYPE;
