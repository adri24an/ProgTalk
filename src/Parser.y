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
//    origin ::= LAMBDA | FROM iid time_ref_opt
//    destiny ::= LAMBDA | TO iid time_ref_opt
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
%type <num> dif_time_opt
%type <num> num
%type <cad> iid
%type <cad> tid
%type <cad> mid
%type <cad> string
%type <cad> mid_opt
%type <cad> string_opt
%type <tstamp> origin
%type <tstamp> destiny

%start msc
 
%%

msc:
        inst_decl_seq message_seq
;
    
inst_decl_seq:
        // EMPTY
{ }
|
        inst_decl_seq inst_decl
{ }
;
 
inst_decl:
        INSTANCE iid OF tid LEFT_BRACE string RIGHT_BRACE SEMICOLON EOLN
        {
		  addInst ($2, $4, $6);
		}
|
        INSTANCE iid OF tid SEMICOLON EOLN
        {
		  addInst ($2, $4, (char *) "No_Info_Available");
		}
|
        INSTANCE iid LEFT_BRACE string RIGHT_BRACE SEMICOLON EOLN
        {
		  addInst ($2, (char *) "No_Info_Available", $4);
		  std::cout << "añadida instancia cuyo token string es: " << $4  
					<< std::endl;
		}
|
        INSTANCE iid SEMICOLON EOLN
        {
		  addInst ($2, (char *) "No_Info_Available", 
				   (char *)"No_Info_Available");
		}
;
        
message_seq:
        // EMPTY
{ }
|
        message_seq message
{ }
;

message:
        MESSAGE mid_opt string_opt origin destiny SEMICOLON EOLN
        { 
		  std::cout << "entra en message" << std::endl;
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

			  if ($$ != 0)
				{
				  $$ = $$ - 1;
				  $$ = getTime_rec($$) + $4->getValue();
				  addMsg($2,$3,$4->getIid(),$5->getIid(), 
						 $$, $5->getValue());
				}
			  else
				{
				  addMsg($2,$3,$4->getIid(),$5->getIid(), 
						 $4->getValue(), $5->getValue());
				}
			}
		  else if (($4->getValtype() == 1) && ($5->getValtype() == 1))
			{
			  $$ = msgSize();

			  if ($$ != 0)
				{
				  $$ = $$ - 1;
				  $$ = getTime_rec($$) + $4->getValue();
				  addMsg($2,$3,$4->getIid(),$5->getIid(),
						 $$, ($$ + $5->getValue()));
				}
			  else
				{
				  addMsg($2,$3,$4->getIid(),$5->getIid(),
						 $4->getValue(), ($4->getValue() + $5->getValue()));
				}
			}
		  else if (($4->getValtype() == 1) && ($5->getValtype() == 2))
			{
			  $$ = msgSize();

			  if ($$ != 0)
				{
				  $$ = $$ - 1;
				  $$ = getTime_rec($$) + $4->getValue();
				  addMsg($2,$3,$4->getIid(),$5->getIid(),
						 $$, ($$ + 1));
				}
			  else
				{
				  addMsg($2,$3,$4->getIid(),$5->getIid(),
						 $4->getValue(), ($4->getValue() + 1));
				}
			}
		  else if (($4->getValtype() == 2) && ($5->getValtype() == 0))
			{
			  $$ = msgSize();

			  if ($$ != 0)
				{
				  $$ = $$ - 1;
				  $$ = getTime_rec($$) + 1;
				  addMsg($2,$3,$4->getIid(),$5->getIid(),
						 $$, $5->getValue());
				}
			  else
				{
				  addMsg($2,$3,$4->getIid(),$5->getIid(),
						 0, $5->getValue());
				}
			}
		  else if (($4->getValtype() == 2) && ($5->getValtype() == 1))
			{			  
			  $$ = msgSize();

			  if ($$ != 0)
				{
				  $$ = $$ - 1;
				  $$ = getTime_rec($$) + 1;
				  addMsg($2,$3,$4->getIid(),$5->getIid(),
						 $$, ($$ + $5->getValue()));
				}
			  else
				{
				  addMsg($2,$3,$4->getIid(),$5->getIid(),
						 0, $5->getValue());
				}
			}
		  else if (($4->getValtype() == 2) && ($5->getValtype() == 2))
			{
			  $$ = msgSize();

			  if ($$ != 0)
				{
				  $$ = $$ - 1;
				  $$ = getTime_rec($$) + 1;
				  addMsg($2,$3,$4->getIid(),$5->getIid(),
						 $$, ($$ + 1));
				}
			  else
				{
				  addMsg($2,$3,$4->getIid(),$5->getIid(),
						 0, 1);
				}
			}
		  else
			{
			  std::cout << "FATAL ERROR: the message couldn't be " 
						<< "parsed due to relative time issues" << std::endl;
			  exit(0);
			}
		  std::cout << "y sale de  message" << std::endl;
		  
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
          strcpy ($$,$1);
		}
;

string_opt:
        // EMPTY
        {
		  $$ = new char[18];
          strcpy ($$,"No_Info_Available");
		}
|
        LEFT_BRACE string RIGHT_BRACE	
        {
		  $$ = new char[strlen($2)+1];
          strcpy ($$, $2);
		}     
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
        ref dif_time_opt
		{
		  $$ = new Timeref(0, $1 + $2); 
		}
        dif_time
		{
		  $$ = new Timeref(1, $1);
		}
;

ref:
        mid EXCLAMATION
	    {
		  $$ = getTime_sent($1);
		} 
|
        mid INTERROGATION
	    {
		  $$ = getTime_rec($1);
		}
;

dif_time_opt:
        //LAMBDA
        {
		  $$ = 1;
        }
|
        dif_time
	    {
		  $$ = $1;
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
		  if (!(strcmp ($$, "instance")) || !(strcmp ($$, "of")) || 
			  !(strcmp ($$, "message")) || !(strcmp ($$, "from")) ||
			  !(strcmp ($$, "to")))
			{
			  std::cout << "Error: a reserved word (" << $$ << 
				") was used as an identifier" << std::endl;
			  exit(0);
			}
		}
;

tid:
        ID
	    {
		  $$ = new char[strlen(d_scanner.YYText())+1];
          strcpy ($$, d_scanner.YYText());
		  if (!(strcmp ($$, "instance")) || !(strcmp ($$, "of")) || 
			  !(strcmp ($$, "message")) || !(strcmp ($$, "from")) ||
			  !(strcmp ($$, "to")))
			{
			  std::cout << "Error: a reserved word (" << $$ << 
				") was used as an identifier" << std::endl;
			  exit(0);
			}
		}
;

mid:
        ID
	    {
		  $$ = new char[strlen(d_scanner.YYText())+1];
          strcpy ($$, d_scanner.YYText());
		  if (!(strcmp ($$, "instance")) || !(strcmp ($$, "of")) || 
			  !(strcmp ($$, "message")) || !(strcmp ($$, "from")) ||
			  !(strcmp ($$, "to")))
			  {
				std::cout << "Error: a reserved word (" << $$ << 
				  ") was used as an identifier" << std::endl;
				exit(0);
			  }
		}
;

string:
        STRING
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
