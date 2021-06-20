#include "binaryManager.h"

#define AVM_STACKSIZE 4096
#define AVM_ENDING_PC code.size()
#define AVM_MAX_INSTRUCTIONS (unsigned) nop_v
#define AVM_WIPEOUT(m) memset(&(m), 0, sizeof(m))
#define AVM_NUMACTUALS_OFFSET +4
#define AVM_SAVEDPC_OFFSET +3
#define AVM_SAVEDTOP_OFFSET +2
#define AVM_SAVEDTOPSP_OFFSET +1
#define AVM_STACKENV_SIZE 4

avm_memcell ax, bx, cx;
avm_memcell retval;
int top, topsp;
int totalActuals = 0;
int currLine = 0;
bool executionFinished = false;
int pc = 0;

avm_memcell avm_stack[AVM_STACKSIZE];
vector<double> numConst;
vector<string> stringConst;
vector<string> libFuncConst;
vector<userFunc*> userFuncs;
vector<instruction*> code;


//CRAPPPP 

typedef char* (*tostring_func_t) (avm_memcell*);
extern char* number_tostring (avm_memcell*);
extern char* string_tostring (avm_memcell*);
extern char* bool_tostring (avm_memcell*);
extern char* table_tostring (avm_memcell*);
extern char* userfunc_tostring (avm_memcell*);
extern char* libfunc_tostring (avm_memcell*);
extern char* nil_tostring (avm_memcell*);
extern char* undef_tostring (avm_memcell*);

tostring_func_t tostringFuncs[] = {
    number_tostring,
    string_tostring,
    bool_tostring,
    table_tostring,
    userfunc_tostring,
    libfunc_tostring,
    nil_tostring,
    undef_tostring
};


char* number_tostring(avm_memcell* m){
	assert(m->type == number_m);
	return strdup(to_string(m->data.numVal).c_str());

}
char* string_tostring(avm_memcell* m){
	return strdup(m->data.strVal);
}

char* bool_tostring(avm_memcell* m){
	assert(m->type == bool_m);
	if(m->data.boolVal) return strdup("false");
	else return strdup("true");
}

char* table_tostring(avm_memcell* m){
	return strdup("change me pls! :)"); // fix later
}

char* userfunc_tostring(avm_memcell* m){
	assert(m->type == userfunc_m);
	return strdup("Func");

}

char* libfunc_tostring(avm_memcell* m){
	return strdup("LibFunc");
}

char* nil_tostring(avm_memcell* m){
	return strdup("Nil");
}
char* undef_tostring(avm_memcell* m){
	return strdup("Undef");

}
//END CRAPPP

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
void avm_error(string v){
	printf("%s",v.c_str());
	exit(0);
}
void avm_warning(string v){
	printf("%s",v.c_str());
}
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
	if(y == 0){avm_error("Error:Division with zero attempted.\n");}
	return x/y;
}

double mod_impl( double x, double y ){
	if(y == 0){avm_error("Error:Division with zero attempted.\n");}
	return (( unsigned ) x ) % (( unsigned ) y );
}

arithmetic_func_t arithmeticFuncs[] ={
	add_impl,
	sub_impl,
	mul_impl,
	div_impl,
	mod_impl
};



double avm_get_envalue(int i) {
    assert(avm_stack[i].type == number_m);
    double val = avm_stack[i].data.numVal;
    return val;
}
int avm_get_envvalue(int i){
    int val = (int) avm_stack[i].data.numVal;
    return val;
}
double consts_getnumber(int idx){
	return numConst[idx];
}

char* consts_getstring(int idx){
	return strdup(stringConst[idx].c_str());
}

char* libfuncs_getused(int idx){
	return strdup(stringConst[idx].c_str());
}

avm_memcell* avm_translate_operand (vmarg* arg, avm_memcell* reg) {
    switch (arg->type){
        case global_a: return (&avm_stack[AVM_STACKSIZE-1-arg->val]);
        case local_a: return (&avm_stack[topsp-arg->val]);
        case formal_a: return (&avm_stack[topsp+AVM_STACKENV_SIZE+1+arg->val]);
        case retval_a: return (&retval);
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
        default: 
		printf("DEBUG:argtype:%d\n",arg->type);
		assert(0);
    }
}

