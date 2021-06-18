#include <string>
#include <iostream>
#include <assert.h>
#include <stdio.h>

#define AVM_ENDING_PC codeSize
#define AVM_STACKSIZE 4096
#define AVM_WIPEOUT(m) memset(&(m), 0, sizeof(m))
#define AVM_TABLE_HASHSIZE 211
#define AVM_STACKENV_SIZE 4
#define AVM_MAX_INSTRUCTIONS (unsigned) nop_v

typedef void (*execute_func_t) (instruction*);

extern void execute_assign (instruction*);
extern void execute_add (instruction*);
extern void execute_sub (instruction*);
extern void execute_mul (instruction*);
extern void execute_div (instruction*);
extern void execute_mod (instruction*);
extern void execute_unimus (instruction*);
extern void execute_and (instruction*);
extern void execute_or (instruction*);
extern void execute_not (instruction*);
extern void execute_jeq (instruction*);
extern void execute_jne (instruction*);
extern void execute_jle (instruction*);
extern void execute_jge (instruction*);
extern void execute_jlt (instruction*);
extern void execute_jgt (instruction*);
extern void execute_call (instruction*);
extern void execute_pusharg (instruction*);
extern void execute_funcenter (instruction*);
extern void execute_funcexit (instruction*);
extern void execute_newtable (instruction*);
extern void execute_tablegetelem (instruction*);
extern void execute_tablesetelem (instruction*);
extern void execute_nop (instruction*);

avm_memcell ax, bx, cx;
avm_memcell retval;
unsigned top, topsp;

double consts_getnumber(unsigned index);
string consts_getstring(unsigned index);
string libfuncs_getused(unsigned index);

unsigned consts_newstring(string s);
unsigned consts_newnumber(double n);
unsigned libfuncs_newused(string s);
unsigned userfuncs_newfuncs(symbol* sym);

unsigned char executionFinished = 0;
unsigned pc = 0;
unsigned currLine = 0;
unsigned codeSize = 0;
instruction* code = (instruction*) 0;

typedef unsigned char (*tobool_func_t) (avm_memcell*);

avm_memcell stack[AVM_STACKSIZE];


void avmbinaryfile() {
	return magicnumber() && arrays() && code() ;
}

bool magicnumber() {
	return match(UNSIGNED) && currtoken.intVal == MAGICNUMBER;
}

bool arrays() {
	return strings() && numbers() && userfunctions() && libfunctions();
}

bool strings() {
	unsigned n;
	if ( !match(UNSIGNED) )
		return false;
	else
		for (n = currtoken.intVal; n; --n) string();
}



struct vmarg { vmarg_t type; unsigned val; }
enum vmarg_t {
	label_a = 0,
	global_a = 1,
	formal_a = 2,
	local_a = 3,
	number_a = 4,
	string_a = 5,
	bool_a = 6,
	nil_a = 7,
	userfunc_a = 8,
	libfunc_a = 9,
	retval_a = 10
}




struct userfunc {
	unsigned address;
	unsigned localSize;
	string id;
};

double *numConst;
unsigned totalNumConsts;
char** stringConst;
unsigned totalStringConsts;
char** namedLibfuncs;
unsigned totalNamedLibfuncs;
userfunc* userFuncs;
unsigned totalUserFuncs;


extern void generate_ADD 					(quad *quad);
extern void generate_SUB 					(quad *quad);
extern void generate_MUL 					(quad *quad);
extern void generate_DIV 					(quad *quad);
extern void generate_MOD 					(quad *quad);
extern void generate_NEWTABLE 				(quad *quad);
extern void generate_TABLEGETELM 			(quad *quad);
extern void generate_TABLESETELEM			(quad *quad);
extern void generate_ASSIGN 				(quad *quad);
extern void generate_NOP 					(quad *quad);
extern void generate_JUMP 					(quad *quad);
extern void generate_IF_EQ 				    (quad *quad);
extern void generate_IF_NOTEQ 				(quad *quad);
extern void generate_IF_GREATER 			(quad *quad);
extern void generate_IF_GREATEREQ 			(quad *quad);
extern void generate_IF_LESS 				(quad *quad);
extern void generate_IF_LESSEQ 			    (quad *quad);
extern void generate_NOT					(quad *quad);
extern void generate_OR 					(quad *quad);
extern void generate_PARAM 					(quad *quad);
extern void generate_CALL 					(quad *quad);
extern void generate_GETRETVAL 				(quad *quad);
extern void generate_FUNCSTART				(quad *quad);
extern void generate_RETURN					(quad *quad);
extern void generate_FUNCEND				(quad *quad);

