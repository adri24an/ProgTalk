#include "Parser.h"
#include "PrettyPrinting.h"
#include "TimeChecker.h"
#include "LatexPrint.h"

int main()
{
  Parser * parser = new Parser;
  PrettyPrinting * visitorpprinting = new PrettyPrinting;
  //TimeChecker * visitortime = new TimeChecker;
  //LatexPrint * visitorprint = new LatexPrint;

  parser->parse();
  parser->accept(*visitorpprinting);
  //parser->accept(*visitortime);
  //parser->accept(*visitorprint);
  
  return 0;
}
