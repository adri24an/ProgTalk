#ifndef _MESSAGE_H
#define _MESSAGE_H


#include <string>
using namespace std;

class MSC;
class Receipt;
class Sending;

//This class represents a message in a communication between instances.
class Message {
  protected:
    MSC * msc;

    string mid;

    Receipt * time_rec;

    Sending * time_sent;

};
#endif