typedef void (*generator_func_t) (quad*);




struct avm_table;

struct avm_memcell {
   avm_memcell_t type;
   union {
      double numVal;
      int intVal;
      string strVal; //may use string
      unsigned char boolVal;
      struct avm_table *tableVal;
      unsigned int funcVal;
      string libfuncVal;   
   }data;
};

enum avm_memcell_t {
	number_m	= 0,
	string_m	= 1,
	bool_m		= 2,
	table_m		= 3,
	userfunc_m	= 4,
	libfunc_m	= 5,
	nil_m		= 6,
	undef_m		= 7
};

static void avm_initstack(void){
	for(int i = 0; i < AVM_STACKSIZE; i++) {
		AVM_WIPEOUT(stack[i]);
		stack[i].type = undef_m;
	}
}


avm_table* avm_tablenew(void);
void avm_tabledestroy(avm_table* t);
avm_memcell* avm_tablegetelem(avm_memcell* key);
void avm_tablesetelem(avm_memcell* key, avm_memcell* value);

struct avm_table_bucket {
	unsigned refCounter;
	avm_table_bucket* strIndexed[AVM_TABLE_HASHSIZE];
	avm_table_bucket* numIndexed[AVM_TABLE_HASHSIZE];
	unsigned total;
};

avm_tableincrefcounter(avm_table* t) { ++t->refCounter; }

void avm_tabledecrefcounter (avm_table* t){
	assert(t->refCounter > 0);
	if(!--t->refCounter)
		avm_tabledestroy(t);
}

void avm_tablebucketsinit(avm_table_bucket** p){
	for(int i = 0; i < AVM_TABLE_HASHSIZE; ++i)
		p[i] = (avm_table_bucket*) 0;
}

avm_table* avm_tablenew(void){
	avm_table* t = (avm_table*) malloc(sizeof(avm_table));
	AVM_WIPEOUT(*t);

	t->refCounter = t->total = 0;
	avm_tablebucketsinit(t->numIndexed);
	avm_tablebucketsinit(t->strIndexed);

	return t;
}

void avm_memcellclear(avm_memcell* m);

void avm_tablebucketsdestroy(avm_table_bucket** p){
	for (int i = 0; i < AVM_TABLE_HASHSIZE; ++i, ++p){
		for(avm_table_bucket *b = p; b;){
			avm_table_bucket* del = b;
			b = b->next;
			avm_memcellclear(&del->key);
			avm_memcellclear(&del->value);
			free(del);
		}
		p[i] = (avm_table_bucket*) 0;
	}
}

void avm_tabledestroy(avm_table* t){
	avm_tablebucketsdestroy(t->strIndexed);
	avm_tablebucketsdestroy(t->numIndexed);
	free(t);
}



avm_memcell* avm_translate_operand (vmarg* arg, avm_memcell* reg) {
    switch (arg->type){
        //variables
        case global_a: return (&stack[AVM_STACKSIZE-1-arg->val]);
        case local_a: return (&stack[topsp-arg->val]);
        case formal_a: return (&stack[topsp+AVM_STACKENV_SIZE+1+arg->val]);
        case retval_a: return (&retval);
        //case integer_a:
        case number_a: {
            reg->type = number_m;
            reg->data.numVal = consts_getnumber(arg->val);//constArray[arg->val].value->doubletype;
	 	    return reg;
        }	 
        case string_a: {
	 	    reg->type = string_m;
	 	    reg->data.strVal = consts_getstring(arg->val); //= strdup(constArray[arg->val].value->strtype);
	 	    return reg;
        }
        case bool_a: {
	 	    reg->type = bool_m;
	 	    reg->data.boolVal = arg->val;
	 	    return reg;
        }
        
        case nil_a: reg->type = nil_m; return reg;

        case userfunc_a: {
            reg->type = userfunc_m;
            reg->data.funcVal = arg->val; //= userFunctions[FindFunctionUserByAddr(arg->val)]->taddress;
            //assert(reg->data.funcVal);
            return reg;
        }
        case libfunc_a: {
            reg->type = libfunc_m;
            reg->data.libfuncVal = libfuncs_getused(arg->val); //=strdup(libFunctions[arg->val]->name);
            return reg;
        }
        default: assert(0);
		    //printf("DEBUG:argtype:%d\n",arg->type);
    }
}

