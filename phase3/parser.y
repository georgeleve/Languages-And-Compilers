%{
	#include "helper.h"
	//#include "functions.h"
	int yyerror (char* yaccProvidedMessage);
	extern int yylineno;
	extern FILE* yyin;
	extern int yylex(void);
	extern char* yytext;
	extern FILE* yyout;
	
	int fID = 1;
	bool shouldInsert = true;
	bool insideCall = false;
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
%type <stringval> elist callsuffix normcall methodcall indexed indexedelem temp_stmt

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
	| BREAK SEMICOLON{
		if(!isLastTypeLoop()) printf("ERROR: No loop found in this scope. (line %d)\n",yylineno);
	}
	| CONTINUE SEMICOLON{
		if(!isLastTypeLoop()) printf("ERROR: No loop found in this scope. (line %d)\n",yylineno);
	}
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
	| expr GREATER expr	 { $$ = ($1 > $3)?1:0; }
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
	| PLUS_PLUS lvalue { 
				string var = $2;
				pair<int,Information> scopeFound = lookupTillGlobalScope(var,true);
				if(scopeFound.first==-1){
					printf("Error: %s was not found! (line %d)\n",var.c_str(),yylineno); 
				}else if(scopeFound.first==-2){
					printf("Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
				}else {
					if(scopeFound.second.type == USERFUNC || scopeFound.second.type == LIBFUNC){
						printf("Error: Can't use increment operator on function! (line %d)\n", yylineno);
					} //else printf("Prefix increment operator at %s (line %d) at scope %d\n",var.c_str(), yylineno, scopeFound);
				}
			}
	| lvalue PLUS_PLUS { 
				string var = $1;
				pair<int,Information> scopeFound = lookupTillGlobalScope(var,true);
				if(scopeFound.first==-1){
					printf("Error: %s was not found! (line %d)\n",var.c_str(),yylineno); 
				}else if(scopeFound.first==-2){
					printf("Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
				}else {
					if(scopeFound.second.type == USERFUNC || scopeFound.second.type == LIBFUNC){
						printf("Error: Can't use increment operator on function! (line %d)\n", yylineno);
					} //else printf("Suffix increment operator at %s (line %d) at scope %d\n",var.c_str(), yylineno, scopeFound);
				}
			}
	| MINUS_MINUS lvalue { 
				string var = $2;
				pair<int,Information> scopeFound = lookupTillGlobalScope(var,true);
				if(scopeFound.first==-1){
					printf("Error: %s was not found! (line %d)\n",var.c_str(),yylineno); 
				}else if(scopeFound.first==-2){
					printf("Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
				}else {
					if(scopeFound.second.type == USERFUNC || scopeFound.second.type == LIBFUNC){
						printf("Error: Can't use decrement operator on function! (line %d)\n", yylineno);
					} //else printf("Prefix decrement operator at %s (line %d) at scope %d\n",var.c_str(), yylineno, scopeFound);
				}
			}
	| lvalue MINUS_MINUS {
				string var = $2;
				pair<int,Information> scopeFound = lookupTillGlobalScope(var,true);
				if(scopeFound.first==-1){
					printf("Error: %s was not found! (line %d)\n",var.c_str(),yylineno); 
				}else if(scopeFound.first==-2){
					printf("Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
				}else {
					if(scopeFound.second.type == USERFUNC || scopeFound.second.type == LIBFUNC){
						printf("Error: Can't use decrement operator on function! (line %d)\n", yylineno);
					} //else printf("Suffix decrement operator at %s (line %d) at scope %d\n",var.c_str(), yylineno, scopeFound);
				}
			}
	| primary
	;

assignexpr: ID ASSIGN expr { //This should be correct - This part is done
			string var = $1;
			pair<int,Information> scopeFound = lookupTillGlobalScope(var,true);
			//printf("playing with %s (line %d) (scopeFound: %d)\n",var.c_str(),yylineno,scopeFound.first); 
			if(scopeFound.first==-1){
				insertVariable(var, yylineno);
				//printf("%s inserted! (line %d)\n",var.c_str(),yylineno); 
			}else if(scopeFound.first==-2){
				printf("Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
			}else {
				if(scopeFound.second.type == USERFUNC || scopeFound.second.type == LIBFUNC){
					printf("Error: Can not assign value to function! (line %d)\n", yylineno);
				} //else printf("We refer to the already existant %s (line %d) at scope %d\n",var.c_str(), yylineno, scope);
			}
		}
		 | LOCAL ID ASSIGN expr {
			string var = $2;
			pair<int,Information> lk = lookup(var);
			if(lk.first==-1){
				if(!isSystemFunction(var)){
					insertVariable(var,yylineno);
					//printf("%s inserted! (line %d)\n",var.c_str(),yylineno); 
				}else printf("Error: %s is a system function. (line %d)\n",var.c_str(),yylineno); 
			}else {
				if(lk.second.type == USERFUNC || lk.second.type == LIBFUNC){
					printf("Error: Can not assign value to function! (line %d)\n",yylineno);
				} //else printf("We refer to the already existant %s (line %d)\n",var.c_str(),yylineno);
			}
	   	 }
		 | DOUBLE_COLON ID ASSIGN expr { 
				string var = $2;
				pair<int,Information> lk = globalLookup(var);
				if(lk.first!=-1){
					if(lk.second.type == USERFUNC || lk.second.type == LIBFUNC){
						printf("Error: Can not assign value to function! (line %d)\n",yylineno);
					} //else printf("We refer to the global %s (line %d)\n",var.c_str(),yylineno);
				}else{
					printf("Error: Could not find a global variable/function %s (line %d)\n",var.c_str(),yylineno);
				}
	   	 }
		 | ID ASSIGN funcdef
		 | LOCAL ID ASSIGN funcdef
		 | DOUBLE_COLON ID ASSIGN funcdef
		 | member ASSIGN expr
		 ;

primary: lvalue
	   | call
	   | objectdef
	   | LEFT_PARENTH funcdef RIGHT_PARENTH
	   | const
	   ;

lvalue: ID {
			string var = $1;
			//lookup without taking into account if there is function in between
			pair<int,Information> search = lookupTillGlobalScope(var,false);
		
			if(search.first==-1){
				//Not found at all!
				if(shouldInsert) {
					insertVariable(var, yylineno);
					//printf("%s inserted! (line %d)\n",var.c_str(),yylineno); 
				}else {
					printf("Error: %s was not found! (line %d)\n",var.c_str(),yylineno);
				}	
			}else{
				if(search.second.type == USERFUNC || search.second.type == LIBFUNC){
					printf("We refer to the already existant function %s (line %d) at scope %d\n",var.c_str(), yylineno, scope);
				}else{
					//In this case the variable should be a variable
					search = lookupTillGlobalScope(var,true);
					if(search.first==-1){
						if(shouldInsert) {
							insertVariable(var, yylineno);
							//printf("%s inserted! (line %d)\n",var.c_str(),yylineno); 
						}else {
							printf("Error: %s was not found! (line %d)\n",var.c_str(),yylineno);
						}					
					}else if(search.first==-2){
						printf("Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
					}else {
						printf("We refer to the already existant %s (line %d) at scope %d\n",var.c_str(), yylineno, scope);
					}
				}
			}
			/*
			
			sym = lookup(id.name);
			if (sym == nul) { sym = newsymbol(id.name);
!!!!!!!!!   sym.space = currscopespace();
			sym.offset = currscopeoffset();
			inccurrscopeoffset();
			} lvalue.sval = lvalue_expr(sym);

		   */
			
		}
	  | LOCAL ID { //This part is correct 100%
			string var = $2;
			if(lookup(var).first==-1){
				if(!isSystemFunction(var)){
					if(shouldInsert) insertVariable(var,yylineno);
					//printf("%s inserted! (line %d)\n",var.c_str(),yylineno); 
				}else printf("Error: %s is a system function. (line %d)\n",var.c_str(),yylineno); 
			}//else printf("We refer to the already existant %s (line %d)\n",var.c_str(),yylineno); 
		
		}
	  | DOUBLE_COLON ID { //This part is correct 100%
			string var = $2;
			pair<int,Information> lk = globalLookup(var);
			if(lk.first==-1)
				printf("Error: Could not find global variable %s (line %d)\n", var.c_str(), yylineno);
			//else printf("We refer to the already existant global %s (line %d)\n", var.c_str(), yylineno); 
		}

   	  | member
  	  ;

member: lvalue DOT ID
	  | lvalue LEFT_BRACKET expr RIGHT_BRACKET
      | call DOT ID
	  | call LEFT_BRACKET expr RIGHT_BRACKET
   	  ;

call: call LEFT_PARENTH elist RIGHT_PARENTH
	| lvalue callsuffix;
	| LEFT_PARENTH funcdef RIGHT_PARENTH LEFT_PARENTH elist RIGHT_PARENTH
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

indexedelem: LEFT_BRACE{shouldInsert = false;} expr COLON{shouldInsert = true;} expr RIGHT_BRACE
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
			pair<int,Information> lk = lookup(fName);
			if(lk.first!=-1){
				printf("Error: %s already declared in this scope (line %d).\n",fName.c_str(),yylineno);
			}else{
				if(isSystemFunction(fName)){
					printf("Error: %s it is already defined as a lib function. (line %d)\n",fName.c_str(),yylineno);
				} else insertUserFunction(fName, yylineno);
			}
		}
		LEFT_PARENTH  { increaseScope(); pushType(1);}
		idlist
		RIGHT_PARENTH
		LEFT_BRACE
		temp_stmt
		RIGHT_BRACE {decreaseScope();popType();}
		| FUNCTION { 
			string fName = ("_f"+to_string(fID++));
			while(lookup(fName).first!=-1 || isSystemFunction(fName)) fName = ("_f"+to_string(fID++));
			insertUserFunction(fName, yylineno);
			//printf("Inserted function with name %s\n", fName.c_str());
		}
		LEFT_PARENTH  { increaseScope(); pushType(1);}
		idlist
		RIGHT_PARENTH
		LEFT_BRACE
		temp_stmt
		RIGHT_BRACE {decreaseScope();popType();}
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
				printf("Error: %s already declared in this scope (line %d).\n",varName.c_str(),yylineno);
			}else{
				if(isSystemFunction(varName)){
					printf("Error: %s can not be a function argument, it is a lib function. (line %d)\n",varName.c_str(),yylineno);
				} else insertArgument(varName, yylineno);
			}
		}
		|idlist COMMA ID	{	
			string varName = yytext; 
			pair<int,Information> lk = lookup(varName);
			if(lk.first!=-1){
				printf("Error: %s already declared in this scope (line %d).\n",varName.c_str(),yylineno);
			}else{
				if(isSystemFunction(varName)){
					printf("Error: %s can not be a function argument, it is a lib function. (line %d)\n",varName.c_str(),yylineno);
				} else insertArgument(varName, yylineno);
			}
		} 
		| {}
	  ;

ifstmt:	IF LEFT_PARENTH expr RIGHT_PARENTH
		{
			//printf("if(expr)");
		}
		stmt
		{
			//printf("if stmt"); 
		}
	 | ifstmt ELSE
		{
			//printf("else"); 
		}
		stmt
		{
			//printf("else stmt"); 
		}
	 ;	 

whilestmt:	WHILE  
		 {
			 pushType(0);
		 }
		 LEFT_PARENTH expr RIGHT_PARENTH
		 {
		 }
		 stmt
		 {
			popType();
		 } 
		 ;  	

	
forstmt:	FOR
		{
			pushType(0);
		}
		LEFT_PARENTH elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTH 
		{
		}
		stmt
		{
			popType();
		} 
		;	 

returnstmt:	RETURN SEMICOLON {if(!isInFunction()) printf("Error: This return is not part of a function. (line %d)\n",yylineno); }
		  | RETURN{shouldInsert = false;} expr SEMICOLON{ if(!isInFunction()) printf("Error: This return is not part of a function. (line %d)\n",yylineno); shouldInsert = true;}
		  ;	 
%%

/* this will be called if we have syntax errors */
int yyerror (char* yaccProvidedMessage) {
	fprintf(stderr, "%s: at line %d, before token: %s\n", yaccProvidedMessage, yylineno, yytext);
	fprintf(stderr, "INPUT NOT VALID\n");
	cout << "Error: parse error on line " << yylineno << "!  Message: " << yaccProvidedMessage << endl;
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