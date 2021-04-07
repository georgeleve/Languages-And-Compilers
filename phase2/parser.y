%{
	#include "helper.h"

	int yyerror (char* yaccProvidedMessage);
	extern int yylineno;
	extern FILE* yyin;
	extern int yylex(void);
	extern char* yytext;
	extern FILE* yyout;
	
%}
%start program

%union {
	char* stringval;
	int intval;
	float floatval;
}

%token <stringval> ID
%token <stringval> STRING
%token <intval> INTEGER
%token <floatval> FLOAT
%token <stringval> IF ELSE WHILE FOR FUNCTION RETURN BREAK CONTINUE AND NOT OR LOCAL TRUE FALSE NIL
%token <stringval> ASSIGN PLUS MINUS MUL DIV MODULO EQUAL NOT_EQUAL PLUS_PLUS MINUS_MINUS GREATER LESS GREATER_EQUAL LESS_EQUAL 
%token <stringval> LEFT_BRACE RIGHT_BRACE LEFT_BRACKET RIGHT_BRACKET LEFT_PARENTH RIGHT_PARENTH SEMICOLON COMMA COLON DOUBLE_COLON DOT DOT_DOT

%type <intval> expr
%type <stringval> stmt ifstmt whilestmt forstmt returnstmt block funcdef lvalue primary call objectdef const member
%type <stringval> elist callsuffix normcall methodcall indexed indexedelem temp_stmt ident_temp

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
	| SEMICOLON { printf(" ; SEMICOLON\n"); }
	;

expr: assignexpr { printf("Assignes expression \n"); }
	| assignexpr_str {printf("String assign \n");}
	| expr PLUS expr	 {printf("expression  + expression -> %d+%d\n", $1, $3); 	$$ = $1 + $3;}
	| expr MINUS expr	 {printf("expression  - expression -> %d-%d\n", $1, $3); 	$$ = $1 - $3;}
	| expr MUL expr		 {printf("expression  * expression -> %d*%d\n", $1, $3); 	$$ = $1 * $3;}
	| expr DIV expr		 {printf("expression  / expression -> %d/%d\n", $1, $3); 	$$ = $1 / $3;}
	| expr MODULO expr	 {printf("expression %% expression -> %d %% %d\n", $1, $3); 	$$ = $1 % $3;}
	| expr GREATER expr	 {printf("expression  > expression -> %d>%d\n", $1, $3); 	$$ = ($1 > $3)?1:0;}
	| expr GREATER_EQUAL expr {printf("expression >= expression -> %d>=%d\n", $1, $3); 	$$ = ($1>=$3)?1:0;}
	| expr LESS expr	 {printf("expression  < expression -> %d<%d\n", $1, $3); 	$$ = ($1<$3)?1:0;}
	| expr LESS_EQUAL expr {printf("expression <= expression -> %d<=%d\n", $1, $3); 	$$ = ($1<=$3)?1:0;}
	| expr EQUAL expr		 {printf("expression == expression -> %d==%d\n", $1, $3); 	$$ = ($1==$3)?1:0;}
	| expr NOT_EQUAL expr	 {printf("expression != expression -> %d!=%d\n", $1, $3); 	$$ = ($1!=$3)?1:0;}
	| expr AND expr	   	 {printf("expression && expression -> %d&&%d\n", $1, $3); 	$$ = ($1&&$3)?1:0;}
	| expr OR expr		 {printf("expression || expression -> %d/%d\n", $1, $3); 	$$ = ($1||$3)?1:0;}
	| term			     {printf(" term: \n");}
	;

term: LEFT_PARENTH expr RIGHT_PARENTH { printf( "(" ); }
	| MINUS expr { printf(" - ");}
	| NOT expr { printf(" != "); }
	| PLUS_PLUS lvalue { printf(" ++lvalue "); }
	| lvalue PLUS_PLUS { printf(" lvalue++ "); }
	| MINUS_MINUS lvalue { printf(" --lvalue "); }
	| lvalue MINUS_MINUS { printf(" lvalue-- "); }
	| primary { printf(" primary "); }
	;

