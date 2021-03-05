%{
#include "header_file.h"

int alpha_yylex (vector<alpha_token*> &yval);

alpha_token* Initialize(unsigned int numline, unsigned int numToken,string content , string type);
int total = 0;
int no_of_lines = 1;
#define YY_DECL int alpha_yylex(vector<alpha_token*> &yval)     // na to kano uncomment kapoia stigmh
%}

/* Flex options */
%option noyywrap
%option yylineno

/* Flex macros */
id [a-zA-Z][a-zA-Z_0-9]*
string \"[^\n"]*\"
comment "//".*

%x C_COMMENT

%%

\n  no_of_lines++; 


"if"        { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD IF <-enumerated\n", no_of_lines, total, yytext); yval.push_back(Initialize(no_of_lines,total,yytext,"KEYWORD"));}
"else"      { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD ELSE <-enumerated\n", no_of_lines, total, yytext);  yval.push_back(Initialize(no_of_lines,total,yytext,"KEYWORD"));  }
"while"     { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD WHILE <-enumerated\n", no_of_lines, total, yytext);  yval.push_back(Initialize(no_of_lines,total,yytext,"KEYWORD"));   }
"for"       { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD FOR <-enumerated\n", no_of_lines, total, yytext);   yval.push_back(Initialize(no_of_lines,total,yytext,"KEYWORD"));    }
"function"  { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD FUNCTION <-enumerated\n", no_of_lines, total, yytext);  yval.push_back(Initialize(no_of_lines,total,yytext,"KEYWORD")); }
"return"    { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD RETURN <-enumerated\n", no_of_lines, total, yytext);  yval.push_back(Initialize(no_of_lines,total,yytext,"KEYWORD"));  }
"break"     { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD BREAK <-enumerated\n", no_of_lines, total, yytext);  yval.push_back(Initialize(no_of_lines,total,yytext,"KEYWORD"));   }
"continue"  { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD CONTINUE <-enumerated\n", no_of_lines, total, yytext);  yval.push_back(Initialize(no_of_lines,total,yytext,"KEYWORD")); }
"and"       { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD AND <-enumerated\n", no_of_lines, total, yytext);   yval.push_back(Initialize(no_of_lines,total,yytext,"KEYWORD"));    }
"not"       { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD NOT <-enumerated\n", no_of_lines, total, yytext);    yval.push_back(Initialize(no_of_lines,total,yytext,"KEYWORD"));   }
"or"        { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD OR <-enumerated\n", no_of_lines, total, yytext);    yval.push_back(Initialize(no_of_lines,total,yytext,"KEYWORD"));    }
"local"     { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD LOCAL <-enumerated\n", no_of_lines, total, yytext);    }
"true"      { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD TRUE <-enumerated\n", no_of_lines, total, yytext);     }
"false"     { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD FALSE <-enumerated\n", no_of_lines, total, yytext);    }
"nil"       { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD NIL <-enumerated\n", no_of_lines, total, yytext);      }

[0-9]+    { total++; fprintf(yyout, "%d: #%d  \"%s\" CONST_INT %s <-integer\n", no_of_lines, total, yytext, yytext); }
"-"[0-9]+ { total++; fprintf(yyout, "%d: #%d  \"%s\" CONST_INT %s <-integer\n", no_of_lines, total, yytext, yytext);       }
[0-9]*"."[0-9]+ { total++; fprintf(yyout, "%d: #%d  \"%s\" CONST_REAL %s <-real\n", no_of_lines, total, yytext, yytext);   } 
[-][0-9]*"."[0-9]+ { total++; fprintf(yyout, "%d: #%d  \"%s\" CONST_REAL %s <-real\n", no_of_lines, total, yytext, yytext);}
^[a-zA-Z_][a-zA-Z0-9_]* { total++; fprintf(yyout, "%d: #%d  \"%s\" IDENT <-ident\n", no_of_lines, total, yytext);          }
[A-Za-z] { total++; fprintf(yyout, "%d: #%d  \"%s\" IDENT <-ident\n", no_of_lines, total, yytext);                         }


"="     { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR  EQUAL <-enumerated\n", no_of_lines, total, yytext);         } 
"+"     { total++; fprintf(yyout, "%d: #%d  \"\"%s\"\" OPERATOR  PLUS <-enumerated\n", no_of_lines, total, yytext);      }
"-"     { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR MINUS <-enumerated\n", no_of_lines, total, yytext);          } 
"*"     { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR MULTIPLICATION <-enumerated\n", no_of_lines, total, yytext);  } 
"/"     { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR DIVISION <-enumerated\n", no_of_lines, total, yytext);       } 
"%"     { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR PERCENTAGE <-enumerated\n", no_of_lines, total, yytext);     } 
"=="    { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR EQUAL_EQUAL <-enumerated\n", no_of_lines, total, yytext);    }
"!="    { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR NOTEQUAL <-enumerated\n", no_of_lines, total, yytext);       } 
"++"    { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR PLUS_PLUS <-enumerated\n", no_of_lines, total, yytext);      } 
"--"    { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR MINUS_MINUS <-enumerated\n", no_of_lines, total, yytext);    } 
">"     { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR GREATER <-enumerated\n", no_of_lines, total, yytext);        } 
"<"     { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR LESS_THAN <-enumerated\n", no_of_lines, total, yytext);      } 
">="    { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR GREATER_EQUAL <-enumerated\n", no_of_lines, total, yytext);  } 
"<="    { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR LESS_EQUAL <-enumerated\n", no_of_lines, total, yytext);     } 

"{"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION LEFT_BRACE <-enumerated\n" , no_of_lines, total, yytext);    }
"}"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION RIGHT_BRACE <-enumerated\n" , no_of_lines, total, yytext);     }
"["     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION LEFT_BRACE <-enumerated\n" , no_of_lines, total, yytext);    }
"]"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION RIGHT_BRACE <-enumerated\n" , no_of_lines, total, yytext);     }
"("     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION LEFT_BRACE <-enumerated\n" , no_of_lines, total, yytext);    }
")"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION RIGHT_BRACE <-enumerated\n" , no_of_lines, total, yytext);     }
";"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION SEMICOLON <-enumerated\n" , no_of_lines, total, yytext);      }
","     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION COMMA <-enumerated\n" , no_of_lines, total, yytext);          }
":"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION COLON <-enumerated\n" , no_of_lines, total, yytext);          }
"::"    { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION DOUBLE_COLON <-enumerated\n" , no_of_lines, total, yytext);   }
"."     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION DOT <-enumerated\n" , no_of_lines, total, yytext);            }
".."    { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION DOUBLE_DOT <-enumerated\n" , no_of_lines, total, yytext);      }

{id} { total++; fprintf(yyout, "%d: #%d  \"%s\" ID \"%s\" <-char*\n", no_of_lines, total, yytext, yytext);  }
{string} { total++; fprintf(yyout, "%d: #%d  %s STRING %s <-char*\n", no_of_lines, total, yytext, yytext);  }
{comment} { total++; fprintf(yyout, "%d: #%d   \"\" COMMENT LINE_COMMENT <-enumerated\n" , no_of_lines, total);      }

"/*"            { BEGIN(C_COMMENT); }
<C_COMMENT>"*/" { BEGIN(INITIAL);   }
<C_COMMENT>.    { }
<C_COMMENT>\n   { }

. { printf("%s", yytext); }

[\t]+   /*ignore wite spaces and newlines */
[[:space:]]+; /* Ignore whitespace */
[ \t]* /* ignores whitespaces */;

%%

alpha_token* Initialize(unsigned int numline,unsigned int numToken, string content , string type ) {
    alpha_token* a = (alpha_token*) malloc(sizeof(alpha_token));
    a->numline = numline;
    a->numToken = numToken;
    a->content = content;
    a->type = type;
    return a;
}


/* Na ftiaxo tis diafores metaxi id kai identifier , na mporoume na teliosoyme otan diabazoyme apo to std in.
na ftiaxoume to struct kai oti allo xreiazetai*/
int main(int argc, char** argv) {
    if(argc > 1){
        if(!(yyin = fopen(argv[1], "r"))) {
            fprintf(stderr, "Cannot read file: %s\n", argv[1]);
            return 1;
        }
        yyout = fopen(argv[2], "w");
    }
    else {
        yyin = stdin; /* na tsekaro pote teleionei kai epishs na leitoyrgei otan den dino output file px na ta ektiponei sto std out */
        yyout = stdout;
    }

    fprintf(yyout, "--------------------   Lexical Analysis   --------------------\n\n");

    vector<alpha_token*> token;
    alpha_yylex(token); 
    fprintf(yyout, "\nTotal Tokens = %d %d", total,token.size()); 
    for(auto a : token) {

        
        fprintf(yyout, "%s DICKS %d", a->content.c_str(),a->numline); 
    }
    return 0;
}