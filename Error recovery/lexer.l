%{
#include<cstdio>
#include<cstring>
#include <cmath>
#include <iostream>
#include <string>
#include "parser1.tab.hpp"
#include "symbol_table.h"
int lineenum=1;
int cscope=0;
int cclass=0;
Visibility cVis=PUBLIC_V;
extern char* cType;
extern Symbol_Table arrays;
extern Symbol_Table variables;
extern Symbol_Table func_declare;
extern Symbol_Table classes;
using namespace std;
%}


%option noyywrap

/*definitions*/
QUOTE "'"
DQUOTE \"
ID [a-zA-Z_][a-zA-Z0-9_]*
INTEGER 0|[1-9][0-9]*
BOOLEAN true|false
TYPE int|char|double|boolean|String|void


%%
 /*rules*/

public {cVis=PUBLIC_V; return PUBLIC;}
private {cVis=PRIVATE_V; return PRIVATE;}
{TYPE} {strcpy(yylval.dataType, yytext); return  TYPE;}
{INTEGER} {yylval.intVal=atoi(yytext); return  INT;}
{INTEGER}"."{INTEGER}d {return  DOUBLE;}
{BOOLEAN} {return  BOOLEAN;}
{QUOTE}[^']{QUOTE}|{QUOTE}"\\"[^\\]{QUOTE}|{QUOTE}"\\"[^\\]*{QUOTE} {return  CHAR;}
{DQUOTE}[^"]*{DQUOTE} {for(int i=0; yytext[i]!='\0'; i++){
                            if(yytext[i]=='\n')
                                lineenum++;
                    }
                    return STRING;} /*count the lines*/
new {return  NEW;}
default {return  DEFAULT;}
break {return  BREAK;}
class {cclass=cscope; return  CLASS;}
if {return  IF;}
else {return  ELSE;}
switch {return SWITCH;}
case {return  CASE;}
do {return  DO;}
for {return  FOR;}
while {return  WHILE;}
out {return  OUT;}
println {return  PRINTLN;}
return {return RETURN;}
"=""="{BOOLEAN} {return  BOOLCMP;}
"!""="{BOOLEAN} {return  BOOLCMP;}
"/""/"[^\n]*[\n] {lineenum++;}
"=" {return  EQUAL;}
"+" {return    PLUS;}
"-" {return    MINUS;}
"*" {return    TIMES;}
"/" {return    DIV;}
"<" {return    SMALLER;}
">" {return    GREATER;}
"<""=" {return    SMALLER_OR_EQUAL;}
">""=" {return    GREATER_OR_EQUAL;}
"=""=" {return    ISEQUAL;}
"!""=" {return    NOTEQUAL;}
"&""&" {return    AND;}
"|""|" {return    OR;}
"!" {return    NOT;}
"," {return    COMMA;}
"." {return    DOT;}
":" {return    DDOT;}
";" {return    SEMICOLON;}
"(" { return    OPEN_PARENTHESIS;}
")" { return    CLOSED_PARENTHESIS;}
"[" {return    OPEN_BRACKS;}
"]" {return    CLOSED_BRACKS;}
"{" {cscope++; return    OPEN_BRACES;}
"}" {arrays.erase_in_scope(cscope); variables.erase_in_scope(cscope); func_declare.erase_in_scope(cscope); classes.erase_in_scope(cscope); cscope--; return    CLOSED_BRACES;}
{ID} {strcpy(yylval.symbol, yytext); return    ID;}
[\n] {lineenum++;}
"/""*"[^/*]*"*""/" {for(int i=0; yytext[i]!='\0'; i++){
                            if(yytext[i]=='\n')
                                lineenum++;
                    }} /*count the lines of the comments so that the error is in the appropriate line*/
[ \t] {;}
. {cerr<<" error unrecognised token "<<yytext;}

%%
