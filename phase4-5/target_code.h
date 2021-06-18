#include "array_management.h"
int nextinstructionlabel = 0;
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
struct vmarg { 
	vmarg_t type; 
	unsigned val; 
}
enum vmopcode {
	assign_v, 	add_v,		sub_v,
	mul_v,		divide_v,		mod_v,
	uminus_v,			if_eq_v,		if_not_eq_v,
	if_lesseq_v,	if_greatereq_v,	if_less_v,
	if_greater_v,	call_v,		param_v,
	ret_v,		getretval_v,	funcstart_v,
	funcend_v,	jump_v,		tablecreate_v,
	tablegetelem_v,	tablesetelem_v, and_v, or_v, not_v, nop_v
};
struct instruction {
    vmopcode opcode;
    vmarg result;
    vmarg arg1;
    vmarg arg2;
    unsigned srcLine; // we may use unsigned int
};

void make_operand 					(expr* e, vmarg* arg);
void make_numberoperand				(vmarg* arg, double val);
void make_booloperand 				(vmarg* arg, unsigned int val);

void add_incomplete_jump			(unsigned int instrNo, unsigned int iaddress);
void patchInstrLabel				(unsigned int instrNo, unsigned int iaddress);
void patchIncompleteJumps			(unsigned int totalQuads);

void make_booloperand 				(vmarg *arg, unsigned int logical);
void reset_operand 					(vmarg *arg);

void generate						(vmopcode op, quad *quad);
void generate_ADD 					(quad *quad);
void generate_SUB 					(quad *quad);
void generate_MUL 					(quad *quad);
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

void add_incomplete_jump (unsigned instrNo, unsigned iaddress);

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

