// Class: RequestTakeoff
// Purpose: Used to creat instances of request Takeoff events
#include "RequestTakeOff.h"
#include <iostream>
using namespace std;
RequestTakeOff :: RequestTakeOff(int t, Plane* p) : Event(t, p){
}

void RequestTakeOff:: processEvent()
{
    cout <<getPlane()->getCallSign() << " " << getPlane()->getFlightNum() << " ("<< getPlane()->getAtc() <<") " <<getPlane()->getSize()<<
    " ready for takeoff."<<endl;
}