#include "EventsList.h"

//------------------------------------------------------------------
// Class NodeEventsList
//------------------------------------------------------------------

NodeEventsList :: NodeEventsList (Event * e)
{
	event = e;
	sig = NULL;
}

NodeEventsList :: ~NodeEventsList ()
{
	delete event;
}

//Returns a pointer to the next node
NodeEventsList * NodeEventsList :: GetSig () const
{
	return sig;
}

//Sets the "sig" pointer to "node"
void NodeEventsList :: SetSig (NodeEventsList * node)
{
	sig = node;
}

//Returns the object Event from the node
Event * NodeEventsList :: GetEvent () const
{
	return event;
}

//------------------------------------------------------------------
// Class EventsList
//------------------------------------------------------------------

EventsList :: EventsList()
{
	list = NULL;
}

EventsList :: ~EventsList()
{
    NodeEventsList *ant, *act;
    act = list;
    while (act)
    {
        ant = act;
        act = act->GetSig();
        delete ant;
    }
}

//Adds a new Event
void EventsList :: AddEvent (char * n1, int t1, char * n2, int t2, 
				   char * text)
{
    NodeEventsList * index = list;
    Event * e;
    NodeEventsList * n;

    if (list != NULL)
    {
        while (index->GetSig() != NULL)
	{
	    index = index->GetSig();
	}

	e = new Event (n1, t1, n2, t2, text);
	n = new NodeEventsList (e);
	index->SetSig(n);
    }
    else
    {
        e = new Event (n1, t1, n2, t2, text);
        n = new NodeEventsList (e);
        list = n;
    }
}

//Prints all storaged info
void EventsList :: Print()
{
    NodeEventsList * index = list;
    Event * e;
  
    while (index != NULL)
    {
	e = index->GetEvent();
	std::cout << "(" 
		  << e->GetEntity1Name()
		  << ","
		  << e->GetEntity1Time()
		  << ") "
		  << "(" 
		  << e->GetEntity2Name()
		  << ","
		  << e->GetEntity2Time()
		  << ") "
		  << "\""
		  << e->GetText()
		  << "\""
		  << std::endl;
	index = index->GetSig();
    }
}
