#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_management.h"


#pragma GCC diagnostic ignored "-Wenum-compare"
#pragma GCC diagnostic ignored "-Wwrite-strings"
#pragma GCC diagnostic ignored "-Wformat="


enum SymbolType { GLOBAL, LOC, FORMAL, USERFUNC, LIBFUNC};

struct forstruct{
	int enter;
	int test;
};

typedef struct Information{
	enum SymbolType type;
	string name;
	unsigned int line;
	unsigned int offset;
	unsigned int scope;
} Information;

Information* lookup(string s);
void insertVariable(string name, unsigned int line);

unsigned int total = 0, currQuad = 0, tempcounter = 0, scopeSpaceCounter = 1, quadsCounter = 0;
stack<vector<int>> scopeSpaces; //vect[0] = programVarOffset, vect[1] = functionLocalOffset, vect[3] = formalArgOffset
stack<int> funcPatchList; //Patch list for function jumps

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
	mapitem_e,
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
	char* name;
	scopespace_t space; 
	unsigned offset;
	unsigned scope;
	unsigned line;
};


struct expr {
	expr_t			type;
	Information*	sym;
	expr*			index;
	expr*			mapKey;
	expr*			mapValue;
	int 			iaddress;
	double 			numConst;
	string			strConst;
	bool			boolConst;
	expr*			next;
};

struct quad { 
	iopcode op;
	expr* result;
	expr* arg1;
	expr* arg2;
	int label;
	int line; 
	int iaddress;
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
	return "Fail";
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
	else if(op == tablesetelem) return "tablesetelem";
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
	q->line		= quadsCounter++;

	quads.push_back(q);
}

void printQuads(){
	int idx = 1;
	for(auto q : quads){
		if(q->label == -1)
			printf("%-15s %-20s %-20s %-20s %-20s\n", (to_string(idx++)+":").c_str(), opToString(q->op).c_str(), exprToString(q->result).c_str(), exprToString(q->arg1).c_str(), exprToString(q->arg2).c_str());
		else
			printf("%-15s %-20s %-20s %-20s %-20s %-20d\n", (to_string(idx++)+":").c_str(), opToString(q->op).c_str(), exprToString(q->result).c_str(), exprToString(q->arg1).c_str(), exprToString(q->arg2).c_str(), q->label);
	}
	printf("\n\n");
}

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


unsigned int nextQuad(){ return quadsCounter+1; }

expr* newexpr(expr_t t){
  expr* e = new expr;
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
		emit(tablegetelem, result, e, e->index, -1, yylineno);
		return result;
	}
}

expr* newexpr_conststring(string val) {
	expr* e = newexpr(conststring_e);
	e->strConst = val;
	return e;
}

expr* member_item(expr* e, string name, int yylineno) {
	e = emit_iftableitem(e, yylineno); // Emit code if r-value use of table item
	expr* ti = newexpr(tableitem_e); // Make a new expression
	ti->sym = e->sym;
	ti->index = newexpr_conststring(name); // Const string index
	return ti;
}

expr *make_call(expr *lv, expr* elist, int yylineno) {
	expr* current = elist;
  	expr *prev = NULL, *next = NULL;
  	while (current != NULL) {
       	next = current->next;
       	current->next = prev;
       	prev = current;
      	current = next;
    }
   	expr* head = prev;
	expr *func = emit_iftableitem(lv,yylineno);
	while (head) {
		emit(param, head, NULL, NULL, -1,yylineno);
		head = head->next;
	}
	emit(call, NULL, func, NULL, -1, yylineno);
	expr *result = newexpr(var_e);
	result->sym = newtemp();
	emit(getretval, result, NULL, NULL, -1, yylineno);
	return result;
}

expr* newexpr_constnum(double i) {
	expr *e = newexpr(constnum_e);
	e->numConst = i;
	return e;
}

bool istempname(string s) { return s[0] == '_'; }

bool istempexpr(expr *e) { return e->sym && istempname(e->sym->name); }

