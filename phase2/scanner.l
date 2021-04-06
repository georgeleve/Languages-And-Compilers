%{
    /* This is in order to get the token types from Yacc
       extern YYSTYPE yylval;   */
    #include "parser.hpp"
    #include <bits/stdc++.h>
    using namespace std;
%}

/* Flex options */
%option noyywrap
%option yylineno
 
/* Flex macros */
id [a-zA-Z][a-zA-Z_0-9]*
string [\"]([^\"]|\.)*[\"]
one_line_comment "//".*
integer [0-9]+

%%

\n  { }

"if" 		{return IF;}
"else" 		{return ELSE;}
"while" 	{return WHILE;}
"for" 		{return FOR;}
"function" 	{return FUNCTION;}
"return" 	{return RETURN;}
"break" 	{return BREAK;}
"continue" 	{return CONTINUE;}
"and"    	{return AND;}
"not"    	{return NOT;}
"or" 		{return OR;}
"local" 	{return LOCAL;}
"true" 		{return TRUE;}
"false" 	{return FALSE;}
"nil" 		{return NIL;}

"="		{return ASSIGN;}
"+"		{return PLUS;}
"-"		{return MINUS;}
"*"		{return MUL;}
"/"		{return DIV;}
"%"		{return MODULO;}
"=="	{return EQUAL;}
"!="	{return NOT_EQUAL;}
"++"	{return PLUS_PLUS;}
"--"	{return MINUS_MINUS;}
">"		{return GREATER;}
"<"		{return LESS;}
">="	{return GREATER_EQUAL;}
"<="	{return LESS_EQUAL;}

"{"		{return LEFT_BRACE;}
"}"		{return RIGHT_BRACE;}
"["		{return LEFT_BRACKET;}
"]"		{return RIGHT_BRACKET;}
"("		{return LEFT_PARENTH;}
")"		{return RIGHT_PARENTH;}
";"		{return SEMICOLON;}
","		{return COMMA;}
":"		{return COLON;}
"::"	{return DOUBLE_COLON;}
"."		{return DOT;}
".."	{return DOT_DOT;}

{integer} { yylval.intval = atoi(yytext); return INTEGER; }
"-"[0-9]+ { yylval.intval = atoi(yytext); return INTEGER; } /* negative integer */
[0-9]*"."[0-9]+ { yylval.floatval = atof(yytext); return FLOAT;}
[-][0-9]*"."[0-9]+ { yylval.floatval = atof(yytext); return FLOAT;}
{one_line_comment} {}
 
<<EOF>>		    { return EOF; }

"\"" {
    int temp = yylineno;
    char prev = '-';
    string v = "";
    while(true){
        char c = yyinput();
        if(c == EOF || c == '\0'){
            fprintf(yyout, "Error, non closing string at line: %d\n",temp);
            exit(0);
        }
        if(c == '\"') {
            if(prev == '\\') {
                v+= "\"";
                prev = c;
                continue;
            }
            else break;
        }
        if(c == '\\' && prev=='\\'){
            v += '\\';
            prev = '-';
            continue;
        }
        if(c == '\n'){
          v+= "\\n";  
          yylineno++; 
        } 
        else if(c == '\t') v += "\\t";
        else if(c != 13) v += c;
        prev = c;
    }
    /* fprintf(yyout, "%d: #%d  \"%s\" STRING \"%s\" <-char*\n", temp, v.c_str(), v.c_str()); */
}

"/*" {
    int temp = yylineno;
    char prev = '-';
    stack<string> par;
    stack<int> s;
    s.push(yylineno);
    while(true){
        char c = yyinput();
        if(c == EOF || c == '\0') break;
		bool in = false;
        if(prev == '/' && c == '*'){ /* opening */
            s.push(yylineno);
			in = true;
        }
        if(prev == '*' && c == '/') { /* closing */
            if(s.empty()){
                fprintf(yyout, "Error, comment closing at line: %d has not been opened.\n", yylineno);
                exit(0);
            }
            par.push(to_string(s.top())+" - "+to_string(yylineno));
            s.pop();
			in = true;
        }
        if(c == '\n') yylineno++; 
        if(s.empty()) break;
        if(in) prev = '-';
		else prev = c;
    }
    if(!s.empty()) {
        fprintf(yyout, "Error, non closing comment at line: %d\n", temp);
        exit(0);
    }
    string tp = par.top();
    string lineNo = "";
    for(char c : tp) {
        if(c == ' ') break;
        lineNo += c;
    }
    /* fprintf(yyout, "%s: #%d \"%s\" COMMENT BLOCK_COMMENT <-enumerated\n", lineNo.c_str(), tp.c_str()); */
    par.pop();
    while(!par.empty()) {
        string tp = par.top();
        string lineNo = "";
        for(char c : tp) {
            if(c==' ') break;
            lineNo += c;
        }
        /* fprintf(yyout, "%s: #%d \"%s\" COMMENT NESTED_COMMENT <-enumerated\n", lineNo.c_str(), tp.c_str()); */
        par.pop();
    }
}

{id} { yylval.stringval = strdup(yytext); return ID; }

. {
    if(yytext[0]!=13 && yytext[0]!=32 && yytext[0]!='\t') {
		fprintf(stderr, "Cannot match character %c (%d) with any rule\n", yytext[0], yytext[0]);
        exit(0);
    }   
}
[ \t]*

%%