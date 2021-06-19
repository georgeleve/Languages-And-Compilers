#include <bits/stdc++.h>
#include "structs.h"
using namespace std;

void storeNumbers(ofstream& file, vector<double> vec){
	file << vec.size() << endl;
	for(double i : vec) file << i<< endl;
}

void storeStrings(ofstream& file, vector<string> vec){
	file << vec.size() << endl;
	for(string i : vec) file << i << endl;
}

void storeLibFuncs(ofstream& file, vector<string> vec){
	file << vec.size() << endl;
	for(string i : vec) file << i<< endl;
}

void storeUserFuncs(ofstream& file, vector<userFunc*> vec){
	file << vec.size() << endl;
	for(userFunc* i : vec) {
		file << i->address << endl;
		file << i->localSize << endl;
		file << i->id << endl;
	}
}
void storeVmarg(ofstream& file, vmarg* v){
	if(v==NULL){
		file << "NULL" << endl;
		return;
	}
	file << vmargToString(v->type) << endl;
	file << v->val << endl;
}
void storeInstructions(ofstream& file, vector<instruction*> vec){
	file << vec.size() << endl;
	for(instruction* i : vec) {
		file << vmOpCodeToString(i->opcode) << endl;
		storeVmarg(file, i->result);
		storeVmarg(file, i->arg1);
		storeVmarg(file, i->arg2);
		file << i->srcLine << endl;
	}
}

void storeAll(vector<double> numberArray, vector<string> stringArray, vector<string> libFuncArray, vector<userFunc*> userFuncArray, vector<instruction*> instructions){
	ofstream file("binary.abc");
  	storeNumbers(file, numberArray);
  	storeStrings(file, stringArray);
  	storeLibFuncs(file, libFuncArray);
  	storeUserFuncs(file, userFuncArray);
  	storeInstructions(file, instructions);
  	file.close();
}








//LOAD FUNCTIONS


void loadNumbers(ifstream& file, vector<double>& vec){
	int len;
	file >> len;
	for(int i = 0; i<len; i++) {
		double v;
		file >> v;
		vec.push_back(v);
	}
}

void loadStrings(ifstream& file, vector<string>& vec){
	int len;
	file >> len;
	for(int i = 0; i<len; i++) {
		string v;
		file >> v;
		vec.push_back(v);
	}
}

void loadLibFuncs(ifstream& file, vector<string>& vec){
	int len;
	file >> len;
	for(int i = 0; i<len; i++) {
		string v;
		file >> v;
		vec.push_back(v);
	}
}

void loadUserFuncs(ifstream& file, vector<userFunc*>& vec){
	int len;
	file >> len;
	for(int i = 0; i<len; i++) {
		userFunc* read = new userFunc;
		file >> read->address;
		file >> read->localSize;
		file >> read->id;
		vec.push_back(read);
	}
}
vmarg* loadVmarg(ifstream& file){
	string in;
	file >> in;
	if(in=="NULL") return NULL;
	vmarg* v = new vmarg;
	v->type = stringToVmarg(in);
	file >> v->val;
	return v;
}
void loadInstructions(ifstream& file, vector<instruction*>& vec){
	int len;
	file >> len;
	printf("Here! total of: %d\n",len);
	for(int i = 0; i<len; i++) {
		instruction* ins = new instruction;
		string op;
		file >> op;
		ins->opcode = stringToVmOpCode(op);

		ins->result = loadVmarg(file);
		ins->arg1 = loadVmarg(file);
		ins->arg2 = loadVmarg(file);
		file >> ins->srcLine;
		vec.push_back(ins);
	}
}

void loadAll(vector<double>& numberArray, vector<string>& stringArray, vector<string>& libFuncArray, vector<userFunc*>& userFuncArray, vector<instruction*>& instructions){
	ifstream file ("binary.abc");
  	if (!(file.is_open())) {
  		cout << "ERROR" << endl;
  		exit(0);
  	}
  	loadNumbers(file, numberArray);
  	loadStrings(file, stringArray);
  	loadLibFuncs(file, libFuncArray);
  	loadUserFuncs(file, userFuncArray);
  	loadInstructions(file, instructions);
  	file.close();
}

