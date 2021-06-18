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
};

struct vmarg { 
	vmarg_t type; 
	unsigned val; 
};

enum vmopcode {
	assign_v, 	add_v,		sub_v,
	mul_v,		divide_v,		mod_v,
	uminus_v,			if_eq_v,		if_not_eq_v,
	if_lesseq_v,	if_greatereq_v,	if_less_v,
	if_greater_v,	call_v,
	ret_v,		getretval_v,	funcenter_v,
	funcexit_v,	jump_v,
	tablegetelem_v,	tablesetelem_v, or_v, not_v, nop_v,
	and_v, jeq_v, jne_v, jle_v, jge_v, jlt_v, jgt_v, pusharg_v, newtable_v,
};
struct instruction {
    vmopcode opcode;
    vmarg* result;
    vmarg* arg1;
    vmarg* arg2;
    unsigned srcLine; // we may use unsigned int
};