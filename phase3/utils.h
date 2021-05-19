#include <assert.h>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
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
	symbol_t type; 
	char* name;  //dynamic string
	scopespace_t space; // originating scope scapce
	unsigned offset; // offset in scope space
	unsigned scope; // scope value
	unsigned line; //source line of declaration
};


// create a vector that is going to store the quad
struct expr {
	expr_t			type;
	symbol*			sym;
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

quad* quads = (quad*) 0;
vector<quad> quadsArray;

//Call this function inside emit() after initializing the quad
void addQuadToVector(quad q);


struct stmt_t {
	int breakList, contList;
};

struct call {
	expr* elist;
	unsigned char method;
	char* name;
};



void emit(iopcode op, expr *arg1, expr *arg2, expr *result, int label, unsigned int line);

// Dimiourgoyme kainourio onoma gia tis prosorines metavlhtes
void newtempname();

void resettemp();

void newtemp();

expr* lvalue_expr (symbol *sym) ;

void expand (void) ;

scopespace_t currScopeSpace(void);

unsigned int currScopeOffset(void);

void inCurrScopeOffset(void);

void enterScopeSpace(void);

void exitScopeSpace(void);

// FIX THIS FUNCTION LATER !!!!!!!!!!!!!
void distributetype(int vars, int type);

void resetformalargoffset();

void resetfunctionlocaloffset();

void restorecurrscopeoffset(unsigned n);

unsigned int nextquadlabel(void);

void patchlabel(unsigned quadNo, unsigned label);

// FIX THIS LATER
void dumparguments();

expr* member_item (expr* lv, char* name);

expr* newexpr(expr_t t);

expr* emit_iftableitem(expr* e);

expr *make_call(expr *lv, expr *reversed_elist);

expr *newexpr_constnum(double i) {
	expr *e = newexpr(constnum_e);
	e->numConst = i;
	return e;
}

void comperror (char* format, ...);

// Use this function to check correct use of
// of expression in arithmetic
void check_arith (expr* e, const char* context);

unsigned int istempname(char *s);

unsigned int istempexpr(expr *e);

void patchlabel(unsigned quadNo, unsigned label) ;

expr *newexpr_constbool(unsigned int b);

unsigned nextquad(void) ;

void make_stmt(stmt_t *s);

int newlist(int i);

int mergelist(int l1, int l2);

void patchlist(int list, int label);

//Loook big dick
void newtempname();

void newtemp();

void resettemp();

void currscope();

void lookup(char * name,int scope);