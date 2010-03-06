#ifndef Parser_h_included
#define Parser_h_included

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Parserbase.h"
#include "Scanner.h"
#include <map>
#include <string>
#include <string.h>

struct ASTintances
{
    std::string tid;
    std::string name;
};

struct ASTmessages
{
    std::string mid;
    std::string sms;
    std::string origin;
    std::string destiny;
    int time_sent;
    int time_rec;
};

typedef std::map<std::string,ASTintances> Instances;
typedef std::map<int,ASTmessages> Messages;

#undef Parser
class Parser: public ParserBase
{       
    public:
        Parser();

	//Returns a pointer to Instances object
	Instances * getInstances();

	//Returns a pointer to Messages object
	Messages * getMessages();

        int parse();

	//Adds a new instance (because vesions 2 and 3 of AddInstance had 
	//the same parameters, we introduce the parameter "aux" in the third
	//version of AddInstance so the compiler can differentiate between
	//them)
	void AddInstance(std::string iid, std::string tid, std::string name);
	void AddInstance(std::string iid, std::string tid);
	void AddInstance(std::string iid, std::string name, int aux);
	void AddInstance(std::string iid);

	//Adds a new message
	void AddMessage(std::string mid, std::string sms, std::string origin,
			std::string destiny, int time_sent, int time_rec);
	
	//Adds a new message
	void AddMessage();

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

	Scanner d_scanner;   //Tokens reader
        
	Instances instances; //Object that storages instances
	Messages messages;  //Object that storages messages
};

inline Parser::Parser()
	      :instances(), messages()
{
}

//Returns a pointer to instances object
inline Instances * Parser::getInstances()
{
    return &instances;
}

//Returns a pointer to EventsList object
inline Messages * Parser::getMessages()
{
    return &messages;
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
