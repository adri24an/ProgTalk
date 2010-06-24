#include "Parser.h"

int main()
{
  Parser * parser = new Parser;

  parser->parse();
  parser->myPrint();

  /*
  Messages * m = new Messages;

  m->addMsg("m1", "hola", "a", "b", 0, 1);
  m->addMsg("m2", "adios", "a", "b", 2, 5);
  m->addMsg("m3", "adri", "a", "b", 6, 8);
  m->myPrint();
  std::cout << m->getTime_rec("m1") << std::endl;
  std::cout << m->getTime_rec("m2") << std::endl;
  std::cout << m->getTime_rec("m3") << std::endl;
  */
  
  return 0;
}
