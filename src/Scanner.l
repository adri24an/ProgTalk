%option noyywrap

%{
#include "Parser.h"
#include <iostream>
%}

DIGIT   [0-9]+
ID      [a-zA-Z][a-zA-Z0-9]*
WHITE   [ \t\n]+

%%

{WHITE}   { /* Ignoramos espacios en blanco */ }

{DIGIT}   {
           cout << "He leido un digito" << endl;
           return(Parser::NUM);
          }

{ID}      {return(Parser::TEXT);}

"("       {return(Parser::LEFT_PAR);}

")"       {return(Parser::RIGHT_PAR);}

"*"       {return(Parser::TIMES);}

","       {return(Parser::COMMA);}

%%
