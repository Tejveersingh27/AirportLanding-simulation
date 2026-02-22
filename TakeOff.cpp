// Class: Takeoff
// Purpose: Used to create instances of Takeoff events
#include "TakeOff.h"
#include <iostream>
using namespace std;
TakeOff :: TakeOff(int t, Plane*p, int r) : Event(t, p){
   runway =r;
} // using the Superclass Constructor

int TakeOff:: getRunway()
{
    return runway;
}
void TakeOff::processEvent() {
    cout << getPlane()->getCallSign()<< " "<< getPlane()->getFlightNum() << " (" <<getPlane()->getAtc()<< ") "<<getPlane()->getSize() << " cleared for takeoff on runway ";
}