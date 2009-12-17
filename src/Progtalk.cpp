#include "Parser.h"

int main()
{
    Parser * parser = new Parser;
    EventsList * list;

    parser->parse();
    parser->MyPrint();
    return 0;
}
