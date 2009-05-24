//--------------------------------------------------------------
//
//  GRAMATICA
//    
//    input ::= LAMBDA | input line
//    line  ::= '\n' | exp '\n'
//    exp   ::= note flow
//    note  ::= STRING | lambda
//    flow  ::= (STRING,INTEGER) (STRING,INTEGER) STRING */
//
//--------------------------------------------------------------
 
 
%union 
{
  int num;
  char string;
}
 
%token <num> NUM
%token <cad> TEXT
%token LEFT_PAR
%token RIGHT_PAR
%token TIMES
%token COMMA
%token UNKNOWN
 
%%

input:
        // empty
|
        input line
;
 
line:
        '\n'
|
        exp '\n'
|
        error '\n'
;
        
exp:
        note flow
;
 
note:
        // empty
|
        TEXT
;
 
flow:
        LEFT_PAR TEXT COMMA NUM RIGHT_PAR LEFT_PAR TEXT COMMA NUM RIGHT_PAR TIMES TEXT TIMES

;
