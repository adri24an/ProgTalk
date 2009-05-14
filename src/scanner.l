%{
#include "parser.h"
%}
 
INTEGER   [0-9]+
STRING    [a-zA-Z]+
WHITE     [ \t]+

%%
 
{WHITE}      { /* Ignoramos espacios en blanco */ }

{INTEGER}    {
              return(NUM);
             }
 
(STRING)     {
              return(STRING);
             }

"("           return(LEFT_PARENTHESIS);
")"           return(RIGHT_PARENTHESIS);
"*"           return(TIMES);
","           return(COMMA);

<<EOF>>      {
              yyterminate();
             }
%%