#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <bits/stdc++.h>

#define EXPAND_SIZE 1024
#define CURR_SIZE 	(total*sizeof(quad))
#define NEW_SIZE 	(EXPAND_SIZE*sizeof(quad)+CURR_SIZE)

unsigned total = 0;
unsigned int currQuad = 0;

int tempcounter = 0;
unsigned programVarOffset = 0;
unsigned functionLocalOffset = 0;
unsigned formalArgOffset = 0;
unsigned scopeSpaceCounter = 1;

int quadsCounter = 0;

// na valoume ta and, or , not
enum iopcode {
	assign, 	add,		sub,
	mul,		divide,		mod,
	uminus,			if_eq,		if_not_eq,
	if_lesseq,	if_greatereq,	if_less,
	if_greater,	call,		param,
	ret,		getretval,	funcstart,
	funcend,	jump,		tablecreate,
	tablegetelem,	tablesetelem
};

enum scopespace_t {
	programVar,
	functionLocal,
	formalArg
};

enum symbol_t { 
	var_s, programfunc_s, libraryfunc_s
};

enum expr_t {
	var_e,
	tableitem_e,
	programfunc_e,
	libraryfunc_e,
	arithexpr_e,
	boolexpr_e,
	assignexpr_e,
	newtable_e,
	constnum_e,
	constbool_e,
	conststring_e,
	nil_e
};

struct symbol {
	symbol_t type;                                 //to xoyme hdh
	char* name;  //dynamic string
	scopespace_t space; // originating scope scapce
	unsigned offset; // offset in scope space      //prepei na to kratame san extra pedio 
	unsigned scope; // scope value                // to xoume hdh
	unsigned line; //source line of declaration   //yylineno?
};


// create a vector that is going to store the quad
struct expr {
	expr_t			type;
	Information*	sym;
	expr*			index;
	double 			numConst;
	char*			strConst;
	unsigned char	boolConst;
	expr*			next;
};

struct quad { //maybe typedef struct quad
	iopcode op;
	expr* result;
	expr* arg1;
	expr* arg2;
	unsigned label; //int
	unsigned line; //int
};

vector<quad*> quads;


struct stmt_t {
	int breakList, contList;
};

struct call {
	expr* elist;
	unsigned char method;
	char* name;
};

void emit(iopcode op, expr *arg1, expr *arg2, expr *result, int label, int line) {
	printf("\nMphke sthn emit()\n");

	quad* q = (quad*) malloc(sizeof(quad));
	
	q->op 		= op;
	q->arg1		= arg1;
	q->arg2		= arg2;
	q->result	= result;
	q->label 	= label;
	q->line		= line;

	quadsCounter++;
	quads.push_back(q);
	// !! find how to print an enum:      https://stackoverflow.com/questions/3168306/print-text-instead-of-value-from-c-enum
	printf("\n#quad		opcode		result		arg1		arg2		label\n");
	printf("%d:	  	 %s		 %d		  %d		 %d 		%d\n\n\n", quadsCounter, op, result, arg1, arg2, label);
}

// Dimiourgoyme kainourio onoma gia tis prosorines metavlhtes
const string newtempname() { 
	return "_t" + tempcounter++;
}

void resettemp() { tempcounter = 0; }

pair<int,Information> newtemp() {
	string name = newtempname();
	pair<int,Information> sym = lookup(name);
	if (sym.first==-1){
		insertVariable(name,0);
		sym = lookup(name);
	}
	return sym;
}

expr* lvalue_expr (symbol *sym) {
	assert(sym);
	expr*  e = (expr*) malloc(sizeof(expr));
	memset(e,0,sizeof(expr));	
	e->next = (expr*) 0;
	e->sym = sym;
 
	switch(sym->type){
		//case var_s : e->type = var_s) break;
		//case programfunc_s : e->type = programfunc_e : break;
		//case libraryfunc_s : e->type = libraryfunc_e : break;
		default:assert(0);
	}
	return e;
}

scopespace_t currScopeSpace(void){
	if(scopeSpaceCounter == 1)
		return programVar;
	else if(scopeSpaceCounter % 2 == 0)
		return formalArg;
	else
		return functionLocal;
}

unsigned int currScopeOffset(void){
	switch(currScopeSpace()){
		case programVar		: return programVarOffset;
		case functionLocal	: return functionLocalOffset;
		case formalArg		: return formalArgOffset;
		default				: assert(0);
	}
}

