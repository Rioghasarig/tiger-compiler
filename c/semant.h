#ifndef SEMANT_H
#define SEMANT_H
#include "util.h"
#include "symbol.h"
#include "types.h"
#include "absyn.h"
#include "translate.h"

typedef void *Tr_exp; 
struct expty
{
  Tr_exp exp;
  Ty_ty ty;
};

void SEM_transProg(A_exp exp); 

struct expty transVar(S_table venv, S_table tenv, A_var v);
void transDec(S_table venv, S_table tenv, A_dec d, Tr_level level);
struct expty transExp(S_table venv, S_table tenv, A_exp a, Tr_level level);

Ty_ty tylook(S_table tenv, S_symbol type_name, int pos);
#endif
