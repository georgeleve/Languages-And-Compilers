// #include "utils.h"

void emit(iopcode op, expr *arg1, expr *arg2, expr *result, int label, int line) {
	//if (currQuad == total) expand(); 
	printf("\nmphkeeeeeee\n");

	quad* q 	= quads+currQuad++;
	q->op 		= op;
	q->arg1		= arg1;
	q->arg2		= arg2;
	q->result	= result;
	q->label 	= label;
	q->line		= line;

	//quadsArray.push_back(q);     
	// !! find how to print an enum:      https://stackoverflow.com/questions/3168306/print-text-instead-of-value-from-c-enum
	// printf("New quad with opcode=, result=, arg1=, arg2=, label=", op, result, arg1, arg2, label, line);
}




// Dimiourgoyme kainourio onoma gia tis prosorines metavlhtes
void newtempname() { return "_t" + tempcounter; }

void resettemp() { tempcounter = 0; }

void newtemp() {
	char *name = newtempname();
	sym = lookup(name, currscope());
	
	if (sym == nil)
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
}

void resetformalargoffset(){ formalArgOffset = 0; };

void resetfunctionlocaloffset(){ functionLocalOffset = 0; };

void restorecurrscopeoffset(unsigned n){
	switch( currscopespace()){
		case globalvar		: globalvarOffset = n; break;
		case functionlocal 	: functionLocalOffset = n; break;
		case formalarg 		: formalArgOffset = n; break;
		default				: assert(0);
	}
}

unsigned int nextquadlabel(void){ return currQuad; }

void patchlabel(unsigned quadNo, unsigned label){
	assert(quadNo < currQuad);
	quads[quadNo].label = label;
}

// FIX THIS LATER
void dumparguments() {
	for (local i = 0, local n = totalarguments(); i < n; ++i) {
		printf(argument(i));
		printf("\n"); };
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
  memset(e, 0, sizeof(expr));
  e->type = t;
  return e;
}

expr* emit_iftableitem(expr* e){
	if (e->type != tableitem_e)
		return e;
	else {
		expr* result = newexpr(var_e);
		result->sym = newtemp();
		
		emit(tablegetlem, e, e->index, result); // do I miss some params?

		return result;
	}
}

expr *make_call(expr *lv, expr *reversed_elist) {
	expr *func = emit_iftableitem(lv);
	while (reversed_elist) {
		emit(param, reversed_elist, NULL, NULL);
		reversed_elist = reversed_elist->next;
	}
	emit(call, func, NULL, NULL);
	expr *result = newexpr(var_e);
	result->sym = newtemp();
	emit(getretval, NULL, NULL, result);
	return result;
}

expr *newexpr_constnum(double i) {
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

unsigned int istempname(char *s) { return *s == '_'; }

unsigned int istempexpr(expr *e) { return e->sym && istempname(e->sym->name); }

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

void newtempname(){

}

void newtemp(){

}

void resettemp(){

}

void currscope(){

}

void lookup(char * name, int scope){

}