execute_func_t executeFuncs[] = {
    execute_assign,
    execute_add, 
    execute_sub,
    execute_mul,	
    execute_div,	
    execute_mod,
    execute_unimus,
    execute_and,
    execute_or,
    execute_not,
    execute_jeq,
    execute_jne,
    execute_jle,
    execute_jge,
    execute_jlt,
    execute_jgt,
    execute_call,
    execute_pusharg,
    execute_funcenter,
    execute_funcexit,
    execute_newtable,
    execute_tablegetelem,
    execute_tablesetelem,
    execute_nop
};

void execute_cycle(void){
    if(executionFinished) return;

    if(pc == AVM_ENDING_PC){
	    //printf("DEBUG:%d\n",pc);
        executionFinished = 1;
        return;
    }
    else {
        assert(pc < AVM_ENDING_PC);
        instruction* instr = code + pc;
        //printf("DEBUG:%d\n",instr -> opcode);
        assert(instr->opcode >= 0 && instr->opcode <= AVM_MAX_INSTRUCTIONS);
        if(instr->srcLine)
            currLine = instr -> srcLine;
        unsigned int oldPC = pc; 
        (*executeFuncs[instr->opcode]) (instr);
        if(pc == oldPC)
			++pc;
   }
}

void avm_callsaveenviroment(void){
	avm_push_envvalue(totalActuals);
	avm_push_envvalue(pc+1);
	avm_push_envvalue(top + totalActuals + 2);    //call (sosimo perivalontos kai klhsh)
	avm_push_envvalue(topsp);
}

totalActuals = 0;
userfunc* funcInfo = avm_getfuncinfo(pc);   //funcenter
topsp = top;
top = top - funcInfo->localSize;


void execute_funcexit(instruction *unused){
	unsigned int oldTop = top;
	top = avm_get_envvalue(topsp + AVM_SAVEDTOP_OFFSET);
	pc = avm_get_envvalue(topsp + AVM_SAVEDPC_OFFSET);
	topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);     //funcexit
	//const_s tmpconst_s = constArray[topsp];
	int tmp_s = stack[topsp].data.numVal;
	while(oldTop++ <= top){
		avm_memcellclear(&stack[oldTop]);
	}
}

avm_assign(&stack[top], arg);
++totalActuals;                   // pusharg
avm_dec_top();


memclear_func_t memclearFuns[] = {
	0, //number
	memclear_string,
	0, //bool
	memclear_table,
	0, //userfunc
	0, //libfunc
	0, //nil
	0 //undef
};

avm_memcellclear (avm_memcell* m){
	if(m->type != undef_m) {
		memclear_func_t f = memclearFuncs[m->type];
		if (f)
			(*f)(m);
		m->type = undef_m;
	}
}

typedef void (*memclear_func_t) (avm_memcell*);

void memclear_string(avm_memcell* m){
	assert(m->data.strVal);
	free(m->data.strVal);
}

void memclear_table(avm_memcell* m){
	assert(m->data.tableVal);
	avm_tabledecrefcounter(m->data.tableVal);
}


extern void avm_warning(string format, ...);
extern void avm_assign(avm_memcell* lv, avm_memcell* rv);



void execute_assign (instruction *instr){

	avm_memcell *lv = avm_translate_operand(&instr->result, (avm_memcell *) 0);
	avm_memcell *rv = avm_translate_operand(&instr->arg1, &ax);

	assert(lv && (&stack[AVM_STACKSIZE-1] >= lv && lv > &stack[top] || lv==&retval ));
	assert(rv);	
	
	avm_assign(lv, rv);
}


void avm_assign(avm_memcell* lv, avm_memcell* rv){
	
	if(lv == rv)
		return;

	if (lv->type == table_m && rv->type == table_m && lv->data.tableVal == rv.data.tableVal) 
		return;
	
	if(rv->type == undef_m ||rv->type ==  nil_m)
		avm_warning("assigning from 'undef' content!");
	
	avm_memcellclear(lv);
	
	memcpy(lv, rv, sizeof(avm_memcell));
	
	if(lv -> type == string_m)
		lv->data.strVal = strdup(rv->data.strVal);

	else if(lv->type == number_m)
		lv->data.numVal = rv->data.numVal;
	
	else if(lv->type = bool_m)
		lv->data.boolVal = rv->data.boolVal;
	
	else if(lv->type == userfunc_m)
		lv->data.funcVal = rv->data.funcVal;
	
	else if(lv->type == table_m)
		lv->data.tableVal = rv->data.tableVal;
	
	else if(lv->type == libfunc_m)
		lv->data.libfuncVal = rv->data.libfuncVal;
	
}


