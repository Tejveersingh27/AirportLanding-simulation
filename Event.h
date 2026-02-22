//THIS IS THE ABSTRACT EVENT CLASS ( EVENT OBJECT)
#pragma once
#include <string>
#include "Plane.h"
using namespace std;

class Event
{
private:
int time; // in minutes
Plane* plane; //The plane object involved with a particular event

public:
Event(int, Plane*); // Cnstructor with parameters
virtual ~Event() {} // making the base class destructor virtual
bool compareToEvent(Event*); // Compare to the atcId of another Event
Plane* getPlane();
int getTime();
virtual void processEvent()=0; // this is a virtual method so it should be overwridden in all the subclasses
};
