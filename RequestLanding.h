#pragma once
#include "Event.h"

class RequestLanding: public Event
{

private:
//int runway;
    public:
    //RequestLanding(int, Plane*);
    RequestLanding(int, Plane*);
    //int getRunway();
    void processEvent() override;
    virtual ~RequestLanding() {}
};