extern void avm_error(string format, ...);
extern string avm_tostring(avm_memcell*);
extern void avm_calllibfunc(string funcName);
extern void avm_callsaveenviroment(void);

void execute_call(instruction *instr){

	avm_memcell* func = avm_translate_operand(instr->result, &ax);
	assert(func);
	avm_callsaveenviroment();

	switch(func->type){

		case userfunc_m: {
			pc = func->data.funcVal;
			assert(pc < AVM_ENDING_PC);
			assert(code[pc].opcode == funcenter_v);
			break;
		}
		
		case string_m: avm_calllibfunc(func -> data.strVal);  break;
		
		case libfunc_m: avm_calllibfunc(func -> data.libfuncVal); break;
			
		default: {
			string s = all_tostring(func);
			avm_error("call: cannot bind to function!");
			free(s);
			//executionFinished = 1;
		}
	}
}

unsigned totalActuals = 0;

void avm_dec_top(void){
	if(!top){
		avm_error("stack overflow");
		//executionFinished = 1;
	}
	else
		--top;
}

void avm_push_envvalue(unsigned int val){
	stack[top].type = number_m;
	stack[top].data.numVal = val;
	avm_dec_top();
}

void avm_callsaveenviroment(void){
	avm_push_envvalue(totalActuals);
	avm_push_envvalue(pc + 1);
	avm_push_envvalue(top + totalActuals + 2);
	avm_push_envvalue(topsp);
}



extern userfunc* avm_getfuncinfo(unsigned address);

void execute_funcenter(instruction *instr){
	avm_memcell *func = avm_translate_operand(instr->result, &ax);
	assert(func);
	assert(pc == func -> data.funcVal);
	
	totalActuals = 0;
	userfunc *funcInfo = avm_getfuncinfo(pc);
	topsp = top;
	top = top - funcInfo->localSize;
}





unsigned avm_get_envalue(unsigned i) {
    assert(stack[i].type = number_m);
    unsigned val = (unsigned) stack[i].data.numVal;
    assert(stack[i].data.numVal == ((double) val));
    return val;
}

void execute_funcexit (instruction * unused) {
    unsigned oldTop = top;
    top = avm_get_envalue(topsp + AVM_SAVEDTOP_OFFSET);
    pc = avm_get_envalue(topsp + AVM_SAVEDPC_OFFSET);
    topsp = (avm_get_envalue(topsp + AVM_SAVEDTOPSP_OFFSET));

    while(++oldTop <= top)
        avm_memcellclear(&stack[oldTop]);
}

typedef void (*library_func_t) (void) ;
library_func_t avm_getlibraryfunc (char* id);

void avm_callibfunc (char* id) {
    library_func_t f = avm_getlibraryfunc(id);
    if (!f) {
        avm_error("unsupported lib func '%s' called!",id);
        executionFinished = 1;
    }
    else {
        topsp = top;
        totalActuals = 0;
        (*f) ();
        if(!executionFinished)
            execute_funcexit((instruction*) 0);
    }
}

unsigned avm_totalactuals(void) {
    return avm_get_envalue(topsp + AVM_NUMACTUALS_OFFSET);
}

avm_memcell* avm_getactual (unsigned i) {
    assert(i < avm_totalactuals());
    return &stack[topsp + AVM_STACKENV_SIZE + 1 + i];
}

void libfunc_print (void) {
    unsigned n = avm_totalactuals();
    for(int i = 0; i < n; ++i) {
        string = avm_tostring(avm_getactual(i));
        puts(s);
        free(s);
    }
}

void avm_registerlibfunc (string id, library_func_t addr);

void execute_pusharg (instruction *instr) {
    avm_memcell * arg = avm_translate_operand(&instr->arg1, &ax);
    assert(arg);
    avm_assign(&stack[top],arg);
    ++totalActuals;
    avm_dec_top();
}

typedef string (*tostring_func_t) (avm_memcell*);

extern string number_tostring (avm_memcell*);
extern string string_tostring (avm_memcell*);
extern string bool_tostring (avm_memcell*);
extern string table_tostring (avm_memcell*);
extern string userfunc_tostring (avm_memcell*);
extern string libfunc_tostring (avm_memcell*);
extern string nil_tostring (avm_memcell*);
extern string undef_tostring (avm_memcell*);

