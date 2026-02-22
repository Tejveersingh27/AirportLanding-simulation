#pragma once
#include "Plane.h"
#include "GenericList.h"
#include "RequestLanding.h"
#include "RequestTakeOff.h"
#include "Landing.h"
#include "TakeOff.h"
#include "Complete.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
class EventDrivenSimulation{
private:
bool* runways; // Instead what I am f=doing is taking an array of bools of size of the number of runways 
int runwayNum;
int globalClock;
int wastedTime;

//*****CLASS VARIABLE ******
static int atcIdCounter; // This will increment as we create new planes


GenericList* priorityQueue; // this is the event List
GenericList* queue; // this is waiting List
ifstream inputFile;
public:
EventDrivenSimulation(string fileName, int runways);
~EventDrivenSimulation(); // destructoe
void read();
void run();
void doRequestTakeoff(Event*);
void doRequestLanding(Event*);
void doLanding(Event*);
void doTakeOff(Event*);
void doComplete(Event*);

int getSizeTime(Plane*);
};