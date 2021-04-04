#include <bits/stdc++.h>
using namespace std;

enum type {KEYWORD, OPERATOR, PUNCTUATION, ID, STRING, COMMENT, CONST_INT, CONST_REAL};

typedef struct alpha_token_t {
  unsigned int  numline;
  unsigned int  numToken;
  string content;
  enum type token_type;
} alpha_token;

int alpha_yylex (vector<alpha_token> &yval);