%{
#include <string.h>
#include "util.h"
#include "symbol.h"
#include "absyn.h"
#include "y.tab.h"
#include "errormsg.h"

int charPos=1;

int yywrap(void)
{
 charPos=1;
 return 1;
}

char string_buf[1000];
char *string_buf_ptr;
int string_len;
 
int comment_depth;
 
void adjust(void)
{
 EM_tokPos=charPos;
 charPos+=yyleng;
 yylloc.first_column += yyleng;
}

%}

%option nounput
%option noinput

%x string_c
%x comment_c

%%
[ \r\t] {adjust(); continue;}
\n	 {adjust(); yylloc.first_column=1; yylloc.first_line+=1;
          EM_newline(); continue;}

array {adjust(); return ARRAY;}
if   {adjust(); return IF;}
then {adjust(); return THEN;}
else {adjust(); return ELSE;}
while {adjust(); return WHILE;}
for   {adjust(); return FOR;}
to  {adjust(); return TO;}
do  {adjust(); return DO;}
let  {adjust(); return LET;}
in   {adjust(); return IN;}
end   {adjust(); return END;}
of   {adjust(); return OF;}
break   {adjust(); return BREAK;}
nil   {adjust(); return NIL;}
function   {adjust(); return FUNCTION;}
var   {adjust(); return VAR;}
type   {adjust(); return TYPE;}


[0-9]+	 {adjust(); yylval.ival=atoi(yytext); return INT;}
[a-zA-Z][a-zA-Z0-9_]* {adjust(); yylval.sval = strdup(yytext); return ID;}



"," {adjust(); return COMMA;}
":" {adjust(); return COLON;}
";" {adjust(); return SEMICOLON;}
"(" {adjust(); return LPAREN;}
")" {adjust(); return RPAREN;}
"[" {adjust(); return LBRACK;}
"]" {adjust(); return RBRACK;}
"{" {adjust(); return LBRACE;}
"}" {adjust(); return RBRACE;}
"." {adjust(); return DOT;}
"+" {adjust(); return PLUS;}
"-" {adjust(); return MINUS;}
"*" {adjust(); return TIMES;}
"/" {adjust(); return DIVIDE;}
"=" {adjust(); return EQ;}
"<>" {adjust(); return NEQ;}
"<" {adjust(); return LT;}
"<=" {adjust(); return LE;}
">" {adjust(); return GT;}
">=" {adjust(); return GE;}
"&" {adjust(); return AND;}
"|" {adjust(); return OR;}
":=" {adjust(); return ASSIGN;}

\"       {
  adjust();
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
  yylval.sval  = string_buf;
  BEGIN(INITIAL);
  return STRING;}

"/*"     {adjust(); comment_depth++; BEGIN(comment_c);}
<comment_c>"(*" {adjust(); comment_depth++;}
<comment_c>[^*] {adjust();}
<comment_c>"*"+[^"/"] {adjust();}
<comment_c>"*/" {adjust(); comment_depth--; if(comment_depth==0) BEGIN(INITIAL);}

.	 {adjust(); EM_error(EM_tokPos,"illegal token");}


