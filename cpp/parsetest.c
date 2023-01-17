#include <stdio.h>
#include "util.h"
#include "errormsg.h"
#include "driver.hh"
//extern A_exp absyn_root;


void parse(char *fname) 
{
  driver drv; 
  drv.parse(fname);
// if (yyparse() == 0) /* parsing worked */
//   fprintf(stderr,"Parsing successful!\n");
// else {
//   fprintf(stderr,"Parsing failed\n");
//   return;
// }
  
// SEM_transProg(absyn_root);
}


int main(int argc, char **argv) {
 if (argc!=2) {fprintf(stderr,"usage: a.out filename\n"); return 1;}

 parse(argv[1]);

 
 return 0;
}
