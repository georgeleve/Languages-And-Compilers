%{
	#include "helper.h"
	int yyerror (char* yaccProvidedMessage);
	extern int yylineno;
	extern FILE* yyin;
	extern int yylex(void);
	extern char* yytext;
	extern FILE* yyout;
	
	int fID = 1;
	bool shouldInsert = true;
%}
%start program

%union {
	char* stringval;
	int intval;
	float floatval;
	struct expr* exprval;
}

%token <stringval> ID 
%token <stringval> STRING
%token <intval> INTEGER
%token <floatval> FLOAT
%token <stringval> IF ELSE WHILE FOR FUNCTION RETURN BREAK CONTINUE AND NOT OR LOCAL TRUE FALSE NIL
%token <stringval> ASSIGN PLUS MINUS MUL DIV MODULO EQUAL NOT_EQUAL PLUS_PLUS MINUS_MINUS GREATER LESS GREATER_EQUAL LESS_EQUAL 
%token <stringval> LEFT_BRACE RIGHT_BRACE LEFT_BRACKET RIGHT_BRACKET LEFT_PARENTH RIGHT_PARENTH SEMICOLON COMMA COLON DOUBLE_COLON DOT DOT_DOT

//%type <intval> expr
%type <stringval> whilestmt forstmt block
%type <stringval> temp_stmt
%type <intval> ifprefix elseprefix
%type <exprval> expr lvalue assignexpr stmt const primary term member indexedelem indexed objectdef elist returnstmt funcdef funcprefix call

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
	| expr PLUS expr	 { 
		$$ = newexpr(arithexpr_e);
		$$->sym = newtemp();
		emit(add, $$, $1, $3, -1 , yylineno);
	}
	| expr MINUS expr	 {
		$$ = newexpr(arithexpr_e);
		$$->sym = newtemp();
		emit(sub, $$, $1, $3, -1 , yylineno);
	}
	| expr MUL expr		 { 
		$$ = newexpr(arithexpr_e);
		$$->sym = newtemp();
		emit(mul, $$, $1, $3, -1 , yylineno);
	}
	| expr DIV expr		 { 
		$$ = newexpr(arithexpr_e);
		$$->sym = newtemp();
		emit(divide, $$, $1, $3, -1, yylineno);
	}
	| expr MODULO expr	 { 
		$$ = newexpr(arithexpr_e);
		$$->sym = newtemp();
		emit(mod, $$, $1, $3, -1 , yylineno);
	}
	| expr GREATER expr	 { 
		$$ = newexpr(boolexpr_e);
		$$->sym = newtemp();
		emit(if_greater, $$, $1, $3, nextQuad()+3 , yylineno);
		emit(assign, $$, newexpr_constbool(false), NULL, -1 , yylineno);
		emit(jump,NULL,NULL,NULL,nextQuad()+2, yylineno);
		emit(assign, $$, newexpr_constbool(true), NULL, -1 , yylineno);
	}
	| expr GREATER_EQUAL expr { 
		$$ = newexpr(boolexpr_e);
		$$->sym = newtemp();
		emit(if_greatereq, $$, $1, $3, nextQuad()+3 , yylineno);
		emit(assign, $$, newexpr_constbool(false), NULL, -1 , yylineno);
		emit(jump,NULL,NULL,NULL,nextQuad()+2, yylineno);
		emit(assign, $$, newexpr_constbool(true), NULL, -1 , yylineno);
	}
	| expr LESS expr	 {
		$$ = newexpr(boolexpr_e);
		$$->sym = newtemp();
		emit(if_less, $$, $1, $3, -1 , yylineno);
	}
	| expr LESS_EQUAL expr { 
		$$ = newexpr(boolexpr_e);
		$$->sym = newtemp();
		emit(if_lesseq, $$, $1, $3, -1 , yylineno);
	}
	| expr EQUAL expr		{ 
		$$ = newexpr(boolexpr_e);
		$$->sym = newtemp();
		emit(if_eq, $$, $1, $3, -1 , yylineno);
	}
	| expr NOT_EQUAL expr	 { 
		$$ = newexpr(boolexpr_e);
		$$->sym = newtemp();
		emit(if_not_eq, $$, $1, $3, -1 , yylineno);
	}
	| expr AND expr	   	 { 
		$$ = newexpr(boolexpr_e);
		$$->sym = newtemp();
		emit(and_c, $$, $1, $3, -1 , yylineno);
	}
	| expr OR expr		 { 
		$$ = newexpr(boolexpr_e);
		$$->sym = newtemp();
		emit(or_c, $$, $1, $3, -1 , yylineno);
	}
	| term 
	;

