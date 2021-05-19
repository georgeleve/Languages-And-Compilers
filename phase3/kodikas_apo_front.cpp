
lvalue : id {
	sym = lookup(id.name);
	if (sym == nul)
		{
			sym = newsymbol(id.name);
			sym.space = currscopespace();
			sym.offset = currscopeoffset();
			inccurrscopeoffset();
		}
	lvalue.sval = lvalue_expr(sym);
}


lvalue : local id {
	sym = lookup(id.name, currscope());
	if(sym = nil then)  {
			sym = newsymbol(id.name);
			sym.space = currscopespace();
			sym.offset = currscopeoffset();
			inccurrscopeoffset();
	}
	else {
		// …warning if sym is a function …
	}
	lvalue.sval = lvalue_expr(sym);
}


vardecl : type varlist ;
	{ distributetype($varlist, $type); }

varlist : varlist , var
	{ append($varlist, $var); }

varlist : var
	{ $varlist = newlist(); append($varlist, $var); }

var : id
	{ $var = newsymbol(id.name); $var.class = normalvar; }
var : stars id
	{ $var = newsymbol(id.name); $var.class = pointervar; $var.nest = $stars; }
stars : stars1 *
	{ $stars = $stars1 + 1; }
stars : *
	{ $stars = 1; }



type : int
	{ $type.type = int_t; $type.size = 4; }

type : unsigned int
	{ $type.type = unsigned_int_t; $type.size = 4; }

type : float
	{ $type.type = float_t; $type.size = 4; }

type : double
	{ $type.type = double_t; $type.size = 8; }

type : id
	{ sym = lookup(id.name); $type.type = userdefined_t; $type.size = sym.size; }


var : id array
	{ $var = newsymbol(id.name); $var.class = arrayvar; $var.dims= $array; }

array -> array [ intconst ]
	{ append($array, intconst.value); }

array : [ intconst ]
	{ $array = newlist(); append($array, intconst.value); }

var : stars id array
	{ 	
		$var = newsymbol(id.name);
		$var.class = arraypointervar;
		$var.dims = $array;
		$var.nest = $stars; 
	}

funcname : id
	{ $funcname = id.value; }

funcname : ε
	{ $funcname = newtempfuncname(); }

funprefix : function funcname
	{
		$funprefix = newsymbol($funcname, function_s);
		$funcprefix.iaddress = nextquadlabel();
		emit(funcstart, $funcprefix, NULL, NULL);
		push(scopeoffsetstack, currscopeoffset()); // Save current offset
		enterscopespace(); // Entering function arguments scope space
		resetformalargsoffset(); // Start formals from zero
	}

funcargs : (idlist)
	{
		enterscopespace(); // Now entering function locals space
		resetfunctionlocalsoffset(); // Start counting locals from zero
	}
funcbody : block
	{
		$funcbody = currscopeoffset(); // Extract #total locals
		existscopespace(); // Exiting function locals space
	}


funcdef : funcprefix funcargs funcbody 
{
	existscopespace(); // Exiting function definition space
	$funcprefix.totalLocals = $funcbody; //store #locals in symbol entry
	int offset = pop_and_top(scopeoffsetStack); // pop and get pre scope offset
	restorecurrscopeoffset(offset); //Restore previous scope offset
	$funcdef = $funcprefix; // The function definition returns the symbol
	emit(funcend, $funcprefix, NULL, NULL);
}
typeof<funcname> : char*
typeof<funcbody> : unsigned
typeof<funcprefix, funcdef> : symbol*


