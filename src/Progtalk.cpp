#include "Parser.h"

int main()
{
  Parser * parser = new Parser;

  parser->parse();
  parser->myprint();
  
  return 0;
}
