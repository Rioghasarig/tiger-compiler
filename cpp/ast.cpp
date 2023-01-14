#include "ast.h"

namespace AST {


// Variables 
VariablePtr 
SimpleVariable::Node(int pos, SymbolPtr name) 
{
    VariablePtr node = std::make_shared<SimpleVariable>(pos, name);
    return node; 
}

VariablePtr 
FieldVariable::Node(int pos, VariablePtr var, SymbolPtr field_name) 
{
    VariablePtr node = std::make_shared<FieldVariable>(pos, var, field_name);
    return node;  
} 

VariablePtr
SubscriptVariable::Node(int pos, VariablePtr var, ExpressionPtr exp) 
{
    VariablePtr node = std::make_shared<SubscriptVariable>(pos, var, exp); 
    return node;
}

// Expressions

ExpressionPtr
VariableExpression::Node(int pos, VariablePtr var) 
{
    ExpressionPtr node = std::make_shared<VariableExpression>(pos, var); 
    return node; 
}

ExpressionPtr
IntExpression::Node(int pos, int value) 
{
    ExpressionPtr node = std::make_shared<IntExpression>(pos, value);
    return node;  
}

ExpressionPtr
StringExpression::Node(int pos, std::string string_val ) 
{ 
    ExpressionPtr node  = std::make_shared<StringExpression>(pos, string_val);
    return node;  
}

ExpressionPtr
CallExpression::Node(int pos, SymbolPtr func, ExpressionList args) 
{
    ExpressionPtr node = std::make_shared<CallExpression>(pos, func, args); 
    return node; 
}

ExpressionPtr
OpExpression::Node(int pos, oper op, ExpressionPtr left, ExpressionPtr right) 
{
    ExpressionPtr node = std::make_shared<OpExpression>(pos, op, left, right); 
    return node; 
}

ExpressionPtr
RecordExpression::Node(int pos, SymbolPtr type, efieldList fields)
{
    ExpressionPtr node = 
        std::make_shared<RecordExpression>(pos, type, fields);
    return node;  
}

ExpressionPtr 
ExpressionSequence::Node(int pos, ExpressionList sequence) 
{
    ExpressionPtr node = std::make_shared<ExpressionSequence>(pos, sequence); 
    return node; 
}

ExpressionPtr 
AssignStatement::Node(int pos, VariablePtr var, ExpressionPtr exp) 
{
    ExpressionPtr node = std::make_shared<AssignStatement>(pos, var, exp); 
    return node; 
}

ExpressionPtr 
IfStatement::Node(int pos, ExpressionPtr test, ExpressionPtr then, 
                    ExpressionPtr elsee)
{
    ExpressionPtr node = std::make_shared<IfStatement>(pos, test, then, elsee);
    return node; 
}

ExpressionPtr 
WhileStatement::Node(int pos, ExpressionPtr test, ExpressionPtr body) 
{
    ExpressionPtr node = std::make_shared<WhileStatement>(pos, test, body);
    return node; 
}

ExpressionPtr
ForStatement::Node(int pos, SymbolPtr var, ExpressionPtr lo, ExpressionPtr hi,
                    ExpressionPtr body) 
{
    ExpressionPtr node = std::make_shared<ForStatement>(pos, var, lo, hi, body);
    return node; 
}

ExpressionPtr 
LetStatement::Node(int pos, DeclarationList decs, ExpressionPtr body) {
    ExpressionPtr node = std::make_shared<LetStatement>(pos, decs, body); 
    return node; 
}

ExpressionPtr 
ArrayCreation::Node(int pos, SymbolPtr type, ExpressionPtr size, 
                    ExpressionPtr init) 
{
    ExpressionPtr node = 
        std::make_shared<ArrayCreation>(pos, type, size, init);

    return node; 
}




// Declarations

DeclarationPtr 
FunctionDeclaration::Node(int pos, SymbolPtr name, fieldList params) 
{
    DeclarationPtr node = 
        std::make_shared<FunctionDeclaration>(pos, name, params);

    return node; 
}


DeclarationPtr
VariableDeclaration::Node(int pos, SymbolPtr var_name, SymbolPtr type_name,
                            ExpressionPtr init)
{
    DeclarationPtr node = 
        std::make_shared<VariableDeclaration>(pos, var_name, type_name, init);

    return node;
}

DeclarationPtr
TypeDeclaration::Node(int pos, SymbolPtr type_name, TypePtr type) 
{
    DeclarationPtr node =
        std::make_shared<TypeDeclaration>(pos, type_name, type);
    return node; 
}

// Types 
TypePtr 
SymbolReference::Node(int pos, SymbolPtr type_name) 
{
    TypePtr node =
        std::make_shared<SymbolReference>(pos, type_name);
    return node; 
}

TypePtr 
Record::Node(int pos, fieldList fields) 
{
    TypePtr node =
        std::make_shared<Record>(pos, fields);
    return node; 
}

TypePtr 
ArrayReference::Node(int pos, SymbolPtr array_name)
{
    TypePtr node =
        std::make_shared<ArrayReference>(pos,array_name);

    return node; 
} 
}

