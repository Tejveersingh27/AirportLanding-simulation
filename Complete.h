#pragma once
#include "Event.h"
// has cleared the runway x when takeoff/landed successfully
class Complete : public Event{
private:
int runway; // just to keep track of the runway  We might remove this later on
public:
void processEvent() override;
Complete(int, Plane*, int);
int getRunway();
virtual ~Complete() {} 
};