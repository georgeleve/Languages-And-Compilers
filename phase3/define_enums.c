#define EXPAND_SIZE 1024
#define CURR_SIZE 	(total*sizeof(quad))
#define NEW_SIZE 	(EXPAND_SIZE*sizeof(quad)+CURR_SIZE)

quad* quads = (quad*) 0;
unsigned total;
unsigned int currQuad;

enum iopcode {
    assign, add, sub,
    mul, div, mod,
    unimus, and, or,
    not, if_eq, if_noteq,
    if_lesseq, if_greatereq, if_less,
    if_greater, call, param,
    ret, getretval, funcstart,
    funcend, tablecreate,
    tablegetelem, tablesetelem
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

void emit (
		iopcode			op,
		expr* 			arg1,
		expr* 			arg2,
		expr*			result,
		unsigned int 	label,
		unsigned int 	line
		) {

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

struct symbol {
	symbol_t type; 
	char* name;  //dynamic string
	scopespace_t space; // originating scope scapce
	unsigned offset; // offset in scope space
	unsigned scope; // scope value
	unsigned line; //source line of declaration
}

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