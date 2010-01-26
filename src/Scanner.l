%option noyywrap

%{
#include "Parser.h"
#include <iostream>

%}

DIGIT    [0-9]+
ID       [a-zA-Z][a-zA-Z0-9_]*
WHITE    [ \t]+
STRING   \"[^\"]*\"
INSTANCE 'instance'
OF       'of'
MESSAGE  'message'
FROM     'from'
TO       'to'

%%

{WHITE}   { /* Ignoramos espacios en blanco */ }

{DIGIT}   {
           return(Parser::NUM);
          }

{ID}      {
           return(Parser::TEXT);
          }

{STRING}  {
           return(Parser::STRING);
          }

{INSTANCE}{
           return(Parser::INSTANCE);
          }

{OF}      {
           return(Parser::OF);
          }

{MESSAGE} {
           return(Parser::MESSAGE);
          }

{FROM}    {
           return(Parser::FROM);
          }

{TO}      {
           return(Parser::TO);
          }

"("       {
           return(Parser::LEFT_PAR);
          }

")"       {
           return(Parser::RIGHT_PAR);
          }

\"        {
           return(Parser::TIMES);
          }

","       {
           return(Parser::COMMA);
          }

\n        {
           return(Parser::EOLN);
          }

.         {
           std::cout << "ERROR: CARACTER INCORRECTO" << std::endl;
           yyterminate();
          }

%%
