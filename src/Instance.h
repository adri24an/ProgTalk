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

    char * id;

    char * tid;

    char * name;

    Event * events;

};
#endif
