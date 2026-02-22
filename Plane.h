#pragma once
#include <string>
using namespace std;
class Plane
{
private:
string callSign;
int flightNumber;
string size; //can be small large heavy or super
string requestType; // we might have to chnage this latr on
int atcId;

public:
Plane(string, int, string, string, int); // this is the constructor with parameters(Used to create an newPlane)
string getCallSign();
int getFlightNum();
string getSize();
string getRequestType();
int getAtc();
};