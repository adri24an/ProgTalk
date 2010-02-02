%option noyywrap

%{
#include "Parser.h"
#include <iostream>

%}

DIGIT    [0-9]+
ID       [a-zA-Z][a-zA-Z0-9_]*
WHITE    [ \t]+
STRING   \"[^\"]*\"
INSTANCE "instance"
OF       "of"
MESSAGE  "message"
FROM     "from"
TO       "to"

%%

{WHITE}    { /* Ignoramos espacios en blanco */ }

{DIGIT}    {
            return(Parser::NUM);
           }

{STRING}   {
            return(Parser::STRING);
           }

{INSTANCE} {
            return(Parser::INSTANCE);
           }

{OF}       {
            return(Parser::OF);
           }

{MESSAGE}  {
            return(Parser::MESSAGE);
           }

{FROM}     {
            return(Parser::FROM);
           }

{TO}       {
            return(Parser::TO);
           }

{ID}       {
            return(Parser::TEXT);
           }

"@"        {
            return(Parser::AT);
           }

"+"        {
            return(Parser::PLUS);
           }

"-"        {
            return(Parser::MINUS);
           }

"!"        {
            return(Parser::EXCLAMATION);
           }

"?"        {
            return(Parser::INTERROGATION);
           }

";"        {
            return(Parser::SEMICOLON);
           }

\"         {
            return(Parser::TIMES);
           }

","        {
            return(Parser::COMMA);
           }

\n         {
            return(Parser::EOLN);
           }

.          {
            std::cout << "ERROR: CARACTER INCORRECTO" << std::endl;
            yyterminate();
           }

%%
