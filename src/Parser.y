//------------------------------------------------------------
//
//  GRAMATICA
//    
//    msc ::= inst_decl* message*
//    inst_delc ::= INSTANCE iid |
//                  INSTANCE iid OF tid; |
//                  INSTANCE iid {STRING}; |
//                  INSTANCE iid OF tid {STRING};
//                  
//    message ::= MESSAGE; |
//                MESSAGE mid; |
//                MESSAGE {STRING}; |
//                MESSAGE mid {STRING}; |
//                MESSAGE FROM iid; |
//                MESSAGE mid FROM iid; |
//                MESSAGE {STRING} FROM iid; |
//                MESSAGE mid {STRING} FROM iid; |
//                MESSAGE FROM iid "@" time_ref; |
//                MESSAGE mid FROM iid "@" time_ref; |
//                MESSAGE {STRING} FROM iid "@" time_ref; |
//                MESSAGE mid {STRING} FROM iid "@" time_ref; |
//                MESSAGE TO iid; |
//                MESSAGE mid TO iid; |
//                MESSAGE {STRING} TO iid; |
//                MESSAGE mid {STRING} TO iid; |
//                MESSAGE mid {STRING} FROM iid TO iid; |
//                MESSAGE FROM iid "@" time_ref TO iid; |
//                MESSAGE mid FROM iid "@" time_ref TO iid; |
//                MESSAGE {STRING} FROM iid "@" time_ref TO iid; |
//                MESSAGE mid {STRING} FROM iid "@" time_ref TO iid; |
//                MESSAGE TO iid @ time_ref; |
//                MESSAGE mid TO iid @ time_ref; |
//                MESSAGE {STRING} TO iid @ time_ref; |
//                MESSAGE mid {STRING} TO iid @ time_ref; |
//                MESSAGE mid {STRING} FROM iid TO iid @ time_ref; |
//                MESSAGE FROM iid "@" time_ref TO iid @ time_ref; |
//                MESSAGE mid FROM iid "@" time_ref TO iid @ time_ref; |
//                MESSAGE {STRING} FROM iid "@" time_ref TO iid @ time_ref; |
//                MESSAGE mid {STRING} FROM iid "@" time_ref TO iid @ time_ref;
//
//    time_ref ::= abs_time | rel_time
//    abs_time ::= NUM
//    rel_time ::= ref? diftime
//    ref ::= iid ! | iid ?
//    dif_time ::= + NUM | - NUM
//    iid ::= STRING
//    tid ::= STRING
//    mid ::= STRING
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
        inst_decl message
;
 
inst_decl:
        // EMPTY
|
        INSTANCE iid OF tid LEFT_BRACE STRING RIGHT_BRACE SEMICOLON EOLN
|
        INSTANCE iid OF tid SEMICOLON EOLN
|
        INSTANCE iid LEFT_BRACE STRING RIGHT_BRACE SEMICOLON EOLN
|
        INSTANCE iid SEMICOLON EOLN
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
 

