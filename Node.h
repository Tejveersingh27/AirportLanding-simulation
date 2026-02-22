//This is the node containing an even and its info to be stored in Generic Lis
#pragma once
#include "Event.h"
#include <iostream>
using namespace std;
class Node
{
private:
Event* event; // the event to be stored in the node
Node* next; //pointer to next node

public:
Node(Event*);// constructor with event
Node* getNext();
Event* getEvent();
void setNext(Node*);
};