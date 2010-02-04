//------------------------------------------------------------
//
//  GRAMATICA
//    
//    msc ::= inst_decl* message*
//    inst_delc ::= INSTANCE iid |
//                  INSTANCE iid OF tid; |
//                  INSTANCE iid {STRING}; |
//                  INSTANCE iid OF tid {STRING};               
//    message ::= MESSAGE mid_opt string_opt origin destiny;
//    mid_opt ::= LAMBDA | mid
//    string_opt ::= LAMBDA | {STRING}
//    time_ref_opt ::= LAMBDA | @ time_ref
//    origin ::= LAMBDA | FROM iid time_ref_opt
//    destiny ::= LAMBDA | TO iid time_ref_opt
//    time_ref ::= abs_time | rel_time
//    abs_time ::= NUM
//    rel_time ::= diftime | ref diftime
//    ref ::= iid ! | iid ?
//    dif_time ::= + NUM | - NUM
//    iid ::= ID
//    tid ::= ID
//    mid ::= ID
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
%token <cad> STRING
%token <cad> INSTANCE
%token <cad> OF
%token <cad> MESSAGE
%token <cad> FROM
%token <cad> TO
%token <cad> ID
%token <cad> AT
%token <cad> PLUS
%token <cad> MINUS
%token <cad> EXCLAMATION
%token <cad> INTERROGATION
%token <cad> SEMICOLON
%token <cad> TIMES
%token <cad> LEFT_BRACE
%token <cad> RIGHT_BRACE
%token <cad> EOLN

%type <num> num
%type <num> abs_time
%type <cad> iid
%type <cad> tid
%type <cad> mid

%start msc
 
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
        
message:
        MESSAGE mid_opt string_opt origin destiny SEMICOLON
;

mid_opt:
        // EMPTY
|
        mid
;

string_opt:
        // EMPTY
|
        LEFT_BRACE STRING RIGHT_BRACE
;

origin:
        // EMPTY
|
        FROM iid time_ref_opt
;

time_ref_opt:
        // EMPTY
|
        AT time_ref
;

destiny:
        // EMPTY
|
        TO iid time_ref_opt
;
 
time_ref:
        abs_time
|
        rel_time
;

abs_time:
        NUM 
	{
	  $$ = atoi(d_scanner.YYText());
	}
;

rel_time:
        dif_time
|
        ref dif_time
;

ref:
        iid EXCLAMATION 
|
        iid INTERROGATION
;

dif_time:
        PLUS NUM
|
        MINUS NUM
;

iid:
        ID
	{
	  $$ = new char[strlen(d_scanner.YYText())+1];
          strcpy ($$, d_scanner.YYText());
	}
;

tid:
        ID
	{
	  $$ = new char[strlen(d_scanner.YYText())+1];
          strcpy ($$, d_scanner.YYText());
	}
;

mid:
        ID
	{
	  $$ = new char[strlen(d_scanner.YYText())+1];
          strcpy ($$, d_scanner.YYText());
	}
;

num:
        NUM 
	{
	  $$ = atoi(d_scanner.YYText());
	}
;
