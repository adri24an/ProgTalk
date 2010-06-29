#ifndef _INSTANCE_H
#define _INSTANCE_H


//This class represents an instance in a communication.
class Instance {
  protected:
    //Instance id.
    char * iid;

    //Type id.
    char * tid;

    //Instance alias.
    char * name;


  public:
    Instance();

    ~Instance();

};
#endif
