#ifndef _INSTANCE_H
#define _INSTANCE_H


#include <map>
using namespace std;
#include <string>
using namespace std;

class MSC;
class Event;

//This class represents an instance in a communication.
class Instance {
  protected:
    map<MSC *> msc;

    string id;

    string tid;

    string name;

    Event * ;

};
#endif
