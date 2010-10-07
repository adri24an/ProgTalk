#include "Parser.h"

int main()
{
  Parser * parser = new Parser;

  parser->parse();
  parser->print();
  
  return 0;
}
