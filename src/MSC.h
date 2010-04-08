#ifndef MSC_H
#define MSC_H

#include "Instances.h"
#include "Messages.h"

class MSC
{
  
public:

  MSC();
  ~MSC();

  //Adds a new instance to msc
  void addInst (char * new_iid, char * new_tid, char * new_name);
  //Adds a new instance to message
  void addMsg (char * new_mid, char * new_sms, char * new_origin, 
	      char * new_destiny, int new_time_sent, int new_time_rec);
  //Returns the time when the message marked with id was sent
  int getTime_sent(int id);
  //Returns the time when the message marked with id was received
  int getTime_rec(int id);
  //Returns the time when the message marked with mid was sent
  int getTime_sent(char * mid);
  //Returns the time when the message marked with mid was received
  int getTime_rec(char * mid);
  //Returns the number of messages storaged in msc
  int msgSize();
  //Prints on screen all data storaged
  void myPrint();

private:

  Instances * instances;
  Messages * messages;
};

#endif
