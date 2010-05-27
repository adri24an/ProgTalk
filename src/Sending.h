#ifndef _SENDING_H
#define _SENDING_H


#include "Event.h"

class Message;

//This class represents an event that occurs when a message is sent.
class Sending : public Event {
  protected:
    Message * message;

};
#endif
