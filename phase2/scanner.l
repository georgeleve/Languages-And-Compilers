%{
    // This is in order to get the token types from Yacc
    // extern YYSTYPE yylval;   /*  maybe UNCOMMENT THIS LATER  */
    #include "parser.h"
    /* may use this sometime  [\(\)\{\}:;=,]    { return yytext[0]; }  */
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

\n  { yylineno++; return ENDL; }

[\n]+ { return '\n' }

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

"="		{return '=';}
"+"		{return '+';}
"-"		{return '-';}
"*"		{return '*';}
"/"		{return '/';}
"%"		{return '%';}
"=="	{return '==';}
"!="	{return '!=';}
"++"	{return '++';}
"--"	{return '--';}
">"		{return '>';}
"<"		{return '<';}
">="	{return '>=';}
"<="	{return '<=';}

"{"		{return '{';}
"}"		{return '}';}
"["		{return '[';}
"]"		{return ']';}
"("		{return '(';}
")"		{return ')';}
";"		{return ';';}
","		{return ',';}
":"		{return ':';}
"::"	{return '::';}
"."		{return '.';}
".."	{return '..';}

{integer} { yyval.intval = atoi(yytext); return INTEGER; }
"-"[0-9]+ { yyval.intval = atoi(yytext); return INTEGER; } /* negative integer */
[0-9]*"."[0-9]+ { yylval.floatval = atof(yytext); return FLOAT;}
[-][0-9]*"."[0-9]+ { yylval.floatval = atof(yytext); return FLOAT;}
{one_line_comment} {}
 
<<EOF>>		    { return EOF; }

"\"" {
    int temp = line_number;
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
          line_number++; 
        } 
        else if(c == '\t') v += "\\t";
        else if(c != 13) v += c;
        prev = c;
    }
    total++;
    fprintf(yyout, "%d: #%d  \"%s\" STRING \"%s\" <-char*\n", temp, total, v.c_str(), v.c_str());
    yval.push_back(init_token(line_number, total, yytext, type::STRING));
}

"/*" {
    int temp = line_number;
    char prev = '-';
    stack<string> par;
    stack<int> s;
    s.push(line_number);
    while(true){
        char c = yyinput();
        if(c == EOF || c == '\0') break;
		bool in = false;
        if(prev == '/' && c == '*'){ /* opening */
            s.push(line_number);
			in = true;
        }
        if(prev == '*' && c == '/') { /* closing */
            if(s.empty()){
                fprintf(yyout, "Error, comment closing at line: %d has not been opened.\n", line_number);
                exit(0);
            }
            par.push(to_string(s.top())+" - "+to_string(line_number));
            s.pop();
			in = true;
        }
        if(c == '\n') line_number++; 
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
    fprintf(yyout, "%s: #%d \"%s\" COMMENT BLOCK_COMMENT <-enumerated\n", lineNo.c_str(), ++total, tp.c_str());
    par.pop();
    while(!par.empty()) {
        string tp = par.top();
        string lineNo = "";
        for(char c : tp) {
            if(c==' ') break;
            lineNo += c;
        }
        fprintf(yyout, "%s: #%d \"%s\" COMMENT NESTED_COMMENT <-enumerated\n", lineNo.c_str(), ++total, tp.c_str());
        par.pop();
    }
}

{id} { yyval.stringval = strdup(yytext); return ID; }

. { fprintf(stderr, "Cannot match character %s with any rule\n", yytext); }

[ \t]*

%%