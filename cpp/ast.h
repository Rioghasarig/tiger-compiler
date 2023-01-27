#ifndef AST_H
#define AST_H
#include <list>
#include <memory>
#include <string>

class Variable;
class FieldVariable;
class SubscriptVariable;

class Expression;
class IntExpression;
class StringExpression;
class ExpressionSequence;
class CallExpression;
class BinOpExpression;
class UnOpExpression;
class RecordExpression;
class ArrayExpression;
class AssignStatement;
class IfStatement;
class WhileStatement;
class ForStatement;
class LetStatement;

class SymbolReference;

class Declaration;

class Type;
class Symbol;

struct efield;
struct field;

using VariablePtr = std::shared_ptr<Variable>;
using FieldVariablePtr = std::shared_ptr<FieldVariable>;
using SubscriptVariablePtr = std::shared_ptr<SubscriptVariable>;

using ExpressionPtr = std::shared_ptr<Expression>;
using IntExpressionPtr = std::shared_ptr<IntExpression>;
using StringExpressionPtr = std::shared_ptr<StringExpression>;
using ExpressionSequencePtr = std::shared_ptr<ExpressionSequence>;
using CallExpressionPtr = std::shared_ptr<CallExpression>;
using BinOpExpressionPtr = std::shared_ptr<BinOpExpression>;
using UnOpExpressionPtr = std::shared_ptr<UnOpExpression>;
using RecordExpressionPtr = std::shared_ptr<RecordExpression>;
using ArrayExpressionPtr = std::shared_ptr<ArrayExpression>;
using AssignStatementPtr = std::shared_ptr<AssignStatement>;
using IfStatementPtr = std::shared_ptr<IfStatement>;
using WhileStatementPtr = std::shared_ptr<WhileStatement>;
using ForStatementPtr = std::shared_ptr<ForStatement>;

using DeclarationPtr = std::shared_ptr<Declaration>;

using TypePtr = std::shared_ptr<Type>;
using SymbolReferencePtr = std::shared_ptr<SymbolReference>;

using SymbolPtr = std::shared_ptr<Symbol>;

// List Aliases
using DeclarationList = std::list<DeclarationPtr>;
using ExpressionList = std::list<ExpressionPtr>;
using ExpressionListPtr = std::shared_ptr<ExpressionList>;

// using efieldPtr = std::shared_ptr<efield>;
// using efieldList = std::list<efieldPtr>;
using efieldList = std::list<efield>;
using fieldPtr = std::shared_ptr<field>;
using fieldList = std::list<fieldPtr>;

struct efield {
  SymbolPtr name;
  ExpressionPtr exp;
};

struct field {
  SymbolPtr name;
  SymbolPtr type;
  int pos;
};

class ASTNode {
 private:
  int id;
};
using NodePtr = std::shared_ptr<ASTNode>;

class Symbol {
  std::string name;

 public:
  Symbol(std::string name) : name(name){};

  static SymbolPtr Gen(std::string name) {
    return std::make_shared<Symbol>(name);
  }
};

// Variables
class Variable : public ASTNode {
 public:
  enum var_kind { simpleVar, fieldVar, subscriptVar };
  Variable(int pos, var_kind kind) : pos(pos), kind(kind) {}

 private:
  int pos;
  var_kind kind;
};

class SimpleVariable : public Variable {
 public:
  SimpleVariable(int pos, SymbolPtr name)
      : Variable(pos, simpleVar), name(name){};

  static VariablePtr Node(int pos, SymbolPtr name);
  void set_var(VariablePtr v) { return; }

 private:
  SymbolPtr name;
};

class FieldVariable : public Variable {
 public:
  FieldVariable(int pos, VariablePtr var, SymbolPtr field_name)
      : Variable(pos, fieldVar), var(var), field_name(field_name) {}
  FieldVariable(int pos, SymbolPtr field_name)
      : Variable(pos, fieldVar), field_name(field_name) {}

  void set_var(VariablePtr v) { var = v; }
  static FieldVariablePtr Node(int pos, VariablePtr var, SymbolPtr field_name);
  static FieldVariablePtr PartialNode(int pos, SymbolPtr field_name);

 private:
  VariablePtr var;
  SymbolPtr field_name;
};

class SubscriptVariable : public Variable {
 public:
  SubscriptVariable(int pos, VariablePtr var, ExpressionPtr exp)
      : Variable(pos, subscriptVar), var(var), exp(exp) {}

  SubscriptVariable(int pos, ExpressionPtr exp)
      : Variable(pos, subscriptVar), exp(exp) {}

