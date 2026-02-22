// class: Node
// purpose acts as Node for the genric List
#include "Node.h"

Node:: Node(Event* e)
{
    this->event = e;
    this->next = nullptr;
}

Node* Node:: getNext()
{
    return this->next;
}

Event* Node:: getEvent()
{
    return this->event; // otherwise I had to dereference the pointer
}

void Node::setNext(Node* n) 
{
    this->next = n;  // Sets next node
}
