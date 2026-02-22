//class: EventDrivenSimulation
// Purpose: This class basically controls the processing of events as they are read from the input file
// We are using an instance of this class in main method just so that our main method looks cleaner

#include "EventDrivenSimulation.h"

int EventDrivenSimulation::atcIdCounter = 1;  // this is our static counter It will Increment whenever there is a new Plane

//constructor
EventDrivenSimulation:: EventDrivenSimulation(string fileName, int runway)
{
    runwayNum =runway;
    priorityQueue = new GenericList(); // this is the event queue
    queue = new GenericList(); // this is the waiting queue
    inputFile.open(fileName);  // opening the file for reading
    // Intialising everything
    wastedTime =0;
    globalClock =0;
    runways = new bool[runwayNum]; //creating an array of bools
    for(int i=0; i<runwayNum; i++)
    {
        runways[i]= true; // by default all runways are free
    }
    read(); // we read the first line of the file
}



//method: read()
// purpose: this method sees if there exist next line in the file (ie EOF is not reached) and then reads a line from
// file and see if its request Landing/Takeoff then insert that event in the PQ accordingly
// parameters: None


void EventDrivenSimulation::read()
{
	string line;
	//cout << "The first line of the file contains the following information: " << endl;
	if(getline(inputFile, line))  //gets the next line from the file and saves it in 'line', if there is one // if this is false means eof is reached
	{
		stringstream sst(line);  //stringstream allows us to parse the line token by token (kind of like a Scanner in Java)
		string token;
		int time = 0;
		string callSign = "";
		string flightNum = "";
		string size = "";
		string requestType = "";
		
		sst >> token;  //grabbing the next token (reading time)
		time = stoi(token); //converting time (string format)
		sst >> callSign;  //grabbing next token (reading call sign)
		sst >> flightNum;  //grabbing next token (reading flight number)
		sst >> size;  //grabbing next token (reading plane size)
		sst >> requestType;  //grabbing next token (reading request type, either landing or takeoff)

Plane* p = new Plane (callSign, stoi(flightNum), size, requestType, atcIdCounter++); // we increase the counter by one each tim ewe create a plane

if(requestType == "landing") 
{
    //we create a new Request Event and add it to the event queue
priorityQueue->insertOrdered(new RequestLanding(time, p)); // adding that event to the priority queue
}
else if(requestType == "takeoff") // we create a new request Takeoff event
{
priorityQueue->insertOrdered(new RequestTakeOff(time, p)); // adding that event to the priority queue
}
	}
}

//Method: Run()
// purpose: This method is basically analysing the element at the top of the priority queue as it dequeue it and
// acts according to what kind of event is present at the top.(It can further call one of the 5 methods doRequestTakeoff(e),
// doRequestLanding(e), doLanding(e),  doTakeOff(e), doComplete(e). and at last it prints the statistics
// parameters: None


  void EventDrivenSimulation:: run()
    {
        cout << "Simulation begins.... \n";
        while(!priorityQueue->isEmpty()) //untile the priority queue is not empoty
        {
            
            Event* e = priorityQueue->dequeue(); // we remove the first element of the priority queue 
            globalClock = e->getTime(); // right now time 1 for delta 1234
            if(dynamic_cast<RequestTakeOff*>(e))
            {
                doRequestTakeoff(e);
            }
            else if(dynamic_cast<RequestLanding*>(e))
            {
                doRequestLanding(e);
            }
            else if(dynamic_cast<Landing*>(e))
            {
                doLanding(e);
            }
            else if(dynamic_cast<TakeOff*>(e))
            {
                doTakeOff(e);
            }
            else if(dynamic_cast<Complete*>(e))
            {
                doComplete(e);
            }
        }

        //Print statistics....//
    cout<<"##########################" << endl;
    cout << "Simulation ends at time " << globalClock << ".\n";
    cout << "Number of runways: " << runwayNum << endl;
    cout << "The total amount of time wasted because runways were not available: " << wastedTime << " minutes.\n";
     cout<<"##########################" << endl;
    }


