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
	   |	{}
       ;

stmt: expr SEMICOLON
	| ifstmt 
	| whilestmt 
	| forstmt 
	| returnstmt 
	| BREAK SEMICOLON
	| CONTINUE SEMICOLON
	| block
	| funcdef
	| SEMICOLON
	;

expr: assignexpr
	| expr PLUS expr	 {$$ = $1 + $3;}
	| expr MINUS expr	 {$$ = $1 - $3;}
	| expr MUL expr		 {$$ = $1 * $3;}
	| expr DIV expr		 {$$ = $1 / $3;}
	| expr MODULO expr	 {$$ = $1 % $3;}
	| expr GREATER expr	 {$$ = ($1 > $3)?1:0;}
	| expr GREATER_EQUAL expr {$$ = ($1>=$3)?1:0;}
	| expr LESS expr	 {$$ = ($1<$3)?1:0;}
	| expr LESS_EQUAL expr {$$ = ($1<=$3)?1:0;}
	| expr EQUAL expr		 {$$ = ($1==$3)?1:0;}
	| expr NOT_EQUAL expr	 {$$ = ($1!=$3)?1:0;}
	| expr AND expr	   	 {$$ = ($1&&$3)?1:0;}
	| expr OR expr		 {$$ = ($1||$3)?1:0;}
	| term
	;

term: LEFT_PARENTH expr RIGHT_PARENTH { printf( "(" ); }
	| MINUS expr { printf(" - ");}
	| NOT expr { printf(" != "); }
	| PLUS_PLUS lvalue { printf(" ++lvalue "); }
	| lvalue PLUS_PLUS { printf(" lvalue++ "); }
	| MINUS_MINUS lvalue { printf(" --lvalue "); }
	| lvalue MINUS_MINUS { printf(" lvalue-- "); }
	| primary
	;

assignexpr: ID ASSIGN expr { //This should be correct - This part is done
			string var = $1;
			pair<int,Information> scopeFound = lookupTillGlobalScope(var);
			printf("playing with %s (line %d) (scopeFound: %d)\n",var.c_str(),yylineno,scopeFound.first); 
			if(scopeFound.first==-1){
				insertVariable(var, yylineno);
				printf("%s inserted! (line %d)\n",var.c_str(),yylineno); 
			}else if(scopeFound.first==-2){
				printf("%s is not accessible! (line %d)\n",var.c_str(),yylineno); 
			}else {
				if(scopeFound.second.type == USERFUNC || scopeFound.second.type == LIBFUNC){
					printf("Can not assign value to function! (line %d)\n",yylineno);
				} else printf("We refer to the already existant %s (line %d) at scope %d\n",var.c_str(),yylineno,scopeFound);
			}
		}
		 | LOCAL ID ASSIGN expr {
			string var = $2;
			pair<int,Information> lk = lookup(var);
			if(lk.first==-1){
				if(!isSystemFunction(var)){
					insertVariable(var,yylineno);
					printf("%s inserted! (line %d)\n",var.c_str(),yylineno); 
				}else printf("%s is a system function.\n (line %d)",var.c_str(),yylineno); 
			}else {
				if(lk.second.type == USERFUNC || lk.second.type == LIBFUNC){
					printf("Can not assign value to function! (line %d)\n",yylineno);
				} else printf("We refer to the already existant %s (line %d)\n",var.c_str(),yylineno);
			}
	   	 }
		 | DOUBLE_COLON ID ASSIGN expr { 
				string var = $2;
				pair<int,Information> lk = globalLookup(var);
				if(lk.first!=-1){
					if(lk.second.type == USERFUNC || lk.second.type == LIBFUNC){
						printf("Can not assign value to function! (line %d)\n",yylineno);
					} else printf("We refer to the global %s (line %d)\n",var.c_str(),yylineno);
				}else{
					printf("Could not find a global variable/function %s (line %d)\n",var.c_str(),yylineno);
				}
	   	 }
		 ;