tostring_func_t tostringFuncs[] = (
    number_tostring,
    string_tostring,
    bool_tostring,
    table_tostring,
    userfunc_tostring,
    libfunc_tostring,
    nil_tostring,
    undef_tostring
);

string avm_tostring(avm_memcell *m) {
    assert(m->type >=0 && m->type = undef_m);
    return (*tostringFuncs[m->type] (m));
}




void avm_initialize(void){
	avm_initstack();

	avm_registerlibfunc("print", libfunc_print);
	avm_registerlibfunc("typeof", libfunc_typeof);
}

typedef void(*library_func_t) (void);
library_func_t avm_getlibraryfunc(string id); // typical hashing

void avm_calllibfunc(char* id){
	library_func_t f = avm_getlibraryfunc(id);
	//printf("DEBUG:FNAME %s\n",f->name);
	if(!f){
		avm_error("unsupported lib func called!");
		executionFinished = 1;
	}
	else{
		topsp = top;
		totalActuals = 0;
        (*f) ();

		if(!executionFinished)
			execute_funcexit((instruction*) 0);
	}
}


unsigned avm_totalactuals(void){
	return avm_get_envvalue(topsp + AVM_NUMACTUALS_OFFSET);
}

avm_memcell *avm_getactual(unsigned i){
	assert(i < avm_totalactuals());
	return &stack[topsp + AVM_STACKENV_SIZE + 1 + i];
}

void libfunc_print(){
	unsigned i = 0;
	unsigned n = 0;	
	n = avm_totalactuals();
	//printf("DEBUG: TOTALACTUALS:%d\n",n);
	for(i = 0; i < n; ++i){  
		string s = avm_tostring(avm_getactual(i));
		//printf("%s", s);
		puts(s);  //strdup(s)
		if(*s)	free(s);
	}
}

void avm_registerlibfunc(string id, library_func_t addr);


void libfunc_typeof(){
	unsigned n = avm_totalactuals();
	if(n != 1){
		avm_error("One argument (not many) expected in 'typeof'.");
	}
	else{
		avm_memcellclear(&retval);
		retval.type = string_m;
		retval.data.strVal = strdup(typeStrings[avm_getactual(0)->type]);//(constArray[avm_getactual(0)->type].value->strtype);
	}
}

void libfunc_totalarguments(){
	unsigned int p_topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET );
	avm_memcellclear(&retval);

	if(!p_topsp){
		avm_warning("Totalarguments() (library function) called outside of function!");
		retval.type = nil_m;
	}
	else{
		retval.type = number_m;
		retval.data.numVal = avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET);
	}
}



#define execute_add execute_arithmetic
#define execute_sub execute_arithmetic
#define execute_mul execute_arithmetic
#define execute_div execute_arithmetic
#define execute_mod execute_arithmetic

typedef double (*arithmetic_func_t) (double x, double y);

double add_impl( double x, double y ){
	return x+y;
}

double sub_impl( double x, double y ){
	return x-y;
}

double mul_impl( double x, double y ){
	return x*y;
}

double div_impl( double x, double y ){
	if( y == 0){avm_error("Error:Division with zero attempted.\n");}
	return x/y;
}

double mod_impl( double x, double y ){
	if( y == 0){avm_error("Error:Division with zero attempted.\n");}
	return (( unsigned ) x ) % (( unsigned ) y );
}

arithmetic_func_t arithmeticFuncs[] ={
	add_impl,
	sub_impl,
	mul_impl,
	div_impl,
	mod_impl
};


void execute_arithmetic (instruction* instr){
	avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell*)0);  // maybe some without &
	avm_memcell* rv1= avm_translate_operand(&instr->arg1,&ax);
	avm_memcell* rv2= avm_translate_operand(&instr->arg2,&bx);

	assert(lv && (&stack[0] <= lv && &stack[top] > lv || lv == &retval ));
	assert(rv1 && rv2);

	if (rv1->type != number_m || rv2->type != number_m){
		avm_error("not a number arithmetic!\n");
		executionFinished=1;
	}
	else{
		arithmetic_func_t op = arithmeticFuncs[instr->opcode - add_v];
		avm_memcellclear(lv);
		lv->type = number_m;
		lv->data.numVal = (*op)(rv1->data.numVal,rv2->data.numVal);
	}
	//printf("DEBUG VALUE:%d\n",(int)lv->data.numVal);
}



unsigned char number_tobool (avm_memcell* m) {
	return m->data.numVal !=0; 
}

unsigned char string_tobool (avm_memcell* m) {	
	return m->data.strVal[0] !=0;
}

