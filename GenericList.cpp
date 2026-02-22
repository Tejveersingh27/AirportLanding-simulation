//class: GenericList
//Purpose: This helps create a generic List which can be used both as Priority Queue and a simple FIFO queue
#include "GenericList.h"

GenericList :: GenericList() // initialises a Queue/PQ
{
    this->head = nullptr;
    this->tail =nullptr;
}
void GenericList :: insertOrdered(Event* e) // THIS IS ORDERE INSERTION FOR PRIORITY QUEUE 
{
    Node* newNode = new Node(e);
    if(head == nullptr || e->compareToEvent(head->getEvent())) // meaning list is empty or The new Event has higher proiority
    {
        newNode->setNext(head);
        head = newNode;
        return;
    }

    //otherwise lets find a curr such that it has high priority than new e
   Node* curr = head;
      while(curr->getNext()!=nullptr && !e->compareToEvent(curr->getNext()->getEvent()))
    {
        curr = curr->getNext();
    }
    newNode->setNext(curr->getNext());
    curr->setNext(newNode); 
    
    
}
void GenericList :: addBack(Event *e) //THIS IS THE INSERT FOR REGULAR QUEUE
{
    Node* newNode = new Node(e);
    if(tail==nullptr){
        head = newNode;
        tail = newNode;   
    }
    else
    {
    tail->setNext(newNode); // set the next of tail ement as new Node
    tail = newNode;
    }
}


//Method: dequeue()
//Purpose: It removes the first element of the PQ / Queue and fetches the respective event from it
//return: Event*

Event* GenericList :: dequeue() // THIS DEQUEUE CAN BE USED IN BOTH PRIORITY QUEUE AND REGUALR
{
    if(head == nullptr)
    {
        return nullptr;
    }
    Node* prev = head;
    Event* e = prev->getEvent();
    head = head->getNext(); // move the head 
if (head == nullptr)
 { 
        tail = nullptr;
    }
    delete prev;
    return e; 
}

GenericList :: ~GenericList() // destructor
{
    Node* curr = head;
    while(curr!=nullptr)
    {
        Node* prev = curr;
        curr = curr->getNext();
        delete prev;
    }
     tail =nullptr;
    head =nullptr;
   
}

bool GenericList::isEmpty() 
{
    return head == nullptr;
}

Node* GenericList:: getHead()
{
    return this->head;
}