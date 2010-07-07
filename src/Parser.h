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
  void addInst(char * new_iid, char * new_tid, char * new_name);
  //Adds a new message to msc
  void addMsg(char * new_mid, char * new_sms, char * new_origin, 
	      char * new_destiny, int new_time_sent, int new_time_rec);
   

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

inline void Parser::addInst(char * new_iid, char * new_tid, char * new_name)
{
  i * Instance = new Instance (new_iid, new_tid, new_name);
  msc->addInst(i);
}

inline void Parser::addMsg(char * new_mid, char * new_sms, char * new_origin, 
			   char * new_destiny, int new_time_sent, 
			   int new_time_rec)
{
  m * Message = new Message(char * new_mid, char * new_sms, char * new_origin, 
			    char * new_destiny, int new_time_sent, 
			    int new_time_rec);
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
