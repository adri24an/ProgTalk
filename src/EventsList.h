#include "Event.h"

#include <iostream>
#include <string.h>

//-----------------------------------------------------------------
//Class NodeEventsList
//-----------------------------------------------------------------

class NodeEventsList
{
public:

	NodeEventsList(Event * e);
	
	~NodeEventsList();
	
	//Returns a pointer to the next node
	NodeEventsList * GetSig() const;
	
	//Sets the "sig" pointer to "node" 
	void SetSig (NodeEventsList * node);
	
	//Returns the object Event from the node
	Event * GetEvent () const;

private:

	Event * event; //Object that storages all the info from an
	               //event (communicantion): sender, times,...
        NodeEventsList * sig; //Pointer to the next event
};

//-----------------------------------------------------------------
//Class EventsList
//-----------------------------------------------------------------

class EventsList
{
public:

	EventsList();

	~EventsList();

	//Adds a new Event
	void AddEvent (char * n1, int t1, char * n2, int t2, char * texto);

	//Prints all storaged info
	void Print();

private:

	NodeEventsList * list; //List of nodes (event + pointer to next node)

};
