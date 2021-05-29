unsigned consts_newstring(string s);
unsigned consts_newnumber(double n);
unsigned libfuncs_newused(string s);
struct vmarg { vmarg_t type; unsigned val; }


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
                                switch(e->sym->space){            
                                    case programVar:	arg->type = global_a;   break;
                                    case functionLocal:	arg->type = local_a;    break;
                                    case formalArg:		arg->type = formal_a;   break;
                                    default: assert(0);
                                }
                                break;
		                    }
        // Constants
		case constbool_e: 	{
								//if(e->boolConst == '0') arg->val = 0;
								//else arg->val = 1;
                                arg->val = e->constBool;
								arg->type = bool_a;    break;
		                    }
		case conststring_e:	{
								arg->val = consts_newstring(e->strConst); //  INSERTER_STRING(e->strConst);
								arg->type = string_a;	break;
						 	}
		case constnum_e:	{
									
								arg->val = consts_newnumber(e->numConst); //INSERTER_NUM(e->numConst);
								arg->type = number_a;   break;
							}

		case nil_e:			{
								arg->type = nil_a; break;
							}
        //functions
		case programfunc_e: {
								arg->type = userfunc_a;
								arg->val = e->sym->taddress; //INSERTER_USERFUNC(e->sym->value.funcVal->taddress, e->sym->value.funcVal->totallocals,e->sym->value.funcVal->totalargs, (char*) e->sym->value.funcVal->name);
								break;
							}
		case libraryfunc_e:	{
								arg->type = libfunc_a;
								arg->val = libfuncs_newused(e->sym->name); //INSERTER_LIBFUNC((char*) e->sym->value.funcVal->name);
								break;
							}
		default :   assert(0);
	}
}



struct instruction {
    vmopcode opcode;
    vmarg result;
    vmarg arg1;
    vmarg arg2;
    unsigned srcLine; // we may use unsigned int
};



struct incomplete_jump {
    unsigned instrNo;       // The jump instruction number
    unsigned iaddress;      // The i-code jump-target address
    incomplete_jump* next;  // a trivial linked list
}

incomplete_jump* ij_head = (incomplete_jump*) 0;
unsigned ij_total = 0;

void add_incomplete_jump (unsigned instrNo, unsigned iaddress);


void patch_incomplete_jumps() {
    /*
    for each incomplete jump x do {
    if x.iaddress = intermediate code size then
    instructions[x.instrNo].result = target code size;
    else
    instructions[x.instrNo].result = quads[x.iaddress].taddress;
    }*/
}


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

void generate (void) {
    for(unsigned i = 0; i < total; ++i)
        (*generators[quads[i].op]) (quads + i)
}


struct avm_table;

struct avm_memcell {
   avm_memcell_t type;
   union {
      double numVal;
      //int intVal;
      char *strVal; //may use string
      unsigned char boolVal;
      struct avm_table *tableVal;
      unsigned int funcVal;
      char *libfuncVal;   
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

execute_func_t executeFuncs[]={
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
    execute_nop,
};














void execute_add				(instruction* instr); 
void execute_sub				(instruction* instr);
void execute_mul				(instruction* instr);
void execute_div				(instruction* instr);
void execute_mod				(instruction* instr);
void execute_assign				(instruction* instr);
void execute_call				(instruction* instr);
void execute_pusharg			(instruction* instr);
void execute_funcenter			(instruction* instr);
void execute_funcexit			(instruction* instr);
void execute_jeq				(instruction* instr);
void execute_jne				(instruction* instr);
void execute_jle				(instruction* instr);
void execute_jge				(instruction* instr); 
void execute_jlt				(instruction* instr);
void execute_jgt				(instruction* instr);
void execute_newtable			(instruction* instr);
void execute_tablegetelem		(instruction* instr);
void execute_tablesetelem		(instruction* instr);
void execute_nop				(instruction* instr);
void execute_jump				(instruction* instr);

void execute_arithmetic			(instruction* instr);

void execute_comparison			(instruction* instr);