// Class: RequestLanding
// Purpose: Used to creat instances of requesLanding events

#include "RequestLanding.h"
#include <iostream>
using namespace std;

RequestLanding :: RequestLanding(int t, Plane*p): Event(t,p){
}
void RequestLanding:: processEvent()
{
    cout <<getPlane()->getCallSign() <<" " << getPlane()->getFlightNum() << " ("<< getPlane()->getAtc() <<") " <<getPlane()->getSize()<<
    " inbound for Landing" << endl;
}

// int RequestLanding :: getRunway()
// {
//     return runway;
// }