#ifndef _MSC_H
#define _MSC_H


#include <map>
using namespace std;

class Message;
class Instance;

//This class is used by the parser to access to all the 
//instances and messages storaged.
class MSC {
  protected:
    map<Message *> messages;

    map<Instance *> instances;


  public:
    //This operation adds new instances to msc.
    void addInst(const Instance * & i);

    //This operation adds new messages to msc.
    void addMsg(const Message * & m);

    MSC();

    ~MSC();

};
#endif
