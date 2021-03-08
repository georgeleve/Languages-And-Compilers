%{
#include "header_file.h"

int alpha_yylex (vector<alpha_token*> &yval);
alpha_token* init_token(unsigned int numline,unsigned int numToken,string content,enum type);
int total = 0;
int no_of_lines = 1;
#define YY_DECL int alpha_yylex(vector<alpha_token*> &yval)
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

"if"        { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD IF <-enumerated\n", no_of_lines, total, yytext); yval.push_back(init_token(no_of_lines,total,yytext,type::KEYWORD));}
"else"      { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD ELSE <-enumerated\n", no_of_lines, total, yytext);  yval.push_back(init_token(no_of_lines,total,yytext,type::KEYWORD));  }
"while"     { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD WHILE <-enumerated\n", no_of_lines, total, yytext);  yval.push_back(init_token(no_of_lines,total,yytext,type::KEYWORD));   }
"for"       { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD FOR <-enumerated\n", no_of_lines, total, yytext);   yval.push_back(init_token(no_of_lines,total,yytext,type::KEYWORD));    }
"function"  { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD FUNCTION <-enumerated\n", no_of_lines, total, yytext);  yval.push_back(init_token(no_of_lines,total,yytext,type::KEYWORD)); }
"return"    { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD RETURN <-enumerated\n", no_of_lines, total, yytext);  yval.push_back(init_token(no_of_lines,total,yytext,type::KEYWORD));  }
"break"     { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD BREAK <-enumerated\n", no_of_lines, total, yytext);  yval.push_back(init_token(no_of_lines,total,yytext,type::KEYWORD));   }
"continue"  { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD CONTINUE <-enumerated\n", no_of_lines, total, yytext);  yval.push_back(init_token(no_of_lines,total,yytext,type::KEYWORD)); }
"and"       { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD AND <-enumerated\n", no_of_lines, total, yytext);   yval.push_back(init_token(no_of_lines,total,yytext,type::KEYWORD));    }
"not"       { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD NOT <-enumerated\n", no_of_lines, total, yytext);    yval.push_back(init_token(no_of_lines,total,yytext,type::KEYWORD));   }
"or"        { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD OR <-enumerated\n", no_of_lines, total, yytext);    yval.push_back(init_token(no_of_lines,total,yytext,type::KEYWORD));    }
"local"     { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD LOCAL <-enumerated\n", no_of_lines, total, yytext); yval.push_back(init_token(no_of_lines,total,yytext,type::KEYWORD));   }
"true"      { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD TRUE <-enumerated\n", no_of_lines, total, yytext);  yval.push_back(init_token(no_of_lines,total,yytext,type::KEYWORD));   }
"false"     { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD FALSE <-enumerated\n", no_of_lines, total, yytext);  yval.push_back(init_token(no_of_lines,total,yytext,type::KEYWORD));  }
"nil"       { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD NIL <-enumerated\n", no_of_lines, total, yytext);  yval.push_back(init_token(no_of_lines,total,yytext,type::KEYWORD));    }

"="     { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR  EQUAL <-enumerated\n", no_of_lines, total, yytext);    yval.push_back(init_token(no_of_lines,total,yytext,type::OPERATOR));     } 
"+"     { total++; fprintf(yyout, "%d: #%d  \"\"%s\"\" OPERATOR  PLUS <-enumerated\n", no_of_lines, total, yytext);    yval.push_back(init_token(no_of_lines,total,yytext,type::OPERATOR));    }
"-"     { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR MINUS <-enumerated\n", no_of_lines, total, yytext);       yval.push_back(init_token(no_of_lines,total,yytext,type::OPERATOR));     } 
"*"     { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR MULTIPLICATION <-enumerated\n", no_of_lines, total, yytext);  yval.push_back(init_token(no_of_lines,total,yytext,type::OPERATOR));  } 
"/"     { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR DIVISION <-enumerated\n", no_of_lines, total, yytext);     yval.push_back(init_token(no_of_lines,total,yytext,type::OPERATOR));    } 
"%"     { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR PERCENTAGE <-enumerated\n", no_of_lines, total, yytext);    yval.push_back(init_token(no_of_lines,total,yytext,type::OPERATOR));   } 
"=="    { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR EQUAL_EQUAL <-enumerated\n", no_of_lines, total, yytext);  yval.push_back(init_token(no_of_lines,total,yytext,type::OPERATOR));    }
"!="    { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR NOTEQUAL <-enumerated\n", no_of_lines, total, yytext);     yval.push_back(init_token(no_of_lines,total,yytext,type::OPERATOR));    } 
"++"    { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR PLUS_PLUS <-enumerated\n", no_of_lines, total, yytext);      yval.push_back(init_token(no_of_lines,total,yytext,type::OPERATOR));  } 
"--"    { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR MINUS_MINUS <-enumerated\n", no_of_lines, total, yytext);   yval.push_back(init_token(no_of_lines,total,yytext,type::OPERATOR));   } 
">"     { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR GREATER <-enumerated\n", no_of_lines, total, yytext);       yval.push_back(init_token(no_of_lines,total,yytext,type::OPERATOR));   } 
"<"     { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR LESS_THAN <-enumerated\n", no_of_lines, total, yytext);     yval.push_back(init_token(no_of_lines,total,yytext,type::OPERATOR));   } 
">="    { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR GREATER_EQUAL <-enumerated\n", no_of_lines, total, yytext);  yval.push_back(init_token(no_of_lines,total,yytext,type::OPERATOR));  } 
"<="    { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR LESS_EQUAL <-enumerated\n", no_of_lines, total, yytext);   yval.push_back(init_token(no_of_lines,total,yytext,type::OPERATOR));    } 

"{"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION LEFT_BRACE <-enumerated\n" , no_of_lines, total, yytext);   yval.push_back(init_token(no_of_lines,total,yytext,type::PUNCTUATION));   }
"}"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION RIGHT_BRACE <-enumerated\n" , no_of_lines, total, yytext); yval.push_back(init_token(no_of_lines,total,yytext,type::PUNCTUATION));    }
"["     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION LEFT_BRACE <-enumerated\n" , no_of_lines, total, yytext);   yval.push_back(init_token(no_of_lines,total,yytext,type::PUNCTUATION)); }
"]"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION RIGHT_BRACE <-enumerated\n" , no_of_lines, total, yytext);   yval.push_back(init_token(no_of_lines,total,yytext,type::PUNCTUATION));  }
"("     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION LEFT_BRACE <-enumerated\n" , no_of_lines, total, yytext);  yval.push_back(init_token(no_of_lines,total,yytext,type::PUNCTUATION));  }
")"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION RIGHT_BRACE <-enumerated\n" , no_of_lines, total, yytext);   yval.push_back(init_token(no_of_lines,total,yytext,type::PUNCTUATION));  }
";"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION SEMICOLON <-enumerated\n" , no_of_lines, total, yytext);  yval.push_back(init_token(no_of_lines,total,yytext,type::PUNCTUATION));    }
","     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION COMMA <-enumerated\n" , no_of_lines, total, yytext); yval.push_back(init_token(no_of_lines,total,yytext,type::PUNCTUATION));         }
":"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION COLON <-enumerated\n" , no_of_lines, total, yytext);   yval.push_back(init_token(no_of_lines,total,yytext,type::PUNCTUATION));       }
"::"    { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION DOUBLE_COLON <-enumerated\n" , no_of_lines, total, yytext);  yval.push_back(init_token(no_of_lines,total,yytext,type::PUNCTUATION)); }
"."     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION DOT <-enumerated\n" , no_of_lines, total, yytext);        yval.push_back(init_token(no_of_lines,total,yytext,type::PUNCTUATION));    }
".."    { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION DOUBLE_DOT <-enumerated\n" , no_of_lines, total, yytext);  yval.push_back(init_token(no_of_lines,total,yytext,type::PUNCTUATION));    }

[0-9]+    { total++; fprintf(yyout, "%d: #%d  \"%s\" CONST_INT %s <-integer\n", no_of_lines, total, yytext, yytext); yval.push_back(init_token(no_of_lines,total,yytext,type::CONST_INT)); }
"-"[0-9]+ { total++; fprintf(yyout, "%d: #%d  \"%s\" CONST_INT %s <-integer\n", no_of_lines, total, yytext, yytext);    yval.push_back(init_token(no_of_lines,total,yytext,type::CONST_INT));   }
[0-9]*"."[0-9]+ { total++; fprintf(yyout, "%d: #%d  \"%s\" CONST_REAL %s <-real\n", no_of_lines, total, yytext, yytext); yval.push_back(init_token(no_of_lines,total,yytext,type::CONST_REAL));  } 
[-][0-9]*"."[0-9]+ { total++; fprintf(yyout, "%d: #%d  \"%s\" CONST_REAL %s <-real\n", no_of_lines, total, yytext, yytext); yval.push_back(init_token(no_of_lines,total,yytext,type::CONST_REAL));}
^[a-zA-Z_][a-zA-Z0-9_]* { total++; fprintf(yyout, "%d: #%d  \"%s\" IDENT <-ident\n", no_of_lines, total, yytext);      yval.push_back(init_token(no_of_lines,total,yytext,type::IDENT));    }

{id} { total++; fprintf(yyout, "%d: #%d  \"%s\" ID \"%s\" <-char*\n", no_of_lines, total, yytext, yytext); yval.push_back(init_token(no_of_lines,total,yytext,type::ID)); }
{string} { total++; fprintf(yyout, "%d: #%d  %s STRING %s <-char*\n", no_of_lines, total, yytext, yytext); yval.push_back(init_token(no_of_lines,total,yytext,type::STRING)); }
{comment} { total++; fprintf(yyout, "%d: #%d   \"\" COMMENT LINE_COMMENT <-enumerated\n" , no_of_lines, total); yval.push_back(init_token(no_of_lines,total,yytext,type::COMMENT));      }

"/*"            { BEGIN(C_COMMENT); fprintf(yyout, "%d: #%d \"%d - ", no_of_lines, total, no_of_lines);}
<C_COMMENT>"*/" { BEGIN(INITIAL);   fprintf(yyout, "%d\" COMMENT  BLOCK_COMMENT  <-enumerated\n", no_of_lines); }
<C_COMMENT>.    { }
<C_COMMENT>\n   { }

. { printf("%s", yytext); }

[\t]+ /* ignore wite spaces and newlines */ 

%%

alpha_token* init_token(unsigned int numline, unsigned int numToken, string content, enum type t_type) {
    alpha_token* a = (alpha_token*) malloc(sizeof(alpha_token)); // fix this later
    a->numline = numline;
    a->numToken = numToken;
    a->content = content;
    a->token_type = t_type;
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
    cout << "Total Tokens:" << token.size() << endl;
    for(auto a : token)
        fprintf(yyout, "%d  %s", a->numline, a->content.c_str()); 
    return 0;
}