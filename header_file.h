struct alpha_token_t {
  unsigned int  numline;
  unsigned int  numToken;
  char  *content;
  char  *type;
};

int alpha_yylex (void* yval);