term: LEFT_PARENTH expr RIGHT_PARENTH { $$ = $2;}
	| MINUS expr { 
		check_arith($expr,"Minus");
		$$ = newexpr(arithexpr_e);
		$$->sym = newtemp();
		emit(uminus, $$, $expr, NULL, -1 , yylineno);
	}
	| NOT expr { 
		$$ = newexpr(boolexpr_e);
		$$->sym = newtemp();
		emit(not_c, $$, $expr, NULL, -1 , yylineno);
	}
	| PLUS_PLUS lvalue { 
				string var = $lvalue->sym->name;///////////////CHECK IF THIS IS VALID!!!!
				Information* scopeFound = lookupTillGlobalScope(var,true);
				if(scopeFound==NULL){
					printf("Error: %s was not found! (line %d)\n",var.c_str(),yylineno); 
				}else if(scopeFound->scope==-2){
					printf("Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
				}else {
					if(scopeFound->type == USERFUNC || scopeFound->type == LIBFUNC){
						printf("Error: Can't use increment operator on function! (line %d)\n", yylineno);
					}else{
						//else printf("Prefix increment operator at %s (line %d) at scope %d\n",var.c_str(), yylineno, scopeFound);
						if($lvalue->type == tableitem_e){
							//complete
						}else{
							emit(add, $lvalue, $lvalue, newexpr_constnum(1), -1 , yylineno);
							$$ = newexpr(arithexpr_e);
							$$->sym = newtemp();
							emit(assign, $$, $lvalue, NULL, -1 , yylineno);
						}
					}
				}
			}
	| lvalue PLUS_PLUS { 
				string var = $lvalue->sym->name;
				Information* scopeFound = lookupTillGlobalScope(var,true);
				if(scopeFound==NULL){
					printf("Error: %s was not found! (line %d)\n",var.c_str(),yylineno); 
				}else if(scopeFound->scope==-2){
					printf("Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
				}else {
					if(scopeFound->type == USERFUNC || scopeFound->type == LIBFUNC){
						printf("Error: Can't use increment operator on function! (line %d)\n", yylineno);
					} else{
						//else printf("Suffix increment operator at %s (line %d) at scope %d\n",var.c_str(), yylineno, scopeFound);
						$$ = newexpr(arithexpr_e);
						$$->sym = newtemp();
						if($lvalue->type == tableitem_e){
							//complete
						}else{
							emit(assign, $$, $lvalue, NULL, -1 , yylineno);
							emit(add, $lvalue, $lvalue, newexpr_constnum(1), -1 , yylineno);
						}	
					}
				}
			}
	| MINUS_MINUS lvalue { 
				string var = $lvalue->sym->name;
				Information* scopeFound = lookupTillGlobalScope(var,true);
				if(scopeFound==NULL){
					printf("Error: %s was not found! (line %d)\n",var.c_str(),yylineno); 
				}else if(scopeFound->scope==-2){
					printf("Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
				}else {
					if(scopeFound->type == USERFUNC || scopeFound->type == LIBFUNC){
						printf("Error: Can't use decrement operator on function! (line %d)\n", yylineno);
					}else{
						//else printf("Prefix decrement operator at %s (line %d) at scope %d\n",var.c_str(), yylineno, scopeFound);
						if($lvalue->type == tableitem_e){
							//complete
						}else{
							emit(sub, $lvalue, $lvalue, newexpr_constnum(1), -1 , yylineno);
							$$ = newexpr(arithexpr_e);
							$$->sym = newtemp();
							emit(assign, $$, $lvalue, NULL, -1 , yylineno);
						}
					}
				}
			}
	| lvalue MINUS_MINUS {
				string var = $lvalue->sym->name;
				Information* scopeFound = lookupTillGlobalScope(var,true);
				if(scopeFound==NULL){
					printf("Error: %s was not found! (line %d)\n",var.c_str(),yylineno); 
				}else if(scopeFound->scope==-2){
					printf("Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
				}else {
					if(scopeFound->type == USERFUNC || scopeFound->type == LIBFUNC){
						printf("Error: Can't use decrement operator on function! (line %d)\n", yylineno);
					} else{
						//else printf("Suffix decrement operator at %s (line %d) at scope %d\n",var.c_str(), yylineno, scopeFound);
						$$ = newexpr(arithexpr_e);
						$$->sym = newtemp();
						if($lvalue->type == tableitem_e){
							//complete
						}else{
							emit(assign, $$, $lvalue, NULL, -1 , yylineno);
							emit(sub, $lvalue, $lvalue, newexpr_constnum(1), -1 , yylineno);
						}	
					}
				}
			}
	| primary
	;

assignexpr: lvalue ASSIGN expr {
			//expr* var = $lvalue;
			string var = $1->sym->name;
			Information* scopeFound = lookupTillGlobalScope(var,true);
			//printf("playing with %s (line %d) (scopeFound: %d)\n",var.c_str(),yylineno,scopeFound.first); 
			if(scopeFound==NULL){
				printf("Error var not inserted! \n");
			}else if(scopeFound->scope==-2){
				printf("Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
			}else {
				if(scopeFound->type == USERFUNC || scopeFound->type == LIBFUNC){
					printf("Error: Can not assign value to function! (line %d)\n", yylineno);
				}else{
					if($lvalue->type == tableitem_e){
						emit(tablesetelem, $lvalue, $lvalue->index, $expr, -1, yylineno);
						$$ = emit_iftableitem($lvalue,yylineno);
						$$->type = assignexpr_e;
					}else{
						emit(assign, $lvalue, $expr, NULL, -1, yylineno);
						$assignexpr = newexpr(assignexpr_e);
						$assignexpr->sym = newtemp();
						emit(assign, $assignexpr, $lvalue, NULL, -1, yylineno);
					}
				}
			}
		}
		 | lvalue ASSIGN funcdef
		 ;
primary: lvalue {
		$$ = emit_iftableitem($lvalue,yylineno);
	}| call
	 | objectdef{
	   	$$ = $objectdef;
	 }
	   | LEFT_PARENTH funcdef RIGHT_PARENTH{$$ = $funcdef;}
	   | const
	   ;

lvalue: ID {
			string var = $1;
			//lookup without taking into account if there is function in between
			Information* search = lookupTillGlobalScope(var,false);
		
			if(search==NULL){
				//Not found at all!
				if(shouldInsert) {
					insertVariable(var, yylineno);
					//printf("%s inserted! (line %d)\n",var.c_str(),yylineno); 
				}else {
					printf("Error: %s was not found! (line %d)\n",var.c_str(),yylineno);
				}	
			}else{
				if(search->type == USERFUNC || search->type == LIBFUNC){
					//printf("We refer to the already existant function %s (line %d) at scope %d\n",var.c_str(), yylineno, scope);
				}else{
					//In this case the variable should be a variable
					search = lookupTillGlobalScope(var,true);
					if(search==NULL){
						if(shouldInsert) {
							insertVariable(var, yylineno);
							//printf("%s inserted! (line %d)\n",var.c_str(),yylineno); 
						}else {
							printf("Error: %s was not found! (line %d)\n",var.c_str(),yylineno);
						}					
					}else if(search->type==-2){
						printf("Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
					}else {
						//printf("We refer to the already existant %s (line %d) at scope %d\n",var.c_str(), yylineno, scope);
					}
				}
			}
			$$ = newexpr(var_e);
			$$->sym = lookupTillGlobalScope(var,false);
			$$->type = var_e;
			$$->sym->name = var;
		}
	  | LOCAL ID { 
			string var = $2;
			if(lookup(var)==NULL){
				if(!isSystemFunction(var)){
					if(shouldInsert) insertVariable(var,yylineno);
					//printf("%s inserted! (line %d)\n",var.c_str(),yylineno); 
				}else printf("Error: %s is a system function. (line %d)\n",var.c_str(),yylineno); 
			}//else printf("We refer to the already existant %s (line %d)\n",var.c_str(),yylineno); 
			$$ = newexpr(var_e);
			$$->sym = lookup(var);
			$$->type = var_e;
			$$->sym->name = var;
			//EDOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO an paixtei kana segmentation
		}
	  | DOUBLE_COLON ID { //This part is correct 100%
			string var = $2;
			Information* lk = globalLookup(var);
			if(lk == NULL) printf("Error: Could not find global variable %s (line %d)\n", var.c_str(), yylineno);
			else{
				$$ = newexpr(var_e);
				$$->sym = globalLookup(var);
				$$->type = var_e;
				$$->sym->name = var;
			}
		}

   	  | member
  	  ;

member: lvalue DOT ID{
		$member = member_item($lvalue, $ID, yylineno);
	}| lvalue LEFT_BRACKET expr RIGHT_BRACKET{

		$lvalue = emit_iftableitem($lvalue, yylineno);
		$$ = newexpr(tableitem_e);
		$$->sym = $lvalue->sym;
		$$->index = $expr;

	}| call DOT ID
	  | call LEFT_BRACKET expr RIGHT_BRACKET
   	  ;

call: call LEFT_PARENTH elist RIGHT_PARENTH {								//OK
		$<exprval>$ = make_call($<exprval>1, $<exprval>3, yylineno);
	}

	| lvalue LEFT_PARENTH elist RIGHT_PARENTH {
		$lvalue = emit_iftableitem($lvalue,yylineno);
		$<exprval>$ = make_call($lvalue, $elist, yylineno); 
	}

	| lvalue DOT_DOT ID LEFT_PARENTH elist RIGHT_PARENTH {
		$lvalue = emit_iftableitem($lvalue,yylineno);
		expr* t = $lvalue;
		$lvalue = emit_iftableitem(member_item(t,$ID,yylineno),yylineno);
		t->next = $elist;

		$<exprval>$ = make_call($<exprval>1, t, yylineno); 
	}

	| LEFT_PARENTH funcdef RIGHT_PARENTH LEFT_PARENTH elist RIGHT_PARENTH { //OK
		expr* func = newexpr(programfunc_e);
		func->sym = $funcdef->sym;
		$<exprval>$ = make_call(func, $<exprval>5, yylineno); 
	}
	;
elist: expr{
	$$ = $1;
}| elist COMMA expr{
	expr* tmp = $1;
	while(tmp->next!=NULL) tmp = tmp->next;
	tmp->next = $expr;
	$$ = $1;
}| {$$ = NULL;}
	 ;

objectdef: LEFT_BRACKET elist RIGHT_BRACKET{
			expr* t = newexpr(newtable_e);
			t->sym = newtemp();
			emit(tablecreate, t, NULL, NULL, -1, yylineno);
			int num = 0;
			for(expr* i = $elist; i!=NULL; i = i->next) emit(tablesetelem, t, newexpr_constnum(num++), i,-1,yylineno);
			$$ = t;

		}| LEFT_BRACKET indexed RIGHT_BRACKET{
			expr* t = newexpr(newtable_e);
			t->sym = newtemp();
			emit(tablecreate, t, NULL, NULL, -1, yylineno);
			for(expr* i = $indexed; i!=NULL; i = i->next) emit(tablesetelem, t, i->mapKey, i->mapValue,-1,yylineno);
			$$ = t;
		};

indexed: indexedelem{
	$$ = $1;
}| indexed COMMA indexedelem{
	expr* tmp = $1;
	while(tmp->next!=NULL) tmp = tmp->next;
	tmp->next = $indexedelem;
	$$ = $1;
}
;

indexedelem: LEFT_BRACE{shouldInsert = false;} expr COLON{shouldInsert = true;} expr RIGHT_BRACE{
	$$ = newexpr(mapitem_e);
	$$->mapKey = $3;
	$$->mapValue = $6;
};

temp_stmt:	temp_stmt stmt	{;} 
	| {;}
	;

block: LEFT_BRACE {increaseScope();}
	   temp_stmt{}
	   RIGHT_BRACE {decreaseScope();}
	 ;

funcdef: funcprefix {scopeSpaceIncrease();}
		LEFT_PARENTH  { enterScopeSpace(); increaseScope(); pushType(1);}
		idlist
		RIGHT_PARENTH
		LEFT_BRACE {enterScopeSpace();}
		temp_stmt
		RIGHT_BRACE {
			$funcdef = $funcprefix;
			emit(funcend, $funcprefix, NULL, NULL , -1 ,yylineno);
			exitScopeSpace(); scopeSpaceDecrease(); decreaseScope();popType();
		}
	    ;

funcprefix: FUNCTION ID{
		string fName = $2; 
		Information* lk = lookup(fName);
		if(lk != NULL){
			printf("Error: %s already declared in this scope (line %d).\n",fName.c_str(),yylineno);
		}else{
			if(isSystemFunction(fName)){
				printf("Error: %s it is already defined as a lib function. (line %d)\n",fName.c_str(),yylineno);
			} else insertUserFunction(fName, yylineno);
		}
		$$ = newexpr(programfunc_e);
		$$->sym = lookup(fName);
		$$->iaddress = nextQuad();
		emit(funcstart, $$, NULL, NULL , -1 ,yylineno);
}| FUNCTION {
		string fName = ("_f"+to_string(fID++));
		while(lookup(fName)!=NULL || isSystemFunction(fName)) fName = ("_f"+to_string(fID++));
		insertUserFunction(fName, yylineno);
		$$ = newexpr(programfunc_e);
		$$->sym = lookup(fName);
		$$->iaddress = nextQuad();
		emit(funcstart, $$, NULL, NULL , -1 ,yylineno);
};


const:	INTEGER{
			$$ = newexpr(constnum_e);
			$$->numConst = $1;
		} 
	 | FLOAT{
			$$ = newexpr(constnum_e);
			$$->numConst = $1;
		} 
	 | STRING{
			$$ = newexpr(conststring_e);
			$$->strConst = $1;
		} 
	 | NIL{
			$$ = newexpr(nil_e);
		} 
	 | TRUE{
			$$ = newexpr(constbool_e);
			$$->boolConst = true;
		} 
	 | FALSE{
			$$ = newexpr(constbool_e);
			$$->boolConst = false;
		} 
	 ;

idlist:	ID {	
			string varName = yytext; 
			Information* lk = lookup(varName);
			if(lk!=NULL){
				printf("Error: %s already declared in this scope (line %d).\n",varName.c_str(),yylineno);
			}else{
				if(isSystemFunction(varName)){
					printf("Error: %s can not be a function argument, it is a lib function. (line %d)\n",varName.c_str(),yylineno);
				} else insertArgument(varName, yylineno);
			}
		}
		|idlist COMMA ID{	
			string varName = yytext; 
			Information* lk = lookup(varName);
			if(lk!=NULL){
				printf("Error: %s already declared in this scope (line %d).\n",varName.c_str(),yylineno);
			}else{
				if(isSystemFunction(varName)){
					printf("Error: %s can not be a function argument, it is a lib function. (line %d)\n",varName.c_str(),yylineno);
				} else insertArgument(varName, yylineno);
			}
		} 
		| {}
	  ;

ifprefix: IF LEFT_PARENTH expr RIGHT_PARENTH{
		emit(if_eq, $expr, newexpr_constbool(true), NULL, nextQuad()+2, yylineno);
		$$ = nextQuad();
		printf("init type: %d\n",nextQuad());
		emit(jump,NULL, NULL, NULL, -1, yylineno);
};

elseprefix: ELSE{
	$$ = nextQuad();
	emit(jump,NULL,NULL,NULL, -1, yylineno);
};

ifstmt:	ifprefix stmt {
			printf("ints: %d %d \n",$<intval>1, nextQuad());
			patchlabel($<intval>1 ,nextQuad());
	}
	|ifprefix stmt elseprefix stmt{
		patchlabel($ifprefix , $elseprefix + 1);
		patchlabel($elseprefix , nextQuad());
	};

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

returnstmt:	RETURN SEMICOLON {
				if(!isInFunction()) {
					printf("Error: This return is not part of a function. (line %d)\n",yylineno); 
					exit(0);
				}
				emit(ret, NULL, NULL, NULL, -1, yylineno);
			}
		  | RETURN{shouldInsert = false;} expr SEMICOLON{
		   		if(!isInFunction()) {
		   			printf("Error: This return is not part of a function. (line %d)\n",yylineno); 
		   			exit(0);
		   		}
		   		emit(ret, $expr, NULL, NULL, -1, yylineno);
		   		shouldInsert = true;
			}
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
    printf("\n%-15s %-20s %-20s %-20s %-20s %-20s\n","#quad","opcode","result","arg1","arg2","label");
	initializeSymTable();
	scopeSpaceIncrease();//Inserts 0,0,0 at cur scope space
	yyparse(); /* Parse through the input - the function generated by yacc */
	printEmits();
	printFullSymTable();
	
	fclose(yyin);
    return 0;
}