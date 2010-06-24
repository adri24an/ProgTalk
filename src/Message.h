#ifndef _MESSAGE_H
#define _MESSAGE_H


class MSC;
class Receipt;
class Sending;

//This class represents a message in a communication between instances.
class Message {
  protected:
    MSC * msc;

    char * mid;

    Receipt * receipt;

    Sending * sending;

    char * sms;

};
#endif
