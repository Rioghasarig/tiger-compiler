#include "ast.h"

// Variables
VariablePtr SimpleVariable::Node(int pos, SymbolPtr name) {
  VariablePtr node = std::make_shared<SimpleVariable>(pos, name);
  return node;
}

FieldVariablePtr FieldVariable::Node(int pos, VariablePtr var,
                                     SymbolPtr field_name) {
  FieldVariablePtr node = std::make_shared<FieldVariable>(pos, var, field_name);
  return node;
}

FieldVariablePtr FieldVariable::PartialNode(int pos, SymbolPtr field_name) {
  FieldVariablePtr node = std::make_shared<FieldVariable>(pos, field_name);
  return node;
}

SubscriptVariablePtr SubscriptVariable::Node(int pos, VariablePtr var,
                                             ExpressionPtr exp) {
  SubscriptVariablePtr node =
      std::make_shared<SubscriptVariable>(pos, var, exp);
  return node;
}

SubscriptVariablePtr SubscriptVariable::PartialNode(int pos,
                                                    ExpressionPtr exp) {
  SubscriptVariablePtr node = std::make_shared<SubscriptVariable>(pos, exp);
  return node;
}
// Expressions

ExpressionPtr VariableExpression::Node(int pos, VariablePtr var) {
  ExpressionPtr node = std::make_shared<VariableExpression>(pos, var);
  return node;
}

ExpressionPtr IntExpression::Node(int pos, int value) {
  ExpressionPtr node = std::make_shared<IntExpression>(pos, value);
  return node;
}

ExpressionPtr StringExpression::Node(int pos, std::string string_val) {
  ExpressionPtr node = std::make_shared<StringExpression>(pos, string_val);
  return node;
}

ExpressionPtr NilExpression::Node(int pos) {
  ExpressionPtr node = std::make_shared<NilExpression>(pos);
  return node;
}

CallExpressionPtr CallExpression::Node(int pos, SymbolPtr func,
                                       ExpressionList args) {
  CallExpressionPtr node = std::make_shared<CallExpression>(pos, func, args);
  return node;
}

BinOpExpressionPtr BinOpExpression::Node(int pos, oper op, ExpressionPtr left,
                                         ExpressionPtr right) {
  BinOpExpressionPtr node =
      std::make_shared<BinOpExpression>(pos, op, left, right);
  return node;
}

UnOpExpressionPtr UnOpExpression::Node(int pos, oper op, ExpressionPtr arg) {
  UnOpExpressionPtr node = std::make_shared<UnOpExpression>(pos, op, arg);
  return node;
}

RecordExpressionPtr RecordExpression::Node(int pos, SymbolPtr type,
                                           efieldList fields) {
  RecordExpressionPtr node =
      std::make_shared<RecordExpression>(pos, type, fields);
  return node;
}

ExpressionSequencePtr ExpressionSequence::Node(int pos) {
  ExpressionSequencePtr node = std::make_shared<ExpressionSequence>(pos);
  return node;
}

AssignStatementPtr AssignStatement::Node(int pos, VariablePtr var,
                                         ExpressionPtr exp) {
  AssignStatementPtr node = std::make_shared<AssignStatement>(pos, var, exp);
  return node;
}

IfStatementPtr IfStatement::Node(int pos, ExpressionPtr test,
                                 ExpressionPtr then, ExpressionPtr elsee) {
  IfStatementPtr node = std::make_shared<IfStatement>(pos, test, then, elsee);
  return node;
}

WhileStatementPtr WhileStatement::Node(int pos, ExpressionPtr test,
                                       ExpressionPtr body) {
  WhileStatementPtr node = std::make_shared<WhileStatement>(pos, test, body);
  return node;
}

ForStatementPtr ForStatement::Node(int pos, SymbolPtr var, ExpressionPtr lo,
                                   ExpressionPtr hi, ExpressionPtr body) {
  ForStatementPtr node = std::make_shared<ForStatement>(pos, var, lo, hi, body);
  return node;
}

ExpressionPtr BreakStatement::Node(int pos) {
  ExpressionPtr node = std::make_shared<BreakStatement>(pos);
  return node;
}

ExpressionPtr LetStatement::Node(int pos, DeclarationList decs,
                                 ExpressionPtr body) {
  ExpressionPtr node = std::make_shared<LetStatement>(pos, decs, body);
  return node;
}

ArrayExpressionPtr ArrayExpression::Node(int pos, SymbolPtr type,
                                         ExpressionPtr size,
                                         ExpressionPtr init) {
  ArrayExpressionPtr node =
      std::make_shared<ArrayExpression>(pos, type, size, init);

  return node;
}

// Declarations

DeclarationPtr FunctionDeclaration::Node(int pos, SymbolPtr name,
                                         fieldList params) {
  DeclarationPtr node =
      std::make_shared<FunctionDeclaration>(pos, name, params);

  return node;
}

DeclarationPtr VariableDeclaration::Node(int pos, SymbolPtr var_name,
                                         SymbolPtr type_name,
                                         ExpressionPtr init) {
  DeclarationPtr node =
      std::make_shared<VariableDeclaration>(pos, var_name, type_name, init);

  return node;
}

DeclarationPtr TypeDeclaration::Node(int pos, SymbolPtr type_name,
                                     TypePtr type) {
  DeclarationPtr node = std::make_shared<TypeDeclaration>(pos, type_name, type);
  return node;
}

// Types
SymbolReferencePtr SymbolReference::Node(int pos, SymbolPtr type_name) {
  SymbolReferencePtr node = std::make_shared<SymbolReference>(pos, type_name);
  return node;
}

TypePtr RecordType::Node(int pos, fieldList fields) {
  TypePtr node = std::make_shared<RecordType>(pos, fields);
  return node;
}

TypePtr ArrayType::Node(int pos, SymbolPtr array_name) {
  TypePtr node = std::make_shared<ArrayType>(pos, array_name);

  return node;
}
// namespace AST
