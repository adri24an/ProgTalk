#ifndef _MSC_H
#define _MSC_H


#include <map>
using namespace std;

class Message;
class Instance;
class Timeref;
class Timestg;

//This class is used by the parser to access to all the instances and messages storaged.
class MSC {
  protected:
    map<Message *> messages;

    Instance * instances;

    Parser * ;

    Timeref * ;

    Timestg * ;


  public:
    void addInst(const Instance * & i);

    void addMsg(const Message * & m);

    MSC();

    ~MSC();

};
#endif
