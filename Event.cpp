//Class: Event
// Purpose: This is the base class which is used to pass some properties to the subclasses 

#include "Event.h"
Event:: Event(int t, Plane* p)
{
    time=t;
    plane = p;
}


bool Event:: compareToEvent(Event* e)
{ 
    if(this->getTime()< e->getTime()) // if this event has less time then its higher priority
    {
        return true;
    }
    else if(this->getTime() == e->getTime())
    {
        if(this->getPlane()->getAtc() < e->getPlane()->getAtc() ) // if the Atc Id in this event is lower than the the inputy event
    {
        return true; // indicating the current event has higher priority
    }
    }
    
    return false; // lesser priority
}
Plane* Event:: getPlane()
{
    return plane;
}
int Event:: getTime()
{
    return time;
}