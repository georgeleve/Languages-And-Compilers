#include <bits/stdc++.h>
using namespace std;


enum SymbolType { GLOBAL, LOC, FORMAL, USERFUNC, LIBFUNC};

struct forstruct{
	int enter;
	int test;
};

enum scopespace_t {
	programVar,
	functionLocal,
	formalArg
};
typedef struct userFuncInfo{
	int address;
	int localSize;
	string id;
}userFunc;

typedef struct Information{
	enum SymbolType type;
	string name;
	unsigned int line;
	unsigned int offset;
	int taddress;
	scopespace_t scopeSpace;
	unsigned int scope;
} Information;

enum iopcode{
	assign=0, 	add=1,			sub=2,
	mul=3,		divide=4,		mod=5,
	uminus=6,	and_c=7,			or_c=8,
	not_c=9,		if_eq=10,		if_not_eq=11,
	if_lesseq=12,	if_greatereq=13,	if_less=14,
	if_greater=15,	call=16,		param=17,
	ret=18,		getretval=19,		funcstart=20,
	funcend=21,	jump=22,		tablecreate=23,	
	tablegetelem=24,			tablesetelem=25
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


struct expr {
	expr_t			type;
	Information*	sym;
	expr*			index;
	expr*			mapKey;
	expr*			mapValue;
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
	int taddress;
};
struct stmt_t {
	int breakList, contList;
};

struct call {
	expr* elist;
	unsigned char method;
	char* name;
};


//////////////////////////////////////////////////////////////////////////////phase 4
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
	retval_a = 10,
	NULL_a = 11
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
	and_v, jeq_v, jne_v, jle_v, jge_v, jlt_v, jgt_v, pusharg_v, newtable_v, NULL_v
};

struct instruction {
    vmopcode opcode;
    vmarg* result;
    vmarg* arg1;
    vmarg* arg2;
    unsigned srcLine; // we may use unsigned int
};

string vmargToString(vmarg_t o){
	if(o==label_a) return "label_a";
	if(o==global_a) return "global_a";
	if(o==formal_a) return "formal_a";
	if(o==local_a) return "local_a";
	if(o==number_a) return "number_a";
	if(o==string_a) return "string_a";
	if(o==bool_a) return "bool_a";
	if(o==nil_a) return "nil_a";
	if(o==userfunc_a) return "userfunc_a";
	if(o==libfunc_a) return "libfunc_a";
	if(o==retval_a) return "retval_a";
	//return "NULL";
	return "";
}

vmarg_t stringToVmarg(string o){
	if(o=="label_a") return label_a;
	if(o=="global_a") return global_a;
	if(o=="formal_a") return formal_a;
	if(o=="local_a") return local_a;
	if(o=="number_a") return number_a;
	if(o=="string_a") return string_a;
	if(o=="bool_a") return bool_a;
	if(o=="nil_a") return nil_a;
	if(o=="userfunc_a") return userfunc_a;
	if(o=="libfunc_a") return libfunc_a;
	if(o=="retval_a") return retval_a;
	return NULL_a;
}

string vmOpCodeToString(vmopcode o){
	if(o==assign_v) return "assign_v";
	if(o==add_v) return "add_v";
	if(o==sub_v) return "sub_v";
	if(o==mul_v) return "mul_v";
	if(o==divide_v) return "divide_v";
	if(o==mod_v) return "mod_v";
	if(o==uminus_v) return "uminus_v";
	if(o==if_eq_v) return "if_eq_v";
	if(o==if_not_eq_v) return "if_not_eq_v";
	if(o==if_lesseq_v) return "if_lesseq_v";
	if(o==if_greatereq_v) return "if_greatereq_v";
	if(o==if_less_v) return "if_less_v";
	if(o==if_greater_v) return "if_greater_v";
	if(o==call_v) return "call_v";
	if(o==ret_v) return "ret_v";
	if(o==getretval_v) return "getretval_v";
	if(o==funcenter_v) return "funcenter_v";
	if(o==funcexit_v) return "funcexit_v";
	if(o==jump_v) return "jump_v";
	if(o==tablegetelem_v) return "tablegetelem_v";
	if(o==tablesetelem_v) return "tablesetelem_v";
	if(o==or_v) return "or_v";
	if(o==not_v) return "not_v";
	if(o==nop_v) return "nop_v";
	if(o==and_v) return "and_v";
	if(o==jeq_v) return "jeq_v";
	if(o==jne_v) return "jne_v";
	if(o==jle_v) return "jle_v";
	if(o==jge_v) return "jge_v";
	if(o==jlt_v) return "jlt_v";
	if(o==jgt_v) return "jgt_v";
	if(o==pusharg_v) return "pusharg_v";
	if(o==newtable_v) return "newtable_v";
	//return "NULL";
	return "";
}

vmopcode stringToVmOpCode(string o){
	if(o=="assign_v") return assign_v;
	if(o=="add_v") return add_v;
	if(o=="sub_v") return sub_v;
	if(o=="mul_v") return mul_v;
	if(o=="divide_v") return divide_v;
	if(o=="mod_v") return mod_v;
	if(o=="uminus_v") return uminus_v;
	if(o=="if_eq_v") return if_eq_v;
	if(o=="if_not_eq_v") return if_not_eq_v;
	if(o=="if_lesseq_v") return if_lesseq_v;
	if(o=="if_greatereq_v") return if_greatereq_v;
	if(o=="if_less_v") return if_less_v;
	if(o=="if_greater_v") return if_greater_v;
	if(o=="call_v") return call_v;
	if(o=="ret_v") return ret_v;
	if(o=="getretval_v") return getretval_v;
	if(o=="funcenter_v") return funcenter_v;
	if(o=="funcexit_v") return funcexit_v;
	if(o=="jump_v") return jump_v;
	if(o=="tablegetelem_v") return tablegetelem_v;
	if(o=="tablesetelem_v") return tablesetelem_v;
	if(o=="or_v") return or_v;
	if(o=="not_v") return not_v;
	if(o=="nop_v") return nop_v;
	if(o=="and_v") return and_v;
	if(o=="jeq_v") return jeq_v;
	if(o=="jne_v") return jne_v;
	if(o=="jle_v") return jle_v;
	if(o=="jge_v") return jge_v;
	if(o=="jlt_v") return jlt_v;
	if(o=="jgt_v") return jgt_v;
	if(o=="pusharg_v") return pusharg_v;
	if(o=="newtable_v") return newtable_v;
	return NULL_v;
}