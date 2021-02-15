#include <stdio.h>
#include <stdlib.h>

enum token {
	KEYWORD,
    OPERATOR,
	INTCONST,
	DOUBLECONST,
	STRINGCONST,
	PUNCTUATION,
	IDENT,
	COMMENT
};


struct {
    int line;
} *alpha_token_t;

int alpha_yylex (void* ylval){

}

void al(){


}

int main(){
    al();
    return 0;
}


"if"		{return IF;}
"else"		{return ELSE;}
"while"		{return WHILE;}
"for"		{return FOR;}
"function"	{return FUNCTION;}
"return"	{return RETURN;}
"break"		{return BREAK;}
"continue"	{return CONTINUE;}
"and"		{return AND;}
"not"		{return NOT;}
"or"		{return OR;}
"local"		{return local;}
"true"		{return TRUE;}
"false"		{return FALSE;}
"nil"		{return NIL;}
"="			{return equal;}
"+"			{return plus;}
"-"			{return minus;}
"*"			{return mul;}
"/"			{return divide;}
"%"			{return percent;}
"=="		{return equalequal;}
"!="		{return notequal;}
"++"		{return plusplus;}
"--"		{return minusminus;}
">"			{return greater;}
"<"			{return lesser;}
">="		{return greaterequal;}
"<="		{return lesserequal;}
"{"			{return openblock;}
"}"			{return closeblock;}
"["			{return openbracket;}
"]"			{return closebracket;}
"("			{return openpar;}
")"			{return closepar;}
";"			{return semicolon;}
","			{return comma;}
":"			{return colon;}
"::"		{return coloncolon;}
"."			{return dot;}
".."		{return dotdot;}
"/*"		{return comment}