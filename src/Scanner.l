%option noyywrap

%{
#include "Parser.h"
#include <iostream>

%}

DIGIT   [0-9]+
ID      [a-zA-Z][a-zA-Z0-9]*
WHITE   [ \t]+

%%

{WHITE}   { /* Ignoramos espacios en blanco */ }

{DIGIT}   {
           std::cout << "He leido un digito" << std::endl;
           return(Parser::NUM);
          }

{ID}      {
           std::cout << "He leido el identificador: " << yytext << std::endl;
           return(Parser::TEXT);
          }

"("       {
           std::cout << "He leido un (" << std::endl;
           return(Parser::LEFT_PAR);
          }

")"       {
           std::cout << "He leido un )" << std::endl;
           return(Parser::RIGHT_PAR);
          }

\"        {
           std::cout << "He leido una \"" << std::endl;
           return(Parser::TIMES);
          }

","       {
           std::cout << "He leido una ," << std::endl;
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
