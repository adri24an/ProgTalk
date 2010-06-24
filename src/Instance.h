#ifndef _INSTANCE_H
#define _INSTANCE_H


#include <map>
using namespace std;

class MSC;
class Event;

//This class represents an instance in a communication.
class Instance {
  protected:
    map<MSC *> msc;

    //Instance id.
    char * iid;

    //Type id.
    char * tid;

    //Instance alias.
    char * name;

    Event * events;


  public:
    Instance();

    ~Instance();

};
#endif
