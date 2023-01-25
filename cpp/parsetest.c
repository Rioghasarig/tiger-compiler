#include <stdio.h>

#include "driver.hh"
#include "errormsg.h"
#include "util.h"
// extern A_exp absyn_root;
#define PARSE_TRACE 1
#define SCAN_TRACE 1

void parse(char *fname) {
  driver drv;
  drv.trace_parsing = PARSE_TRACE;
  // drv.trace_scanning = SCAN_TRACE;
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
  if (argc != 2) {
    fprintf(stderr, "usage: a.out filename\n");
    return 1;
  }

  parse(argv[1]);

  return 0;
}
