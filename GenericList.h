//class: GenericList
//Purpose: This helps create a generic List which can be used both as Priority Queue and a simple FIFO queue
#pragma once
#include "Node.h"
#include "Event.h"
class GenericList{
private:
Node* head; //Points to the first Element
Node* tail; // points to the last element 

public:
// GenericList(Node*, Node*); // This is the Constructor for regular queue takes head and tail
// GenericList(Node*); //This is the constructore for Priority Queue takes only head
GenericList(); // This constructor will do the job
void insertOrdered(Event*);
void addBack(Event*); // this adds at the back of the Queue
Event* dequeue();
bool isEmpty();
~GenericList();
Node* getHead();
};