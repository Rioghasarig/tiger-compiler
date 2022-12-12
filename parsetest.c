#include <stdio.h>
#include "util.h"
#include "errormsg.h"
#include "symbol.h"
#include "absyn.h"

extern int yyparse(void);
extern int yydebug;
extern A_exp absyn_root;
extern struct S_symbol_;

void parse(string fname) 
{EM_reset(fname);
 yydebug = 1;
 if (yyparse() == 0) /* parsing worked */
   fprintf(stderr,"Parsing successful!\n");
 else fprintf(stderr,"Parsing failed\n");
}


int main(int argc, char **argv) {
 if (argc!=2) {fprintf(stderr,"usage: a.out filename\n"); exit(1);}

 parse(argv[1]);
 //fprintf(stdout, "AST Root: %s\n", absyn_root->u.var->u.simple->name); 
 return 0;
}
