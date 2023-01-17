%{
#include <string.h>
#include "util.h"
#include "symbol.h"
#include "ast.h"
#include "errormsg.h"
#include "driver.hh" 
#include "tiger.tab.hh"

#define yyterminate() return yy::parser::make_YYEOF(loc)
int charPos=1;

char string_buf[1000];
char *string_buf_ptr;
int string_len;
 
int comment_depth;
 
yy::location loc; 
%}

%option noyywrap
%option nounput
%option noinput

%x string_c
%x comment_c

%%
[ \r\t] { continue;}
\n	 { 
          EM_newline(); continue;}

array { return yy::parser::make_ARRAY(loc);}
if   { return yy::parser::make_IF(loc);}
then { return yy::parser::make_THEN(loc);}
else { return yy::parser::make_ELSE(loc);}
while { return yy::parser::make_WHILE(loc);}
for   { return yy::parser::make_FOR(loc);}
to  { return yy::parser::make_TO(loc);}
do  { return yy::parser::make_DO(loc);}
let  { return yy::parser::make_LET(loc);}
in   { return yy::parser::make_IN(loc);}
end   { return yy::parser::make_END(loc);}
of   { return yy::parser::make_OF(loc);}
break   { return yy::parser::make_BREAK(loc);}
nil   { return yy::parser::make_NIL(loc);}
function   { return yy::parser::make_FUNCTION(loc);}
var   { return yy::parser::make_VAR(loc);}
type   { return yy::parser::make_TYPE(loc);}


[0-9]+	 { int n =atoi(yytext); return yy::parser::make_INT(n, loc);}
[a-zA-Z][a-zA-Z0-9_]* { return yy::parser::make_ID(yytext, loc);}



"," { return yy::parser::make_COMMA(loc);}
":" { return yy::parser::make_COLON(loc);}
";" { return yy::parser::make_SEMICOLON(loc);}
"(" { return yy::parser::make_LPAREN(loc);}
")" { return yy::parser::make_RPAREN(loc);}
"[" { return yy::parser::make_LBRACK(loc);}
"]" { return yy::parser::make_RBRACK(loc);}
"{" { return yy::parser::make_LBRACE(loc);}
"}" { return yy::parser::make_RBRACE(loc);}
"." { return yy::parser::make_DOT(loc);}
"+" { return yy::parser::make_PLUS(loc);}
"-" { return yy::parser::make_MINUS(loc);}
"*" { return yy::parser::make_TIMES(loc);}
"/" { return yy::parser::make_DIVIDE(loc);}
"=" { return yy::parser::make_EQ(loc);}
"<>" { return yy::parser::make_NEQ(loc);}
"<" { return yy::parser::make_LT(loc);}
"<=" { return yy::parser::make_LE(loc);}
">" { return yy::parser::make_GT(loc);}
">=" { return yy::parser::make_GE(loc);}
"&" { return yy::parser::make_AND(loc);}
"|" { return yy::parser::make_OR(loc);}
":=" { return yy::parser::make_ASSIGN(loc);}

\"       {
  
  string_buf_ptr = string_buf;
  string_len = 0;
  BEGIN (string_c);}


<string_c>[^\"] {
  char *yptr = yytext;
  *string_buf_ptr++ = *yptr;
  string_len++; 
 }
           
<string_c>\" {
  EM_tokPos=charPos;
  charPos += string_len+1;
  *string_buf_ptr = '\0';
  BEGIN(INITIAL);
  return yy::parser::make_STRING(string_buf,loc);}

"/*"     { comment_depth++; BEGIN(comment_c);}
<comment_c>"(*" { comment_depth++;}
<comment_c>[^*] {}
<comment_c>"*"+[^"/"] {}
<comment_c>"*/" { comment_depth--; if(comment_depth==0) BEGIN(INITIAL);}

.	 { EM_error(EM_tokPos,"illegal token");}
%%


void
driver::scan_begin ()
{
  yy_flex_debug = trace_scanning;
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    {
      std::cerr << "cannot open " << file << ": " << strerror (errno) << '\n';
      exit (EXIT_FAILURE);
    }
}

void
driver::scan_end ()
{
  fclose (yyin);
}