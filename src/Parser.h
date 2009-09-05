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
    // $insert ListaEventosObject
    ListaEventos lista = new ListaEventos;
        
    public:
        int parse();

    private:
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

	void AnadirEvento (ListaEventos * lista, char * n1, int t1, 
			   char * n2, int t2, char * texto)
	{
	  lista -> AnadirEvento (n1, t1, n2, t2, texto);
	}

    // support functions for parse():
        void executeAction(int ruleNr);
        void errorRecovery();
        int lookup(bool recovery);
        void nextToken();
};


#endif
