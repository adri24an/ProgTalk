//------------------------------------------------------------
//
//  GRAMATICA
//    
//    msc ::= inst_decl* message*
//    inst_decl ::= INSTANCE iid |
//                  INSTANCE iid OF tid; |
//                  INSTANCE iid {STRING}; |
//                  INSTANCE iid OF tid {STRING};               
//    message ::= MESSAGE mid_opt string_opt origin destiny;
//    mid_opt ::= LAMBDA | mid
//    string_opt ::= LAMBDA | {STRING}
//    origin ::= LAMBDA | FROM iid time_ref_opt
//    destiny ::= LAMBDA | TO iid time_ref_opt
//    time_ref_opt ::= LAMBDA | @ time_ref
//    time_ref ::= abs_time | rel_time
//    abs_time ::= num
//    rel_time ::= diftime | ref diftime
//    ref ::= id ! | id ?
//    dif_time ::= + NUM | - NUM
//    iid ::= ID
//    tid ::= ID
//    mid ::= ID
//    id ::= NUM
//    num ::= NUM
//
//------------------------------------------------------------
 
%class-name Parser
%scanner Scanner.h
%lines
 
%union 
{
  int num;
  char * cad;
  Timestamp * tstamp;
  Timeref * timevalue;
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
%type <num> message
%type <num> ref
%type <num> dif_time
%type <num> num
%type <num> id
%type <cad> iid
%type <cad> tid
%type <cad> mid
%type <cad> mid_opt
%type <cad> string_opt
%type <tstamp> origin
%type <tstamp> destiny

%start msc
 
%%

msc:
        inst_decl message
;
 
inst_decl:
        // EMPTY
|
        INSTANCE iid OF tid LEFT_BRACE STRING RIGHT_BRACE SEMICOLON EOLN 
		inst_decl
        {
		  addInst ($2, $4, $6);
		}
|
        INSTANCE iid OF tid SEMICOLON EOLN inst_decl
        {
		  addInst ($2, $4, (char *) "No_Info_Available");
		}
|
        INSTANCE iid LEFT_BRACE STRING RIGHT_BRACE SEMICOLON EOLN inst_decl
        {
		  addInst ($2, (char *) "No_Info_Available", $4);
		}
|
        INSTANCE iid SEMICOLON EOLN inst_decl
        {
		  addInst ($2, (char *) "No_Info_Available", 
				   (char *)"No_Info_Available");
		}
;
        
message:
        // EMPTY
        {
		  $$ = 0;
		}
|
        MESSAGE mid_opt string_opt origin destiny SEMICOLON EOLN message
        { 
		  if ((($4->getValtype() == 0)) && ($5->getValtype() == 0))
			{
			  addMsg($2,$3,$4->getIid(),$5->getIid(),
					 $4->getValue(), $5->getValue());
			}
		  else if (($4->getValtype() == 0) && ($5->getValtype() == 1))
			{
			  addMsg($2,$3,$4->getIid(),$5->getIid(),
					 $4->getValue(), ($4->getValue() + $5->getValue()));
			}
		  else if  (($4->getValtype() == 0) && ($5->getValtype() == 2))
			{
			  addMsg($2,$3,$4->getIid(),$5->getIid(),
					 $4->getValue(), ($5->getValue() + 1));
			}
		  else if (($4->getValtype() == 1) && ($5->getValtype() == 0))
			{
			  $$ = msgSize();
			  $$ = getTime_rec($$) + $4->getValue();
			  addMsg($2,$3,$4->getIid(),$5->getIid(),
					 $$, $5->getValue());
			}
		  else if (($4->getValtype() == 1) && ($5->getValtype() == 1))
			{
			  $$ = msgSize();
			  $$ = getTime_rec($$) + $4->getValue();
			  addMsg($2,$3,$4->getIid(),$5->getIid(),
					 $$, ($$ + $5->getValue()));
			}
		  else if (($4->getValtype() == 1) && ($5->getValtype() == 2))
			{
			  $$ = msgSize();
			  $$ = getTime_rec($$) + $4->getValue();
			  addMsg($2,$3,$4->getIid(),$5->getIid(),
					 $$, ($$ + 1));
			}
		  else if (($4->getValtype() == 2) && ($5->getValtype() == 0))
			{
			  $$ = msgSize();
			  $$ = getTime_rec($$) + 1;
			  addMsg($2,$3,$4->getIid(),$5->getIid(),
					 $$, $5->getValue());
			}
		  else if (($4->getValtype() == 2) && ($5->getValtype() == 1))
			{
			  $$ = msgSize();
			  $$ = getTime_rec($$) + 1;
			  addMsg($2,$3,$4->getIid(),$5->getIid(),
					 $$, ($$ + $5->getValue()));
			}
		  else if (($4->getValtype() == 1) && ($5->getValtype() == 2))
			{
			  $$ = msgSize();
			  $$ = getTime_rec($$) + 1;
			  addMsg($2,$3,$4->getIid(),$5->getIid(),
					 $$, ($$ + 1));
			}
		}
;

mid_opt:
        // EMPTY
        {
		  $$ = new char[18];
          strcpy ($$,"No_Info_Available");
		}
|
        mid
        {
		  $$ = new char[strlen(d_scanner.YYText())+1];
          strcpy ($$, d_scanner.YYText());
		}
;

string_opt:
        // EMPTY
        {
		  $$ = new char[18];
          strcpy ($$,"No_Info_Available");
		}
|
        LEFT_BRACE STRING 	
        {
		  $$ = new char[strlen(d_scanner.YYText())+1];
          strcpy ($$, d_scanner.YYText());
		}

        RIGHT_BRACE
;

origin:
        // EMPTY
        {
		  $$ = new Timestamp((char *) "No_Info_Available", NULL);
		}
|
        FROM iid time_ref_opt
        {
		  $$ = new Timestamp($2, $3);
		}
;

time_ref_opt:
        // EMPTY
        {
		  $$ = new Timeref(2, 1);
		}
|
        AT time_ref
        {
		  $$ = $2;
		}
;

destiny:
        // EMPTY
        {
		  $$ = new Timestamp((char *) "No_Info_Available", NULL);
		}
|
        TO iid time_ref_opt
        {
		  $$ = new Timestamp($2, $3);
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
		  $$ = new Timeref(0, $1);
		}
;

rel_time:
        dif_time
		{
		  $$ = new Timeref(1, $1);
		}
|
        ref dif_time
        {
		  $$ = new Timeref(0, $1 + $2);
		}
;

ref:
        id EXCLAMATION
	    {
		  $$ = getTime_sent($1);
		} 

|
        id INTERROGATION
	    {
		  $$ = getTime_rec($1);
		}
;

dif_time:
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

id:
        num
	    {
		  $$ = $1;
		}
;

num:
        NUM 
	    {
		  $$ = atoi(d_scanner.YYText());
		}
;