primary: lvalue
	   | call
	   | objectdef
	   | LEFT_PARENTH funcdef RIGHT_PARENTH
	   | const
	   
	   
	   
	   
	   ;

lvalue: ID
	  | LOCAL ID { //This part is correct 100%
			string var = $2;
			if(lookup(var).first==-1){
				if(!isSystemFunction(var)){
					insertVariable(var,yylineno);
					printf("%s inserted! (line %d)\n",var.c_str(),yylineno); 
				}else printf("%s is a system function.\n (line %d)",var.c_str(),yylineno); 
			}else printf("We refer to the already existant %s (line %d)\n",var.c_str(),yylineno); 
		
		}
	  | DOUBLE_COLON ID { //This part is correct 100%
			string var = $2;
			pair<int,Information> lk = globalLookup(var);
			if(lk.first!=-1){
				printf("Could not find global variable: %s (line %d)\n",var.c_str(),yylineno);
			}else printf("We refer to the already existant global %s (line %d)\n",var.c_str(),yylineno); 
		}
   	  | member
  	  ;

member: lvalue DOT ID
	  | lvalue LEFT_BRACKET expr RIGHT_BRACKET
      | call DOT ID
	  | call LEFT_BRACKET expr RIGHT_BRACKET
   	  ;

call: call LEFT_PARENTH elist RIGHT_PARENTH
	| lvalue callsuffix
	| LEFT_PARENTH funcdef RIGHT_PARENTH LEFT_PARENTH elist RIGHT_BRACKET
	;

callsuffix: normcall
		  | methodcall
	      ;

normcall: LEFT_PARENTH elist RIGHT_PARENTH
		;

methodcall: DOT_DOT ID LEFT_PARENTH elist RIGHT_PARENTH 
		  ;

elist: expr
	 | elist COMMA expr
	 | {}
	 ;

objectdef: LEFT_BRACKET elist RIGHT_BRACKET
		 | LEFT_BRACKET indexed RIGHT_BRACKET
		 ;

indexed: indexedelem
	   |indexed COMMA indexedelem 
	   ;

indexedelem: LEFT_BRACE expr COLON expr RIGHT_BRACE
		   ;

temp_stmt:	temp_stmt stmt	{;} 
	| {;}
	;

block: LEFT_BRACE {increaseScope();}
	   temp_stmt{}
	   RIGHT_BRACE {decreaseScope();}
	 ;
	 
funcdef: FUNCTION ID { 
			string fName = $2; 
			pair<int,Information> lk = generalLookup(fName);
			if(lk.first!=-1){
				printf("%s already declared in this scope (line %d).\n",fName.c_str(),yylineno);
			}else{
				insertUserFunction(yytext, yylineno);
			}
		}
		LEFT_PARENTH  { increaseScope();}
		idlist
		RIGHT_PARENTH
		LEFT_BRACE
		temp_stmt
		RIGHT_BRACE {decreaseScope();}
	    ;

const:	INTEGER
	 | FLOAT
	 | STRING
	 | NIL
	 | TRUE
	 | FALSE
	 ;

idlist:	ID 					{	
			string varName = yytext; 
			pair<int,Information> lk = lookup(varName);
			if(lk.first!=-1){
				printf("%s already declared in this scope (line %d).\n",varName.c_str(),yylineno);
			}else{
				if(isSystemFunction(varName)){
					printf("%s can not be a function argument, it is a lib function. (line %d)\n",varName.c_str(),yylineno);
				} else insertArgument(varName, yylineno);
			}
		}
		|idlist COMMA ID	{	
			string varName = yytext; 
			pair<int,Information> lk = lookup(varName);
			if(lk.first!=-1){
				printf("%s already declared in this scope (line %d).\n",varName.c_str(),yylineno);
			}else{
				if(isSystemFunction(varName)){
					printf("%s can not be a function argument, it is a lib function. (line %d)\n",varName.c_str(),yylineno);
				} else insertArgument(varName, yylineno);
			}
		} 
		| {}
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