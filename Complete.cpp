// Class: Complete
// Purpose: Used to create instances of Complete events
#include "Complete.h"
#include <iostream>
using namespace std;
Complete :: Complete(int t, Plane*p, int r): Event(t, p){
    runway = r;
}
int Complete:: getRunway()
{
    return runway; // this will return the runway number which is being used
}
void Complete::processEvent() 
{
    cout << getPlane()->getCallSign() <<" " << getPlane()->getFlightNum() << " (" <<getPlane()->getAtc()<<") "<<getPlane()->getSize() << " has cleared the runway " << runway<< endl;
}
