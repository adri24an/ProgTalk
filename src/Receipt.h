#ifndef _RECEIPT_H
#define _RECEIPT_H


#include "Event.h"

class Message;

//This class represents an event that occurs when a message is received.
class Receipt : public Event {
  protected:
    Message * message;

};
#endif
