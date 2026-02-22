// Class: Landing
// Purpose: Used to create instances of Landing events

#include "Landing.h"
#include <iostream>
using namespace std;
//Landing:: Landing(int t, Plane*  p): Event(t, p){}

Landing:: Landing(int t, Plane* p, int r): Event(t, p){
    runway =r;
}

int Landing:: getRunway()
{
    return runway;
}
void Landing::processEvent() {
    cout << getPlane()->getCallSign()<<" " << getPlane()->getFlightNum() << " (" << getPlane()->getAtc()<<") " <<getPlane()->getSize() << " cleared for landing on runway ";
}