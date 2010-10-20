#ifndef Parser_h_included
#define Parser_h_included

#define ABSOLUTE 0
#define RELATIVE 1
#define SENDING 1
#define RECEIVING 2

#include "Absolute.h"
#include "Relative.h"
#include "Timeref.h"
#include "Timestg.h"
#include "Sending.h"
#include "Instance.h"
#include "Message.h"
#include "MSC.h"
#include "Parserbase.h"
#include "Scanner.h"

#include <utility>
#include <map>
#include <string>
#include <stdlib.h>
#include <iostream>

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
	      string new_destiny, const Timeref * new_time_rec, 
	      const Timeref * new_time_sent);
  //Check if msc has any message storaged
  int firstMsg();
  //Returns the message storaged just before the one we are processing
  Message * getPrevMsg();
  //My print operation
  void myprint();

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
  Instance * i = new Instance(new_iid, new_tid, new_name);
  msc->addInst(*i);
}

inline void Parser::addMsg(string new_mid, string new_sms, string new_origin, 
			   string new_destiny, const Timeref * new_time_sent, 
			   const Timeref * new_time_rec)
{
  Instance * orig = msc->searchIid(new_origin);
  Instance * dest = msc->searchIid(new_destiny);
  Message * m = NULL;
  Sending * sen = NULL;
  Receipt * rec = NULL;

  if (orig == NULL)
    {
      std::cout << "The origen of the message (" << new_origin 
		<< ") doesn't exist." << std::endl;
      exit(0);
    }
  else if (dest == NULL)
    {
     std::cout << "The destiny of the message (" << new_destiny 
	       << ") doesn't exist." << std::endl;
     exit(0);
    }

  if ((new_time_sent->get_valtype()) == ABSOLUTE)
    {
      Absolute *a = new Absolute(new_time_sent->get_value());
      sen = new Sending(*orig, *a);
    }
  else if (new_time_sent->get_valtype() == RELATIVE)
    {
      if (new_time_sent->get_mode() != 0)
	{
	  m = msc->searchMid(new_time_sent->get_ref());

	  if (m == NULL)
	    {
	      std::cout << "The Message referenced (" 
			<< new_time_sent->get_ref() 
			<< ") doesn't exist." << std::endl;
	      exit(-1);
	    }
	
	  if (new_time_sent->get_mode() == 1)
	    {  
	      Relative r(new_time_sent->get_value(), *(m->get_sending()));
	      sen = new Sending(*orig, r);
	    }
	  else if (new_time_sent->get_mode() == 2)
	    {
	      Relative r(new_time_sent->get_value(), *(m->get_receipt()));
	      sen = new Sending(*orig, r);
	    }
	}
      else if (new_time_sent->get_mode() == 0)
	{
	  Message * aux = getPrevMsg();
	  Relative r(new_time_sent->get_value(), *(aux->get_receipt()));
	  sen = new Sending(*orig, r);
	}
    }

  if (new_time_rec->get_valtype() == ABSOLUTE)
    {
      Absolute a(new_time_rec->get_value());
      rec = new Receipt(*dest, a);
    }
  else if (new_time_rec->get_valtype() == RELATIVE)
    {
      if (new_time_rec->get_mode() != 0)
	{
	  m = msc->searchMid(new_time_rec->get_ref());
	  
	  if (m == NULL)
	    {
	      std::cout << "The Message referenced (" 
			<< new_time_sent->get_ref() 
			<< ") doesn't exist." << std::endl;
	      exit(-1);
	    }

	  if (new_time_rec->get_mode() == 1)
	    {
	      Relative r(new_time_rec->get_value(), *(m->get_sending()));
	      rec = new Receipt(*dest, r);
	    }
	  else if (new_time_rec->get_mode() == 2)
	    {
	      Relative r(new_time_rec->get_value(), *(m->get_receipt()));
	      rec = new Receipt(*dest, r);
	    }
	}
      else if (new_time_rec->get_mode() == 0)
	{
	  Relative r(new_time_rec->get_value(), *(sen));
	  rec = new Receipt(*dest, r);
	}
    }

  m = new Message(new_mid, new_sms, *sen, *rec);
  msc->addMsg(*m);
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
inline void Parser::print()
{
}

//Check if msc has any message storaged
inline int Parser::firstMsg()
{
  return msc->firstMsg();
}

//Returns the message storaged just before the one we are processing
inline Message * Parser::getPrevMsg()
{
  return msc->getPrevMsg();
}

//My print operation
inline void Parser::myprint()
{
  msc->print();
}

#endif
