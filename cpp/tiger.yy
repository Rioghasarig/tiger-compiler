%{
#include <stdio.h>
#include "util.h"
#include "errormsg.h"
#include "ast.h"

AST::ExpressionPtr absyn_root; 
%}


%skeleton "lalr1.cc" // -*- C++ -*-
%require "3.8.2"
%header

%define api.token.raw

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
  # include <string>
  class driver;
}

// The parsing context.
%param { driver& drv }


%locations

%define parse.trace
%define parse.error detailed
%define parse.lac full

%code {
# include "driver.hh"
}

%token <std::string> ID STRING;
%token <int> INT;

%nterm <AST::ExpressionPtr> exp;

%token 
  COMMA COLON SEMICOLON LPAREN RPAREN LBRACK RBRACK 
  LBRACE RBRACE DOT 
  PLUS MINUS TIMES DIVIDE EQ NEQ LT LE GT GE
  AND OR ASSIGN
  ARRAY IF THEN ELSE WHILE FOR TO DO LET IN END OF 
  BREAK NIL
  FUNCTION VAR TYPE 

%nonassoc FOR TO
%nonassoc WHILE DO
%nonassoc THEN
%nonassoc ELSE
%left ASSIGN
%left AND
%left OR
%nonassoc EQ NEQ GT GE LT LE OF
%left PLUS MINUS
%left TIMES DIVIDE
%left UMINUS

%%
%start program;
/* This is a skeleton grammar file, meant to illustrate what kind of
 * declarations are necessary above the %% mark.  Students are expected
 *  to replace the two dummy productions below with an actual grammar. 
 */

program: exp 

exp: INT {$$ = AST::IntExpression::Node(0, $1);}
exp: lvalue 
exp: NIL 
exp: STRING 
exp: BREAK 
exp: LPAREN expression_sequence RPAREN 
exp: function_call 
exp: arithmetic_exp  
exp: negation_exp 
exp: comparison_exp 
exp: boolean_exp 
exp: record_creation 
exp: array_creation 
exp: assignment_exp 
exp: if_statement 
exp: while_loop 
exp: for_loop 
exp: let_statement

expression_sequence: 
expression_sequence: exp exp_seq_tail 

exp_seq_tail:  /*empty*/ 
exp_seq_tail: SEMICOLON exp exp_seq_tail 

function_call: ID LPAREN function_args RPAREN 
	                                    
function_args: /* empty */ 
function_args: exp function_args_tail 

function_args_tail: /*empty*/  
function_args_tail: COMMA exp function_args_tail 


arithmetic_exp:  exp PLUS exp 
arithmetic_exp:  exp MINUS exp
arithmetic_exp:  exp TIMES exp 
arithmetic_exp:  exp DIVIDE exp

negation_exp: MINUS exp %prec UMINUS 

comparison_exp: exp EQ exp 
comparison_exp: exp NEQ exp
comparison_exp: exp GT exp 
comparison_exp: exp GE exp 
comparison_exp: exp LT exp 
comparison_exp: exp LE exp 
		
boolean_exp: exp AND exp 
boolean_exp: exp OR exp 


record_creation: ID LBRACE record_list RBRACE

record_list: ID EQ exp record_list_extension
	     
record_list_extension: /*empty*/ 
record_list_extension: COMMA ID EQ exp record_list_extension       


array_creation: ID LBRACK exp RBRACK OF exp
		

assignment_exp: lvalue ASSIGN exp

if_statement: IF exp THEN exp ELSE exp

if_statement: IF exp THEN exp 

while_loop: WHILE exp DO exp 

for_loop: FOR ID ASSIGN exp TO exp DO exp

let_statement: LET declaration_sequence IN expression_sequence END

declaration_sequence: /*empty*/
declaration_sequence: declaration declaration_sequence
		      
declaration: type_declaration     
declaration: variable_declaration 
declaration: function_declaration 

type_declaration: TYPE ID EQ type 

type: ID 
type: LBRACE  type_fields RBRACE 
type: ARRAY OF ID 

type_fields: /*empty*/ 
type_fields: ID COLON ID type_fields_extension

type_fields_extension: /*empty*/ 
type_fields_extension: COMMA ID COLON ID  type_fields_extension
		       
variable_declaration: VAR ID ASSIGN exp 
variable_declaration: VAR ID COLON ID ASSIGN exp

function_declaration: FUNCTION ID LPAREN type_fields RPAREN EQ exp
function_declaration: FUNCTION ID LPAREN type_fields RPAREN COLON ID EQ exp

lvalue: ID lvalue_extension 

lvalue_extension: /* empty */ 
lvalue_extension: DOT ID lvalue_extension 
lvalue_extension: LBRACK exp RBRACK lvalue_extension 
%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}