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

struct quad {
	iopcode			op;
	expr*			result;
	expr* 			arg1;
	expr* 			arg2;
	unsigned int 	label;
	unsigned int 	line;
};