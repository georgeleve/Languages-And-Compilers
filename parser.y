%{
	#include <stdio.h>
	#include <stdlib.h>
	int yyerror (char* yaccProvidedMessage);
	int yylex(void);

	extern int yylineno;
	extern char* yytext;
	extern FILE* yyin;
%}

%start program

/* Token Types Union */
%union {
	char* stringValue;
	int intValue;
}

/* Rest of the tokens */

%token <stringValue>	ID
%token <intValue>		INTEGER

%right '='
%left '+' '-'
%left '*' '/'
%right UMINUS
%left '(' ')'

%type <intValue> expression

%destructor { free($$); } ID

/* APO EDO */
%token ID INTEGER
%right '='
%left ','
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS
%left '(' ')'
/* MEXRI EDO  ISOS NA TA SBHSOUME argotera */


%%

program: assignments expressions {;}
	 | /* empty */  {;}
	 ;

expression:		INTEGER  						{ $$ = $1; }
				| ID	 						{ $$ = lookup($1); free($1); }
				| expression '+' expression		{ $$ = $1 + $3; }
				| expression '-' expression		{ $$ = $1 - $3; }
				| expression '*' expression		{ $$ = $1 * $3; }
				| expression '/' expression		{ $$ = $1 / $3; }
				| '(' expression ')'			{ $$ = $2; }
				| '-' expression %prec UMINUS   { $$ = -$2; }
				;

expr:	expression ';' { fprintf(stdout, "Result is: %d\n", $1); }

expr:	expression ';' { fprintf(stdout, "Result is: %d\n", $1); }
		| error ';' { yyerrok; }
		;

expressions: expression expr {;}
	     | expr {;}
	     ;

assignment: ID '=' expression ';' { assign($1, $3); }
	     ;

assignments:  assignments assignment {;}
	     | /* empty */ {;}
	     ;



%%


int yyerror (char* yaccProvidedMessage) {
	fprintf(stderr, "%s: at line %d, before token: %s\n", yaccProvidedMessage, yylineno, yytext);
	fprintf(stderr, "INPUT NOT VALID\n");
}
 
int main(int argc, char** argv){
	if (argc > 1){
		if(!yyin = fopen(argv[1], "r"))){
			fprintf(stderr, "Cannot read file: %s\n", argv[1]);
			return 1;
		}
	}else{
		yyin = stdin;
	}

	yyparse();
	return 0;
}