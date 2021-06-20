#include "executeFunctions.h"

#pragma GCC diagnostic ignored "-Wenum-compare"
#pragma GCC diagnostic ignored "-Wwrite-strings"
#pragma GCC diagnostic ignored "-Wformat="

static void avm_initavm_stack(){
	for(int i = 0; i < AVM_STACKSIZE; i++) {
		AVM_WIPEOUT(avm_stack[i]);
		avm_stack[i].type = undef_m;
	}
}
 
int main(){
	loadAll(numConst, stringConst, libFuncConst, userFuncs, code);
	avm_initavm_stack();
	top = topsp = AVM_STACKSIZE- 100 -1;
	
	while(!executionFinished){
		execute_cycle();
	}
	
}