  void set_var(VariablePtr v) { var = v; }
  static SubscriptVariablePtr Node(int pos, VariablePtr var, ExpressionPtr exp);
  static SubscriptVariablePtr PartialNode(int pos, ExpressionPtr exp);

 private:
  VariablePtr var;
  ExpressionPtr exp;
};

// Expressions
class Expression : public ASTNode {
 public:
  enum expression_kind {
    varExp,
    nilExp,
    intExp,
    stringExp,
    callExp,
    unOpExp,
    binOpExp,
    recordExp,
    seqExp,
    assignExp,
    ifExp,
    whileExp,
    forExp,
    breakExp,
    letExp,
    arrayExp
  };
  Expression(int pos, expression_kind kind) : pos(pos), kind(kind) {}

 private:
  int pos;
  expression_kind kind;
};

class VariableExpression : public Expression {
 public:
  VariableExpression(int pos, VariablePtr var)
      : Expression(pos, varExp), var(var) {}

  static ExpressionPtr Node(int pos, VariablePtr var);

 private:
  VariablePtr var;
};

class IntExpression : public Expression {
 public:
  IntExpression(int pos, int value) : Expression(pos, intExp), value(value) {}

  static ExpressionPtr Node(int pos, int value);

 private:
  int value;
};

class NilExpression : public Expression {
 public:
  NilExpression(int pos) : Expression(pos, nilExp) {}

  static ExpressionPtr Node(int pos);
};

class StringExpression : public Expression {
 public:
  StringExpression(int pos, std::string string_val)
      : Expression(pos, stringExp), string_val(string_val) {}

  static ExpressionPtr Node(int pos, std::string string_val);

 private:
  std::string string_val;
};

class CallExpression : public Expression {
 public:
  CallExpression(int pos, SymbolPtr func, ExpressionList args)
      : Expression(pos, callExp), func(func), args(std::move(args)) {}

  static CallExpressionPtr Node(int pos, SymbolPtr func, ExpressionList args);

 private:
  SymbolPtr func;
  ExpressionList args;
};

class BinOpExpression : public Expression {
 public:
  enum oper {
    plusOp,
    minusOp,
    timesOp,
    divideOp,
    eqOp,
    neqOp,
    ltOp,
    leOp,
    gtOp,
    geOp,
    andOp,
    orOp
  };

  BinOpExpression(int pos, oper op, ExpressionPtr left, ExpressionPtr right)
      : Expression(pos, binOpExp), op(op), left(left), right(right) {}

  static BinOpExpressionPtr Node(int pos, oper op, ExpressionPtr left,
                                 ExpressionPtr right);

 private:
  oper op;
  ExpressionPtr left;
  ExpressionPtr right;
};

class UnOpExpression : public Expression {
 public:
  enum oper { negationOp };
  UnOpExpression(int pos, oper op, ExpressionPtr arg)
      : Expression(pos, unOpExp), op(op), arg(arg) {}

  static UnOpExpressionPtr Node(int pos, oper op, ExpressionPtr arg);

 private:
  oper op;
  ExpressionPtr arg;
};

class RecordExpression : public Expression {
 public:
  RecordExpression(int pos, SymbolPtr type, efieldList fields)
      : Expression(pos, recordExp), type(type), fields(std::move(fields)) {}

  static RecordExpressionPtr Node(int pos, SymbolPtr type, efieldList fields);

 private:
  SymbolPtr type;
  efieldList fields;
};

class ExpressionSequence : public Expression {
 public:
  ExpressionSequence(int pos) : Expression(pos, seqExp) {}

  static ExpressionSequencePtr Node(int pos);

  void push_front(ExpressionPtr item) { sequence.push_front(item); }

 private:
  ExpressionList sequence;
};

class AssignStatement : public Expression {
 public:
  AssignStatement(int pos, VariablePtr var, ExpressionPtr exp)
      : Expression(pos, assignExp), var(var), exp(exp) {}

  static AssignStatementPtr Node(int pos, VariablePtr, ExpressionPtr exp);

 private:
  VariablePtr var;
  ExpressionPtr exp;
};

class IfStatement : public Expression {
 public:
  IfStatement(int pos, ExpressionPtr test, ExpressionPtr then,
              ExpressionPtr elsee)
      : Expression(pos, ifExp), test(test), then(then), elsee(elsee) {}

  static IfStatementPtr Node(int pos, ExpressionPtr test, ExpressionPtr then,
                             ExpressionPtr elsee);

 private:
  ExpressionPtr test;
  ExpressionPtr then;
  ExpressionPtr elsee;
};

