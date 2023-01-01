#include <stdio.h>
#include "std_functions.h"
#include "env.h"

void add_std_functions(S_table venv) {
  struct std_function print = {
    "print",
    Ty_Void(),
    Ty_TyList(Ty_String(), NULL)
  };
  
  struct std_function flush = {
    "flush",    
    Ty_Void(),
    NULL
  };

  struct std_function  getchar = {
    "getchar",
    Ty_String(),
    NULL
  };

  struct std_function ord = {
    "ord",
    Ty_Int(),
    Ty_TyList(Ty_String(), NULL)
  };

  struct std_function chr = {
    "chr",
    Ty_String(),
    Ty_TyList(Ty_Int(), NULL)
  };

  struct std_function std_funcs[5] = {print, flush, getchar, ord, chr};

  for(int i = 0; i < 5; i++) {
    struct std_function f = std_funcs[i];
    S_enter(venv, S_Symbol(f.name), E_FunEntry(f.arguments, f.return_type)); 
  }
}