unsigned char bool_tobool (avm_memcell* m) {
	return m->data.boolVal !=0; 
}

unsigned char table_tobool (avm_memcell* m) {	
	return 1; 
}

unsigned char userfunc_tobool (avm_memcell* m) {
	return 1; 
}

unsigned char libfunc_tobool (avm_memcell* m) {
	return 1; 
}

unsigned char nil_tobool (avm_memcell* m) {	
	return 0; 
}
	
unsigned char undef_tobool (avm_memcell* m) {
	return 0; 
}

tobool_func_t toboolFuncs[] = {
	number_tobool,
	string_tobool,
	bool_tobool,
	table_tobool,
	userfunc_tobool,
	libfunc_tobool,
	nil_tobool,
	undef_tobool
};

unsigned char avm_tobool(avm_memcell* m){
	assert(m->type >=0 && m->type < undef_m);
	return (*toboolFuncs[m->type])(m);
}



void execute_jeq(instruction* instr){

	assert(instr->result->type == label_a);

	avm_memcell* rv1 = avm_translate_operand(&instr->arg1, &ax);  //maybe without &
	avm_memcell* rv2 = avm_translate_operand(&instr->arg2, &bx);

    unsigned char result = 0;


	if (rv1->type == undef_m || rv2->type == undef_m) {
		avm_error("'Undef' involved in equality!");
	} else if(rv1->type==nil_m || rv2->type ==nil_m) {
		result = (rv1->type == nil_m) && (rv2->type == nil_m);
	} else if(rv1->type == bool_m || rv2->type == bool_m) {
		result=rv1->data.boolVal == rv2->data.boolVal;
	} else if(rv1->type != rv2->type) {
		avm_error("String is illegal!"); //,typeStrings[rv1->type]);
    } else {
		switch (rv1->type) {
			case number_m: {
				result = rv1->data.numVal == rv2->data.numVal;	
				break;
			}
			case string_m: {
				result = !(strcmp(rv1->data.strVal,rv2->data.strVal));		
				break;
			}
			case table_m: {
				result = rv1->data.tableVal == rv2->data.tableVal ; 	
				break;	
			}
			case userfunc_m: {
				result = rv1->data.funcVal == rv2->data.funcVal;			
				break;
			}
			case libfunc_m: {
				result = !(strcmp(rv1->data.libfuncVal,rv2->data.libfuncVal));		
				break;
			}

			default: assert(0);
		}
	}
	
	if(!executionFinished && (result == 1))	pc=instr->result->val;
}

string typeStrings[]={
    "number",
    "string",
    "bool",
    "table",
    "userfunc",
    "libfunc",
    "nil",
    "undef"
};



void execute_newtable(instruction* instr){

	avm_memcall* lv = avm_translate_operand(&instr->result, (avm_memcall*) 0);

	avm_memcellclear(lv);

	lv->type = table_m;
	lv->data.tableVal = avm_tablenew();
	avm_tableincrefcounter(lv->data.tableVal);
}

avm_memcell* avm_tablegetelem(avm_table* table, avm_memcell* index);

void avm_tablesetelem(avm_table* table, avm_memcell* index, avm_memcell* content);


void execute_tablegetelem(instruction* instr){
	avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell*) 0);	
	avm_memcell* t = avm_translate_operand(&instr->arg1, (avm_memcell*) 0);
	avm_memcell* i = avm_translate_operand(&instr->arg2, &ax);

	assert(lv && (&stack[0] <= lv && &stack[top] > lv || lv == &retval));
	assert(t && &stack[0] <= t && &stack[top] > t);
	assert(i);

	avm_memcellclear(lv);
	lv->type = nil_m;

	if(t->type != table_m){
		avm_error("Illegal use of type %s as table!", typeStrings[t->type]);
	}else{
		string ts = avm_tostring(t);
		string is = avm_tostring(i);
		avm_warning("%s[%s] not found!", ts, is);
		free(ts);
		free(is);
	}
}

void execute_tablesetelem(instruction* instr){
	avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell*) 0);
	avm_memcell* i = avm_translate_operand(&instr->arg1, &ax);
	avm_memcell* c = avm_translate_operand(&instr->arg2, &bx);

	assert(t && &stack[0] <= t && &stack[top] > t);
	assert(i && c);

	if(t->type != table_m)
		avm_error("Illegal use of type %s as table!", typeString[t->type]);
	else
		avm_tablesetelem(t->data.tableVal, i, c);
}

