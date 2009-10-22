#ifndef Parser_h_included
#define Parser_h_included

// for error()'s inline implementation
#include <iostream>

// $insert baseclass
#include "Parserbase.h"
// $insert scanner.h
#include "Scanner.h"
// $insert ListaEventos.h
#include "ListaEventos.h"


#undef Parser
class Parser: public ParserBase
{
    // $insert scannerobject
    Scanner d_scanner;
    ListaEventos * le;
        
    public:
        int parse();

        Parser()
        {
	    this -> le = new ListaEventos();
        }

	~Parser()
	{
	    delete le;
        }

	ListaEventos * GetLE()
	{
	    return le;
	}

    private:

	void AnadirEvento (char * n1, int t1, char * n2, int t2, char * texto)
	{
	    le->AnadirEvento(n1,t1,n2,t2,texto);
	}

        void error(char const *msg)
        {
            std::cerr << msg << std::endl;
        }

        // $insert lex
        int lex()
        {
            return d_scanner.yylex();
        }

        void print()    // d_token, d_loc
        {}

    // support functions for parse():
        void executeAction(int ruleNr);
        void errorRecovery();
        int lookup(bool recovery);
        void nextToken();
};


#endif
