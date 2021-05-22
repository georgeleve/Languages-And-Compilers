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
// na valoume ta and, or , not   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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

struct symbol {
	symbol_t type;                                 //to xoyme hdh
	char* name;  //dynamic string
	scopespace_t space; // originating scope scapce
	unsigned offset; // offset in scope space      //prepei na to kratame san extra pedio 
	unsigned scope; // scope value                // to xoume hdh
	unsigned line; //source line of declaration   //yylineno?
};

typedef struct Information{
	enum SymbolType type;
	string name;
	unsigned int line;
	unsigned int offset;
	unsigned int scope;
} Information;
// create a vector that is going to store the quad
struct expr {
	expr_t			type;
	Information*	sym;
	expr*			index;
	int 			iaddress;
	double 			numConst;
	string			strConst;
	bool			boolConst;
	expr*			next;
};