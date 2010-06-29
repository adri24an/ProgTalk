#ifndef _RECEIPT_H
#define _RECEIPT_H


#include "Event.h"

//This class represents an event that occurs when a message is received.
class Receipt : public Event {
  public:
    Receipt();

    ~Receipt();

};
#endif