//Method:doRequestTakeoff(Event* e)
// parameters: Event*
// purpose: It first processes the request event checks if there is a runway available if there 
//is creates a new Process Landing/ Takeoff event and insert it into
// the PQ if runway not avialble it adds that request event into FIFO queue
void EventDrivenSimulation:: doRequestTakeoff(Event* e)
{
    cout<< "Time: "<< globalClock << "->";
    e->processEvent(); // cout the details of the event
    int actualRunway = 0; /// we might change this logic later on
    // Since we had an array of bools
    for(int i=0; i< runwayNum; i++) // loop iterates until it finds the first true position(ie available runway)
    {
        if(runways[i]) // we select the first Runway which is true
        {
            runways[i]= false; //set it to false
            actualRunway = i + 1 ; // + 1 cozz runway starts from 0 
            break;  /// OUT!!!!
        }
    }

    //cout<<actualRunway<<endl; DEBUGGING

    if(actualRunway!=0) // meaning the runway is available
    { /// We have to add runwya num in the takeoff even class
        priorityQueue->insertOrdered(new TakeOff(globalClock, e->getPlane(), actualRunway)); // we create a  takeoff event
       // runwayNum--; // reduces the available runways by 1
    }
    else
    { // lets say if a runway is already in use we can still put in into the waiting queue

    // int wait = globalClock - e->getTime(); //we may change this!!
    // wastedTime += wait; //
        queue->addBack(e);
    }
 
        read(); // we read the next line and insert the event in order into the event List
 }


//Method: doRequestLanding(Event*e)
// parameters: Event*
//Purpose: Does the same as doRequestTakeoff(Event* e) but for landing requests
void EventDrivenSimulation:: doRequestLanding(Event*e)
{
    cout<< "Time: "<< globalClock << "->";
    e->processEvent();
    int actualRunway = 0; /// we might change this logic later on
    for(int i=0; i< runwayNum; i++)
    {
        if(runways[i]) // we select the first Runway which is true
        {
            runways[i]= false; //set it to false
            actualRunway = i +1; // +1 cozz runway starts from 0 okkk
            break; 
        }
    }
    if(actualRunway!=0) // means that there is some runway available
    {
        priorityQueue->insertOrdered(new Landing(globalClock, e->getPlane(), actualRunway));
        //runwayNum--;
    }
    else 
    // if its 0 means that no runway is available
    {
    // int wait = globalClock - e->getTime(); //we may change this!!
    // wastedTime += wait; //
        queue->addBack(e); 
    }

        read(); // read next life if there is one
    
}

//Method: doLanding(Event* e)
//parameter: Event*
//purpose: If the event at the head is a Landing event it first processes the event
// calculate all the extra time required by the event, insert a Complete Event accordingly
void EventDrivenSimulation:: doLanding(Event* e)
{
    cout<< "Time: "<< globalClock << "->";
    //if(runwayNum>0){ //We may Remove this later on to see what does it looklike
    int extra = 1 + 2 + getSizeTime(e->getPlane()); //1+ 2 minutes for landing + the extra time due to turbulence of plane due to size
    int waste = globalClock - e->getTime();
    wastedTime += waste;
    e->processEvent();

    int actualRunway = dynamic_cast<Landing*>(e)->getRunway(); // lets see if only e landing will work

    cout<< actualRunway <<"(time req. for Landing: " << extra << ")" << endl; // this is used to print the extra required time
    // we still need to check is runway NUm righT??
    priorityQueue->insertOrdered(new Complete(globalClock + extra, e->getPlane(), actualRunway)); // insert a complete event at this time in the event list
    //  runwayNum--; // Lets see what this does maybe remove later on !!!
    //}
}

 

//Method: doTakeoff(Event*e)
//parameter: Event *
// purpose: Does the same thing as doLanding(Event* e) but For Takeoff Events
void EventDrivenSimulation:: doTakeOff(Event* e)
{
    cout<< "Time: "<< globalClock << "->";
    int extra = 1 + getSizeTime(e->getPlane());
    int waste = globalClock - e->getTime();
    wastedTime += waste;
      e->processEvent();

    int actualRunway = (dynamic_cast<TakeOff*>(e))->getRunway();

    cout<< actualRunway <<"(time req. for takeoff: " << extra << ")" << endl;// this is used to print the extra required time
    priorityQueue->insertOrdered(new Complete(globalClock + extra, e->getPlane(), actualRunway));
}


