#ifndef _MESSAGE_H
#define _MESSAGE_H


class MSC;
class Receipt;
class Sending;

//This class represents a message in a communication between instances.
class Message {
  protected:
    MSC * msc;

    //Message id.
    char * mid;

    Receipt * receipt;

    Sending * sending;

    //Text transmitted in the Message.
    char * sms;


  public:
    Message();

    ~Message();

};
#endif