void patchlabel(int quadNo, int label) {
	quads[quadNo-1]->label = label;
}

void functionJumpPatch(int label){
	int jumpLabel = funcPatchList.top();funcPatchList.pop();
	patchlabel(jumpLabel,label);
}
void functionJumpStore(int label){
	funcPatchList.push(label);
}
expr* newexpr_constbool(bool val) {
	expr* e = newexpr(constbool_e);
	e->boolConst = val;
	return e;
}

void make_stmt(stmt_t *s) {
	s->breakList = s->contList = 0;
}

void check_arith(expr* e, string context) {
	if (e->type == constbool_e ||
	e->type == conststring_e ||
	e->type == nil_e ||
	e->type == newtable_e ||
	e->type == programfunc_e ||
	e->type == libraryfunc_e ||
	e->type == boolexpr_e ){
		//printf("Illegal expr used in %s!", context.c_str());
		//exit(0);
	}
}

int scope = 0;

Information* allocInfo(SymbolType type, string name, int line, int offset, int scope){
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
stack<vector<int>> breakLists;
stack<vector<int>> contLists;
void loopEnter(){
	vector<int> a;
	vector<int> b;
	breakLists.push(a);
	contLists.push(b);
}
void patchBreak(int label){
	for(int i : breakLists.top()) {
		printf("Pached break %d , at %d\n",i,label);
		patchlabel(i,label);
	}
}
void patchCont(int label){
	for(int i : contLists.top()) {
		printf("Pached cont %d , at %d\n",i,label);
		patchlabel(i,label);
	}
}
void insertBreak(int label){
	breakLists.top().push_back(label);
}
void insertCont(int label){
	contLists.top().push_back(label);
}
void loopExit(){
	breakLists.pop();
	contLists.pop();
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

	Information info2;
	info2.type = scope==0?GLOBAL:LOC;
	info2.line = line;
	info2.name = name;
	info2.scope = scope;
	info2.offset = currScopeOffset();
	fullSymTable[scope].push_back({name, info2});
	inCurrScopeOffset();
}

//Information
void insertArgument(string name, unsigned int line){
	Information* info = allocInfo(FORMAL, name, line, currScopeOffset(), scope);
	activeSymTable[scope].insert({name, info});

	Information info2;
	info2.type = FORMAL;
	info2.line = line;
	info2.name = name;
	info2.scope = scope;
	info2.offset = currScopeOffset();
	fullSymTable[scope].push_back({name, info2});
	inCurrScopeOffset();
}

//Information
void insertUserFunction(string name, unsigned int line){
	Information* info = allocInfo(USERFUNC, name, line, 0, scope);
	activeSymTable[scope].insert({name, info});

	Information info2;
	info2.type = USERFUNC;
	info2.line = line;
	info2.name = name;
	info2.scope = scope;
	info2.offset = 0;
	fullSymTable[scope].push_back({name, info2});
}

bool isSystemFunction(string name){
	return systemFunctions.find(name) != systemFunctions.end();
}

// Information
void globalInsert(string name, enum SymbolType type, unsigned int line){
	Information* info = allocInfo(type, name, line, 0, 0);
	activeSymTable[0].insert({name, info});
	
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
			printf("\"%s\" %s (line %d) (scope %d)\n",key.c_str(),label.c_str(),info.line,i);
		}
	}
}

