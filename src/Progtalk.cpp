#include "Parser.h"
#include "PrettyPrinting.h"
#include "LatexPrint.h"

int main()
{
  Parser * parser = new Parser;
  //PrettyPrinting * visitor = new PrettyPrinting;
  LatexPrint * visitor = new LatexPrint;

  parser->parse();
  parser->accept(*visitor);
  
  return 0;
}
