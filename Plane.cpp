//Class: Plane
//Purpose: Used to create instances of Plane objects
# include "Plane.h"
#include <iostream>

Plane:: Plane(string flightname, int n, string s, string type, int id ) // might have to make some chnages to it
{
    callSign = flightname;
    flightNumber=n;
    size = s;
    requestType= type;
    atcId = id;
}

string Plane::getCallSign()
{
    return callSign;
}
int Plane:: getFlightNum()
{
    return flightNumber;
}
string Plane:: getSize()
{
    return size;
}
string Plane:: getRequestType()
{
    return requestType;
}
int Plane:: getAtc()
{
    return atcId;
}
