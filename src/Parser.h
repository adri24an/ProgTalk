#ifndef Parser_h_included
#define Parser_h_included

#define ABSOLUTE 0
#define RELATIVE 1
#define RECEIVING 1
#define SENDING 2

#include <iostream>

#include "MSC.h"
#include "Timestg.h"
#include "Timeref.h"
#include "Parserbase.h"
#include "Scanner.h"
#include <map>
#include <string>
#include <string.h>



#undef Parser
class Parser: public ParserBase
{       
 public:
  //Constructor
  Parser();
  //Parses the tokens sent by Scanner
  int parse();
  //Returns the msc object
  MSC * getMSC();
  //Adds a new instance to msc
  void addInst(string new_iid, string new_tid, string new_name);
  //Adds a new message to msc
  void addMsg(string new_mid, string new_sms, string new_origin, 
	      string new_destiny, int new_time_rec, int new_time_sent);
   

 private:
  
  void error(char const *msg);
  
  int lex();
  
  //Default print operation (not implemented)
  void print();

  //Support functions for parse():
  void executeAction(int ruleNr);
  void errorRecovery();
  int lookup(bool recovery);
  void nextToken();
  
  //Tokens reader
  Scanner d_scanner;   
        
  //Object that storages instances and messages
  MSC * msc; 
};

inline Parser::Parser()
{
  msc = new MSC;
}

inline MSC * Parser::getMSC()
{
  return msc;
}

inline void Parser::addInst(string new_iid, string new_tid, string new_name)
{
  Instance * i = new Instance (new_iid, new_tid, new_name);
  msc->addInst(i);
}

inline void Parser::addMsg(string new_mid, string new_sms, string new_origin, 
			   string new_destiny, Timeref * new_time_rec, 
			   Timeref * new_time_sent)
{
  Timestamp * t = NULL;
  Instance * or = msc->searchIid(new_origin);
  Instance * de = msc->searchIid(new_destiny);
  
  if (or == NULL)
    {
      std::cout << "The origen of the message (" << new_origin 
		<< ") doesn't exist." << std::endl;
      exit(0);
    }
  else if (de == NULL)
    {
     std::cout << "The destiny of the message (" << new_destiny 
	       << ") doesn't exist." << std::endl;
     exit(0);
    }

  if (new_time_rec->get_valtype() == ABSOLUTE)
    {
      t = new Absolute (new_time_rec->get_value());
    }
  else if (new_time_rec->get_valtype() == RELATIVE)
    {
      //BUSCA EL MID Y SEGUN SI ES ENVIO Y RECEPCION
      t = new Relative (ref, new_time_rec->get_value());
    }
  
  r * Receipt = Receipt(or, t);
  s * Sending = Sending(de, time);
  Message * m = new Message(string new_mid, string new_sms, r, s);
  
  msc->addMsg(m);
}



inline void Parser::error(char const *msg)
{
    std::cerr << msg << std::endl;
}

inline int Parser::lex()
{
    return d_scanner.yylex();
}

//Default print operation (not implemented)
inline void Parser::print(){}

#endif