void avm_dec_top(){
	if(!top){
		avm_error("avm_stack overflow");
	}else --top;
}

void avm_push_envvalue(int val){
	avm_stack[top].type = number_m;
	avm_stack[top].data.numVal = val;
	avm_dec_top();
}

void avm_callsaveenviroment(){
	avm_push_envvalue(totalActuals);
	avm_push_envvalue(pc+1);
	avm_push_envvalue(top + totalActuals + 2); 
	avm_push_envvalue(topsp);
}

void avm_assign(avm_memcell* lv, avm_memcell* rv){
	
	if(lv == rv)return;
	if (lv->type == table_m && rv->type == table_m && lv->data.tableVal == rv->data.tableVal) return;

	if(rv->type == undef_m ||rv->type ==  nil_m)
		avm_warning("assigning from 'undef' content!");
	
	//avm_memcellclear(lv);
	
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
		lv->data.libfuncVal = strdup(rv->data.libfuncVal);
	
}
void avm_calllibfunc(char* id){
	/*
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
	*/
}

char* avm_tostring(avm_memcell *m) {
    assert(m->type >=0 && m->type == undef_m);
    return strdup((*tostringFuncs[m->type])(m));
}

userFunc* avm_getfuncinfo(int address) {
	for(auto i : userFuncs) if(i->address == address) return i;
	printf("DEN TIN VRIKAME GTXM!\n\n\n");
	return NULL;
}
//void avm_tableincrefcounter(avm_table* t) { ++t->refCounter; }

/////////////////////////////////////////////  EXECUTE FUNCTIONS BELOW  /////////////////////////////////////////////


void execute_assign (instruction *instr){

	avm_memcell *lv = avm_translate_operand(instr->result, (avm_memcell *) 0);
	avm_memcell *rv = avm_translate_operand(instr->arg1, &ax);

	assert(lv && (&avm_stack[AVM_STACKSIZE-1] >= lv && lv > &avm_stack[top] || lv==&retval ));
	assert(rv);	
	
	avm_assign(lv, rv);
}

void execute_call(instruction *instr){

	avm_memcell* func = avm_translate_operand(instr->result, &ax); //maybe change to arg1 HEEEHHEHEHHE HEREEE
	assert(func);
	avm_callsaveenviroment();

	switch(func->type){

		case userfunc_m: {
			pc = func->data.funcVal;
			assert(pc < AVM_ENDING_PC);
			assert(code[pc]->opcode == funcenter_v);
			break;
		}
		
		case string_m: avm_calllibfunc(func -> data.strVal);  break;
		
		case libfunc_m: avm_calllibfunc(func -> data.libfuncVal); break;
			
		default: {
			string s = avm_tostring(func);
			avm_error("call: cannot bind to function!");
			executionFinished = true;
		}
	}
}


void execute_funcenter(instruction *instr){
	avm_memcell *func = avm_translate_operand(instr->result, &ax);
	assert(func);
	assert(pc == func -> data.funcVal);
	
	totalActuals = 0;
	userFunc* funcInfo = avm_getfuncinfo(pc);
	topsp = top;
	top = top - funcInfo->localSize;
}

void execute_funcexit (instruction* unused) {
    int oldTop = top;
    top = avm_get_envalue(topsp + AVM_SAVEDTOP_OFFSET);
    pc = avm_get_envalue(topsp + AVM_SAVEDPC_OFFSET);
    topsp = (avm_get_envalue(topsp + AVM_SAVEDTOPSP_OFFSET));

    while(++oldTop <= top){
       // avm_memcellclear(&avm_stack[oldTop]);
	}
}

void execute_pusharg(instruction *instr) {
    avm_memcell * arg = avm_translate_operand(instr->arg1, &ax);
    assert(arg);
    avm_assign(&avm_stack[top],arg);
    ++totalActuals;
    avm_dec_top();
}



