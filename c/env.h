#include "types.h"
#include "translate.h"
typedef struct E_enventry_ *E_enventry;

struct E_enventry_ {
  enum { E_varEntry, E_funEntry } kind;
  union {
    struct {
      Tr_access access;
      Ty_ty ty;
    } var;
    struct {
      Tr_level level;
      Temp_label label;
      Ty_tyList formals;
      Ty_ty result;
    } fun;
  } u;
};

E_enventry E_VarEntry(Tr_access access, Ty_ty ty);
E_enventry E_FunEntry(Tr_level level, Temp_label label, Ty_tyList formals,
                      Ty_ty result);
