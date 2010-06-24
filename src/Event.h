#ifndef _EVENT_H
#define _EVENT_H


class Instance;
class Timestamp;
class Relative;

//This class represents an event in the communication between instances. An event is represented by:
//- instance where the event occurred
//- time when the event occurred
class Event {
  protected:
    Instance * ;

    Timestamp * timestamp;

    Relative * ;


  public:
    Event();

    ~Event();

};
#endif
