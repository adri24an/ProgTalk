#ifndef Parser_h_included
#define Parser_h_included

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Parserbase.h"
#include "Scanner.h"
#include "Timestamp.h"
#include "MSC.h"
#include <map>
#include <string>
#include <string.h>

#undef Parser
class Parser: public ParserBase
{       
    public:
        Parser();

        int parse();

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
        
	MSC msc; //Object that storages instances and messages
};

inline Parser::Parser()
	      :msc()
{
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