/*


███╗░░░███╗███████╗░██████╗░░█████╗░  ░█████╗░██████╗░░█████╗░██████╗░  ██████╗░███████╗██╗░░░░░░█████╗░░██╗░░░░░░░██╗
████╗░████║██╔════╝██╔════╝░██╔══██╗  ██╔══██╗██╔══██╗██╔══██╗██╔══██╗  ██╔══██╗██╔════╝██║░░░░░██╔══██╗░██║░░██╗░░██║
██╔████╔██║█████╗░░██║░░██╗░███████║  ██║░░╚═╝██████╔╝███████║██████╔╝  ██████╦╝█████╗░░██║░░░░░██║░░██║░╚██╗████╗██╔╝
██║╚██╔╝██║██╔══╝░░██║░░╚██╗██╔══██║  ██║░░██╗██╔══██╗██╔══██║██╔═══╝░  ██╔══██╗██╔══╝░░██║░░░░░██║░░██║░░████╔═████║░
██║░╚═╝░██║███████╗╚██████╔╝██║░░██║  ╚█████╔╝██║░░██║██║░░██║██║░░░░░  ██████╦╝███████╗███████╗╚█████╔╝░░╚██╔╝░╚██╔╝░
╚═╝░░░░░╚═╝╚══════╝░╚═════╝░╚═╝░░╚═╝  ░╚════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░░░░  ╚═════╝░╚══════╝╚══════╝░╚════╝░░░░╚═╝░░░╚═╝░░

*/


int nextInstructionIdx = 0;

typedef void (*generator_func_t) (quad*);
void make_operand 					(expr* e, vmarg* arg);
void make_numberoperand				(vmarg* arg, double val);
void make_booloperand 				(vmarg* arg, unsigned int val);
void make_retvaloperand 			(vmarg* arg);

void add_incomplete_jump			(unsigned int instrNo, unsigned int iaddress);
void patchInstrLabel				(unsigned int instrNo, unsigned int iaddress);
void patchIncompleteJumps			(unsigned int totalQuads);

void make_booloperand 				(vmarg *arg, unsigned int logical);
void reset_operand 					(vmarg *arg);
void make_retvaloperand 			(vmarg *arg);

void generate						(vmopcode op, quad *quad);
void generate_ADD 					(quad *quad);
void generate_SUB 					(quad *quad);
void generate_MUL 					(quad *quad);
void generate_GETRETVAL 			(quad *quad);
void generate_FUNCSTART				(quad *quad);
void generate_RETURN 				(quad *quad);
void generate_FUNCEND 				(quad *quad);
void generate_NOT 					(quad *quad);
void generate_OR 					(quad *quad);
void generate_PARAM					(quad *quad);
void generate_CALL 					(quad *quad);
void generate_DIV 					(quad *quad);
void generate_MOD 					(quad *quad);
void generate_NEWTABLE 				(quad *quad);
void generate_TABLEGETELM 			(quad *quad);
void generate_TABLESETELEM			(quad *quad);
void generate_ASSIGN 				(quad *quad);
void generate_NOP 					(quad *quad);

void generate_JUMP 					(quad *quad);
void generate_IF_EQ 				(quad *quad);
void generate_IF_NOTEQ 				(quad *quad);
void generate_IF_GREATER 			(quad *quad);
void generate_IF_GREATEREQ 			(quad *quad);
void generate_IF_LESS 				(quad *quad);
void generate_IF_LESSEQ 			(quad *quad);



struct incomplete_jump {
    unsigned instrNo;       // The jump instruction number
    unsigned iaddress;      // The i-code jump-target address
    incomplete_jump* next;  // a trivial linked list
};

incomplete_jump* ij_head = (incomplete_jump*) 0;
unsigned ij_total = 0;


//Implementations below
generator_func_t generators [] = {
    generate_ADD,
    generate_SUB,
    generate_MUL,
    generate_DIV,
    generate_MOD,
    generate_NEWTABLE,
    generate_TABLEGETELM,
    generate_TABLESETELEM,
    generate_ASSIGN,
    generate_NOP,
    generate_JUMP,
    generate_IF_EQ,
    generate_IF_NOTEQ,
    generate_IF_GREATER,
    generate_IF_GREATEREQ,
    generate_IF_LESS,
    generate_IF_LESSEQ,
    generate_NOT,
    generate_OR,
    generate_PARAM,
    generate_CALL,
    generate_GETRETVAL,
    generate_FUNCSTART,
    generate_RETURN,
    generate_FUNCEND
}; 
int currprocessedquad = 0;
void generate(void) {
    for(unsigned i = 0; i < total; ++i){
		currprocessedquad = i;
        (*generators[quads[i]->op]) (quads[i]);
	}
}

