%{
#include <stdio.h>
#include "util.h"
#include "errormsg.h"
#include "ast.h"

AST::ExpressionPtr absyn_root; 
%}


%skeleton "lalr1.cc" // -*- C++ -*-
%require "3.8"
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

%code {
# include "driver.hh"
}

%token <std::string> ID STRING;
%token <int> INT;

%nterm <AST::ExpressionPtr> exp; 
%nterm <AST::VariablePtr> lvalue; 
%nterm <AST::FieldVariablePtr> field_extension;
%nterm <AST::SubscriptVariablePtr> subscript_extension;
%nterm <AST::ExpressionSequencePtr> expression_sequence exp_seq_tail;
%nterm <AST::CallExpressionPtr> function_call;
%nterm <AST::BinOpExpressionPtr> arithmetic_exp comparison_exp boolean_exp; 
%nterm <AST::UnOpExpressionPtr> negation_exp; 

%nterm <AST::ExpressionList> function_args function_args_tail
%nterm <AST::efieldList> record_list record_list_extension
%nterm <AST::efield> record_field

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

program: exp {absyn_root = $1;}

exp: INT {$$ = AST::IntExpression::Node(drv.location.begin.line, $1);}
exp: lvalue 
exp: NIL {$$ = AST::NilExpression::Node(drv.location.begin.line);}
exp: STRING {$$ = AST::StringExpression::Node(drv.location.begin.line, $1);}
exp: BREAK {$$ = AST::BreakStatement::Node(drv.location.begin.line);}
exp: LPAREN expression_sequence RPAREN {$$ = (AST::ExpressionPtr)$2;}
exp: function_call {$$ = (AST::ExpressionPtr)$1;}
exp: arithmetic_exp  {$$ = (AST::ExpressionPtr)$1;}
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

expression_sequence: {$$ = AST::ExpressionSequence::Node(drv.location.begin.line);}
expression_sequence: exp exp_seq_tail {$2->push_front($1); $$ = $2;}

exp_seq_tail:  /*empty*/ {$$ = AST::ExpressionSequence::Node(drv.location.begin.line);}
exp_seq_tail: SEMICOLON exp exp_seq_tail  {$3->push_front($2); $$ = $3;}

function_call: ID LPAREN function_args RPAREN 
  {$$ = AST::CallExpression::Node(drv.location.begin.line, AST::Symbol::Gen($1), $3);}
	                                    
function_args: /* empty */ {$$ = AST::ExpressionList();}
function_args: exp function_args_tail {$2.push_front($1); $$ = std::move($2);}

function_args_tail: /*empty*/  {$$ = AST::ExpressionList();}
function_args_tail: COMMA exp function_args_tail {$3.push_back($2); $$ = std::move($3);}


arithmetic_exp:  exp PLUS exp 
  {$$ = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::plusOp, 
                                    $1,$3);}
arithmetic_exp:  exp MINUS exp 
  {$$ = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::minusOp, 
                                    $1,$3);}
arithmetic_exp:  exp TIMES exp 
  {$$ = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::timesOp, 
                                    $1,$3);}
arithmetic_exp:  exp DIVIDE exp 
  {$$ = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::divideOp, 
                                    $1,$3);}

negation_exp: MINUS exp %prec UMINUS {$$ = AST::UnOpExpression::Node(drv.location.begin.line,
                                                        AST::UnOpExpression::negationOp, $2); }

comparison_exp: exp EQ exp 
  {$$ = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::eqOp, 
                                    $1,$3);}
comparison_exp: exp NEQ exp
  {$$ = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::neqOp, 
                                    $1,$3);}
comparison_exp: exp GT exp
  {$$ = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::gtOp, 
                                    $1,$3);} 
comparison_exp: exp GE exp
  {$$ = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::geOp, 
                                    $1,$3);} 
comparison_exp: exp LT exp
  {$$ = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::ltOp, 
                                    $1,$3);} 
comparison_exp: exp LE exp 
  {$$ = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::leOp, 
                                    $1,$3);} 		
boolean_exp: exp AND exp
  {$$ = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::andOp, 
                                    $1,$3);} 
boolean_exp: exp OR exp
  {$$ = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::orOp, 
                                    $1,$3);}  


record_creation: ID LBRACE record_list RBRACE

record_list: record_field record_list_extension 
  {$2.push_front($1); $$ = std::move($2);}
	     
record_list_extension: {$$ = AST::efieldList();}
record_list_extension: COMMA record_field record_list_extension  
  {$3.push_front($2); $$ = std::move($3);}    

record_field: ID EQ exp {$$ = AST::efield{AST::Symbol::Gen($1), $3};}

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

lvalue: ID {$$ = AST::SimpleVariable::Node(0, AST::Symbol::Gen($1));}
lvalue: ID field_extension {$$ = AST::SimpleVariable::Node(0, AST::Symbol::Gen($1)); $2->set_var($$);}
lvalue: ID subscript_extension {$$ = AST::SimpleVariable::Node(0, AST::Symbol::Gen($1)); $2->set_var($$);}

field_extension: DOT ID  {$$ = AST::FieldVariable::PartialNode(0, AST::Symbol::Gen($2)); }
field_extension: DOT ID field_extension {$$ = AST::FieldVariable::PartialNode(0, AST::Symbol::Gen($2)); $3->set_var($$);}
field_extension: DOT ID subscript_extension {$$ = AST::FieldVariable::PartialNode(0, AST::Symbol::Gen($2)); $3->set_var($$);}

subscript_extension: LBRACK exp RBRACK  {$$ = AST::SubscriptVariable::PartialNode(0, $2);}
subscript_extension: LBRACK exp RBRACK field_extension {$$ = AST::SubscriptVariable::PartialNode(0,$2); $4->set_var($$);}
subscript_extension: LBRACK exp RBRACK subscript_extension {$$ = AST::SubscriptVariable::PartialNode(0,$2); $4->set_var($$);}
%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}