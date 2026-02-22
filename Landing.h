#pragma once
#include "Event.h"
class Landing : public Event{
private:
int runway;

public:
void processEvent() override;
//Landing(int, Plane*);
Landing(int, Plane*, int);

int getRunway(); // this a new method to get runway
virtual ~Landing() {} 
};