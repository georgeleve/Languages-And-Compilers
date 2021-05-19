#include <assert.h>
#include <stdio.h>
#include <string.h>
#include<stdlib.h> 

#define EXPAND_SIZE 1024
#define CURR_SIZE 	(total*sizeof(quad))
#define NEW_SIZE 	(EXPAND_SIZE*sizeof(quad)+CURR_SIZE)

quad* quads = (quad*) 0;
unsigned total = 0;
unsigned int currQuad = 0;

int tempcounter = 0;

void newtempname() { return "_t" + tempcounter; }

void resettemp() { tempcounter = 0; }

void newtemp() {
	name = newtempname();
	sym = lookup(name, currscope());
	
	if (sym = nil)
		return newsymbol(name);
	else
		return sym;
}

expr* lvalue_expr (symbol *sym) {
	assert(sym);
	expr*  e = (expr*) malloc(sizeof(expr));
	memset(e,0,sizeof(expr));	
	e->next = (expr*) 0;
	e->sym = sym;
 
	switch(sym->type){
		case var_s : e->type = var)e; break;
		case programfunc_s : e->type = programfunc_e : break;
		case libraryfunc_s : e->type = libraryfunc_e : break;
		default:assert(0);
	}
	return e;
}

enum iopcode {
    assign, add, sub,
    mul, div, mod,
    unimus, and, or,
    not, if_eq, if_noteq,
    if_lesseq, if_greatereq, if_less,
    if_greater, call, param,funprefix,
    ret, getretval, funcstart,
    funcend, tablecreate,
    tablegetelem, tablesetelem
};

struct quad {
	iopcode op;
	expr* result;
	expr* arg1;
	expr* arg2;
	unsigned label;
	unsigned line;
};

struct stmt_t {
	int breakList, contList;
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

struct expr {
	expr_t			type;
	symbol*			sym;
	expr*			index;
	double 			numConst;
	char*			strConst;
	unsigned char	boolConst;
	expr*			next;
};

void expand (void) {
	assert(total == currQuad);
	quad* p = (quad*) malloc(NEW_SIZE);
	if(quads){
		memcpy(p, quads, CURR_SIZE);
		free(quads);
	} 
	quads = p;
	total += EXPAND_SIZE;
}

void emit(iopcode op, expr* arg1, expr* arg2, expr* result, unsigned int label, unsigned int line) {

	if (currQuad == total) expand(); 

	quad* p 	= quads+currQuad++;
	//p->op 		= op;
	p->arg1		= arg1;
	p->arg2		= arg2;
	p->result	= result;
	p->label 	= label;
	p->line		= line;
}


enum scopespace_t {
	programVar,
	functionLocal,
	formalArg
};

enum sumbol_t { var_s, programfunc_s, libraryfunc_s}

struct symbol {
	symbol_t type; 
	char* name;  //dynamic string
	scopespace_t space; // originating scope scapce
	unsigned offset; // offset in scope space
	unsigned scope; // scope value
	unsigned line; //source line of declaration
};

unsigned programVarOffset = 0;
unsigned functionLocalOffset = 0;
unsigned formalArgOffset = 0;
unsigned scopeSpaceCounter = 1;

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
distributetype(int vars, int type) {
	for each v in vars do {   
		if (v.class = pointervar) {
			v.size = 4;
		}else if (v.class = arrayvar){
			v.size = arraytotal(v.dims)*type.size;
		}else if (v.class = arraypointervar){
			v.size = arraytotal(v.dims)*4;
		}else{
			v.size = type.size;
			v.offset =getcurroffset();
			inccurroffset(v.size);
		}
}

void resetformalargoffset(){
	formalArgOffset = 0;
}

void resetfunctionlocaloffset(){
	functionLocalOffset = 0;
}

void restorecurrscopeoffset(unsigned n){
	switch( currscopespace()){
		case globalvar		: globalvarOffset = n; break;
		case functionlocal 	: functionLocalOffset = n; break;
		case formalarg 		: formalArgOffset = n; break;
		default				: assert(0);
	}
}

unsigned int nextquadlabel(void){
	return currQuad;
}

void patchlabel(unsigned quadNo, unsigned label){
	assert(quadNo < currQuad);
	quads[quadNo].label = label;
}

// FIX THIS LATER
void dumparguments() {
	for (local i = 0, local n = totalarguments(); i < n; ++i) {
		print(argument(i)); print(“\n”); }
	}
}

expr* member_item (expr* lv, char* name) {
	lv = emit_iftableitem(lv); // Emit code if r-value use of table item
	expr* ti = newexpr(tableitem_e); // Make a new expression
	ti->sym = lv->sym;
	ti->index = newexpr_conststring(name); // Const string index
	return ti;
}

expr* newexpr(expr_t t){
  expr* e = (expr*) malloc(sizeof(expr));
  memset(e,0,sizeof(expr));
  e->type = t;
  return e;
}

expr* emit_iftableitem(expr* e){
	if (e->type !+ tableitem_e)
		return e;
	else {
		expr* result = newexpr(var_e);
		result->sym = newtemp();
		
		emit("tablegetlem", e, e->index, result); // do I miss a param?

		return result;
	}
}

expr *make_call(expr *lv, expr *reversed_elist) {
	expr *func = emit_iftableitem(lv);
	while (reversed_elist)
	{
		emit(param, reversed_elist, NULL, NULL);
		reversed_elist = reversed_elist->next;
	}
	emit(call, func, NULL, NULL);
	expr *result = newexpr(var_e);
	result->sym = newtemp();
	emit(getretval, NULL, NULL, result);
	return result;
}

struct call {
	expr* elist;
	unsigned char method;
	char* name;
};

exrp *newexpr_constnum(double i) {
	expr *e = newexpr(constnum_e);
	e->numConst = i;
	return e;
}

void comperror (char* format, ...);

// Use this function to check correct use of
// of expression in arithmetic
void check_arith (expr* e, const char* context) {
	if ( e->type == constbool_e ||
	e->type == conststring_e ||
	e->type == nil_e ||
	e->type == newtable_e ||
	e->type == programfunc_e ||
	e->type == libraryfunc_e ||
	e->type == boolexpr_e )
	comperror("Illegal expr used in %s!", context);
}

unsigned int istempname(char *s) {
	return *s == '_';
}
unsigned int istempexpr(expr *e) {
	return e->sym && istempname(e->sym->name);
}

void patchlabel(unsigned quadNo, unsigned label) {
	assert(quadNo < currQuad && !quads[quadNo].label);
	quads[quadNo].label = label;
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
	quads[i].label = 0;
	return i;
}

int mergelist(int l1, int l2) {
	if (!l1)
		return l2;
	else if (!l2)
		return l1;
	else {
		int i = l1;
		while (quads[i].label){
			i = quads[i].label;
		}
		quads[i].label = l2;
		return l1;
	}
}

void patchlist(int list, int label) {
	while (list) {
		int next = quads[list].label;
		quads[list].label = label;
		list = next;
	}
}