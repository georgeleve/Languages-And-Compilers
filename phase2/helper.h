#include <bits/stdc++.h>
using namespace std;

int scope = 0;

enum SymbolType {
 GLOBAL, LOC, FORMAL, USERFUNC, LIBFUNC
}; 
/*
typedef struct Variable {
	const string name;
	unsigned int scope;
	unsigned int line;
} Variable;

typedef struct Function {
	const string name;
	unsigned int scope;
	unsigned int line;
} Function;

typedef struct SymbolTableEntry {
	bool isActive;
	union {
		Variable *varVal;
		Function *funcVal;
	} value;
	enum SymbolType type;
} SymbolTableEntry; 
*/

typedef struct Information{
	enum SymbolType type;
	unsigned int line;
} Information;

vector<map<string,Information>> symTable;

void increaseScope(){
	scope++;
	map<string,Information> tp;
	symTable.push_back(tp);
}

bool decreaseScope(){
	scope--;
	symTable.pop_back();
}

bool lookup(string s){
	return symTable.back().find(s) != symTable.back().end();
}

bool globalLookup(string s){
	return symTable[0].find(s) != symTable[0].end();
}

bool generalLookup(string s){
	return lookup(s) || globalLookup(s);      
}

void insert(string name, enum SymbolType type, unsigned int line){
	Information info;
	info.type = type;
	info.line = line;
	symTable.back().insert({name,info});
}

void globalInsert(string name, enum SymbolType type, unsigned int line){
	Information info;
	info.type = type;
	info.line = line;
	symTable[0].insert({name,info});
}

void initializeSymTable(){
	map<string,Information> tp;
	symTable.push_back(tp);
	globalInsert("print",LIBFUNC,0);
	globalInsert("input",LIBFUNC,0);
	globalInsert("objectmemberkeys",LIBFUNC,0);
	globalInsert("objecttotalmembers",LIBFUNC,0);
	globalInsert("objectcopy",LIBFUNC,0);
}