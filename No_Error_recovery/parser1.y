%{
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <ctype.h>
#include "symbol_table.h"

typedef struct Expr_str{
              char* typeof_expr;
}Expr;

void yyerror(const char *s);
void variable_semantic_error(const char* var, int scope, char* type);
void variable_undeclared_error(const char* var, int scope, Expr*& vari);
void function_semantic_error(const char* func, int scope, char* type);
void function_undeclared_error(const char* func, int scope, Expr*& function);
void array_semantic_error(const char* var, int scope, char* type);
void assign_at_definition_mismatch_error(Expr*& exp1, Expr*& exp2);
void assign_mismatch_error(Expr*& exp1, Expr*& exp2);
void type_mismatch_error(Expr*& exp1, Expr*& exp2, Expr*& exp3, char op);
void member_variable_semantic_error(const char* var, char* type, Visibility vis);
void member_array_semantic_error(const char* var, char* type, Visibility vis);
void member_function_semantic_error(const char* func, char* type, Visibility vis);
Visibility member_variable_undeclared_error(const char* var, Expr*& vari, const char* cName);
Visibility member_function_undeclared_error(const char* var, Expr*& vari, const char* cName);
bool hasArithmeticType(char* str);
extern int yylex();
extern FILE *yyin;
extern FILE *yyout;
extern int lineenum;
extern int cscope;
extern int cclass;
extern Visibility cVis;
bool isArr;
bool loop=false;
Symbol_Table classes;
member_table memVars;
member_table memFuncs;
member_table memArrs;
Symbol_Table variables;
Symbol_Table arrays;
Symbol_Table func_declare;
char* chType;
char* cType;
char* Ftype;
char* cName=nullptr;
char* prevClass=nullptr;
using namespace std;
%}


%union{
       char dataType[100];
       char symbol[100];
       int intVal;
       double dval;
       struct Expr_str* expT;
}



%define parse.lac full
%define parse.error verbose


/*tokens*/
%token PUBLIC
%token PRIVATE
%token NEW
%token DEFAULT
%token BREAK
%token CLASS
%token IF
%token ELSE
%token SWITCH
%token CASE
%token FOR
%token DO
%token WHILE
%token SMALLER_OR_EQUAL
%token GREATER_OR_EQUAL
%token OPEN_BRACES
%token CLOSED_BRACES
%token<dataType> TYPE
%token EQUAL
%token OPEN_PARENTHESIS
%token CLOSED_PARENTHESIS
%token AND
%token OR
%token NOT
%token SEMICOLON
%token<symbol> ID
%token COMMA
%token DOT
%token DDOT
%token INT
%token DOUBLE
%token BOOLEAN
%token BOOLCMP
%token PLUS
%token MINUS
%token TIMES
%token DIV
%token GREATER
%token SMALLER
%token ISEQUAL
%token NOTEQUAL
%token OPEN_BRACKS
%token CLOSED_BRACKS
%token STRING
%token CHAR
%token OUT
%token PRINTLN
%token RETURN
/*rules*/

%type<expT> expression arithmetic factor term basic_exp variable number function_call member_variable method_call comparison object_creation
%type<symbol> data_type

