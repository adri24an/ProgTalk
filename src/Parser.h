#ifndef Parser_h_included
#define Parser_h_included

#include <iostream>

#include "MSC.h"
#include "Timestamp.h"
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
  Parser();
  
  int parse();
  MSC * getMSC();
  void addInst(char * newiid, char * newtid, char * newname);
  void addMsg(char * new_mid, char * new_sms, char * new_origin, 
			  char * new_destiny, int new_time_sent, int new_time_rec);
  int getTime_sent(int id);
  int getTime_rec(int id);
  int msgSize();
  //A custom print operation
  void MyPrint();       

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

inline void Parser::addInst(char * newiid, char * newtid, char * newname)
{
  msc->addInst(newiid, newtid, newname);
}

inline void Parser::addMsg(char * new_mid, char * new_sms, char * new_origin, 
			   char * new_destiny, int new_time_sent, 
			   int new_time_rec)
{
  msc->addMsg(new_mid, new_sms, new_origin, new_destiny, new_time_sent, 
	       new_time_rec);
}

inline int Parser::getTime_sent(int id)
{
  int time = msc->getTime_sent(id);

  return time;
}

inline int Parser::getTime_rec(int id)
{
  int time = msc->getTime_rec(id);

  return time;
}

inline int Parser :: msgSize()
{
  return msc->msgSize();
}

inline void Parser::error(char const *msg)
{
    std::cerr << msg << std::endl;
}

inline int Parser::lex()
{
    return d_scanner.yylex();
}

//A custom print operation
inline void Parser::MyPrint ()
{
  ;
}

//Default print operation (not implemented)
inline void Parser::print(){}

#endif
