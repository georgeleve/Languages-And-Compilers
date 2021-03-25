%{
    #include "parcer.h" /* this will be generated from parser.y */
%}

/* Flex options */
%option noyywrap
%option yylineno

/* Flex macros */
id [a-zA-Z][a-zA-Z_0-9]*
integer [0-9]+

%%

"+" { return '+'; }
"-" { return '-'; }
"*" { return '*'; }
"/" { return '/'; }
"(" { return '('; }
")" { return ')'; }
"=" { return '='; }
";" { return ';'; }

{integer} { yyval.intValue = atoi(yytext); return INTEGER; }
{id} { yyval.stringValue = strdup(yytext); return ID; }

[ \t\n]+ {}

. { fprintf(stderr, "Cannot match character %s with any rule\n", yytext); }
