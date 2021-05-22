#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wenum-compare"
#pragma GCC diagnostic ignored "-Wwrite-strings"
#pragma GCC diagnostic ignored "-Wformat="

int scope = 0;

enum SymbolType { GLOBAL, LOC, FORMAL, USERFUNC, LIBFUNC};

typedef struct Information{
	enum SymbolType type;
	string name;
	unsigned int line;
	unsigned int offset;
	unsigned int scope;
} Information;

Information* allocInfo(SymbolType type, string name, int line, int offset, int scope){
	//Information* info = (Information*) malloc(sizeof(Information));
	Information* info = new Information;
	info->type = type;
	info->name = name;
	info->line = line;
	info->offset = offset;
	info->scope = scope;
	return info;
}
typedef struct PrintToken{
	string value;
	Information info;
} PrintToken;

bool comparator(PrintToken a, PrintToken b){
	return a.info.line < b.info.line;
}

set<string> systemFunctions;
vector<map<string,Information*>> activeSymTable;
vector<vector<PrintToken>> fullSymTable;
stack<int> lastType; //Top of stack is 0 if the latest thing we found between a function and a loop is a function

void pushType(int type){ // 0 is loop 1 is function
	lastType.push(type);
}

void popType(){
	lastType.pop();
}
bool isLastTypeLoop(){ // 0 is loop 1 is function
	if(lastType.empty()) return false;
	return lastType.top()==0;
}
bool isInFunction(){
	bool in = false;
	stack<int> temp;
	while(!lastType.empty()){
		int p = lastType.top(); lastType.pop();
		temp.push(p);
		if(p==1) in = true;
	}
	while(!temp.empty()){
		int p = temp.top(); temp.pop();
		lastType.push(p);
	}
	return in;
}
void increaseScope(){
	scope++;
	map<string, Information*> tp;
	activeSymTable.push_back(tp);
	if(fullSymTable.size()<=scope){
		vector<PrintToken> tp2;
		fullSymTable.push_back(tp2);
	}
}

void decreaseScope(){
	scope--;
	activeSymTable.pop_back();
}

Information* lookup(string s){
	if(activeSymTable.back().find(s) != activeSymTable.back().end()) return activeSymTable.back().find(s)->second;
	return NULL;
}

Information* globalLookup(string s){
	if(activeSymTable[0].find(s) != activeSymTable[0].end()) return activeSymTable[0].find(s)->second;
	return NULL;
}

Information* generalLookup(string s){
	if(lookup(s)!=NULL) return lookup(s);
	return globalLookup(s);
}

Information* lookupTillGlobalScope(string s, bool careAboutFunctionInBetween){ 
	if(lookup(s)!=NULL) return activeSymTable[scope].find(s)->second;
	bool functionInBetween = false;
	for(int i = scope-1; i>=0; i--) {
		for(auto v : activeSymTable[i]) if(v.second->type == USERFUNC) functionInBetween = true;
		if(activeSymTable[i].find(s) != activeSymTable[i].end()){
			if(i==0) return activeSymTable[i].find(s)->second;
			if(functionInBetween && careAboutFunctionInBetween) return allocInfo(GLOBAL, "", 0, 0, -2); //Not accesible.
			return activeSymTable[i].find(s)->second;
		}
	}
	return NULL; //Not found at all
}

void insertVariable(string name, unsigned int line){
	Information* info = allocInfo(scope==0?GLOBAL:LOC, name, line, 0, scope);
	activeSymTable[scope].insert({name, info});
	//info.offset = ?;
	Information info2;
	info2.type = scope==0?GLOBAL:LOC;
	info2.line = line;
	info2.name = name;
	info2.scope = scope;
	fullSymTable[scope].push_back({name, info2});
	//return info;
}

//Information
void insertArgument(string name, unsigned int line){
	Information* info = allocInfo(FORMAL, name, line, 0, scope);
	activeSymTable[scope].insert({name, info});
	//info.offset = ?;

	Information info2;
	info2.type = FORMAL;
	info2.line = line;
	info2.name = name;
	info2.scope = scope;
	fullSymTable[scope].push_back({name, info2});
	//return info;
}

//Information
void insertUserFunction(string name, unsigned int line){
	Information* info = allocInfo(USERFUNC, name, line, 0, scope);
	activeSymTable[scope].insert({name, info});
	//info.offset = ?;

	Information info2;
	info2.type = USERFUNC;
	info2.line = line;
	info2.name = name;
	info2.scope = scope;
	fullSymTable[scope].push_back({name, info2});
	//return info;
}

bool isSystemFunction(string name){
	return systemFunctions.find(name) != systemFunctions.end();
}

// Information
void globalInsert(string name, enum SymbolType type, unsigned int line){
	Information* info = allocInfo(type, name, line, 0, 0);
	activeSymTable[0].insert({name, info});
	//info.offset = ?;
	
	Information info2;
	info2.type = type;
	info2.line = line;
	info2.name = name;
	info2.scope = scope;
	fullSymTable[0].push_back({name, info2});
	
	if(type == LIBFUNC) systemFunctions.insert(name);
}

void initializeSymTable(){
	map<string,Information*> tp;
	activeSymTable.push_back(tp);
	vector<PrintToken> tp2;
	fullSymTable.push_back(tp2);
	
	globalInsert("print", LIBFUNC, 0);
	globalInsert("input", LIBFUNC, 0);
	globalInsert("objectmemberkeys", LIBFUNC, 0);
	globalInsert("objecttotalmembers", LIBFUNC, 0);
	globalInsert("objectcopy", LIBFUNC, 0);
	globalInsert("totalarguments", LIBFUNC, 0);
	globalInsert("argument", LIBFUNC, 0);
	globalInsert("typeof", LIBFUNC, 0);
	globalInsert("strtonum", LIBFUNC, 0);
	globalInsert("sqrt", LIBFUNC, 0);
	globalInsert("cos", LIBFUNC, 0);
	globalInsert("sin", LIBFUNC, 0);
}


void printFullSymTable(){
	for(int i = 0; i<fullSymTable.size(); i++){
		printf("------------   Scope #%d   ------------\n",i);
		vector<PrintToken> a;
		for(auto v : fullSymTable[i]){
			string key = v.value;
			Information info = v.info;
			enum SymbolType { GLOBAL, LOC, FORMAL, USERFUNC, LIBFUNC };
			string label = "";
			if(info.type == GLOBAL) label = "[global variable]";
			else if(info.type == LOC) label = "[local variable]";
			else if(info.type == FORMAL) label = "[formal argument]";
			else if(info.type == USERFUNC) label = "[user function]";
			else label = "[library function]";	
			printf("\"%s\" %s (line %d) (scope %d)\n",key.c_str(),label.c_str(),info.line,i);
		}
	}
}