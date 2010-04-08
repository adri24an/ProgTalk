%option noyywrap

%{
#include "Parser.h"
#include <iostream>

%}

NUM      [0-9]+
ID       [a-zA-Z][a-zA-Z0-9_]*
WHITE    [ \t]+
STRING   \"[^\"\n]*\"
EOLN     [\n]+
INSTANCE "instance"
OF       "of"
MESSAGE  "message"
FROM     "from"
TO       "to"

%%

{WHITE}    { /* Ignoramos espacios en blanco */ }

{NUM}      {
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
            return(Parser::ID);
           }

{EOLN}     {
            return(Parser::EOLN);
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

"{"        {
            return(Parser::LEFT_BRACE);
           }

"}"        {
            return(Parser::RIGHT_BRACE);
           }

.          {
            std::cout << "Error: Scanner couldn't match data." << std::endl;
            yyterminate();
           }

%%