void make_operand (expr* e, vmarg* arg) {
    /*
	if(e == NULL){
		arg->val = -1;
		arg->type = -1;
		return;
	}*/
    //All those below use a variable for storage
	switch(e->type){
		case var_e:
		case tableitem_e:
		case arithexpr_e:
		case boolexpr_e:
		//case assignexpr_e:
		case newtable_e:    {
                               // assert(e->sym);
                                arg->val = e->sym->offset;
								if(e->sym->type == GLOBAL) arg->type = global_a;
								else if(e->sym->type == USERFUNC) arg->type = local_a;
								else if(e->sym->type == FORMAL) arg->type = local_a;
								else assert(0);
								/*
                                switch(e->sym->space){            
                                    case programVar:	arg->type = global_a;   break;
                                    case functionLocal:	arg->type = local_a;    break;
                                    case formalArg:		arg->type = formal_a;   break;
                                    default: assert(0);
                                }
								*/
                                break;
		                    }
        // Constants
		case constbool_e: 	{
								//if(e->boolConst == '0') arg->val = 0;
								//else arg->val = 1;
                                arg->val = e->boolConst;
								arg->type = bool_a;    break;
		                    }
		case conststring_e:	{
								arg->val = insert_string(e->strConst); //  INSERTER_STRING(e->strConst);
								arg->type = string_a;	break;
						 	}
		case constnum_e:	{
									
								arg->val = insert_number(e->numConst); //INSERTER_NUM(e->numConst);
								arg->type = number_a;   break;
							}

		case nil_e:			{
								arg->type = nil_a; break;
							}
        //functions
		case programfunc_e: {
								arg->type = userfunc_a;
								//METHODOS STROUNTHOKAMILOU!!!
								
								//arg->val = e->sym->iaddress; //INSERTER_USERFUNC(e->sym->value.funcVal->iaddress, ///e->sym->value.funcVal->totallocals,e->sym->value.funcVal->totalargs, (char*) //e->sym->value.funcVal->name);
								arg->val = insert_userFunc(-1,-1,e->sym->name);
								break;
							}
		case libraryfunc_e:	{
								arg->type = libfunc_a;
								arg->val = insert_libFunc(e->sym->name); //INSERTER_LIBFUNC((char*) e->sym->value.funcVal->name);
								break;
							}
		default :   assert(0);
	}
}
void reset_operand(vmarg* a){
	a = NULL;
}

int nextinstructionlabel(){
	return nextInstructionIdx++;
}
void make_numberoperand(vmarg* arg, double val){
	//arg->val = consts_newnumber(val);
	arg->val = val;//changed to this maybe fault?
	arg->type = number_a;
}

void make_booloperand(vmarg* arg, unsigned val){
	arg->val = val;
	arg->type = bool_a;
}

void retvaloperand(vmarg* arg){
	arg->type = retval_a;
}

void emitInstruction(instruction* t){
	instruction *tmp = new instruction;
	tmp->opcode = t->opcode;
	tmp->arg1 = t->arg1;
	tmp->arg2 = t->arg2;
	tmp->result = t->result;
	tmp->srcLine = t-> srcLine; 
	instructions.push_back(tmp);
}

void generate(vmopcode op, quad* quad) {
	instruction *t = new instruction;
	t->arg1 = new vmarg;
	t->arg2 = new vmarg;
	t->result = new vmarg;
	t->opcode = op;
	make_operand(quad->arg1, t->arg1);
	make_operand(quad->arg2, t->arg2);
	make_operand(quad->result, t->result);
	quad->result->iaddress = nextinstructionlabel();
	emitInstruction(t);
}

