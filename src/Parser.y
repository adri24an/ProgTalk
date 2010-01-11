//------------------------------------------------------------
//
//  GRAMATICA
//    
//    msc ::= inst_decl* message*
//    inst_delc ::= "instance" iid ("of" tid)? ("{" STRING "}")? ";"
//    message ::= "message" mid? ("{" STRING "}")? ("from" iid 
//                 ("@" time_ref)?)? ("to" iid ("@" time_ref)?)? ";"
//    time_ref ::= abs_time | rel_time
//    abs_time ::= NUM
//    rel_time ::= ref? diftime
//    ref ::= iid "!" | iid "?"
//    dif_time ::= "+" NUM | "-" NUM
//    iid ::= NUM
//    tid ::= NUM
//    mid ::= NUM
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

msc:
        // empty
|
        msc inst_decl message
;
 
inst_decl:
        STRING iid LEFT_PAR STRING tid RIGHT_PAR LEFT_PAR LEFT_BRACE
	STRING RIGHT_BRACE RIGHT_PAR
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
 

