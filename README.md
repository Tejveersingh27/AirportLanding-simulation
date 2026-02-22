## Airport Runway Event-Driven Simulation (C++)

This program simulates airport runway traffic using an event-driven system.
It processes aircraft takeoff and landing requests from an input file and manages runway usage accordingly.

The simulation handles:

Landing requests
Takeoff requests
Runway assignment
Wake turbulence timing delays
Waiting queue when no runway is available
Total wasted time calculation

## How to Compile and Run:

Make sure all .cpp and .h files are in the same directory.
Compile using:

clang++ *.cpp -std=c++11 -o simulation
./simulation input.txt 1

## Input Format:

Each line in the input file must follow this format:
time callSign flightNumber size requestType
Where:

time = integer time when request occurs
callSign = airline name
flightNumber = integer
size = small | large | heavy | super
requestType = landing | takeoff

Example Input (input.txt)
1 Delta 1243 heavy takeoff
1 AirCanada 973 heavy takeoff
5 Emirates 1598 super landing
8 Sunwing 556 large landing
10 Volaris 401 small takeoff
15 AirTransat 225 large landing
18 Delta 5225 heavy takeoff
18 UPS 785 super takeoff
18 Southwest 3355 heavy landing


## Example Output (1 Runway):
Simulation begins.... 
Time: 1->Delta 1243 (1) heavy ready for takeoff.
Time: 1->Delta 1243 (1) heavy cleared for takeoff on runway 1(time req. for takeoff: 3)
Time: 1->AirCanada 973 (2) heavy ready for takeoff.
Time: 4->Delta 1243 (1) heavy has cleared the runway 1
Time: 4->AirCanada 973 (2) heavy cleared for takeoff on runway 1(time req. for takeoff: 3)
Time: 5->Emirates 1598 (3) super inbound for Landing
Time: 7->AirCanada 973 (2) heavy has cleared the runway 1
Time: 7->Emirates 1598 (3) super cleared for landing on runway 1(time req. for Landing: 6)
Time: 8->Sunwing 556 (4) large inbound for Landing
Time: 10->Volaris 401 (5) small ready for takeoff.
Time: 13->Emirates 1598 (3) super has cleared the runway 1
Time: 13->Sunwing 556 (4) large cleared for landing on runway 1(time req. for Landing: 4)
Time: 15->AirTransat 225 (6) large inbound for Landing
Time: 17->Sunwing 556 (4) large has cleared the runway 1
Time: 17->AirTransat 225 (6) large cleared for landing on runway 1(time req. for Landing: 4)
Time: 18->Delta 5225 (7) heavy ready for takeoff.
Time: 18->UPS 785 (8) super ready for takeoff.
Time: 18->Southwest 3355 (9) heavy inbound for Landing
Time: 21->AirTransat 225 (6) large has cleared the runway 1
Time: 21->Southwest 3355 (9) heavy cleared for landing on runway 1(time req. for Landing: 5)
Time: 26->Southwest 3355 (9) heavy has cleared the runway 1
Time: 26->Volaris 401 (5) small cleared for takeoff on runway 1(time req. for takeoff: 1)
Time: 27->Volaris 401 (5) small has cleared the runway 1
Time: 27->Delta 5225 (7) heavy cleared for takeoff on runway 1(time req. for takeoff: 3)
Time: 30->Delta 5225 (7) heavy has cleared the runway 1
Time: 30->UPS 785 (8) super cleared for takeoff on runway 1(time req. for takeoff: 4)
Time: 34->UPS 785 (8) super has cleared the runway 1
##########################
Simulation ends at time 34.
Number of runways: 1
The total amount of time wasted because runways were not available: 52 minutes.
##########################
