%{

int total = 0;
int no_of_lines = 1;

%}

/* Flex options */
%option noyywrap
%option yylineno
%option noyywrap

/* Flex macros */
id [a-zA-Z][a-zA-Z_0-9]*
string \"[^\n"]*\"
comment "//".*

%x C_COMMENT

%%

\n  no_of_lines++; 

[0-9]+    { total++; fprintf(yyout, "%d: #%d  \"%s\" CONST_INT %s <-integer\n", no_of_lines, total, yytext, yytext);       }
"-"[0-9]+ { total++; fprintf(yyout, "%d: #%d  \"%s\" CONST_INT %s <-integer\n", no_of_lines, total, yytext, yytext);       }
[0-9]*"."[0-9]+ { total++; fprintf(yyout, "%d: #%d  \"%s\" CONST_REAL %s <-real\n", no_of_lines, total, yytext, yytext);   } 
[-][0-9]*"."[0-9]+ { total++; fprintf(yyout, "%d: #%d  \"%s\" CONST_REAL %s <-real\n", no_of_lines, total, yytext, yytext);}
^[a-zA-Z_][a-zA-Z0-9_]* { total++; fprintf(yyout, "%d: #%d  \"%s\" IDENT <-ident\n", no_of_lines, total, yytext);          }
[A-Za-z] { total++; fprintf(yyout, "%d: #%d  \"%s\" IDENT <-ident\n", no_of_lines, total, yytext);                         }


"if"        { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD  IF <-enumerated\n", no_of_lines, total, yytext);       }
"else"      { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD  ELSE <-enumerated\n", no_of_lines, total, yytext);     }
"while"     { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD  WHILE <-enumerated\n", no_of_lines, total, yytext);    }
"for"       { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD  FOR <-enumerated\n", no_of_lines, total, yytext);      }
"function"  { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD  FUNCTION <-enumerated\n", no_of_lines, total, yytext); }
"return"    { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD  RETURN <-enumerated\n", no_of_lines, total, yytext);   }
"break"     { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD  BREAK <-enumerated\n", no_of_lines, total, yytext);    }
"continue"  { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD CONTINUE <-enumerated\n", no_of_lines, total, yytext);  }
"and"       { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD  AND <-enumerated\n", no_of_lines, total, yytext);      }
"not"       { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD  NOT <-enumerated\n", no_of_lines, total, yytext);      }
"or"        { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD  OR <-enumerated\n", no_of_lines, total, yytext);       }
"local"     { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD  LOCAL <-enumerated\n", no_of_lines, total, yytext);    }
"true"      { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD  TRUE <-enumerated\n", no_of_lines, total, yytext);     }
"false"     { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD  FALSE <-enumerated\n", no_of_lines, total, yytext);    }
"nil"       { total++; fprintf(yyout, "%d: #%d  \"%s\" KEYWORD NIL <-enumerated\n", no_of_lines, total, yytext);       }

"="	    { total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR  EQUAL <-enumerated\n", no_of_lines, total, yytext);          } 
"+"		{ total++; fprintf(yyout, "%d: #%d  \"\"%s\"\" OPERATOR  PLUS <-enumerated\n", no_of_lines, total, yytext);       }
"-"		{ total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR  MINUS <-enumerated\n", no_of_lines, total, yytext);          } 
"*"		{ total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR  MUL <-enumerated\n", no_of_lines, total, yytext);            } 
"/"		{ total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR  DIVISION <-enumerated\n", no_of_lines, total, yytext);       } 
"%"		{ total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR  PERCENTAGE <-enumerated\n", no_of_lines, total, yytext);     } 
"=="	{ total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR  EQUAL_EQUAL <-enumerated\n", no_of_lines, total, yytext);    }
"!="	{ total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR  NOTEQUAL <-enumerated\n", no_of_lines, total, yytext);       } 
"++"	{ total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR  PLUS_PLUS <-enumerated\n", no_of_lines, total, yytext);      } 
"--"	{ total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR  MINUS_MINUS <-enumerated\n", no_of_lines, total, yytext);    } 
">"		{ total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR  GREATER <-enumerated\n", no_of_lines, total, yytext);        } 
"<"		{ total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR  LESS_THAN <-enumerated\n", no_of_lines, total, yytext);      } 
">="	{ total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR  GREATER_EQUAL <-enumerated\n", no_of_lines, total, yytext);  } 
"<="	{ total++; fprintf(yyout, "%d: #%d  \"%s\" OPERATOR  LESS_EQUAL <-enumerated\n", no_of_lines, total, yytext);     } 

"{"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION RIGHT_BRACE <-enumerated\n" , no_of_lines, total, yytext);     }
"}"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION LEFT_BRACE <-enumerated\n" , no_of_lines, total, yytext);    }
"["     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION RIGHT_BRACE <-enumerated\n" , no_of_lines, total, yytext);    }
"]"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION LEFT_BRACE <-enumerated\n" , no_of_lines, total, yytext);     }
"("     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION RIGHT_BRACE <-enumerated\n" , no_of_lines, total, yytext);    }
")"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION LEFT_BRACE <-enumerated\n" , no_of_lines, total, yytext);     }
";"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION SEMICOLON <-enumerated\n" , no_of_lines, total, yytext);      }
","     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION COMMA <-enumerated\n" , no_of_lines, total, yytext);          }
":"     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION MPLAMPLA <-enumerated\n" , no_of_lines, total, yytext);       }
"::"    { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION DOUBLEMPLAMPLA <-enumerated\n" , no_of_lines, total, yytext); }
"."     { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION DOT <-enumerated\n" , no_of_lines, total, yytext);            }
".."    { total++; fprintf(yyout, "%d: #%d   \"%s\" PUNCTUATION DOUBLEDOT <-enumerated\n" , no_of_lines, total, yytext);      }

{id} { total++; fprintf(yyout, "%d: #%d  \"%s\" ID \"%s\" <-char*\n", no_of_lines, total, yytext, yytext);  }
{string} { total++; fprintf(yyout, "%d: #%d  %s STRING %s <-char*\n", no_of_lines, total, yytext, yytext);  }
{comment} { total++; fprintf(yyout, "%d: #%d   \"\" COMMENT LINE_COMMENT <-enumerated\n" , no_of_lines, total);      }

"/*"            { BEGIN(C_COMMENT); }
<C_COMMENT>"*/" { BEGIN(INITIAL); }
<C_COMMENT>.    { }
<C_COMMENT>\n   { }

. { printf("%s", yytext); }

[\t]+   /*ignore wite spaces and newlines */
[[:space:]]+; /* Ignore whitespace */

%%

/* Na ftiaxo tis diafores metaxi id kai identifier */
int main(int argc, char** argv) {
    if(argc > 1){
        if(!(yyin = fopen(argv[1], "r"))) {
            fprintf(stderr, "Cannot read file: %s\n", argv[1]);
            return 1;
        }
        yyout = fopen(argv[2], "w");
    }
    else {
        yyin = stdin; /* na tsekaro pote teleionei kai epishs na leitoyrgei otan den dino output file */
        yyout = stdout;
    }

    fprintf(yyout, "--------------------   Lexical Analysis   --------------------\n\n");
    yylex();
	/* fprintf(yyout, "\nTotal Tokens = %d", total); */
    return 0;
}