assignexpr_str: ID ASSIGN STRING {
				string var = $1;
				string toAssign = $3;
				printf(" BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB: %s",var.c_str());
				if(lookup(var)){
					printf(" ITS ALREADY IN\n");
				}else{
					insert(var, LOC, yylineno);
					printf("assigned %s ",var.c_str());
				}
	   	 }
		 | LOCAL ID ASSIGN STRING {
				string var = $2;
				string toAssign = $4;
				printf(" BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB: %s",var.c_str());
				if(lookup(var)){
					printf(" ITS ALREADY IN\n");
				}else{
					insert(var, LOC, yylineno);
					printf("assigned %s ",var.c_str());
				}
	   	 }
		 | DOUBLE_COLON ID ASSIGN STRING {
				string var = $1;
				string toAssign = $3;
				printf(" BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB: %s",var.c_str());
				if(lookup(var)){
					printf(" ITS ALREADY IN\n");
				}else{
					insert(var, LOC, yylineno);
					printf("assigned %s ",var.c_str());
				}
	   	 }
		 ;
		 
assignexpr: ID ASSIGN expr {
				string var = $1;
				printf(" AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA: %s",var.c_str());
				if(lookup(var)){
					printf(" ITS ALREADY IN\n");
				}else{
					insert(var, LOC, yylineno);
					printf("assigned %s ",var.c_str());
				}
	   	 }
		 | LOCAL ID ASSIGN expr { 
				string var = $2;
				printf(" AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA: %s",var.c_str());
				if(lookup(var)){
					printf(" ITS ALREADY IN\n");
				}else{
					insert(var, LOC, yylineno);
					printf("assigned %s ",var.c_str());
				}
	   	 }
		 | DOUBLE_COLON ID ASSIGN expr { 
				string var = $2;
				printf(" AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA: %s",var.c_str());
				if(lookup(var)){
					printf(" ITS ALREADY IN\n");
				}else{
					insert(var, LOC, yylineno);
					printf("assigned %s ",var.c_str());
				}
	   	 }
		 ;

primary: lvalue { printf(" lvalue %s", $1); }
	   | call { printf(" call "); }
	   | objectdef { printf(" objectdef "); }
	   | LEFT_PARENTH funcdef RIGHT_PARENTH { printf(" LEFT_PARENTH funcdef RIGHT_PARENTH "); }
	   | const { printf(" const "); }
	   ;

lvalue: ID { printf(" ID UPDATEDDDDDDDDDDDDDDDDDDDDDDDDDDDD "); }
	  | LOCAL ID { string var = $2; printf(" LOCAL ID -------------------------------------- %s",var.c_str()); }
	  | DOUBLE_COLON ID { printf(" DOUBLE_COLON ID "); }
   	  | member { printf(" member "); }
  	  ;

member: lvalue DOT ID { printf(" lvalue DOT ID "); }
	  | lvalue LEFT_BRACKET expr RIGHT_BRACKET { printf(" lvalue LEFT_BRACKET expr RIGHT_BRACKET "); }
      | call DOT ID { printf(" call DOT ID "); }
	  | call LEFT_BRACKET expr RIGHT_BRACKET { printf("call LEFT_BRACKET expr RIGHT_BRACKET "); }
   	  ;

call: call LEFT_PARENTH elist RIGHT_PARENTH { printf(" call LEFT_PARENTH elist RIGHT_PARENTH "); }
	| lvalue callsuffix { printf("  lvalue callsuffix "); }
	| LEFT_PARENTH funcdef RIGHT_PARENTH LEFT_PARENTH elist RIGHT_BRACKET { printf("LEFT_PARENTH funcdef RIGHT_PARENTH LEFT_PARENTH elist RIGHT_BRACKET"); }
	;

callsuffix: normcall { printf(" "); }
		  | methodcall { printf(" "); }
	      ;

normcall: LEFT_PARENTH elist RIGHT_PARENTH { printf("normcall "); }
		;

methodcall: DOT_DOT ID LEFT_PARENTH elist RIGHT_PARENTH { printf(" methodcall "); } 
		  ;

elist: expr { printf("elist"); }
	 | elist COMMA expr	{ printf("elist\n");} 
	 | { printf("elist\n"); }
	 ;

objectdef: LEFT_BRACKET elist RIGHT_BRACKET { printf(" objectdef ");  }
		 | LEFT_BRACKET indexed RIGHT_BRACKET { printf(" ");  } 
		 ;

indexed: indexedelem { printf("Idexedelem\n"); }
	   |indexed COMMA indexedelem { printf("indexedelem comma indexedelem\n"); }
	   ;

