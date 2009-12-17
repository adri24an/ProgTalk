class Event
{
  
public:

  Event(char * n1, int t1, char * n2, int t2, char * text);
  ~Event();

  char * GetEntity1Name ();
  int GetEntity1Time ();
  char * GetEntity2Name ();
  int GetEntity2Time ();
  char * GetText ();

private:

  char * name1; //Name of the sender
  int time1;    //Time when the message was sended
  char * name2; //Name of the receiver
  int time2;    //Time when the message was received
  char * text;  //Text of the message
};