void execute_arithmetic (instruction* instr){
	avm_memcell* lv = avm_translate_operand(instr->result, (avm_memcell*)0);  // maybe some without &
	avm_memcell* rv1= avm_translate_operand(instr->arg1,&ax);
	avm_memcell* rv2= avm_translate_operand(instr->arg2,&bx);

	assert(lv && (&avm_stack[0] <= lv && &avm_stack[top] > lv || lv == &retval ));
	assert(rv1 && rv2);

	if (rv1->type != number_m || rv2->type != number_m){
		avm_error("not a number arithmetic!\n");
		executionFinished=true;
	}
	else{
		arithmetic_func_t op = arithmeticFuncs[instr->opcode - add_v];
		//avm_memcellclear(lv);
		lv->type = number_m;
		lv->data.numVal = (*op)(rv1->data.numVal,rv2->data.numVal);
	}
	//printf("DEBUG VALUE:%d\n",(int)lv->data.numVal);
}



void execute_jeq(instruction* instr){

	assert(instr->result->type == label_a);

	avm_memcell* rv1 = avm_translate_operand(instr->arg1, &ax);  //maybe without &
	avm_memcell* rv2 = avm_translate_operand(instr->arg2, &bx);

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

void execute_unimus (instruction*){
	
}
void execute_and (instruction*){
	
}
void execute_or (instruction*){
	
}
void execute_not (instruction*){
	
}
void execute_jne (instruction*){
	
}
void execute_jle (instruction*){
	
}
void execute_jge (instruction*){
	
}
void execute_jlt (instruction*){
	
}
void execute_jgt (instruction*){
	
}
void execute_nop (instruction*){
	
}

void execute_newtable(instruction* instr){
/*
	avm_memcell* lv = avm_translate_operand(instr->result, (avm_memcell*) 0);

	//avm_memcellclear(lv);

	lv->type = table_m;
	lv->data.tableVal = avm_tablenew();
	//avm_tableincrefcounter(lv->data.tableVal);
	*/
}

void execute_tablegetelem(instruction* instr){
	/*
	avm_memcell* lv = avm_translate_operand(instr->result, (avm_memcell*) 0);	
	avm_memcell* t = avm_translate_operand(instr->arg1, (avm_memcell*) 0);
	avm_memcell* i = avm_translate_operand(instr->arg2, &ax);

	assert(lv && (&avm_stack[0] <= lv && &avm_stack[top] > lv || lv == &retval));
	assert(t && &avm_stack[0] <= t && &avm_stack[top] > t);
	assert(i);

	//avm_memcellclear(lv);
	lv->type = nil_m;

	if(t->type != table_m){
		avm_error("Illegal use of type %s as table!", typeStrings[t->type]);
	}else{
		string ts = avm_tostring(t);
		string is = avm_tostring(i);
		printf("%s[%s] not found!", ts, is);
	}
	*/
}

void execute_tablesetelem(instruction* instr){
	/*
	avm_memcell* lv = avm_translate_operand(instr->result, (avm_memcell*) 0);
	avm_memcell* i = avm_translate_operand(instr->arg1, &ax);
	avm_memcell* c = avm_translate_operand(instr->arg2, &bx);

	assert(t && &avm_stack[0] <= t && &avm_stack[top] > t);
	assert(i && c);

	if(t->type != table_m)
		avm_error("Illegal use of type %s as table!", typeString[t->type]);
	//else
		//avm_tablesetelem(t->data.tableVal, i, c);
	*/
}

/////////////////////////////////////////////EXECUTE FUNCTIONS ABOVE/////////////////////////////////////////////


void execute_cycle(){
    if(executionFinished) return;
    if(pc == AVM_ENDING_PC){
	    //printf("DEBUG:%d\n",pc);
        executionFinished = true;
        return;
    }
    else {
        assert(pc < AVM_ENDING_PC);
        instruction* instr = code[pc];
        printf("DEBUGAAAA:%d \n",instr -> opcode);
		assert(instr->opcode >= 0 );
       // assert(instr->opcode >= 0 && instr->opcode <= AVM_MAX_INSTRUCTIONS);
        if(instr->srcLine) currLine = instr -> srcLine;
        int oldPC = pc; 
        (*executeFuncs[instr->opcode]) (instr);
        if(pc == oldPC) ++pc;
   }
}