void inCurrScopeOffset(void){
	switch(currScopeSpace()){
		case programVar 	: ++programVarOffset; break;
		case functionLocal  : ++functionLocalOffset; break;
		case formalArg 		: ++formalArgOffset; break;
		default 			: assert(0);
	}
}

void enterScopeSpace(void){
	++scopeSpaceCounter;
}

void exitScopeSpace(void){
	assert(scopeSpaceCounter > 1);
	--scopeSpaceCounter;
}

// FIX THIS FUNCTION LATER !!!!!!!!!!!!!
void distributetype(int vars, int type) {
	/*
	for each v in vars do {   
		if (v.class = pointervar) {
			v.size = 4;
		}else if (v.class = arrayvar){
			v.size = arraytotal(v.dims)*type.size;
		}else if (v.class = arraypointervar){
			v.size = arraytotal(v.dims)*4;
		}else{
			v.size = type.size;
			v.offset = getcurroffset();
			inccurroffset(v.size);
		}
		*/
}

void resetformalargoffset(){ formalArgOffset = 0; };

void resetfunctionlocaloffset(){ functionLocalOffset = 0; };


void restorecurrscopeoffset(unsigned n){
	switch(currScopeSpace()){
		case programVar		: programVarOffset = n; break;
		case functionLocal 	: functionLocalOffset = n; break;
		case formalArg 		: formalArgOffset = n; break;
		default				: assert(0);
	}
}

unsigned int nextquadlabel(void){ return currQuad; }

// FIX THIS LATER
/*
void dumparguments() {
	for (local i = 0, local n = totalarguments(); i < n; ++i) {
		printf(argument(i));
		printf("\n"); };
	}
}*/

expr* newexpr(expr_t t){
  expr* e = (expr*) malloc(sizeof(expr));
  memset(e, 0, sizeof(expr));
  e->type = t;
  return e;
}

expr* emit_iftableitem(expr* e){
	if (e->type != tableitem_e)
		return e;
	else {
		expr* result = newexpr(var_e);
		//result->sym = newtemp();
		
		//emit(tablegetelem, e, e->index, result); // do I miss some params?

		return result;
	}
}

expr* member_item (expr* lv, char* name) {
	lv = emit_iftableitem(lv); // Emit code if r-value use of table item
	expr* ti = newexpr(tableitem_e); // Make a new expression
	ti->sym = lv->sym;
	//ti->index = newexpr_conststring(name); // Const string index
	return ti;
}

expr *make_call(expr *lv, expr *reversed_elist) {
	expr *func = emit_iftableitem(lv);
	while (reversed_elist) {
		//emit(param, reversed_elist, NULL, NULL);
		reversed_elist = reversed_elist->next;
	}
	//emit(call, func, NULL, NULL);
	expr *result = newexpr(var_e);
	//result->sym = newtemp();
	//emit(getretval, NULL, NULL, result);
	return result;
}

expr *newexpr_constnum(double i) {
	expr *e = newexpr(constnum_e);
	e->numConst = i;
	return e;
}

void comperror (char* format, ...);

unsigned int istempname(char *s) { return *s == '_'; }

unsigned int istempexpr(expr *e) { return e->sym && istempname(e->sym->name); }

void patchlabel(unsigned quadNo, unsigned label) {
	assert(quadNo < currQuad && !quads[quadNo]->label);
	quads[quadNo]->label = label;
}

expr *newexpr_constbool(unsigned int b) {
	expr *e = newexpr(constbool_e);
	e->boolConst = !!b;
	return e;
}

unsigned nextquad(void) { return currQuad; }

void make_stmt(stmt_t *s) {
	s->breakList = s->contList = 0;
}

int newlist(int i) {
	quads[i]->label = 0;
	return i;
}

int mergelist(int l1, int l2) {
	if (!l1)
		return l2;
	else if (!l2)
		return l1;
	else {
		int i = l1;
		while (quads[i]->label){
			i = quads[i]->label;
		}
		quads[i]->label = l2;
		return l1;
	}
}

void patchlist(int list, int label) {
	while (list) {
		int next = quads[list]->label;
		quads[list]->label = label;
		list = next;
	}
}

// Use this function to check correct use of
// of expression in arithmetic
/*
void check_arith(expr* e, const char* context) {
	if (e->type == constbool_e ||
	e->type == conststring_e ||
	e->type == nil_e ||
	e->type == newtable_e ||
	e->type == programfunc_e ||
	e->type == libraryfunc_e ||
	e->type == boolexpr_e )
	comperror("Illegal expr used in %s!", context);
}
*/