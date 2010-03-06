class Timestamp
{
  
public:

  Timestamp(char * iid, int time);
  ~Timestamp();

  char * getIid ();
  int getTime ();

private:

  char * iid;
  int time;
};
