//------------------------------------------------------------
//
//  GRAMATICA
//    
//    input ::= LAMBDA | input line
//    line  ::= '\n' | exp '\n'
//    exp   ::= note flow
//    note  ::= STRING | lambda
//    flow  ::= (STRING,INTEGER) (STRING,INTEGER) STRING */
//
//------------------------------------------------------------
 
%class-name Parser
%scanner Scanner.h
%lines
 
%union 
{
  int num;
  char * cad;
}
 
%token <num> NUM
%token <cad> TEXT
%token <cad> LEFT_PAR
%token <cad> RIGHT_PAR
%token <cad> TIMES
%token <cad> COMMA
%token <cad> EOLN

%type <num> num
%type <cad> text

%start input
 
%%

input:
        // empty
|
        input line
;
 
line:
        EOLN
|
        exp
|
        error
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
LEFT_PAR 
text 
COMMA 
num
RIGHT_PAR 
LEFT_PAR 
text
COMMA 
num
RIGHT_PAR 
TIMES 
text
TIMES 
EOLN 
{
  AddEvent($2,$4,$7,$9,$12);
}
;

num:
        NUM 
	{
	  $$ = atoi(d_scanner.YYText());
	}
;

text:
        TEXT
        {
	  $$ = new char[strlen(d_scanner.YYText())+1];
          strcpy ($$, d_scanner.YYText());
	}
;
 