void generate_ADD (quad *quad) { generate(add_v, quad); }
void generate_SUB (quad *quad) { generate(sub_v, quad); }
void generate_MUL (quad *quad) { generate(mul_v, quad); }
void generate_DIV (quad *quad) { generate(divide_v, quad); }
void generate_MOD (quad *quad) { generate(mod_v, quad); }


void generate_NEWTABLE (quad *quad) { generate(newtable_v, quad); }
void generate_TABLEGETELM (quad *quad) { generate(tablegetelem_v, quad); }
void generate_TABLESETELEM (quad *quad) { generate(tablesetelem_v, quad); }
void generate_ASSIGN (quad *quad) { generate(assign_v, quad); }
void generate_NOP (quad* weDontUseThisAtAllButIfWeDontPutItItGetsScrewed) { 
	instruction* t = new instruction;
	t->opcode=nop_v; 
	emitInstruction(t); 
} 

void add_incomplete_jump(int instrAddress, int instructionNo){
	/*
    incJump *tmp = malloc( sizeof( incJump ) );
    tmp->instrAddress = instrAddress;
    tmp->instrNo = instrNo;

    if( incJumpH == NULL ){
        tmp->next = NULL;
    }else{
        tmp->next = incJumpH;
    }

    incJumpH = tmp;

    return;*/ //FIIIXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
}

void generate_relational(vmopcode op, quad* quad) {
	instruction *t = new instruction;
	t->arg1 = new vmarg;
	t->arg2 = new vmarg;
	t->result = new vmarg;
	t->opcode = op;
	make_operand(quad->arg1, t->arg1);
	make_operand(quad->arg2, t->arg2);
	t->result->type = label_a;
	if (quad->label < currprocessedquad) {
		t->result->val = quads[quad->label]->iaddress;
	}else {
		add_incomplete_jump(nextinstructionlabel(), quad->label);
	}
	quad->iaddress = nextinstructionlabel();
	emitInstruction(t);
}

void generate_JUMP (quad *quad) { generate_relational(jump_v, quad); }
void generate_IF_EQ (quad *quad) { generate_relational(jeq_v, quad); }
void generate_IF_NOTEQ(quad *quad) { generate_relational(jne_v, quad); }
void generate_IF_GREATER (quad *quad) { generate_relational(jgt_v, quad); }
void generate_IF_GREATEREQ(quad *quad) { generate_relational(jge_v, quad); }
void generate_IF_LESS (quad *quad) { generate_relational(jlt_v, quad); }
void generate_IF_LESSEQ (quad *quad) { generate_relational(jle_v, quad); }

void generate_NOT (quad *quad) {
	quad->iaddress = nextinstructionlabel();
	instruction *t = new instruction;

	t->opcode = jeq_v;
	make_operand(quad->arg1, t->arg1);
	make_booloperand(t->arg2, false);
	t->result->type = label_a;
	t->result->val = nextinstructionlabel()+3;
	emitInstruction(t);

	t->opcode = assign_v;
	make_booloperand(t->arg1, false);
	reset_operand(t->arg2);
	make_operand(quad->result, t->result);
	emitInstruction(t);

	t->opcode = jump_v;
	reset_operand (t->arg1);
	reset_operand(t->arg2);
	t->result->type = label_a;
	t->result->val = nextinstructionlabel()+2;
	emitInstruction(t);

	t->opcode = assign_v;
	make_booloperand(t->arg1, true);
	reset_operand(t->arg2);
	make_operand(quad->result, t->result);
	emitInstruction(t);
}

void generate_OR (quad *quad) {
	quad->iaddress = nextinstructionlabel();
	instruction *t = new instruction;

	t->opcode = jeq_v;
	make_operand(quad->arg1, t->arg1);
	make_booloperand(t->arg2, true);
	t->result->type = label_a;
	t->result->val = nextinstructionlabel()+4;
	emitInstruction(t);

	make_operand(quad->arg2, t->arg1);
	t->result->val = nextinstructionlabel()+3;
	emitInstruction(t);

	t->opcode = assign_v;
	make_booloperand(t->arg1, false);
	reset_operand(t->arg2);
	make_operand(quad->result, t->result);
	emitInstruction(t);

	t->opcode = jump_v;
	reset_operand (t->arg1);
	reset_operand(t->arg2);
	t->result->type = label_a;
	t->result->val = nextinstructionlabel()+2;
	emitInstruction(t);

	t->opcode = assign_v;
	make_booloperand(t->arg1, true);
	reset_operand(t->arg2);
	make_operand(quad->result, t->result);
	emitInstruction(t);
} 

