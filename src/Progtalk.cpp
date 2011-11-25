#include "Parser.h"
#include "PrettyPrinting.h"
#include "TimeChecker.h"
#include "LatexPrint.h"

int main()
{
  Parser * parser = new Parser;
  PrettyPrinting * visitorpprinting = new PrettyPrinting;
  TimeChecker * visitortime = new TimeChecker;
  LatexPrint * visitorprint = new LatexPrint;

  parser->parse();
  parser->accept(*visitortime);
  parser->accept(*visitorpprinting); // Esto lo podemos quitar cuando queramos.
  parser->accept(*visitorprint);
  
  //parser->accept(*visitorprint);
  
  return 0;
}
