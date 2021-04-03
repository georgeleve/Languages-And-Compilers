%{
    // This is in order to get the token types from Yacc
    #include "y.tab.h" /* This is the file that will be created from parcer.y  */
    // extern YYSTYPE yylval;   /*  maybe UNCOMMENT THIS LATER  */
    int yylineno = 1;
%}

/* Flex options */
%option noyywrap
%option yylineno
 
/* Flex macros */
id [a-zA-Z][a-zA-Z_0-9]*
string [\"]([^\"]|\.)*[\"]
one_line_comment "//".*

%%

\n  { yylineno++; return ENDL; }

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

"="		{return EQUAL;}
"+"		{return PLUS;}
"-"		{return MINUS;}
"*"		{return MULTIPLICATION;}
"/"		{return DIVISION;}
"%"		{return PERCENTAGE;}
"=="	{return EQUAL_EQUAL;}
"!="	{return NOTEQUAL;}
"++"	{return PLUS_PLUS;}
"--"	{return MINUS_MINUS;}
">"		{return GREATER;}
"<"		{return LESS_THAN;}
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
".."	{return DOUBLE_DOT;}

/* store the value of the token and then return the value */
[0-9]+ { yyval.intval = atoi(yytext); return INTEGER; }
"-"[0-9]+ { yyval.intval = atoi(yytext); return INTEGER; }

{id} { yyval.stringval = strdup(yytext); return ID; }

[0-9]*"."[0-9]+ { yylval.floatval = atof(yytext); return FLOAT;}
[-][0-9]*"."[0-9]+ { yylval.floatval = atof(yytext); return FLOAT;}

{one_line_comment} { total++; fprintf(yyout, "%d: #%d  \"\" COMMENT LINE_COMMENT <-enumerated\n", line_number, total);  }
 
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

. { fprintf(stderr, "Cannot match character %s with any rule\n", yytext); }

[ \t]*