void generate (void) {
    for(unsigned i = 0; i < total; ++i)
        (*generators[quads[i].op]) (quads + i);
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
                                arg->val = e->constBool;
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
								arg->val = userfuncs_newfuncs(-1,-1,e->sym->name);
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
int nextinstructionlabel(){
	return nextinstructionlabel++;
}
void make_numberoperand(vmarg* arg, double val){
	arg->val = consts_newnumber(val);
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
	quad->expr->iaddress = nextinstructionlabel();
	emitInstruction(t);
}
void generate_ADD (quad *quad) { generate(add, quad); }
void generate_SUB (quad *quad) { generate(sub, quad); }
void generate_MUL (quad *quad) { generate(mul, quad); }
void generate_DIV (quad *quad) { generate(div, quad); }
void generate_MOD (quad *quad) { generate(mod, quad); }


void generate_NEWTABLE (quad *quad) { generate(newtable, quad); }
void generate_TABLEGETELM (quad *quad) { generate(tablegetelem, quad); }
void generate_TABLESETELEM (quad *quad) { generate(tablesetelem, quad); }
void generate_ASSIGN (quad *quad) { generate(assign, quad); }
void generate_NOP () { 
	instruction* t = new instruction;
	t->opcode=nop; 
	emitInstruction(t); 
} 

void generate_relational(vmopcode op, quad *quad) {
	instruction *t = new instruction;
	t->arg1 = new vmarg;
	t->arg2 = new vmarg;
	t->result = new vmarg;
	t->opcode = op;
	make_operand(quad->arg1, t->arg1);
	make_operand(quad->arg2, t->arg2);
	t->result->type = label_a;
	if (quad->label < currprocessedquad()) {
		t->result->value = quads[quad->label].iaddress;
	}else {
		add_incomplete_jump(nextinstructionlabel(), quad->label);
	}
	quad->iaddress = nextinstructionlabel();
	emitInstruction(t);
}

void generate_JUMP (quad *quad) { generate_relational(jump, quad); }
void generate_IF_EQ (quad *quad) { generate_relational(jeq, quad); }
void generate_IF_NOTEQ(quad *quad) { generate_relational(jne, quad); }
void generate_IF_GREATER (quad *quad) { generate_relational(jgt, quad); }
void generate_IF_GREATEREQ(quad *quad) { generate_relational(jge, quad); }
void generate_IF_LESS (quad *quad) { generate_relational(jlt, quad); }
void generate_IF_LESSEQ (quad *quad) { generate_relational(jle, quad); }

void generate_NOT (quad *quad) {
	quad->iaddress = nextinstructionlabel();
	instruction *t = new instruction;

	t->opcode = jeq;
	make_operand(quad->arg1, t->arg1);
	make_booloperand(t->arg2, false);
	t->result->type = label_a;
	t->result->value = nextinstructionlabel()+3;
	emitInstruction(t);

	t->opcode = assign;
	make_booloperand(t->arg1, false);
	reset_operand(t->arg2);
	make_operand(quad->result, t->result);
	emitInstruction(t);

	t->opcode = jump;
	reset_operand (t->arg1);
	reset_operand(t->arg2);
	t->result->type = label_a;
	t->result->value = nextinstructionlabel()+2;
	emitInstruction(t);

	t->opcode = assign;
	make_booloperand(t->arg1, true);
	reset_operand(t->arg2);
	make_operand(quad->result, t->result);
	emitInstruction(t);
}

void generate_OR (quad *quad) {
	quad->iaddress = nextinstructionlabel();
	instruction *t = new instruction;

	t->opcode = jeq;
	make_operand(quad->arg1, t->arg1);
	make_booloperand(t->arg2, true);
	t->result->type = label_a;
	t->result->value = nextinstructionlabel()+4;
	emitInstruction(t);

	make_operand(quad->arg2, t->arg1);
	t->result->value = 
	nextinstructionlabel()+3;
	emitInstruction(t);

	t->opcode = assign;
	make_booloperand(t->arg1, false);
	reset_operand(t->arg2);
	make_operand(quad->result, t->result);
	emitInstruction(t);

	t->opcode = jump;
	reset_operand (t->arg1);
	reset_operand(t->arg2);
	t->result->type = label_a;
	t->result->value = nextinstructionlabel()+2;
	emitInstruction(t);

	t->opcode = assign;
	make_booloperand(t->arg1, true);
	reset_operand(t->arg2);
	make_operand(quad->result, t->result);
	emitInstruction(t);
} 

// Kapos etsi einai alla mporei na thelei kai allages
void generate_AND (quad *quad) {
	quad->iaddress = nextinstructionlabel();
	instruction *t = new instruction;
	t->opcode = jeq;
	make_operand(quad->arg1, t->arg1);
	make_booloperand(t->arg2, true);
	t->result->type = label_a;
	t->result->value = nextinstructionlabel()+4;
	emitInstruction(t);
	
	make_operand(quad->arg2, t->arg1);
	t->result->value = nextinstructionlabel()+3;
	emitInstruction(t);

	t->opcode = assign;
	make_booloperand(t->arg1, false);
	reset_operand(t->arg2);
	make_operand(quad->result, t->result);
	emitInstruction(t);
	
	t->opcode = jump;
	reset_operand (t->arg1);
	reset_operand(t->arg2);
	t->result->type = label_a;
	t->result->value = nextinstructionlabel()+2;
	emitInstruction(t);

	t->opcode = assign;
	make_booloperand(t->arg1, true);
	reset_operand(t->arg2);
	make_operand(quad->result, t->result);
	emitInstruction(t);
}

void generate_PARAM(quad *quad) {
	quad->iaddress = nextinstructionlabel();
	instruction *t = new instruction;
	t->opcode = pusharg;
	make_operand(quad->arg1, t->arg1);
	emitInstruction(t);
}

void generate_CALL(quad *quad) {
	quad->iaddress = nextinstructionlabel();
	instruction *t = new instruction;
	t->opcode = callfunc;
	make_operand(quad->arg1, t->arg1);
	emitInstruction(t);
}

void generate_GETRETVAL(quad *quad) {
	quad->iaddress = nextinstructionlabel();
	instruction *t = new instruction;
	t->opcode = assign;
	make_operand(quad->result, t->result);
	arg->type = retval_a
	emitInstruction(t);
}

void generate_FUNCSTART(quad *quad) { 
	f = quad->result->sym;
	f->value.funcVal->iaddress = nextinstructionlabel();
	quad->iaddress = nextinstructionlabel();

	userfunctions.add(f->id, f->iaddress, f->totallocals);
	push(funcstack, f);

	instruction *t = new instruction;
	t->opcode = enterfunc;
	make_operand(quad->result, t->result);
	emitInstruction(t);
}

void generate_RETURN(quad *quad) { 
	quad->iaddress = nextinstructionlabel();
	instruction *t = new instruction;
	t->opcode = assign_v;

	make_retvalοperand(t->result);
	make_operand(quad->arg1, t->arg1);
	emitInstruction(t);

	f = top(funcstack);
	assert(f->returnList, nextinstructionlabel());

	t->opcode = jump_v;
	reset_operand(t->arg1);
	reset_operand(t->arg2);
	t->result->type = label_a;
	emitInstruction(t);
}

void generate_FUNCEND(quad *quad) {
 	f = pop(funcstack);
 	backpatch(f.returnList, nextinstructionlabel());

 	quad->iaddress = nextinstructionlabel();
 	instruction *t = new instruction;
 	t->opcode = funcexit_v;
		
 	make_operand(quadInput->result, t->result);
 	emitInstruction(t);
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