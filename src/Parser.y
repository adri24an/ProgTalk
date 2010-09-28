//------------------------------------------------------------
//
//  GRAMATICA
//    
//    msc ::= inst_decl* message*
//    inst_decl ::= INSTANCE iid |
//                  INSTANCE iid OF tid; |
//                  INSTANCE iid {string}; |
//                  INSTANCE iid OF tid {string};               
//    message ::= MESSAGE mid_opt string_opt origin destiny;
//    mid_opt ::= LAMBDA | mid
//    string_opt ::= LAMBDA | {string}
//    origin ::= LAMBDA | origin_opt
//    origin_opt ::= FROM iid time_ref_opt
//    destiny ::= LAMBDA | destiny_opt
//    destiny_opt ::= TO iid time_ref_opt
//    time_ref_opt ::= LAMBDA | @ time_ref
//    time_ref ::= abs_time | rel_time
//    abs_time ::= num
//    rel_time ::= ref dif_time_opt | dif_time
//    ref ::= mid ! | mid ?
//    dif_time_opt ::= LAMBDA | dif_time
//    dif_time ::= + num | - num
//    iid ::= ID
//    tid ::= ID
//    mid ::= ID
//    string ::= STRING
//    num ::= NUM
//
//------------------------------------------------------------
 
%class-name Parser
%scanner Scanner.h
%lines
 
%union 
{
  int num;
  string * cad;
  Timestg * tstamp;
  Timeref * timevalue;
  pair<int, string> * par;
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
%token <cad> LEFT_BRACE
%token <cad> RIGHT_BRACE
%token <cad> EOLN

%type <timevalue> rel_time
%type <timevalue> abs_time
%type <timevalue> time_ref
%type <timevalue> time_ref_opt
%type <par> ref
%type <num> dif_time
%type <num> num
%type <cad> iid
%type <cad> tid
%type <cad> mid
%type <cad> str
%type <cad> mid_opt
%type <cad> string_opt
%type <tstamp> origin
%type <tstamp> origin_opt
%type <tstamp> destiny
%type <tstamp> destiny_opt

%start msc
 
%%

msc:
        inst_decl_seq message_seq
	{
	}
;
    
inst_decl_seq:
        // EMPTY
       { 
       }
|
        inst_decl_seq inst_decl
        { 
	}
;
 
inst_decl:
        INSTANCE iid OF tid LEFT_BRACE str RIGHT_BRACE SEMICOLON EOLN
        {
	  addInst (*$2, *$4, *$6);
	}
|
        INSTANCE iid OF tid SEMICOLON EOLN
        {
	  addInst (*$2, *$4, "");
	}
|
        INSTANCE iid LEFT_BRACE str RIGHT_BRACE SEMICOLON EOLN
        {
	  addInst (*$2, "", *$4);
	}
|
        INSTANCE iid SEMICOLON EOLN
        {
	  addInst (*$2, "", "");
	}
;
        
message_seq:
        // EMPTY
        { 
	}
|
        message_seq message
        { 
	}
;

message:
        MESSAGE mid_opt string_opt origin_opt destiny_opt SEMICOLON EOLN
        { 
	  string * mid = $2;
          string * desc = $3;
          Timestg * orig = $4;
          Timestg * dest = $5;

	  if (mid == NULL)
	    mid->assign(autogenIid());
	  
	  if (desc == NULL)
	    desc->assign("");

          addMsg(*mid, *desc, orig->get_iid(), dest->get_iid(), 
		 orig->get_timeref(), dest->get_timeref());
	}
;

mid_opt:
        // EMPTY
        {
	  $$ = NULL;
	}
|
        mid
        {
          $$ = $1;
	}
;

string_opt:
        // EMPTY
        {
	  $$ = NULL;
	}
|
        LEFT_BRACE str RIGHT_BRACE	
        {
	  $$ = $2;
	}     
;

origin_opt:
        // EMPTY
        {
	  $$ = NULL;
	}
|
        origin
        {
	  $$ = $1;
	}
;

origin:
        FROM iid time_ref_opt
        {
	  $$ = new Timestg(*$2, *$3);
	}
;

time_ref_opt:
        // EMPTY
        {
	  $$ = new Timeref(RELATIVE, 1, 0, "");
	}
|
        AT time_ref
        {
	  $$ = $2;
	}
;

destiny_opt:
        // EMPTY
        {
	  $$ = NULL;
	}
|
        destiny
        {
	  $$ = $1;
	}
;

destiny:
        TO iid time_ref_opt
        {
	  $$ = new Timestg(*$2, *$3);
	}
;
 
time_ref:
        abs_time
        {
	  $$ = $1;
	}
|
        rel_time
        { 
	  $$ = $1;
	}
;

abs_time:
        num
	{
	  $$ = new Timeref(ABSOLUTE, $1, 0, "");
	}
;

rel_time:
        dif_time
	{
	  $$ = new Timeref(RELATIVE, $1, 0, "");
	}
|
        ref dif_time
        {
	  $$ = new Timeref(RELATIVE, $2, $1->first, $1->second); 
	}
;

ref:
        // EMPTY
        { 
	  $$ = NULL;
	}
|
        mid EXCLAMATION
        {
	  $$ = new pair<int, string>(SENDING,$1);
	} 
|
        mid INTERROGATION
	{
	  $$ = new pair<int, string>(RECEIVING,$1);
	}
;

dif_time:
        // EMPTY
        { 
	  $$ = 1;
	}
|
        PLUS num
        {
	  $$ = $2;
	}
|
        MINUS num
	{
	  $$ = -$2;
	}
;

iid:
        ID
	{
	  $$ = new string(d_scanner.YYText());
	}
;

tid:
        ID
        {
	  $$ = new string(d_scanner.YYText());
	}
;

mid:
        ID
	{
	  $$ = new string(d_scanner.YYText());
	}
;

str:
        STRING
        {
	  $$ = new string(d_scanner.YYText());
	}
;

num:
        NUM 
        {
	  $$ = atoi(d_scanner.YYText());
	}
;
