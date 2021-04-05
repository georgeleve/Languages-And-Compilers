%{
	#include <cstdio>
  	#include <iostream>
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <string.h>
  	using namespace std;

	int yyerror (char* yaccProvidedMessage);
	extern int yylineno;
	extern FILE* yyin;
	extern int yylex(void);
	extern char* yytext;
  	//extern int yyparse();
%}
%start program
%error-verbose /* print more information about errors */

%union {
	char* stringval;
	int intval;
	float floatval;
}

%token <stringval> ID;
%token <stringval> STRING;
%token <intval> INTEGER;
%token <floatval> FLOAT;
%token <stringval> IF ELSE WHILE FOR FUNCTION RETURN BREAK CONTINUE AND NOT OR LOCAL TRUE FALSE NIL
%token <stringval> ASSIGN PLUS MINUS MUL DIV MODULO EQUAL NOT_EQUAL PLUS_PLUS MINUS_MINUS GREATER LESS GREATER_EQUAL LESS_EQUAL 
%token <stringval> LEFT_BRACE RIGHT_BRACE LEFT_BRACKET RIGHT_BRACKET LEFT_PARENTH RIGHT_PARENTH SEMICOLON COMMA COLON DOUBLE_COLON DOT DOT_DOT

%type <intval> expr
%type <stringval> stmt ifstmt whilestmt forstmt returnstmt block funcdef lvalue primary call objectdef const member
%type <stringval> elist callsuffix normcall methodcall indexed indexedelem

%left ASSIGN
%left OR
%left AND
%nonassoc EQUAL NOT_EQUAL
%nonassoc GREATER GREATER_EQUAL LESS LESS_EQUAL
%left PLUS MINUS
%left MUL DIV MODULO
%right NOT PLUS_PLUS MINUS_MINUS UMINUS
%left DOT DOT_DOT
%left LEFT_BRACKET RIGHT_BRACKET
%left LEFT_PARENTH RIGHT_PARENTH


/* grammar rules (h allios legontai productions)  pou to kathe ena exei actions */  

/* This is the actual grammar that bison will parse */
%%

program: stmt program 	
	   |	{ printf("Program\n"); }
       ;

stmt: expr SEMICOLON { }
	| ifstmt { printf("IF statement\n"); }
	| whilestmt { printf("WHILE statement\n"); }
	| forstmt { printf("FOR statement\n"); }
	| returnstmt { } 
	| BREAK SEMICOLON { printf("BREAK\n"); }
	| CONTINUE SEMICOLON { printf("CONTINUE semicolon\n"); }
	| block { printf("Block\n"); }
	| funcdef { printf("Function definition\n"); }
	| SEMICOLON { printf("We saw a ;  (SEMICOLON)\n"); }
	;

expr: assignexpr { printf("Assignes expression \n"); }
	| expr PLUS expr	 {printf("expression  + expression -> %d+%d\n",$1,$3); 	$$ = $1 + $3;}
	| expr MINUS expr	 {printf("expression  - expression -> %d-%d\n",$1,$3); 	$$ = $1 - $3;}
	| expr MUL expr		 {printf("expression  * expression -> %d*%d\n",$1,$3); 	$$ = $1 * $3;}
	| expr DIV expr		 {printf("expression  / expression -> %d/%d\n",$1,$3); 	$$ = $1 / $3;}
	| expr MODULO expr		 {printf("expression %% expression -> %d %% %d\n",$1,$3); 	$$ = $1 % $3;}
	| expr GREATER expr	 {printf("expression  > expression -> %d>%d\n",$1,$3); 	$$ = ($1 > $3)?1:0;}
	| expr GREATER_EQUAL expr {printf("expression >= expression -> %d>=%d\n",$1,$3); 	$$ = ($1>=$3)?1:0;}
	| expr LESS expr	 {printf("expression  < expression -> %d<%d\n",$1,$3); 	$$ = ($1<$3)?1:0;}
	| expr LESS_EQUAL expr {printf("expression <= expression -> %d<=%d\n",$1,$3); 	$$ = ($1<=$3)?1:0;}
	| expr EQUAL expr		 {printf("expression == expression -> %d==%d\n",$1,$3); 	$$ = ($1==$3)?1:0;}
	| expr NOT_EQUAL expr	 {printf("expression != expression -> %d!=%d\n",$1,$3); 	$$ = ($1!=$3)?1:0;}
	| expr AND expr	   	 {printf("expression && expression -> %d&&%d\n",$1,$3); 	$$ = ($1&&$3)?1:0;}
	| expr OR expr		 {printf("expression || expression -> %d/%d\n",$1,$3); 	$$ = ($1||$3)?1:0;}
	| term			     {printf("Terminal\n");}
	;

