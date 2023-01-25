#include "env.h"

#include "symbol.h"
#include "types.h"
#include "util.h"

E_enventry E_VarEntry(Tr_access access, Ty_ty ty) {
  E_enventry p = checked_malloc(sizeof(*p));
  p->kind = E_varEntry;
  p->u.var.ty = ty;
  p->u.var.access = access;
  return p;
}

E_enventry E_FunEntry(Tr_level level, Temp_label label, Ty_tyList formals,
                      Ty_ty result) {
  E_enventry p = checked_malloc(sizeof(*p));
  p->kind = E_funEntry;
  p->u.fun.formals = formals;
  p->u.fun.result = result;
  p->u.fun.level = level;
  p->u.fun.label = label; 
  return p ; 
}
