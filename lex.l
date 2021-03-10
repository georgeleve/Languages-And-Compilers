%{
#include "header_file.h"

int total = 0;
int line_number = 1;
int alpha_yylex (vector<alpha_token*> &yval);
alpha_token* init_token(unsigned int numline, unsigned int numToken, string content,enum type);
#define YY_DECL int alpha_yylex(vector<alpha_token*> &yval)
%}
 
/* Flex options */
%option noyywrap
%option yylineno
 
/* Flex macros */
id [a-zA-Z][a-zA-Z_0-9]*
string [\"]([^\"]|\.)*[\"]
one_line_comment "//".*

%%

\n  line_number++; 
 
"if"        { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD IF <-enumerated\n", line_number, total, yytext); yval.push_back(init_token(line_number,total,yytext,type::KEYWORD));        }
"else"      { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD ELSE <-enumerated\n", line_number, total, yytext);  yval.push_back(init_token(line_number,total,yytext,type::KEYWORD));     }
"while"     { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD WHILE <-enumerated\n", line_number, total, yytext);  yval.push_back(init_token(line_number,total,yytext,type::KEYWORD));    }
"for"       { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD FOR <-enumerated\n", line_number, total, yytext);   yval.push_back(init_token(line_number,total,yytext,type::KEYWORD));     }
"function"  { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD FUNCTION <-enumerated\n", line_number, total, yytext);  yval.push_back(init_token(line_number,total,yytext,type::KEYWORD)); }
"return"    { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD RETURN <-enumerated\n", line_number, total, yytext);  yval.push_back(init_token(line_number,total,yytext,type::KEYWORD));   }
"break"     { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD BREAK <-enumerated\n", line_number, total, yytext);  yval.push_back(init_token(line_number,total,yytext,type::KEYWORD));    }
"continue"  { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD CONTINUE <-enumerated\n", line_number, total, yytext);  yval.push_back(init_token(line_number,total,yytext,type::KEYWORD)); }
"and"       { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD AND <-enumerated\n", line_number, total, yytext);   yval.push_back(init_token(line_number,total,yytext,type::KEYWORD));     }
"not"       { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD NOT <-enumerated\n", line_number, total, yytext);    yval.push_back(init_token(line_number,total,yytext,type::KEYWORD));    }
"or"        { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD OR <-enumerated\n", line_number, total, yytext);    yval.push_back(init_token(line_number,total,yytext,type::KEYWORD));     }
"local"     { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD LOCAL <-enumerated\n", line_number, total, yytext); yval.push_back(init_token(line_number,total,yytext,type::KEYWORD));     }
"true"      { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD TRUE <-enumerated\n", line_number, total, yytext);  yval.push_back(init_token(line_number,total,yytext,type::KEYWORD));     }
"false"     { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD FALSE <-enumerated\n", line_number, total, yytext);  yval.push_back(init_token(line_number,total,yytext,type::KEYWORD));    }
"nil"       { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD NIL <-enumerated\n", line_number, total, yytext);  yval.push_back(init_token(line_number,total,yytext,type::KEYWORD));      }
 
"="     { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR  EQUAL <-enumerated\n", line_number, total, yytext);    yval.push_back(init_token(line_number,total,yytext,type::OPERATOR));       } 
"+"     { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR  PLUS <-enumerated\n", line_number, total, yytext);    yval.push_back(init_token(line_number,total,yytext,type::OPERATOR));    }
"-"     { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR MINUS <-enumerated\n", line_number, total, yytext);       yval.push_back(init_token(line_number,total,yytext,type::OPERATOR));     } 
"*"     { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR MULTIPLICATION <-enumerated\n", line_number, total, yytext);  yval.push_back(init_token(line_number,total,yytext,type::OPERATOR)); } 
"/"     { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR DIVISION <-enumerated\n", line_number, total, yytext);     yval.push_back(init_token(line_number,total,yytext,type::OPERATOR));    } 
"%"     { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR PERCENTAGE <-enumerated\n", line_number, total, yytext);    yval.push_back(init_token(line_number,total,yytext,type::OPERATOR));   } 
"=="    { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR EQUAL_EQUAL <-enumerated\n", line_number, total, yytext);  yval.push_back(init_token(line_number,total,yytext,type::OPERATOR));    }
"!="    { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR NOTEQUAL <-enumerated\n", line_number, total, yytext);     yval.push_back(init_token(line_number,total,yytext,type::OPERATOR));    } 
"++"    { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR PLUS_PLUS <-enumerated\n", line_number, total, yytext);      yval.push_back(init_token(line_number,total,yytext,type::OPERATOR));  } 
"--"    { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR MINUS_MINUS <-enumerated\n", line_number, total, yytext);   yval.push_back(init_token(line_number,total,yytext,type::OPERATOR));   } 
">"     { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR GREATER <-enumerated\n", line_number, total, yytext);       yval.push_back(init_token(line_number,total,yytext,type::OPERATOR));   } 
"<"     { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR LESS_THAN <-enumerated\n", line_number, total, yytext);     yval.push_back(init_token(line_number,total,yytext,type::OPERATOR));   } 
">="    { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR GREATER_EQUAL <-enumerated\n", line_number, total, yytext);  yval.push_back(init_token(line_number,total,yytext,type::OPERATOR));  } 
"<="    { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR LESS_EQUAL <-enumerated\n", line_number, total, yytext);   yval.push_back(init_token(line_number,total,yytext,type::OPERATOR));    } 
 
"{"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION LEFT_BRACE <-enumerated\n" , line_number, total, yytext);   yval.push_back(init_token(line_number,total,yytext,type::PUNCTUATION));   }
"}"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION RIGHT_BRACE <-enumerated\n" , line_number, total, yytext); yval.push_back(init_token(line_number,total,yytext,type::PUNCTUATION));    }
"["     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION LEFT_BRACE <-enumerated\n" , line_number, total, yytext);   yval.push_back(init_token(line_number,total,yytext,type::PUNCTUATION));   }
"]"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION RIGHT_BRACE <-enumerated\n" , line_number, total, yytext);   yval.push_back(init_token(line_number,total,yytext,type::PUNCTUATION));  }
"("     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION LEFT_BRACE <-enumerated\n" , line_number, total, yytext);  yval.push_back(init_token(line_number,total,yytext,type::PUNCTUATION));    }
")"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION RIGHT_BRACE <-enumerated\n" , line_number, total, yytext);   yval.push_back(init_token(line_number,total,yytext,type::PUNCTUATION));  }
";"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION SEMICOLON <-enumerated\n" , line_number, total, yytext);  yval.push_back(init_token(line_number,total,yytext,type::PUNCTUATION));     }
","     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION COMMA <-enumerated\n" , line_number, total, yytext); yval.push_back(init_token(line_number,total,yytext,type::PUNCTUATION));          }
":"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION COLON <-enumerated\n" , line_number, total, yytext);   yval.push_back(init_token(line_number,total,yytext,type::PUNCTUATION));        }
"::"    { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION DOUBLE_COLON <-enumerated\n" , line_number, total, yytext);  yval.push_back(init_token(line_number,total,yytext,type::PUNCTUATION));  }
"."     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION DOT <-enumerated\n" , line_number, total, yytext);        yval.push_back(init_token(line_number,total,yytext,type::PUNCTUATION));     }
".."    { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION DOUBLE_DOT <-enumerated\n" , line_number, total, yytext);  yval.push_back(init_token(line_number,total,yytext,type::PUNCTUATION));    }
 
[0-9]+    { total++; fprintf(yyout, "%d: #%d  \"%s\" CONST_INT %s <-integer\n", line_number, total, yytext, yytext); yval.push_back(init_token(line_number,total,yytext,type::CONST_INT)); }
"-"[0-9]+ { total++; fprintf(yyout, "%d: #%d  \"%s\" CONST_INT %s <-integer\n", line_number, total, yytext, yytext);    yval.push_back(init_token(line_number,total,yytext,type::CONST_INT));   }
[0-9]*"."[0-9]+ { total++; fprintf(yyout, "%d: #%d  \"%s\" CONST_REAL %s <-real\n", line_number, total, yytext, yytext); yval.push_back(init_token(line_number,total,yytext,type::CONST_REAL));  } 
[-][0-9]*"."[0-9]+ { total++; fprintf(yyout, "%d: #%d  \"%s\" CONST_REAL %s <-real\n", line_number, total, yytext, yytext); yval.push_back(init_token(line_number,total,yytext,type::CONST_REAL));}
 
{one_line_comment} {
    total++; 
    fprintf(yyout, "%d: #%d  \"\" COMMENT LINE_COMMENT <-enumerated\n", line_number, total);
}
 
"\"" {
    char prev = '-';
    string v = "";
    while(true){
        char c = yyinput();
        if(c == '\"') {
            if(prev == '\\') {
                v+= "\"";
                prev = c;
                continue;
            }
            else break;
        } 
        if(c == '\n'){
          v+= "\\n";  
          line_number++; 
        } 
        else if(c == '\t') v+= "\\t";
        else if(c != 13) v += c;
        prev = c;
    }
    total++; 
    fprintf(yyout, "%d: #%d  \"%s\" STRING %s <-char*\n", line_number, total, v.c_str(), v.c_str());
}
"/*" {
    char prev = '-';
    stack<string> par;
    stack<int> s;
    s.push(line_number);
    while(true){
        char c = yyinput();
        if(c == EOF || c == '\0') break;
        if(prev == '/' && c == '*'){ /* opening */
            s.push(line_number);
        }
        if(prev == '*' && c == '/') { /* closing */
            if(s.empty()){
                fprintf(yyout, "Error, non balanced comment!\n");
                exit(0);
            }
            par.push(to_string(s.top())+" - "+to_string(line_number));
            s.pop();
        }
        if(c == '\n') line_number++; 
        if(s.empty()) break;
        prev = c;
    }
    if(!s.empty()) {
        fprintf(yyout,"Error, non closing comment!\n");
        exit(0);
    }
    string tp = par.top();
    string lineNo = "";
    for(char c : tp) {
        if(c == ' ') break;
        lineNo += c;
    }
    fprintf(yyout, "%s: #%d \"%s\" COMMENT BLOCK_COMMENT <-enumerated\n", lineNo.c_str(), ++total, tp.c_str());
    par.pop();
    while(!par.empty()) {
        string tp = par.top();
        string lineNo = "";
        for(char c : tp) {
            if(c==' ') break;
            lineNo += c;
        }
        fprintf(yyout, "%s: #%d \"%s\" COMMENT NESTED_COMMENT <-enumerated\n", lineNo.c_str(), ++total, tp.c_str());
        par.pop();
    }
}
{id} { total++; fprintf(yyout, "%d: #%d  \"%s\" ID \"%s\" <-char*\n", line_number, total, yytext, yytext); yval.push_back(init_token(line_number,total,yytext,type::ID)); }

[\t]+ /* with this rule we ignore white spaces and newlines */ 
 
%%
 
alpha_token* init_token(unsigned int numline, unsigned int numToken, string content, enum type t_type) {
    alpha_token* a = (alpha_token*) malloc(sizeof(alpha_token));
    a->numline = numline;
    a->numToken = numToken;
    a->content = content;
    a->token_type = t_type;
    return a;
}
 
int main(int argc, char** argv) {
    if(argc > 1){
        if(!(yyin = fopen(argv[1], "r"))) {
            fprintf(stderr, "Cannot read file: %s\n", argv[1]);
            return 1;
        }
        yyout = fopen(argv[2], "w");
    }
    else {
        yyin = stdin; 
        yyout = stdout;
    }
    fprintf(yyout, "--------------------   Lexical Analysis   --------------------\n\n");
    vector<alpha_token*> token;
    alpha_yylex(token); 
    cout << "Total Tokens:" << token.size() << endl;
    /* for(auto a : token)
        fprintf(yyout, "%s", a->content.c_str()); UNCOMMENT FOR DEBUG */
    return 0;
}
