%{

int total = 0;

%}

/* Flex options */
%option noyywrap


/* Flex macros */
id [a-zA-Z][a-zA-Z_0-9]*
string \"[^\n"]*\"
comment "//".*


%%


"if"        { total++; fprintf(yyout, "line: #%d  \"%s\" KEYWORD  IF <- enumerated\n", total, yytext);       }
"else"      { total++; fprintf(yyout, "line: #%d  \"%s\" KEYWORD  ELSE <- enumerated\n", total, yytext);     }
"while"     { total++; fprintf(yyout, "line: #%d  \"%s\" KEYWORD  WHILE <- enumerated\n", total, yytext);    }
"for"       { total++; fprintf(yyout, "line: #%d  \"%s\" KEYWORD  FOR <- enumerated\n", total, yytext);      }
"function"  { total++; fprintf(yyout, "line: #%d  \"%s\" KEYWORD  FUNCTION <- enumerated\n", total, yytext); }
"return"    { total++; fprintf(yyout, "line: #%d  \"%s\" KEYWORD  RETURN <- enumerated\n", total, yytext);   }
"break"     { total++; fprintf(yyout, "line: #%d  \"%s\" KEYWORD  BREAK <- enumerated\n", total, yytext);    }
"continue"  { total++; fprintf(yyout, "line: #%d  \"%s\" KEYWORD CONTINUE <- enumerated\n", total, yytext);  }
"and"       { total++; fprintf(yyout, "line: #%d  \"%s\" KEYWORD  AND <- enumerated\n", total, yytext);      }
"not"       { total++; fprintf(yyout, "line: #%d  \"%s\" KEYWORD  NOT <- enumerated\n", total, yytext);      }
"or"        { total++; fprintf(yyout, "line: #%d  \"%s\" KEYWORD  OR <- enumerated\n", total, yytext);       }
"local"     { total++; fprintf(yyout, "line: #%d  \"%s\" KEYWORD  LOCAL <- enumerated\n", total, yytext);    }
"true"      { total++; fprintf(yyout, "line: #%d  \"%s\" KEYWORD  TRUE <- enumerated\n", total, yytext);     }
"false"     { total++; fprintf(yyout, "line: #%d  \"%s\" KEYWORD  FALSE <- enumerated\n", total, yytext);    }
"nil"       { total++; fprintf(yyout, "line: #%d  \"%s\" KEYWORD NIL <- enumerated\n", total, yytext);       }

"="	    { total++; fprintf(yyout, "line: #%d  \"%s\" OPERATOR  EQUAL <- enumerated\n", total, yytext);          } 
"+"		{ total++; fprintf(yyout, "line: #%d  \"\"%s\"\" OPERATOR  PLUS <- enumerated\n", total, yytext);       }
"-"		{ total++; fprintf(yyout, "line: #%d  \"%s\" OPERATOR  MINUS <- enumerated\n", total, yytext);          } 
"*"		{ total++; fprintf(yyout, "line: #%d  \"%s\" OPERATOR  MUL <- enumerated\n", total, yytext);            } 
"/"		{ total++; fprintf(yyout, "line: #%d  \"%s\" OPERATOR  DIVISION <- enumerated\n", total, yytext);       } 
"%"		{ total++; fprintf(yyout, "line: #%d  \"%s\" OPERATOR  PERCENTAGE <- enumerated\n", total, yytext);     } 
"=="	{ total++; fprintf(yyout, "line: #%d  \"%s\" OPERATOR  EQUAL_EQUAL <- enumerated\n", total, yytext);    }
"!="	{ total++; fprintf(yyout, "line: #%d  \"%s\" OPERATOR  NOTEQUAL <- enumerated\n", total, yytext);       } 
"++"	{ total++; fprintf(yyout, "line: #%d  \"%s\" OPERATOR  PLUS_PLUS <- enumerated\n", total, yytext);      } 
"--"	{ total++; fprintf(yyout, "line: #%d  \"%s\" OPERATOR  MINUS_MINUS <- enumerated\n", total, yytext);    } 
">"		{ total++; fprintf(yyout, "line: #%d  \"%s\" OPERATOR  GREATER <- enumerated\n", total, yytext);        } 
"<"		{ total++; fprintf(yyout, "line: #%d  \"%s\" OPERATOR  LESS_THAN <- enumerated\n", total, yytext);      } 
">="	{ total++; fprintf(yyout, "line: #%d  \"%s\" OPERATOR  GREATER_EQUAL <- enumerated\n", total, yytext);  } 
"<="	{ total++; fprintf(yyout, "line: #%d  \"%s\" OPERATOR  LESS_EQUAL <- enumerated\n", total, yytext);     } 

"{"     { total++; fprintf(yyout, "line: #%d   \"%s\" PUNCTUATION LEFT_BRACE <- enumerated\n" , total, yytext);     }
"}"     { total++; fprintf(yyout, "line: #%d   \"%s\" PUNCTUATION RIGHT_BRACE <- enumerated\n" , total, yytext);    }
"["     { total++; fprintf(yyout, "line: #%d   \"%s\" PUNCTUATION RIGHT_BRACE <- enumerated\n" , total, yytext);    }
"]"     { total++; fprintf(yyout, "line: #%d   \"%s\" PUNCTUATION LEFT_BRACE <- enumerated\n" , total, yytext);     }
"("     { total++; fprintf(yyout, "line: #%d   \"%s\" PUNCTUATION RIGHT_BRACE <- enumerated\n" , total, yytext);    }
")"     { total++; fprintf(yyout, "line: #%d   \"%s\" PUNCTUATION LEFT_BRACE <- enumerated\n" , total, yytext);     }
";"     { total++; fprintf(yyout, "line: #%d   \"%s\" PUNCTUATION SEMICOLON <- enumerated\n" , total, yytext);      }
","     { total++; fprintf(yyout, "line: #%d   \"%s\" PUNCTUATION COMMA <- enumerated\n" , total, yytext);          }
":"     { total++; fprintf(yyout, "line: #%d   \"%s\" PUNCTUATION MPLAMPLA <- enumerated\n" , total, yytext);       }
"::"    { total++; fprintf(yyout, "line: #%d   \"%s\" PUNCTUATION DOUBLEMPLAMPLA <- enumerated\n" , total, yytext); }
"."     { total++; fprintf(yyout, "line: #%d   \"%s\" PUNCTUATION DOT <- enumerated\n" , total, yytext);            }
".."    { total++; fprintf(yyout, "line: #%d   \"%s\" PUNCTUATION DOUBLEDOT <- enumerated\n" , total, yytext);      }

[ \t]*; /*ignore wite spaces */


%%

int main(int argc, char** argv) {
    if(argc > 1){
        if(!(yyin = fopen(argv[1], "r"))) {
            fprintf(stderr, "Cannot read file: %s\n", argv[1]);
            return 1;
        }
    }
    else
        yyin = stdin; /* na tsekaro pote teleionei */
    
    
    yyout = fopen(argv[2], "w");


    fprintf(yyout, "--------------------   Lexical Analysis   --------------------\n");
    yylex();
	fprintf(yyout, "\n\n Total Tokens = %d",total);
    return 0;
}

