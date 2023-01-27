%{
#include <stdio.h>
#include "util.h"
#include "errormsg.h"
#include "ast.h"

ExpressionPtr absyn_root; 
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

%nterm <ExpressionPtr> exp; 
%nterm <VariablePtr> lvalue; 
%nterm <FieldVariablePtr> field_extension;
%nterm <SubscriptVariablePtr> subscript_extension;
%nterm <ExpressionSequencePtr> expression_sequence exp_seq_tail;
%nterm <CallExpressionPtr> function_call;
%nterm <BinOpExpressionPtr> arithmetic_exp comparison_exp boolean_exp; 
%nterm <UnOpExpressionPtr> negation_exp; 
%nterm <RecordExpressionPtr> record_expression; 
%nterm <ArrayExpressionPtr> array_expression; 
%nterm <AssignStatementPtr> assign_statement; 
%nterm <IfStatementPtr> if_statement; 
%nterm <WhileStatementPtr> while_statement;
%nterm <ForStatementPtr> for_statement; 

%nterm <SymbolReferencePtr> type; 
%nterm <ExpressionListPtr> function_args function_args_tail
%nterm <efieldList> record_list record_list_extension
%nterm <efield> record_field

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

exp: INT {$$ = IntExpression::Node(drv.location.begin.line, $1);}
exp: lvalue 
exp: NIL {$$ = NilExpression::Node(drv.location.begin.line);}
exp: STRING {$$ = StringExpression::Node(drv.location.begin.line, $1);}
exp: BREAK {$$ = BreakStatement::Node(drv.location.begin.line);}
exp: LPAREN expression_sequence RPAREN {$$ = (ExpressionPtr)$2;}
exp: function_call {$$ = (ExpressionPtr)$1;}
exp: arithmetic_exp  {$$ = (ExpressionPtr)$1;}
exp: negation_exp 
exp: comparison_exp 
exp: boolean_exp 
exp: record_expression
exp: array_expression 
exp: assign_statement 
exp: if_statement 
exp: while_statement 
exp: for_statement
exp: let_statement

expression_sequence: {$$ = ExpressionSequence::Node(drv.location.begin.line);}
expression_sequence: exp exp_seq_tail {$2->push_front($1); $$ = $2;}

exp_seq_tail:  /*empty*/ {$$ = ExpressionSequence::Node(drv.location.begin.line);}
exp_seq_tail: SEMICOLON exp exp_seq_tail  {$3->push_front($2); $$ = $3;}

function_call: ID LPAREN function_args RPAREN 
  {$$ = CallExpression::Node(drv.location.begin.line, Symbol::Gen($1), *$3);}
	                                    
function_args: /* empty */ {$$ = std::make_shared<ExpressionList>();}
function_args: exp function_args_tail {$2->push_front($1); $$ = $2;}

function_args_tail: /*empty*/  {$$ = std::make_shared<ExpressionList>();}
function_args_tail: COMMA exp function_args_tail {$3->push_back($2); $$ = $3;}


arithmetic_exp:  exp PLUS exp 
  {$$ = BinOpExpression::Node(drv.location.begin.line, 
                                    BinOpExpression::plusOp, 
                                    $1,$3);}
arithmetic_exp:  exp MINUS exp 
  {$$ = BinOpExpression::Node(drv.location.begin.line, 
                                    BinOpExpression::minusOp, 
                                    $1,$3);}
arithmetic_exp:  exp TIMES exp 
  {$$ = BinOpExpression::Node(drv.location.begin.line, 
                                    BinOpExpression::timesOp, 
                                    $1,$3);}
arithmetic_exp:  exp DIVIDE exp 
  {$$ = BinOpExpression::Node(drv.location.begin.line, 
                                    BinOpExpression::divideOp, 
                                    $1,$3);}

negation_exp: MINUS exp %prec UMINUS {$$ = UnOpExpression::Node(drv.location.begin.line,
                                                        UnOpExpression::negationOp, $2); }

comparison_exp: exp EQ exp 
  {$$ = BinOpExpression::Node(drv.location.begin.line, 
                                    BinOpExpression::eqOp, 
                                    $1,$3);}
comparison_exp: exp NEQ exp
  {$$ = BinOpExpression::Node(drv.location.begin.line, 
                                    BinOpExpression::neqOp, 
                                    $1,$3);}
comparison_exp: exp GT exp
  {$$ = BinOpExpression::Node(drv.location.begin.line, 
                                    BinOpExpression::gtOp, 
                                    $1,$3);} 
comparison_exp: exp GE exp
  {$$ = BinOpExpression::Node(drv.location.begin.line, 
                                    BinOpExpression::geOp, 
                                    $1,$3);} 
comparison_exp: exp LT exp
  {$$ = BinOpExpression::Node(drv.location.begin.line, 
                                    BinOpExpression::ltOp, 
                                    $1,$3);} 
comparison_exp: exp LE exp 
  {$$ = BinOpExpression::Node(drv.location.begin.line, 
                                    BinOpExpression::leOp, 
                                    $1,$3);} 		
boolean_exp: exp AND exp
  {$$ = BinOpExpression::Node(drv.location.begin.line, 
                                    BinOpExpression::andOp, 
                                    $1,$3);} 
boolean_exp: exp OR exp
  {$$ = BinOpExpression::Node(drv.location.begin.line, 
                                    BinOpExpression::orOp, 
                                    $1,$3);}  


record_expression: ID LBRACE record_list RBRACE 
  {$$ = RecordExpression::Node(drv.location.begin.line,
                              Symbol::Gen($1), 
                              $3);}

record_list: record_field record_list_extension 
  {$2.push_front($1); $$ = std::move($2);}
	     
record_list_extension: {$$ = efieldList();}
record_list_extension: COMMA record_field record_list_extension  
  {$3.push_front($2); $$ = std::move($3);}    

record_field: ID EQ exp {$$ = efield{Symbol::Gen($1), $3};}

array_expression: ID LBRACK exp RBRACK OF exp
  {$$ = ArrayExpression::Node(drv.location.begin.line,
                                    Symbol::Gen($1),
                                    $3, $6);}

assign_statement: lvalue ASSIGN exp 
  {$$ = AssignStatement::Node(drv.location.begin.line,
                              $1, $3);}

if_statement: IF exp THEN exp ELSE exp
  {$$ = IfStatement::Node(drv.location.begin.line,
                                $2,$4,$6);}

if_statement: IF exp THEN exp 
  {$$ = IfStatement::Node(drv.location.begin.line,
                                $2,$4, NULL);}

while_statement: WHILE exp DO exp 
  {$$ = WhileStatement::Node(drv.location.begin.line,
                                    $2,$4);}

for_statement: FOR ID ASSIGN exp TO exp DO exp 
  {$$ = ForStatement::Node(drv.location.begin.line,
                                Symbol::Gen($2), $4, $6,$8);}

let_statement: LET declaration_sequence IN expression_sequence END

declaration_sequence: /*empty*/
declaration_sequence: declaration declaration_sequence
		      
declaration: type_declaration     
declaration: variable_declaration 
declaration: function_declaration 

type_declaration: TYPE ID EQ type 

type: ID 
  {$$ = SymbolReference::Node(drv.location.begin.line,
                                    Symbol::Gen($1));}
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

lvalue: ID {$$ = SimpleVariable::Node(0, Symbol::Gen($1));}
lvalue: ID field_extension {$$ = SimpleVariable::Node(0, Symbol::Gen($1)); $2->set_var($$);}
lvalue: ID subscript_extension {$$ = SimpleVariable::Node(0, Symbol::Gen($1)); $2->set_var($$);}

field_extension: DOT ID  {$$ = FieldVariable::PartialNode(0, Symbol::Gen($2)); }
field_extension: DOT ID field_extension {$$ = FieldVariable::PartialNode(0, Symbol::Gen($2)); $3->set_var($$);}
field_extension: DOT ID subscript_extension {$$ = FieldVariable::PartialNode(0, Symbol::Gen($2)); $3->set_var($$);}

subscript_extension: LBRACK exp RBRACK  {$$ = SubscriptVariable::PartialNode(0, $2);}
subscript_extension: LBRACK exp RBRACK field_extension {$$ = SubscriptVariable::PartialNode(0,$2); $4->set_var($$);}
subscript_extension: LBRACK exp RBRACK subscript_extension {$$ = SubscriptVariable::PartialNode(0,$2); $4->set_var($$);}
%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}