class WhileStatement : public Expression {
 public:
  WhileStatement(int pos, ExpressionPtr test, ExpressionPtr body)
      : Expression(pos, whileExp), test(test), body(body) {}

  static WhileStatementPtr Node(int pos, ExpressionPtr test,
                                ExpressionPtr body);

 private:
  ExpressionPtr test;
  ExpressionPtr body;
};

class ForStatement : public Expression {
 public:
  ForStatement(int pos, SymbolPtr var, ExpressionPtr lo, ExpressionPtr hi,
               ExpressionPtr body)
      : Expression(pos, forExp), var(var), lo(lo), hi(hi), body(body) {}

  static ForStatementPtr Node(int pos, SymbolPtr var, ExpressionPtr lo,
                              ExpressionPtr hi, ExpressionPtr body);

 private:
  SymbolPtr var;
  ExpressionPtr lo;
  ExpressionPtr hi;
  ExpressionPtr body;
};

class BreakStatement : public Expression {
 public:
  BreakStatement(int pos) : Expression(pos, breakExp) {}
  static ExpressionPtr Node(int pos);
};

class LetStatement : public Expression {
 public:
  LetStatement(int pos, DeclarationList decs, ExpressionPtr body)
      : Expression(pos, letExp), decs(std::move(decs)), body(body) {}

  static ExpressionPtr Node(int pos, DeclarationList decs, ExpressionPtr body);

 private:
  DeclarationList decs;
  ExpressionPtr body;
};

class ArrayExpression : public Expression {
 public:
  ArrayExpression(int pos, SymbolPtr type, ExpressionPtr size,
                  ExpressionPtr init)
      : Expression(pos, arrayExp), type(type), size(size), init(init) {}

  static ArrayExpressionPtr Node(int pos, SymbolPtr type, ExpressionPtr size,
                                 ExpressionPtr init);

 private:
  SymbolPtr type;
  ExpressionPtr size;
  ExpressionPtr init;
};

// Declarations

class Declaration : public ASTNode {
 public:
  enum dec_kind { functionDec, varDec, typeDec };
  Declaration(int pos, dec_kind kind) : pos(pos), kind(kind) {}

 private:
  int pos;
  dec_kind kind;
};

class FunctionDeclaration : public Declaration {
 public:
  FunctionDeclaration(int pos, SymbolPtr name, fieldList params)
      : Declaration(pos, functionDec), name(name), params(std::move(params)) {}

  static DeclarationPtr Node(int pos, SymbolPtr name, fieldList params);

 private:
  SymbolPtr name;
  fieldList params;
};

class VariableDeclaration : public Declaration {
 public:
  VariableDeclaration(int pos, SymbolPtr var_name, SymbolPtr type_name,
                      ExpressionPtr init)
      : Declaration(pos, varDec),
        var_name(var_name),
        type_name(type_name),
        init(init) {}

  static DeclarationPtr Node(int pos, SymbolPtr var_name, SymbolPtr type_name,
                             ExpressionPtr init);

 private:
  SymbolPtr var_name;
  SymbolPtr type_name;
  ExpressionPtr init;
};

class TypeDeclaration : public Declaration {
 public:
  TypeDeclaration(int pos, SymbolPtr type_name, TypePtr type)
      : Declaration(pos, typeDec), type_name(type_name), type(type) {}

  static DeclarationPtr Node(int pos, SymbolPtr type_name, TypePtr type);

 private:
  SymbolPtr type_name;
  TypePtr type;
};

// Types
class Type {
 public:
  enum type_kind { symbol_ref, record, array_ref };

  Type(int pos, type_kind kind) : pos(pos), kind(kind) {}

 private:
  int pos;
  type_kind kind;
};

class SymbolReference : public Type {
 public:
  SymbolReference(int pos, SymbolPtr type_name)
      : Type(pos, symbol_ref), type_name(type_name) {}

  static SymbolReferencePtr Node(int pos, SymbolPtr type_name);

 private:
  SymbolPtr type_name;
};

class RecordType : public Type {
 public:
  RecordType(int pos, fieldList fields)
      : Type(pos, record), fields(std::move(fields)) {}
  static TypePtr Node(int pos, fieldList fields);

 private:
  fieldList fields;
};

class ArrayType : public Type {
 public:
  ArrayType(int pos, SymbolPtr array_name)
      : Type(pos, array_ref), array_name(array_name) {}

  static TypePtr Node(int pos, SymbolPtr array_name);

 private:
  SymbolPtr array_name;
};

#endif