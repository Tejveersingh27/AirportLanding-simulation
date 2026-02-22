#pragma once
#include "Event.h"
//When event i sprocessed it should print something to the console..
//console prints ready for takeoff.
class RequestTakeOff: public Event{
private:
public:
void processEvent() override;
// RequestTakeOff(int, Plane*);
RequestTakeOff(int, Plane*);
virtual ~RequestTakeOff() {}
};