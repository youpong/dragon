/* parse.c */
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
} TOKEN_TYPE;

typedef struct {
  TOKEN_TYPE type;
  int val;
} TOKEN;

TOKEN lexan();

extern TOKEN lookahead;

/* emit */
void emit(TOKEN_TYPE);
void emit_NUM(int);
void emit_lvalue(int);
