#include <bits/stdc++.h>
using namespace std;
typedef struct alpha_token_t {
  unsigned int  numline;
  unsigned int  numToken;
  string content;
  string type;
} alpha_token;

int alpha_yylex (vector<alpha_token> &yval);