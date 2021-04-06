#include <bits/stdc++.h>
using namespace std;

int scope = 0;

enum SymbolType { GLOBAL, LOC, FORMAL, USERFUNC, LIBFUNC };

typedef struct Information{
	enum SymbolType type;
	unsigned int line;
} Information;

typedef struct PrintToken{
	string value;
	Information info;
} PrintToken;

bool comparator(PrintToken a, PrintToken b){
	return a.info.line < b.info.line;
}
vector<map<string,Information>> activeSymTable;
vector<vector<PrintToken>> fullSymTable;

void increaseScope(){
	scope++;
	map<string, Information> tp;
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

bool lookup(string s){
	return activeSymTable.back().find(s) != activeSymTable.back().end();
}

bool globalLookup(string s){
	return activeSymTable[0].find(s) != activeSymTable[0].end();
}

bool generalLookup(string s){
	return lookup(s) || globalLookup(s);
}

void insert(string name, enum SymbolType type, unsigned int line){
	Information info;
	info.type = type;
	info.line = line;
	activeSymTable[scope].insert({name, info});
	
	Information info2;
	info2.type = type;
	info2.line = line;
	fullSymTable[scope].push_back({name, info2});
}

void globalInsert(string name, enum SymbolType type, unsigned int line){
	Information info;
	info.type = type;
	info.line = line;
	activeSymTable[0].insert({name, info});
	
	Information info2;
	info2.type = type;
	info2.line = line;
	fullSymTable[0].push_back({name, info2});
}

void initializeSymTable(){
	map<string,Information> tp;
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