// Kapos etsi einai alla mporei na thelei kai allages
void generate_AND (quad *quad) {
	quad->iaddress = nextinstructionlabel();
	instruction *t = new instruction;
	t->opcode = jeq_v;
	make_operand(quad->arg1, t->arg1);
	make_booloperand(t->arg2, true);
	t->result->type = label_a;
	t->result->val = nextinstructionlabel()+4;
	emitInstruction(t);
	
	make_operand(quad->arg2, t->arg1);
	t->result->val = nextinstructionlabel()+3;
	emitInstruction(t);

	t->opcode = assign_v;
	make_booloperand(t->arg1, false);
	reset_operand(t->arg2);
	make_operand(quad->result, t->result);
	emitInstruction(t);
	
	t->opcode = jump_v;
	reset_operand (t->arg1);
	reset_operand(t->arg2);
	t->result->type = label_a;
	t->result->val = nextinstructionlabel()+2;
	emitInstruction(t);

	t->opcode = assign_v;
	make_booloperand(t->arg1, true);
	reset_operand(t->arg2);
	make_operand(quad->result, t->result);
	emitInstruction(t);
}

void generate_PARAM(quad *quad) {
	quad->iaddress = nextinstructionlabel();
	instruction *t = new instruction;
	t->opcode = pusharg_v;
	make_operand(quad->arg1, t->arg1);
	emitInstruction(t);
}

void generate_CALL(quad *quad) {
	quad->iaddress = nextinstructionlabel();
	instruction *t = new instruction;
	t->opcode = call_v;
	make_operand(quad->arg1, t->arg1);
	emitInstruction(t);
}

void generate_GETRETVAL(quad *quad) {
	quad->iaddress = nextinstructionlabel();
	instruction *t = new instruction;
	t->opcode = assign_v;
	make_operand(quad->result, t->result);
	t->arg1->type = retval_a;
	emitInstruction(t);
}
void generate_FUNCSTART(quad *quad) { 
/*
	Information* f = quad->result->sym;
	quad->iaddress = nextinstructionlabel();
	
	insert_userFunc(-1,-1,f->name);
	push(funcstack, f);

	instruction *t = new instruction;
	t->opcode = enterfunc_v;
	make_operand(quad->result, t->result);
	emitInstruction(t);
	*/
}

void generate_RETURN(quad *quad) { 
/*
	quad->iaddress = nextinstructionlabel();
	instruction *t = new instruction;
	t->opcode = assign_v;
	
	t->result = retval_a;
	make_operand(quad->arg1, t->arg1);
	emitInstruction(t);

	f = top(funcstack);

	t->opcode = jump_v;
	reset_operand(t->arg1);
	reset_operand(t->arg2);
	t->result->type = label_a;
	emitInstruction(t);
	*/
}

void generate_FUNCEND(quad *quad) {
	/*
 	f = pop(funcstack);
 	backpatch(f.returnList, nextinstructionlabel());

 	quad->iaddress = nextinstructionlabel();
 	instruction *t = new instruction;
 	t->opcode = funcexit_v;
		
 	make_operand(quadInput->result, t->result);
 	emitInstruction(t);
	*/
}

void patch_incomplete_jumps() {
    /*
    for each incomplete jump x do {
    if x.iaddress = intermediate code size then
    instructions[x.instrNo].result = target code size;
    else
    instructions[x.instrNo].result = quads[x.iaddress].iaddress;
    }*/
}