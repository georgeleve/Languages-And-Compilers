#include <bits/stdc++.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;
#pragma GCC diagnostic ignored "-Wenum-compare"
#pragma GCC diagnostic ignored "-Wwrite-strings"
#pragma GCC diagnostic ignored "-Wformat="

#define EXPAND_SIZE 1024
#define CURR_SIZE 	(total*sizeof(quad))
#define NEW_SIZE 	(EXPAND_SIZE*sizeof(quad)+CURR_SIZE)

//From other file beg
enum SymbolType { GLOBAL, LOC, FORMAL, USERFUNC, LIBFUNC};

typedef struct Information{
	enum SymbolType type;
	string name;
	unsigned int line;
	unsigned int offset;
	unsigned int scope;
} Information;
Information* lookup(string s);
void insertVariable(string name, unsigned int line);
//From other file end


unsigned total = 0;
unsigned int currQuad = 0;

int tempcounter = 0;
stack<vector<int>> scopeSpaces; //vect[0] = programVarOffset, vect[1] = functionLocalOffset, vect[3] = formalArgOffset
unsigned scopeSpaceCounter = 1;

int quadsCounter = 0;

// na valoume ta and, or , not   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
enum iopcode {
	assign, 	add,		sub,
	mul,		divide,		mod,
	uminus,			if_eq,		if_not_eq,
	if_lesseq,	if_greatereq,	if_less,
	if_greater,	call,		param,
	ret,		getretval,	funcstart,
	funcend,	jump,		tablecreate,
	tablegetelem,	tablesetelem, and_c, or_c, not_c
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
	int 			iaddress;
	double 			numConst;
	string			strConst;
	bool			boolConst;
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


string exprToString(expr* e){
	if(e==NULL) return "";
	if(e->type == var_e) return e->sym->name;
	if(e->type == constnum_e) return to_string(e->numConst);
	if(e->type == constbool_e) return e->boolConst?"TRUE":"FALSE";
	if(e->type == tableitem_e) return e->sym->name;
	if(e->type == libraryfunc_e) return e->sym->name;
	if(e->type == arithexpr_e) return e->sym->name;
	if(e->type == conststring_e) return e->strConst;
	if(e->type == newtable_e) return e->sym->name;
	if(e->type == nil_e) return "NIL";
	if(e->type == programfunc_e) return e->sym->name;
	if(e->type == boolexpr_e) return e->sym->name;
	if(e->type == assignexpr_e) return e->sym->name;
	return ("inv");
}

string opToString(iopcode op){
	if(op == assign) return "assign";
	else if(op == add) return "add";
	else if(op == sub) return "sub";
	else if(op == mul) return "mul";
	else if(op == divide) return "div";
	else if(op == uminus) return "uminus";
	else if(op == mod) return "mod";
	else if(op == if_eq) return "if_eq";
	else if(op == if_not_eq) return "if_not_eq";
	else if(op == if_lesseq) return "if_lesseq";
	else if(op == if_greatereq) return "if_greatereq";
	else if(op == if_greater) return "if_greater";
	else if(op == if_less) return "if_less";
	else if(op == call) return "call";
	else if(op == ret) return "ret";
	else if(op == getretval) return "getretval";
	else if(op == funcstart) return "funcstart";
	else if(op == funcend) return "funcend";
	else if(op == jump) return "jump";
	else if(op == tablecreate) return "tablecreate";
	else if(op == tablegetelem) return "tablegetelem";
	else if(op == param) return "param";
	else if(op == not_c) return "not";
	else if(op == or_c) return "or";
	else if(op == and_c) return "and";
	return "";
}

void emit(iopcode op, expr *result, expr *arg1, expr *arg2, int label, int line) {
	quad* q = (quad*) malloc(sizeof(quad));
	
	q->op 		= op;
	q->arg1		= arg1;
	q->arg2		= arg2;
	q->result	= result;
	q->label 	= label;
	q->line		= line;

	quadsCounter++;
	quads.push_back(q);
	printf("%-15s %-20s %-20s %-20s %-20s %-20d\n", (to_string(quadsCounter)+":").c_str(), opToString(op).c_str(), exprToString(result).c_str(), exprToString(arg1).c_str(), exprToString(arg2).c_str(), label);
}

// Dimiourgoyme kainourio onoma gia tis prosorines metavlhtes
string newtempname() { 
	return "_t" + to_string(tempcounter++);
}
void resettemp() { tempcounter = 0; }

Information* newtemp() {
	string name = newtempname();
	Information* sym = lookup(name);
	if (sym==NULL){
		insertVariable(name,0);
		sym = lookup(name);
	}
	return sym;
}

expr* lvalue_expr(Information* sym) {
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
	if(scopeSpaceCounter == 1) return programVar;
	else if(scopeSpaceCounter % 2 == 0) return functionLocal;
	else return formalArg;
}

unsigned int currScopeOffset(){
	switch(currScopeSpace()){
		case programVar		: return scopeSpaces.top()[0];
		case functionLocal	: return scopeSpaces.top()[1];
		case formalArg		: return scopeSpaces.top()[2];
		default				: assert(0);
	}
}

void inCurrScopeOffset(){
	switch(currScopeSpace()){
		case programVar 	: ++scopeSpaces.top()[0]; break;
		case functionLocal  : ++scopeSpaces.top()[1]; break;
		case formalArg 		: ++scopeSpaces.top()[2]; break;
		default 			: assert(0);
	}

}
void scopeSpaceIncrease(){
	vector<int> a(3,0);
	scopeSpaces.push(a);
}
void scopeSpaceDecrease(){
	scopeSpaces.pop();
}
void enterScopeSpace(){
	++scopeSpaceCounter;
}

void exitScopeSpace(){
	assert(scopeSpaceCounter > 2);
	scopeSpaceCounter -= 2;
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


unsigned int nextQuad(){ return quadsCounter+1; }

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

expr* emit_iftableitem(expr* e, int yylineno){
	if (e->type != tableitem_e)
		return e;
	else {
		expr* result = newexpr(var_e);
		result->sym = newtemp();
		emit(tablegetelem, e, e->index, result, -1, yylineno);
		return result;
	}
}

expr* newexpr_conststring(string val) {
	expr* e = newexpr(conststring_e);
	e->strConst = val;
	return e;
}

expr* member_item (expr* e, string name, int yylineno) {
	e = emit_iftableitem(e, yylineno); // Emit code if r-value use of table item
	expr* ti = newexpr(tableitem_e); // Make a new expression
	ti->sym = e->sym;
	ti->index = newexpr_conststring(name); // Const string index
	return ti;
}
/*
expr *make_call(expr *lv, expr *reversed_elist, int yylineno) {
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
*/
expr* newexpr_constnum(double i) {
	expr *e = newexpr(constnum_e);
	e->numConst = i;
	return e;
}

bool istempname(string s) { return s[0] == '_'; }

bool istempexpr(expr *e) { return e->sym && istempname(e->sym->name); }

void patchlabel(unsigned quadNo, unsigned label) {
	assert(quadNo < currQuad && !quads[quadNo]->label);
	quads[quadNo]->label = label;
}

expr* newexpr_constbool(bool val) {
	expr* e = newexpr(constbool_e);
	e->boolConst = val;
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

void check_arith(expr* e, string context) {
	if (e->type == constbool_e ||
	e->type == conststring_e ||
	e->type == nil_e ||
	e->type == newtable_e ||
	e->type == programfunc_e ||
	e->type == libraryfunc_e ||
	e->type == boolexpr_e ){
		printf("Illegal expr used in %s!", context.c_str());
		exit(0);
	}
}



//BELOW IS HELPER FILEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
int scope = 0;

Information* allocInfo(SymbolType type, string name, int line, int offset, int scope){
	//Information* info = (Information*) malloc(sizeof(Information));
	Information* info = new Information;
	info->type = type;
	info->name = name;
	info->line = line;
	info->offset = offset;
	info->scope = scope;
	return info;
}
typedef struct PrintToken{
	string value;
	Information info;
} PrintToken;

bool comparator(PrintToken a, PrintToken b){
	return a.info.line < b.info.line;
}

set<string> systemFunctions;
vector<map<string,Information*>> activeSymTable;
vector<vector<PrintToken>> fullSymTable;
stack<int> lastType; //Top of stack is 0 if the latest thing we found between a function and a loop is a function

void pushType(int type){ // 0 is loop 1 is function
	lastType.push(type);
}

void popType(){
	lastType.pop();
}
bool isLastTypeLoop(){ // 0 is loop 1 is function
	if(lastType.empty()) return false;
	return lastType.top()==0;
}
bool isInFunction(){
	bool in = false;
	stack<int> temp;
	while(!lastType.empty()){
		int p = lastType.top(); lastType.pop();
		temp.push(p);
		if(p==1) in = true;
	}
	while(!temp.empty()){
		int p = temp.top(); temp.pop();
		lastType.push(p);
	}
	return in;
}
void increaseScope(){
	scope++;
	map<string, Information*> tp;
	activeSymTable.push_back(tp);
	if(fullSymTable.size()<=scope){
		vector<PrintToken> tp2;
		fullSymTable.push_back(tp2);
	}
}

void decreaseScope(){
	scope--;
	activeSymTable.pop_back();
}

Information* lookup(string s){
	if(activeSymTable.back().find(s) != activeSymTable.back().end()) return activeSymTable.back().find(s)->second;
	return NULL;
}

Information* globalLookup(string s){
	if(activeSymTable[0].find(s) != activeSymTable[0].end()) return activeSymTable[0].find(s)->second;
	return NULL;
}

Information* generalLookup(string s){
	if(lookup(s)!=NULL) return lookup(s);
	return globalLookup(s);
}

Information* lookupTillGlobalScope(string s, bool careAboutFunctionInBetween){ 
	if(lookup(s)!=NULL) return activeSymTable[scope].find(s)->second;
	bool functionInBetween = false;
	for(int i = scope-1; i>=0; i--) {
		for(auto v : activeSymTable[i]) if(v.second->type == USERFUNC) functionInBetween = true;
		if(activeSymTable[i].find(s) != activeSymTable[i].end()){
			if(i==0) return activeSymTable[i].find(s)->second;
			if(functionInBetween && careAboutFunctionInBetween) return allocInfo(GLOBAL, "", 0, 0, -2); //Not accesible.
			return activeSymTable[i].find(s)->second;
		}
	}
	return NULL; //Not found at all
}

void insertVariable(string name, unsigned int line){
	Information* info = allocInfo(scope==0?GLOBAL:LOC, name, line, currScopeOffset(), scope);
	activeSymTable[scope].insert({name, info});
	//info.offset = ?;
	Information info2;
	info2.type = scope==0?GLOBAL:LOC;
	info2.line = line;
	info2.name = name;
	info2.scope = scope;
	info2.offset = currScopeOffset();
	fullSymTable[scope].push_back({name, info2});
	inCurrScopeOffset();
	//return info;
}

//Information
void insertArgument(string name, unsigned int line){
	Information* info = allocInfo(FORMAL, name, line, currScopeOffset(), scope);
	activeSymTable[scope].insert({name, info});
	//info.offset = ?;

	Information info2;
	info2.type = FORMAL;
	info2.line = line;
	info2.name = name;
	info2.scope = scope;
	info2.offset = currScopeOffset();
	fullSymTable[scope].push_back({name, info2});
	inCurrScopeOffset();
	//return info;
}

//Information
void insertUserFunction(string name, unsigned int line){
	Information* info = allocInfo(USERFUNC, name, line, 0, scope);
	activeSymTable[scope].insert({name, info});
	//info.offset = ?;

	Information info2;
	info2.type = USERFUNC;
	info2.line = line;
	info2.name = name;
	info2.scope = scope;
	info2.offset = 0;
	fullSymTable[scope].push_back({name, info2});
	//return info;
}

bool isSystemFunction(string name){
	return systemFunctions.find(name) != systemFunctions.end();
}

// Information
void globalInsert(string name, enum SymbolType type, unsigned int line){
	Information* info = allocInfo(type, name, line, 0, 0);
	activeSymTable[0].insert({name, info});
	//info.offset = ?;
	
	Information info2;
	info2.type = type;
	info2.line = line;
	info2.name = name;
	info2.scope = scope;
	fullSymTable[0].push_back({name, info2});
	
	if(type == LIBFUNC) systemFunctions.insert(name);
}

void initializeSymTable(){
	map<string,Information*> tp;
	activeSymTable.push_back(tp);
	vector<PrintToken> tp2;
	fullSymTable.push_back(tp2);
	
	globalInsert("print", LIBFUNC, 0);
	globalInsert("input", LIBFUNC, 0);
	globalInsert("objectmemberkeys", LIBFUNC, 0);
	globalInsert("objecttotalmembers", LIBFUNC, 0);
	globalInsert("objectcopy", LIBFUNC, 0);
	globalInsert("totalarguments", LIBFUNC, 0);
	globalInsert("argument", LIBFUNC, 0);
	globalInsert("typeof", LIBFUNC, 0);
	globalInsert("strtonum", LIBFUNC, 0);
	globalInsert("sqrt", LIBFUNC, 0);
	globalInsert("cos", LIBFUNC, 0);
	globalInsert("sin", LIBFUNC, 0);
}


void printFullSymTable(){
	for(int i = 0; i<fullSymTable.size(); i++){
		printf("------------   Scope #%d   ------------\n",i);
		vector<PrintToken> a;
		for(auto v : fullSymTable[i]){
			string key = v.value;
			Information info = v.info;
			enum SymbolType { GLOBAL, LOC, FORMAL, USERFUNC, LIBFUNC };
			string label = "";
			if(info.type == GLOBAL) label = "[global variable]";
			else if(info.type == LOC) label = "[local variable]";
			else if(info.type == FORMAL) label = "[formal argument]";
			else if(info.type == USERFUNC) label = "[user function]";
			else label = "[library function]";	
			printf("\"%s\" %s (line %d) (scope %d) (offset %d)\n",key.c_str(),label.c_str(),info.line,i,info.offset);
		}
	}
}