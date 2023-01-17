#include "symbol.h"
#include "types.h"

struct std_function {
  char name[20];
  Ty_ty return_type;
  Ty_tyList arguments;
};

void add_std_functions(S_table venv);
void add_std_types(S_table tenv); 