dumparguments(23, true, "hello";
dumparguments();
dumparguments(
	print,
	dumparguments,
	(function(){}),
	[]
);

lvalue : id
	{ ... $lvalue = lvalue_expr(sym); }

lvalue : local id
	{ ... $lvalue = lvalue_expr(sym); }

lvalue→ global id
	{ ... $lvalue = lvalue_expr(sym);


lvalue : tableitem
	{ $lvalue = $tableitem; }

tableitem : lvalue.id
	{ $tableitem = member_item($lvalue, id.name); }


tableitem : lvalue [ expr ] {
	$lvalue = emit_iftableitem($lvalue);
	$tableitem = newexpr(tableitem_e);
	$tableitem->sym = $lvalue->sym;
	$tableitem->index = $expr; // The index is the expression
}

primary : lvalue 
	{ $primary = emit_iftableitem($lvalue); }


assginexpr : lvalue = expr
{
	if $lvalue ->type = tableitem_e then {
		emit( // lvalue[index] = expr
			tablesetelem,
			$lvalue,
			$lvalue->index,
			$expr // Use result operand for the assigned value
		);
		$assignexpr = emit_iftableitem($lvalue); // Will always emit
		$assignexpr->type = assignexpr_e;
	}
	else
	{
		emit( // that is: lvalue = expr
			assign,
			$expr,
			NULL,
			$lvalue
		);
		$assignexpr = newexpr(assignexpr_e);
		$assignexpr->sym = newtemp();
		emit(assign, $lvalue, NULL, $assignexpr);
	}
}

methodcall : ..id(elist)
	{
	$methodcall.elist = $elist;
	$methodcall.method = 1;
	$methodcall.name = $id.val;
	}

call : call(elist)
 	{
	$call = make_call($call, $elist);
	}

call : (funcdef)(elist)
	{
	expr *func = newexpr(programfunc_e);
	func->sym = $funcdef;
	$call = make_call(func, $elist);
	}

call → lvalue callsuffix {
	$lvalue = emit_iftableitem($lvalue); in case it was a table item too
	if (callsuffix.method ){
		expr* t = $lvalue;
		$lvalue = emit_iftableitem(member_item(t, $callsuffix.name));
		$callsuffix.elist->next = t; // insert as first argument (reversed, so last)
	}
	$call = make_call($lvalue, $callsuffix.elist);
}

callsuffix : normcall
	{ $callsuffix = $normcall; }
callsuffix : methodcall
	{ $callsuffix = $methodcall; }
normcall : ( elist )
	{
	$normalcall.elist = $elist;
	$normalcall.method = 0;
	$ normalcall.name = NULL;
	}

typeof<callsuffix> : struct call
typeof<normcall> : struct call
typeof<methodcall> : struct call


tablemake : [elist] {
	expr *t = newexpr(newtable_e);
	t->sym = newtemp();
	emit(tablecreate, t, NULL, NULL);
	for (int i = 0; $elist; $elist = $elist->next)
		emit(tablesetelem, t, newexpr_constnum(i++), $elist);
	$tablemake = t;
}

tablemake : [ indexed ] {
	expr* t = newexpr(newtable_e);
	t->sym = newtemp();
	emit(tablecreate, t, NULL, NULL);
	foreach <index, value> in $indexed do
	emit(tablesetelem, t, index, value);
	$tablemake = t;
}


primary : (funcdef){
	$primary = newexpr(programfunc_e);
	$primary->sym = $funcdef;
}

term : ( expr ) { $term = $expr; }

term : primary { $term = $expr; }
 
term : - expr 
	{
		check_arith($expr);
		$term = newexpr(arithexpr_e);
		$term->sym = newtemp();
		emit(uminus,$expr, NULL, $term);
	}
	term → not expr  ολική αποτίμηση bool exprs
	{
		$term = newexpr(boolexpr_e);
		$term->sym = newtemp();
		emit(not,$expr, NULL, $term);
	}

term : not expr // ολική αποτίμηση bool exprs
{
	$term = newexpr(boolexpr_e);
	$term->sym = newtemp();
	emit(not,$expr, NULL, $term);
}

term : lvalue++ {
	check_arith($lvalue);
	$term = newexpr(var_e);
	$term->sym = newtemp();
	if ($lvalue->type == tableitem_e) {
		expr *val = emit_iftableitem($lvalue);
		emit(assign, val, NULL, $term);
		emit(add, val, newexpr_constnum(1), val);
		emit(tablesetelem, $lvalue, $lvalue->index, val);
	}
	else {
		emit(assign, $lvalue, NULL, $term);
		emit(add, $lvalue, newexpr_constnum(1), $lvalue);
	}
}

term : ++lvalue
	{
		check_arith(($lvalue);
		if ($lvalue->type == tableitem_e) {
			$term = emit_iftableitem($lvalue);
			emit(add, $term, newexpr_constnum(1), $term);
			emit(tablesetelem, $lvalue, $lvalue->index, $term);
		}
		else {
			emit(add, $lvalue, newexpr_constnum(1), $lvalue);
			$term = newexpr(arithexpr_e);
			$term->sym = newtemp();
			emit(assign, $lvalue, NULL, $term);
		}
	}

term : --lvalue {       }
term : lvalue-- {       }

term : -expr {
	check_arith($expr);
	$term = newexpr(arithexpr_e);
	$term->sym = istempexpr($expr) ? $expr->sym : newtemp();
	emit(uminus,$expr, NULL, $term);
}


arithop : + { $arithop = add; }
arithop : - { $arithop = sub; }
arithop : * { $arithop = mul; }
arithop : / { $arithop = div; }
arithop : % { $arithop = mod; }
expr : expr1 arithop expr2 {
	$expr = newexpr(arithexpr_e);
	$expr->sym = newtemp();
	emit($arithop, $expr1, $expr2, $expr);
}

relop : > { $relop = if_greater; }
relop : >= { $relop = if_greatereq; }
relop : < { $relop = if_less; }
relop : <= { $relop = if_lesseq; }
relop : == { $relop = if_eq; }
relop : != { $relop = if_noteq; }

expr : expr1 relop expr2 {
	$expr = newexpr(boolexpr_e);
	$expr->sym = newtemp();
	emit($relop, $expr1, $expr2, nextquad() + 3);
	emit(assign, newexpr_constbool(0), $expr);
	emit(jump, nextquad() + 2);
	emit(assign, newexpr_constbool(1), $expr);
}

boolop : && { $boolop = and; }
boolop : || { $boolop = or ; }

expr : expr1 boolop expr2 
	{
	$expr = newexpr(boolexpr_e);
	$expr->sym = newtemp();
	emit($boolop, $expr1, $expr2, $expr);
	}


ifprefix : if (expr)
	{
	emit(if_eq, $expr, newexpr_constbool(1), nextquad() + 2);
	$ifprefix = nextquad();
	emit(jump, NULL, NULL, 0);
	}

if : ifprefix stmt
	{
		patchlabel($ifprefix, nextquad());
	}

elseprefix : else
	{
	$elseprefix = nextquad();
	emit(jump, NULL, NULL, 0);
	}

if : ifprefix stmt1 elseprefix stmt2
	{
		patchlabel($ifprefix, $elseprefix + 1);
		patchlabel($elseprefix, nextquad());
	}

whilestart : while 
	{
	$whilestart = nextquad();
	}

whilecond : (expr) 
{
	emit(if_eq, $expr, newexpr_constbool(1), nextquad() + 2);
	$whilecond = nextquad();
	emit(jump, NULL, NULL, 0);
}

while : whilestart whilecond stmt 
{
	emit(jump, NULL, NULL, $whilestart);
	patchlabel($whilecond, nextquad());
	patchlist($stmt.breaklist, nextquad());
	patchlist($stmt.contlist, $whilestart);
}

N :  { $N = nextquad(); emit(jump, NULL, NULL, 0); }
M : { $M = nextquad(); }

forprefix : for (elist; M expr;
{
	$forprefix.test = $M;
	$forprefix.enter = nextquad();
	emit(if_eq, $expr, newexpr_constbool(1), 0);
}

for : forprefix N1 elist ) N2 stmt N3 
{
	patchlabel($forprefix.enter, $N2 + 1); // true jump
	patchlabel($N1, nextquad()); // false jump
	patchlabel($N2, $forprefix.test); // loop jump
	patchlabel($N3, $N1 + 1); // closure jump

	patchlist($stmt.breaklist, nextquad());
	patchlist($stmt.contlist, $N1 + 1);
}

loopstart : ε { ++loopcounter; }
loopend : ε { --loopcounter; }
loopstmt : loopstart stmt loopend { $ loopstmt = $stmt; }

whilestmt : while (expr) loopstmt
forstmt : for (elist; expr; elist) loopstmt

funcblockstart : ε
{
	push(loopcounterstack, loopcounter); loopcounter = 0;
}

funcblockend : ε { loopcounter = pop(loopcounterstack); }

funcdef : function[id](idlist) funcblockstart block funcblockend


break : break;
{
	make_stmt(&$break);
	$break.breaklist = newlist(nextquad());
	emit(jump, NULL, NULL, 0);
}

continue : continue;
{
	make_stmt(&$continue);
	$continue.contlist = newlist(nextquad());
	emit(jump, NULL, NULL, 0);
}

stmts : stmt { $stmts = $stmt; }
stmts : stmts1 stmt
{
	$stmts.breaklist = mergelist($stmts1.breaklist, $stmt.breaklist);
	$stmts.contlist = mergelist($stmts1.contlist, $stmt.contlist);
}

returnstmt : return ε; 
{
	emit(return, null);
}

returnstmt : return expr;
{
	emit(return, $expr);
}