#ifndef Parser_h_included
#define Parser_h_included

// for error()'s inline implementation
#include <iostream>
#include "Parserbase.h"
#include "Scanner.h"
//#include "ListaEventos.h"
#include "ListaEventos.cpp"

#undef Parser
class Parser: public ParserBase
{
    // $insert scannerobject
    Scanner d_scanner;
    ListaEventos * le;
        
    public:
        Parser();
	ListaEventos * GetLE();
        int parse();

    private:

	void AnadirEvento (char * n1, int t1, char * n2, int t2, char * texto);
        void error(char const *msg);
        int lex();
        void print();

    // support functions for parse():
        void executeAction(int ruleNr);
        void errorRecovery();
        int lookup(bool recovery);
        void nextToken();
};

inline Parser::Parser()
{
    this -> le = new ListaEventos();
}

inline ListaEventos * Parser::GetLE()
{
    return le;
}

inline void Parser::AnadirEvento (char * n1, int t1, char * n2, int t2, 
				  char * texto)
{
    le->AnadirEvento(n1,t1,n2,t2,texto);
}

inline void Parser::error(char const *msg)
{
    std::cerr << msg << std::endl;
}

inline int Parser::lex()
{
    return d_scanner.yylex();
}

inline void Parser::print()// d_token, d_loc
{
}

#endif