//method: doComplete(Event* e)
//parameter: Event * 
// purpose if the event at head of PQ is A complete event then this method runs
//It processe the complete even and frees a runway then it checks the waiting queue and according to priority
// deques an event from it and insert a process Landing/takeoff event into the PQ
void EventDrivenSimulation:: doComplete(Event* e)
{
    cout<< "Time: "<< globalClock << "->";
    e->processEvent();
    int n = dynamic_cast <Complete*>(e)->getRunway();
    runways[n - 1] = true; // we make true the position in runways array

    //if(!queue->isEmpty()) // if the waiting line has not become empty
    // means there is already someone in th efront of the waiting line
    //{
        // Event* e = queue->dequeue(); // we remove the element from the waiting queue
        // if(dynamic_cast<RequestTakeOff*>(e))
        // {
        //     // doRequestTakeoff(e); // we start the request takeoff prcess again for this event now
        //     priorityQueue->insertOrdered(new TakeOff(globalClock, e->getPlane()));  // See the Queue and see there is still
        //     //any takeoff event which was sent to queue is not yet inserted to the event List
        //     runwayNum--; 
        // }
        // else if(dynamic_cast<RequestLanding*>(e))
        // {
        //     // doRequestLanding(e); // this will kinda trigger events after events
        //     priorityQueue->insertOrdered(new Landing(globalClock,e->getPlane()));
        //     runwayNum--;
        // }
       
        if(queue->isEmpty()) 
        {
            return;
        }
 GenericList* temp = new GenericList();
        Event* eve = nullptr;
        bool firstLanding = false; //this will become true when the first Landing event is found
        while(!queue->isEmpty()) // now we go throught the queue to see if teh Landing event is present coz we want to give it priority
        {
            Event* curr = queue->dequeue();
            if(dynamic_cast<RequestLanding*>(curr) && !firstLanding) // until the first LAnding evwnt is not found
            {
                eve = curr;
                firstLanding = true; //now the first landing is found eve will not be overwridden if there is abother Landing event
                //remain landing event after this can still be added to the lis
            }
            else
            {
                temp->addBack(curr); // rest everything except the first Landing event is added back to temp queue
            }
        }

        if((!eve)&& !temp->isEmpty()) // meaning that there was no Landing event in the queue
        {
            eve = temp->dequeue(); // take the first event from temp queue
        }
        //Now with all the remaining elements we add them back to the empty "queue"
        while(!temp->isEmpty())
        {
            queue->addBack(temp->dequeue());
        }
        delete temp;

    if(!eve)
    {
        return;
    }
    int actualRunway = n;// We just use the recently freed runway
     runways[actualRunway - 1] = false; // Mark as occupied again

int waste  = globalClock - eve->getTime();
        wastedTime += waste; 
        if(dynamic_cast<RequestLanding*>(eve))
        {
            priorityQueue->insertOrdered(new Landing(globalClock,eve->getPlane(), actualRunway));
        }
        else if(dynamic_cast<RequestTakeOff*>(eve))
        {
            priorityQueue->insertOrdered(new TakeOff(globalClock, eve->getPlane(), actualRunway)); 
        }
    //}
    //}
} 

//method getSizeTime(Plane* p)
// parameter: Plane*
// purpose it returns the extra time required by a plane based on its size due to Wake Turbulence
int EventDrivenSimulation:: getSizeTime(Plane* p)
{
    if(p->getSize() == "small")
    {
        return 0;
    }
    else if(p->getSize()== "large")
    {
        return 1;
    }
    else if(p->getSize() == "heavy")
    {
        return 2;
    }
    else if(p->getSize() == "super")
    {
        return 3;
    }

    return 0;
}

//Destructor deletes the lists ad close the file
EventDrivenSimulation::~EventDrivenSimulation() 
{
    delete queue;
    delete priorityQueue;
    delete[] runways; 
    inputFile.close();
}


//waheguru//

/*

How to Compile and run:

clang++ *.cpp -std=c++11 -o simulation
./simulation input.txt 1
*/