indexedelem: LEFT_BRACE expr COLON expr RIGHT_BRACE	{ printf("  indexed  { Expr : Expr }\n"); }
		   ;

temp_stmt:	temp_stmt stmt	{;} 
	| {;}
	;

block: LEFT_BRACE {increaseScope(); printf("Scope increased\n");}
	   temp_stmt{}
	   RIGHT_BRACE { printf("{ Statement }\n"); decreaseScope();printf("Scope decreased\n");}
	 ;
	 
funcdef: FUNCTION ID { 
			string fName = $2; 
			if(generalLookup(fName)){
				printf("THIS PIECE ALREADY EXISTS! \n");
			}else{
				insert(yytext, USERFUNC, yylineno);
				printf("Function got into the HASHTABLEEEEEEE! \n");
			}
		}
		LEFT_PARENTH  { printf(" LEFT_PARENTH "); increaseScope();}
		idlist
		{}
		RIGHT_PARENTH  { printf(" RIGHT_PARENTH "); decreaseScope(); }
		block { printf(" block ");  } 
	    ;

const:	INTEGER		{ printf("integer\n");		}	 
	 | FLOAT	{ printf("float\n");	}
	 | STRING		{ printf("string\n");		}
	 | NIL			{ printf("nil\n");			}
	 | TRUE			{ printf("true\n");			}
	 | FALSE		{ printf("false\n");		}
	 ;

idlist:	ID 					{	
			printf("|ID:%s\n",yytext); 
			string varName = yytext; 
			if(generalLookup(varName)){
				printf("THIS PIECE ALREADY EXISTS! \n");
			}else{
				insert(yytext, FORMAL, yylineno);
				printf("Var got deep inside the HASHTABLEEEEEEE \n");
			}
		}
		|idlist COMMA ID	{	
			printf("|ID,...,ID: %s\n",yytext);
			string varName = yytext; 
			if(generalLookup(varName)){
				printf("THIS PIECE ALREADY EXISTS! \n");
			}else{
				insert(yytext, FORMAL, yylineno);
				printf("Var got deep inside my ass! \n");
			}
		} 
	  |	{}
	  ;

ifstmt:	IF LEFT_PARENTH expr RIGHT_PARENTH
		{
			printf("if(expr)");
		}
		stmt
		{
			printf("if stmt"); 
		}
	 | ifstmt ELSE
		{
			printf("else"); 
		}
		stmt
		{
			printf("else stmt"); 
		}
	 ;	 

whilestmt:	WHILE  
		 {
			 printf(" WHILE "); 
		 }
		 LEFT_PARENTH expr RIGHT_PARENTH
		 {
			 printf(" (expr) "); 
		 }
		 stmt
		 {
			printf(" while stmt "); 
		 } 
		 ;  	

	
forstmt:	FOR
		{
			printf(" for "); 
		}
		LEFT_PARENTH elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTH 
		{
			printf(" ( ; ; )"); 
		}
		stmt
		{
			printf(" for stmt "); 
		} 
		;	 

returnstmt:	RETURN SEMICOLON { printf("RETURN;\n"); } 
		  | RETURN expr SEMICOLON{ printf("RETURN EXPR;\n"); }
		  ;	 
%%

/* this will be called if we have syntax errors */
int yyerror (char* yaccProvidedMessage) {
	fprintf(stderr, "%s: at line %d, before token: %s\n", yaccProvidedMessage, yylineno, yytext);
	fprintf(stderr, "INPUT NOT VALID\n");
	cout << "EEK, parse error on line " << yylineno << "!  Message: " << yaccProvidedMessage << endl;
	return 0;
}

int main(int argc, char** argv) {
    if(argc<2 || argc>3){
        fprintf(stderr, "Invalid arguments! Usage: ./calc input.txt (output.txt)\n");
        return 1;
    }
    if(!(yyin = fopen(argv[1], "r"))) {
        fprintf(stderr, "Cannot open input file: %s\n", argv[1]);
        return 1;
    }
	yyout = stdout;
    if(argc==3){
        if(!(yyout = fopen(argv[2], "w"))) {
            fprintf(stderr, "Cannot create output file: %s\n", argv[2]);
            return 1;
        }
    }
	initializeSymTable();
	yyparse(); /* Parse through the input - the function generated by yacc */
	
	printFullSymTable();
	
	fclose(yyin);
    return 0;
}