%%
    program : /*empty*/|
              program class
                    ;
    class : PUBLIC CLASS ID {if(cName==nullptr) asprintf(&cName, "%s", $3);
                             else{
                                   asprintf(&prevClass, "%s", cName);
                                   asprintf(&cName, "%s", $3);
                            }
                             if(!isupper($3[0])){yyerror("Error: class names begin with upperCase"); exit(EXIT_FAILURE);}
                            Symbol sym($3, cscope);
                            if(!classes.exists_in_scope(sym))
                                      classes.insert(sym);
                            else{
                                  yyerror("error class already declared");
                                  exit(EXIT_FAILURE);
                            }
                            } OPEN_BRACES class_body CLOSED_BRACES
                            {
                                                         cVis=PUBLIC_V;
                                                         cclass=cscope-1;
                                                         if(prevClass!=nullptr)
                                                               asprintf(&cName, "%s", prevClass);
                            }
                    ;
    class_body : /*empty*/|
                class_body member
                    ;
    member : MODIFIER definition SEMICOLON {cVis=PUBLIC_V;}|
             MODIFIER function_declare {cVis=PUBLIC_V;}|
             definition SEMICOLON {cVis=PUBLIC_V;}|
             function_declare {cVis=PUBLIC_V;}|
             class {cVis=PUBLIC_V;}
                    ;
    cmd_list : /*empty*/|
               cmd_list command
                     ;
    command : simple_command|
              blc_command
                     ;
    simple_command : definition SEMICOLON|
                     function_call SEMICOLON|
                     assign SEMICOLON|
                     print_command|
                     method_call SEMICOLON|
                     return_command|
                     break_command
                            ;
    break_command : BREAK SEMICOLON {if(!loop){yyerror("Error: break outside of loop"); exit(EXIT_FAILURE);}}
                            ;
    definition : data_type multiple_helper
                        ;
    multiple_helper : basic_helper|
                      multiple_helper COMMA basic_helper
                            ;
    basic_helper : ID {variable_semantic_error($1, cscope, cType);}|
                   ID EQUAL expression {variable_semantic_error($1, cscope, cType);
                                        Expr* exp=new Expr();
                                        asprintf(&exp->typeof_expr, "%s", cType);
                                        assign_at_definition_mismatch_error(exp, $3);
                                       }|
                   ID OPEN_BRACKS arithmetic CLOSED_BRACKS {array_semantic_error($1, cscope, cType); Expr* exp=new Expr(); asprintf(&exp->typeof_expr, "%s", "int"); assign_mismatch_error($3, exp);}
                            ;
    function_call : ID OPEN_PARENTHESIS argument_list CLOSED_PARENTHESIS {
                                                                             function_undeclared_error($1, cscope, $$);
                                                                         }|
                    ID OPEN_PARENTHESIS CLOSED_PARENTHESIS{
                                                              function_undeclared_error($1, cscope, $$);
                                                           }
                            ;
    argument_list : argument|
                    argument_list COMMA argument
                            ;
    argument : expression
                            ;
    assign : variable EQUAL expression {assign_mismatch_error($1, $3);}|
             member_variable EQUAL expression {assign_mismatch_error($1, $3);}
                            ;

    variable : ID {isArr=false; variable_undeclared_error($1, cscope, $$);}|
               ID OPEN_BRACKS arithmetic CLOSED_BRACKS {isArr=true; variable_undeclared_error($1, cscope, $$); Expr* exp=new Expr(); asprintf(&exp->typeof_expr, "%s", "int"); assign_mismatch_error($3, exp);}
                        ;
    expression : arithmetic {$$=new Expr();
                             asprintf(&$$->typeof_expr, "%s", $1->typeof_expr);
                            }|
                 logic{$$=new Expr();
                       asprintf(&$$->typeof_expr, "%s", "boolean");
                      }|
                object_creation {$$=new Expr();
                       asprintf(&$$->typeof_expr, "%s", $1->typeof_expr);}
                        ;
    logic : and_expression|
            logic OR and_expression
                        ;

    and_expression : logic_term|
                     comparison|
                     and_expression AND logic_term|
                     and_expression AND comparison
                        ;
    logic_term : BOOLEAN|
                 OPEN_PARENTHESIS logic CLOSED_PARENTHESIS|
                 NOT OPEN_PARENTHESIS logic CLOSED_PARENTHESIS
                        ;
    arithmetic : factor {$$=new Expr();
                         asprintf(&$$->typeof_expr, "%s", $1->typeof_expr);
                        }|
                 arithmetic PLUS factor{$$=new Expr();
                                        type_mismatch_error($1, $3, $$, '+');
                                       }|
                 arithmetic MINUS factor{$$=new Expr();
                                         type_mismatch_error($1, $3, $$, '-');
                                        }
                        ;
    factor : term {$$=new Expr();
                   asprintf(&$$->typeof_expr, "%s", $1->typeof_expr);
                  }|
             factor TIMES term {$$=new Expr();
                                type_mismatch_error($1, $3, $$, '*');
                               }|
             factor DIV term {$$=new Expr();
                              type_mismatch_error($1, $3, $$, '/');
                             }
                        ;
    term : basic_exp{$$=new Expr();
                     asprintf(&$$->typeof_expr, "%s", $1->typeof_expr);
                    }|
           CHAR{$$=new Expr();
                asprintf(&$$->typeof_expr, "%s", "char");
               }|
           STRING {$$=new Expr();
                   asprintf(&$$->typeof_expr, "%s", "String");
                  }|
           number {$$=new Expr();
                   asprintf(&$$->typeof_expr, "%s", $1->typeof_expr);
                  }|
           OPEN_PARENTHESIS arithmetic CLOSED_PARENTHESIS {$$=new Expr();
                                                           asprintf(&$$->typeof_expr, "%s", $2->typeof_expr);
                                                          }
                        ;
    number : INT {$$=new Expr();
                  asprintf(&$$->typeof_expr, "%s", "int");
                 }|
             DOUBLE {$$=new Expr();
                     asprintf(&$$->typeof_expr, "%s", "double");
                    }
                        ;
    comparison : arithmetic cop arithmetic{type_mismatch_error($1, $3, $$, '>'); asprintf(&$$->typeof_expr, "%s", "boolean");}|
                 logic_term ISEQUAL logic_term {asprintf(&$$->typeof_expr, "%s", "boolean");}|
                 logic_term NOTEQUAL logic_term {asprintf(&$$->typeof_expr, "%s", "boolean");}|
                 basic_exp BOOLCMP {if(strcmp($1->typeof_expr, "boolean")!=0){ yyerror("Error: incompatible types for action"); exit(EXIT_FAILURE);} asprintf(&$$->typeof_expr, "%s", "boolean");}|
                 logic_term BOOLCMP {asprintf(&$$->typeof_expr, "%s", "boolean");}
                        ;
    basic_exp : variable|
                function_call|
                member_variable|
                method_call
                ;
    cop : GREATER|
          GREATER_OR_EQUAL|
          SMALLER|
          SMALLER_OR_EQUAL|
          ISEQUAL|
          NOTEQUAL
                    ;
   parameter_list : parameter |
                    parameter_list COMMA parameter
                            ;
   parameter : data_type ID {
                         cscope++;
                         variable_semantic_error($2, cscope, $1);
                        cscope--;
                        }|
               data_type ID OPEN_BRACKS CLOSED_BRACKS {
                                                   cscope++;
                                                  array_semantic_error($2, cscope, $1);
                                                 cscope--;}
                            ;
   print_command : OUT DOT PRINTLN OPEN_PARENTHESIS STRING COMMA variable_lst CLOSED_PARENTHESIS SEMICOLON|
                   OUT DOT PRINTLN OPEN_PARENTHESIS STRING CLOSED_PARENTHESIS SEMICOLON
                            ;
    variable_lst : variable|
                   member_variable|
                   variable_lst COMMA variable|
                   variable_lst COMMA member_variable
                            ;
   object_creation : NEW ID OPEN_PARENTHESIS CLOSED_PARENTHESIS{
                                                                                           if(!isupper($2[0])){
                                                                                                  yyerror("Error: class names begin with upperCase");
                                                                                                  exit(EXIT_FAILURE);
                                                                                           }
                                                                                           Symbol sym($2, cscope);
                                                                                           if(!classes.exists(sym)){
                                                                                                  yyerror("Undeclared class");
                                                                                                  exit(EXIT_FAILURE);
                                                                                           }
                                                                                           $$=new Expr();
                                                                                           asprintf(&$$->typeof_expr, "%s", $2);
                                                                             }
                            ;
   member_variable : variable DOT ID {isArr=false; Visibility vi=member_variable_undeclared_error($3, $$, $1->typeof_expr); if(vi!=PUBLIC_V && strcmp(cName, $1->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}|
                     variable DOT ID OPEN_BRACKS arithmetic CLOSED_BRACKS {isArr=true; Visibility vi=member_variable_undeclared_error($3, $$, $1->typeof_expr);
                                                                           if(vi!=PUBLIC_V && strcmp(cName, $1->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}
                                                                           Expr* exp=new Expr(); asprintf(&exp->typeof_expr, "%s", "int"); assign_mismatch_error($5, exp);}|
                     member_variable DOT ID {isArr=false; Visibility vi=member_variable_undeclared_error($3, $$, $1->typeof_expr); if(vi!=PUBLIC_V && strcmp(cName, $1->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}|
                     member_variable DOT ID OPEN_BRACKS arithmetic CLOSED_BRACKS {isArr=true; Visibility vi=member_variable_undeclared_error($3, $$, $1->typeof_expr);
                                                                                 if(vi!=PUBLIC_V && strcmp(cName, $1->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}
                                                                                 Expr* exp=new Expr(); asprintf(&exp->typeof_expr, "%s", "int"); assign_mismatch_error($5, exp);}|
                     function_call DOT ID {isArr=false; Visibility vi=member_variable_undeclared_error($3, $$, $1->typeof_expr); if(vi!=PUBLIC_V && strcmp(cName, $1->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}|
                     function_call DOT ID OPEN_BRACKS arithmetic CLOSED_BRACKS {isArr=true; Visibility vi=member_variable_undeclared_error($3, $$, $1->typeof_expr);
                                                                                 if(vi!=PUBLIC_V && strcmp(cName, $1->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}
                                                                                 Expr* exp=new Expr(); asprintf(&exp->typeof_expr, "%s", "int"); assign_mismatch_error($5, exp);}|
                     method_call DOT ID {isArr=false; Visibility vi=member_variable_undeclared_error($3, $$, $1->typeof_expr); if(vi!=PUBLIC_V && strcmp(cName, $1->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}|
                     method_call DOT ID OPEN_BRACKS arithmetic CLOSED_BRACKS {isArr=true; Visibility vi=member_variable_undeclared_error($3, $$, $1->typeof_expr);
                                                                           if(vi!=PUBLIC_V && strcmp(cName, $1->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}
                                                                           Expr* exp=new Expr(); asprintf(&exp->typeof_expr, "%s", "int"); assign_mismatch_error($5, exp);}
                                ;
   method_call : variable DOT ID OPEN_PARENTHESIS argument_list CLOSED_PARENTHESIS {Visibility vi=member_function_undeclared_error($3, $$, $1->typeof_expr);
                                                                                    if(vi!=PUBLIC_V && strcmp(cName, $1->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}|
                 variable DOT ID OPEN_PARENTHESIS CLOSED_PARENTHESIS {Visibility vi=member_function_undeclared_error($3, $$, $1->typeof_expr);
                                                                      if(vi!=PUBLIC_V && strcmp(cName, $1->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}|
                 member_variable DOT ID OPEN_PARENTHESIS argument_list CLOSED_PARENTHESIS {Visibility vi=member_function_undeclared_error($3, $$, $1->typeof_expr);
                                                                                    if(vi!=PUBLIC_V && strcmp(cName, $1->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}|
                 member_variable DOT ID OPEN_PARENTHESIS CLOSED_PARENTHESIS {Visibility vi=member_function_undeclared_error($3, $$, $1->typeof_expr);
                                                                      if(vi!=PUBLIC_V && strcmp(cName, $1->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}|
                 function_call DOT ID OPEN_PARENTHESIS argument_list CLOSED_PARENTHESIS {Visibility vi=member_function_undeclared_error($3, $$, $1->typeof_expr);
                                                                                    if(vi!=PUBLIC_V && strcmp(cName, $1->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}|
                 function_call DOT ID OPEN_PARENTHESIS CLOSED_PARENTHESIS {Visibility vi=member_function_undeclared_error($3, $$, $1->typeof_expr);
                                                                      if(vi!=PUBLIC_V && strcmp(cName, $1->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}|
                 method_call DOT ID OPEN_PARENTHESIS argument_list CLOSED_PARENTHESIS {Visibility vi=member_function_undeclared_error($3, $$, $1->typeof_expr);
                                                                                    if(vi!=PUBLIC_V && strcmp(cName, $1->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}|
                 method_call DOT ID OPEN_PARENTHESIS CLOSED_PARENTHESIS {Visibility vi=member_function_undeclared_error($3, $$, $1->typeof_expr);
                                                                      if(vi!=PUBLIC_V && strcmp(cName, $1->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}

                                ;
   return_command : RETURN expression SEMICOLON {if(strcmp($2->typeof_expr, Ftype)!=0) {yyerror("Incompatible types for action"); exit(EXIT_FAILURE);}}|
                    RETURN SEMICOLON { if(strcmp("void", Ftype)!=0){
                                             yyerror("Incompatible types for action");
                                             exit(EXIT_FAILURE);
                                       }
                                    }
                                ;
   blc_command : if_cmd|
                 case_cmd|
                 for_loop|
                 do_while_loop|
                 function_declare|
                 cmd_block
                         ;
   cmd_block : OPEN_BRACES cmd_list CLOSED_BRACES
                         ;
   if_cmd : if_stmt|
            if_stmt  ELSE cmd_block|
            if_stmt elseif|
            if_stmt elseif ELSE cmd_block
                            ;
   if_stmt : IF OPEN_PARENTHESIS logic CLOSED_PARENTHESIS cmd_block
                            ;
   elseif : elseif_stmt|
            elseif elseif_stmt
                            ;
  elseif_stmt : ELSE IF OPEN_PARENTHESIS logic CLOSED_PARENTHESIS cmd_block
                            ;
  case_cmd :  SWITCH OPEN_PARENTHESIS arithmetic CLOSED_PARENTHESIS {asprintf(&chType, "%s", $3->typeof_expr);} case_cmd_body
                            ;
  case_cmd_body: OPEN_BRACES case_list default_blc CLOSED_BRACES|
                 OPEN_BRACES case_list CLOSED_BRACES
                 ;
  case_list : case|
              case_list case
                            ;
  case : CASE arithmetic {if(strcmp($2->typeof_expr, chType)!=0){yyerror("Error: incompatible types for action"); exit(EXIT_FAILURE);}} DDOT cmd_block
                            ;
  default_blc : DEFAULT DDOT cmd_block
                            ;
  for_loop : FOR OPEN_PARENTHESIS base SEMICOLON logic SEMICOLON step CLOSED_PARENTHESIS {loop=true;} cmd_block {loop=false;}
                            ;
  base : assign{cscope++;}|
         data_type ID EQUAL expression {              cscope++;
                                                 variable_semantic_error($2, cscope, $1);
                                   }
                            ;
  step : assign {cscope--;}
                            ;
  do_while_loop : DO {loop=true;} cmd_block WHILE OPEN_PARENTHESIS logic CLOSED_PARENTHESIS SEMICOLON {loop=false;}
                            ;
  function_declare : data_type ID {asprintf(&Ftype, "%s", $1); function_semantic_error($2, cscope, $1);} function_parameters cmd_block
                            ;
  function_parameters : OPEN_PARENTHESIS parameter_list CLOSED_PARENTHESIS|
                        OPEN_PARENTHESIS CLOSED_PARENTHESIS
                           ;
  MODIFIER : PUBLIC| PRIVATE;
  data_type : TYPE {strcpy($$, $1); asprintf(&cType, "%s", $1);}| ID {Symbol sym($1, cscope);
                        if(!classes.exists(sym)){
                              yyerror("Undeclared class");
                              exit(EXIT_FAILURE);
                        }
                        else{
                            strcpy($$, $1);
                            asprintf(&cType, "%s", $1);

                     }}

%%

void assign_at_definition_mismatch_error(Expr*& exp1, Expr*& exp2){
       if(strcmp(exp1->typeof_expr, exp2->typeof_expr)!=0){
            char* str;
            asprintf(&str, "%s %s to %s","Error: incompatible types for action cannot assign ", exp2->typeof_expr, exp1->typeof_expr);
            yyerror(str);
            exit(EXIT_FAILURE);
       }
}


void assign_mismatch_error(Expr*& exp1, Expr*& exp2){
       if(strcmp(exp1->typeof_expr, exp2->typeof_expr)!=0){
            char* str;
            asprintf(&str, "%s %s to %s","Error: incompatible types for action cannot assign ", exp2->typeof_expr, exp1->typeof_expr);
            yyerror(str);
            exit(EXIT_FAILURE);
       }
}

void type_mismatch_error(Expr*& exp1, Expr*& exp2, Expr*& exp3, char op){
       if(!hasArithmeticType(exp1->typeof_expr) || !hasArithmeticType(exp2->typeof_expr)){
              char* str;
              asprintf(&str, "%s","Error: incompatible types for action");
              yyerror(str);
              exit(EXIT_FAILURE);
       }
       if(op=='+'){
              if(strcmp(exp1->typeof_expr, "String")==0||strcmp(exp2->typeof_expr, "String")==0){
                     asprintf(&exp3->typeof_expr, "%s", "String");
                     return;
              }
       }
       else{
             if(strcmp(exp1->typeof_expr, "String")==0||strcmp(exp2->typeof_expr, "String")==0){
                     char* str;
                     asprintf(&str, "%s","Error: incompatible types for action");
                     yyerror(str);
                     exit(EXIT_FAILURE);
             }
       }
       if(strcmp(exp1->typeof_expr, "double")==0 || strcmp(exp2->typeof_expr, "double")==0)
              asprintf(&exp3->typeof_expr, "%s", "double");
       else if(strcmp(exp1->typeof_expr, "int")==0 || strcmp(exp2->typeof_expr, "int")==0)
               asprintf(&exp3->typeof_expr, "%s", "int");
      else if(strcmp(exp1->typeof_expr, "char")==0 || strcmp(exp2->typeof_expr, "char")==0)
               asprintf(&exp3->typeof_expr, "%s", "char");
}



void function_semantic_error(const char* func, int scope, char* type){
       Symbol smb(func, scope);
       smb.type=string(type);
       if(!func_declare.exists_in_scope(smb)){
               func_declare.insert(smb);
               if(scope-cclass==1){
                     member_function_semantic_error(func, type, cVis);
              }
       }
       else{
            char* str;
            asprintf(&str, "Error redefinition of function :%s", func);
            yyerror(str);
            exit(EXIT_FAILURE);
       }
}

void function_undeclared_error(const char* func, int scope, Expr*& function){
        Symbol smb(func, scope);
        char* typeof_func;
        typeof_func=func_declare.retrieveType(smb);
        if(typeof_func!=nullptr){
              function=new Expr();
              asprintf(&function->typeof_expr, "%s", typeof_func);
              return;
        }
        else{
           char* str;
           asprintf(&str, "Error Function: %s undeclared", func);
           yyerror(str);
           exit(EXIT_FAILURE);
       }
}

void variable_semantic_error(const char* var, int scope, char* type){
       Symbol smb(var, scope);
       if(type!=nullptr){
              if(strcmp(type, "void")==0){
                     char* str;
                     asprintf(&str, "Error: Variable: %s cannot have type void", var);
                     yyerror(str);
                     exit(EXIT_FAILURE);
              }
              smb.type=string(type);
       }
       if(!variables.exists_in_scope(smb)&&!arrays.exists_in_scope(smb)){
                 variables.insert(smb);
                 if(scope-cclass==1)
                     member_variable_semantic_error(var, type, cVis);
       }
       else{
              char* str;
              asprintf(&str, "Error: Variable: %s already declared", var);
              yyerror(str);
              exit(EXIT_FAILURE);
       }
}

void variable_undeclared_error(const char* var, int scope, Expr*& vari){
       Symbol smb(var, scope);
       if(!isArr){
              char* typeof_var=variables.retrieveType(smb);
              if(typeof_var!=nullptr){
                     vari=new Expr();
                     asprintf(&vari->typeof_expr, "%s", typeof_var);
                     return;
              }
       }
       char* typeof_var=arrays.retrieveType(smb);
       if(typeof_var!=nullptr){
              vari=new Expr();
              asprintf(&vari->typeof_expr, "%s", typeof_var);
       }
       else{
              char* str;
              asprintf(&str, "Error Variable: %s undeclared", var);
              yyerror(str);
              exit(EXIT_FAILURE);
       }

}

void array_semantic_error(const char* var, int scope, char* type){
       Symbol smb(var, scope);
       if(type!=nullptr){
              if(strcmp(type, "void")==0){
                     char* str;
                     asprintf(&str, "Error: Variable: %s cannot have type void", var);
                     yyerror(str);
                     exit(EXIT_FAILURE);
              }
              smb.type=string(type);
       }
       if(!arrays.exists_in_scope(smb)&&!variables.exists_in_scope(smb)){
                 arrays.insert(smb);
                 if(scope-cclass==1)
                     member_array_semantic_error(var, type, cVis);
       }
       else{
              char* str;
              asprintf(&str, "Error: Variable: %s already declared", var);
              yyerror(str);
              exit(EXIT_FAILURE);
       }
}



void member_variable_semantic_error(const char* var, char* type, Visibility vis){
       MemberSymbol smb(var, cscope, cclass);
       if(type!=nullptr){
              smb.type=string(type);
              smb.vis=vis;
              smb.class_parent=string(cName);
       }
       auto it1=memVars.exists(smb);
       auto it2=memArrs.exists(smb);
       if(it1==memVars.memTable.end()&&it2==memArrs.memTable.end()){
              memVars.insert(smb);
       }
       else{
              char* str;
              asprintf(&str, "Error: Variable: %s already declared", var);
              yyerror(str);
              exit(EXIT_FAILURE);
       }
}


Visibility member_variable_undeclared_error(const char* var, Expr*& vari, const char* cName){
       MemberSymbol smb(var, cscope, cclass);
       smb.class_parent=string(cName);
       if(!isArr){
              auto cvar=memVars.exists(smb);
              if(cvar!=memVars.memTable.end()){
                     vari=new Expr();
                     asprintf(&vari->typeof_expr, "%s", (*cvar).type.c_str());
                     return (*cvar).vis;
              }
       }
       auto cvar=memArrs.exists(smb);
       if(cvar!=memArrs.memTable.end()){
              vari=new Expr();
              asprintf(&vari->typeof_expr, "%s", (*cvar).type.c_str());
              return (*cvar).vis;
       }
       else{
              char* str;
              asprintf(&str, "Error Variable: %s undeclared", var);
              yyerror(str);
              exit(EXIT_FAILURE);
       }
}

void member_array_semantic_error(const char* var, char* type, Visibility vis){
       MemberSymbol smb(var, cscope, cclass);
       if(type!=nullptr){
              smb.type=string(type);
              smb.vis=vis;
              smb.class_parent=string(cName);
       }
       if(memVars.exists(smb)==memVars.memTable.end()&&memArrs.exists(smb)==memArrs.memTable.end()){
              memArrs.insert(smb);
       }
       else{
              char* str;
              asprintf(&str, "Error: Variable: %s already declared", var);
              yyerror(str);
              exit(EXIT_FAILURE);
       }
}

void member_function_semantic_error(const char* func, char* type, Visibility vis){
      MemberSymbol smb(func, cscope, cclass);
      smb.type=string(type);
      smb.vis=vis;
      smb.class_parent=string(cName);
      auto it=memFuncs.exists(smb);
      if(it==memFuncs.memTable.end()){
              memFuncs.insert(smb);
      }
      else{
            char* str;
            asprintf(&str, "Error redefinition of function :%s", func);
            yyerror(str);
            exit(EXIT_FAILURE);
      }
}


Visibility member_function_undeclared_error(const char* func, Expr*& vari, const char* cName){
       MemberSymbol smb(func, cscope, cclass);
       smb.class_parent=string(cName);
       auto cvar=memFuncs.exists(smb);
       if(cvar!=memFuncs.memTable.end()){
           vari=new Expr();
           asprintf(&vari->typeof_expr, "%s", (*cvar).type.c_str());
           return (*cvar).vis;
       }
       else{
            char* str;
            asprintf(&str, "Error Function: %s undeclared", func);
            yyerror(str);
            exit(EXIT_FAILURE);
       }
}

bool hasArithmeticType(char* str){
       if(strcmp(str, "double")==0)
              return true;
       if(strcmp(str, "int")==0)
              return true;
       if(strcmp(str, "char")==0)
              return true;
       if(strcmp(str, "String")==0)
              return true;
       return false;

}


void yyerror(const char *s) {
    cerr<<lineenum<<": "<< s<<endl;
}


int main ( int argc, char **argv  )
  {
  ++argv; --argc;
  if ( argc > 0 ){
        yyin = fopen( argv[0], "r" );
        char* cmd;
        asprintf(&cmd, "cat %s", argv[0]);
        system(cmd);
   }
  else
        yyin = stdin;
  yyparse ();
  return 0;
  }


