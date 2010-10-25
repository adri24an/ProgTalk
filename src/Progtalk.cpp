#include "Parser.h"
#include "PrettyPrinting.h"

int main()
{
  Parser * parser = new Parser;
  PrettyPrinting * visitor = new PrettyPrinting;

  parser->parse();
  parser->accept(*visitor);
  
  return 0;
}
