#ifndef Parser_h_included
#define Parser_h_included

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Parserbase.h"
#include "Scanner.h"
#include "EventsList.h"
#include <map>
#include <string>

typedef std::map<std::string,int> MyMap;


#undef Parser
class Parser: public ParserBase
{       
    public:
        Parser();

	//Returns a pointer to Instances object
	MyMap * getInstances();

	//Returns a pointer to Messages object
	MyMap * getMessages();

        int parse();

	//A custom print operation
	void MyPrint();       
	

    private:

	//Adds a new event to EventsList object
	void AddEvent (char * n1, int t1, char * n2, int t2, char * text);

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
	EventsList le;       //Object that storages the list of events
	                     //(communications) that were parsed
        
	MyMap instances; //Object that storages instances
	MyMap messages;  //Object that storages messages
};

inline Parser::Parser()
	      :instances(), messages()
{
}

//Returns a pointer to instances object
inline MyMap * Parser::getInstances()
{
    return &instances;
}

//Returns a pointer to EventsList object
inline MyMap * Parser::getMessages()
{
    return &messages;
}

//Adds a new event to EventsList object
inline void Parser::AddEvent (char * n1, int t1, char * n2, int t2, 
			      char * text)
{
    le.AddEvent(n1,t1,n2,t2,text);
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
  le.Print();
}

//Default print operation (not implemented)
inline void Parser::print(){}

#endif
