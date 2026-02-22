#pragma once
#include "Event.h"
//console prints cleared for takeoff on runway x and time required?
class TakeOff: public Event{
private:
int runway;
// int time;
// Plane* p; REDUNDANT
public:
// TakeOff(int, Plane*);
int getRunway();
TakeOff(int, Plane*, int);
void processEvent() override;
virtual ~TakeOff() {}
};