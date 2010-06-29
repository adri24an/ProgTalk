#ifndef _MESSAGE_H
#define _MESSAGE_H


class Receipt;
class Sending;

//This class represents a message in a communication between instances.
class Message {
  protected:
    //Message id.
    char * mid;

    //Text transmitted in the Message.
    char * sms;

    //Author and time of receipt.
    Receipt * receipt;

    //Author and time of sending.
    Sending * sending;


  public:
    Message();

    ~Message();

};
#endif
