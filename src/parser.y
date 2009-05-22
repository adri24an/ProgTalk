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
        '(' TEXT ',' NUM ')' '(' TEXT ',' NUM ')' TEXT

;
