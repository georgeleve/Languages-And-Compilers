#include <bits/stdc++.h>
#include "structs.h"
using namespace std;

typedef struct userFuncInfo{
	int address;
	int localSize;
	string id;
}userFunc;

vector<double> numberArray;
vector<string> stringArray;
vector<string> libFuncArray;
vector<userFunc*> userFuncArray;

vector<instruction*> instructions;


int insert_number(double val){
	numberArray.push_back(val);
	return numberArray.size()-1;
}

int insert_string(string val){
	stringArray.push_back(val);
	return numberArray.size()-1;
}

int insert_libFunc(string val){
	libFuncArray.push_back(val);
	return libFuncArray.size()-1;
}

int insert_userFunc(int address, int localSize, string id){
	userFunc* f = new userFunc;
	f->address = address;
	f->localSize = localSize;
	f->id = id;
	userFuncArray.push_back(f);
	return userFuncArray.size()-1;
}