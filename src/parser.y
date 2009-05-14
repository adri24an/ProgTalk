/* 
   GRAMATICA

   D ::= N E
   N ::= string N | lambda
   T ::= integer
   E ::= (N1,T1) (N2,T2) "string" E | lambda
*/

%{

#include <stdio.h>

%}

%union {
int num;
char *cad;
}

%token NUM STRING LEFT_PARENTHESIS RIGHT_PARENTHESIS TIMES COMMA

%type <num> NUM
%type <cad> STRING

%%

d:n e
;

n:/*vacio*/
|STRING n
;

e:/*vacio*/
|LEFT_PARENTHESIS n COMMA t RIGHT_PARENTHESIS COMMA LEFT_PARENTHESIS n COMMA t RIGHT_PARENTHESIS TIMES STRING TIMES e
;

t:NUM
;

%%

int main()
{
yyparse();
exit(0);
}