term: LEFT_PARENTH expr RIGHT_PARENTH { printf(" hello world "); }
	| MINUS expr { printf(" hello world ");}
	| NOT expr { printf(" hello world "); }
	| PLUS_PLUS lvalue { printf(" hello world "); }
	| lvalue PLUS_PLUS { printf(" hello world "); }
	| MINUS_MINUS lvalue { printf(" hello world "); }
	| lvalue MINUS_MINUS { printf(" hello world "); }
	| primary { printf(" hello world "); }
	;

assignexpr: lvalue ASSIGN expr { printf(" hello world "); }
		  ;

primary: lvalue { printf(" hello world "); }
	   | call { printf(" hello world "); }
	   | objectdef { printf(" hello world "); }
	   | LEFT_PARENTH funcdef RIGHT_PARENTH { printf(" hello world "); }
	   | const { printf(" hello world "); }
	   ;

lvalue: ID { printf(" hello world "); }
	  | LOCAL ID { printf(" hello world "); }
	  | DOUBLE_COLON ID { printf(" hello world "); }
   	  | member { printf(" hello world "); }
  	  ;

member: lvalue DOT ID { printf(" hello world "); }
	  | lvalue LEFT_BRACKET expr RIGHT_BRACKET { printf(" hello world "); }
      | call DOT ID { printf(" hello world "); }
	  | call LEFT_BRACKET expr RIGHT_BRACKET { printf(" hello world "); }
   	  ;

call: call LEFT_PARENTH elist RIGHT_PARENTH { printf(" hello world "); }
	| lvalue callsuffix { printf(" hello world "); }
	| LEFT_PARENTH funcdef RIGHT_PARENTH LEFT_PARENTH elist RIGHT_BRACKET { printf(" hello world "); }
	;

callsuffix: normcall { }
		  | methodcall { }
	      ;

normcall: LEFT_PARENTH elist RIGHT_PARENTH { }
		;

methodcall: DOT_DOT ID LEFT_PARENTH elist RIGHT_PARENTH { } 
		  ;

elist: expr { printf("katiii"); }
	 | elist COMMA expr	{ printf("katiii\n");} 
	 | { printf("katiii\n"); }
	 ;

objectdef: LEFT_BRACKET elist RIGHT_BRACKET { }
		 | LEFT_BRACKET indexed RIGHT_BRACKET { } 
		 ;

indexed: indexedelem { printf("Idexedelem\n"); }
	   |indexed COMMA indexedelem { printf("indexedelem comma indexedelem\n"); }
	   ;

indexedelem: LEFT_BRACE expr COLON expr RIGHT_BRACE	{ printf("{ Expr : Expr }\n"); }
		   ;

block: LEFT_BRACE { } 
		RIGHT_BRACE { printf("{ Statement }\n") }
	 ;

tempid: ID	{ }
	  |	{ }
	  ;  

funcdef: FUNCTION tempid    { }
	   LEFT_PARENTH  { }
	   idlist
	   RIGHT_PARENTH  { }    					{} 
	   block { } 
	   ;

const:	INTEGER		{ printf("NUMBER\n");		}	 
	 | FLOAT	{ printf("REALNUMBER\n");	}
	 | STRING		{ printf("STRING\n");		}
	 | NIL			{ printf("NIL\n");			}
	 | TRUE			{ printf("TRUE\n");			}
	 | FALSE		{ printf("FALSE\n");		}
	 ;

idlist:	ID {		printf("|ID:%s\n",yytext); }
	  |idlist COMMA ID
		{	
			printf("|ID,...,ID: %s\n",yytext);
		} 
	  |	{;}
	  ;

ifstmt:	IF LEFT_PARENTH expr RIGHT_PARENTH
		{
			
		}
		stmt
		{
			
		}
	 | ifstmt ELSE
		{
			
		}
		stmt
		{
			
		}
	 ;	 

whilestmt:	WHILE  
		 {


		 }
		 LEFT_PARENTH expr RIGHT_PARENTH
		 {
		 
		 }
		 stmt
		 {
			
		 } 
		 ;  	

	
forstmt:	FOR
		{
			
		}
		LEFT_PARENTH elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTH 
		{
			
		}
		stmt
		{
			
		} 
		;	 

returnstmt:	RETURN SEMICOLON { printf("|RETURN;\n"); } 
		  | RETURN expr SEMICOLON{ printf("|RETURN EXPR;\n"); }
		  ;	 
%%

/* this will be called if we have syntax errors */
int yyerror (char* yaccProvidedMessage) {
	fprintf(stderr, "%s: at line %d, before token: %s\n", yaccProvidedMessage, yylineno, yytext);
	fprintf(stderr, "INPUT NOT VALID\n");
	cout << "EEK, parse error on line " << yylineno << "!  Message: " << s << endl;
	return 0;
}

// h main opos thn exei to front
int main(int argc, char** argv){
	if (argc > 1){
		if(!yyin = fopen(argv[1], "r"))){
			fprintf(stderr, "Error: cannot read file: %s\n", argv[1]);
			return 1;
		}
	}else{
		yyin = stdin;
	}

	yyparse(); /* Parse through the input - the function generated by yacc */
	
	fclose(yyin);
	return 0;
}