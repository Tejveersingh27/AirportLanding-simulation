//-----------------------------------------
     // NAME		: Tejveer Singh Ghataurey
     // STUDENT NO.	: 7993537
     // COURSE		: COMP 2150
     // INSTRUCTOR	: Heather Matheson
     // ASSIGNMENT	: 2
     // SECTION     : A01
     // 
     // REMARKS: The purpose is to create event driven simulation mimicking airport traffic control
     // which processing takeoff and Landing event and calculating any time wasted
     //
     //-----------------------------------------
#include "EventDrivenSimulation.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Wrong format\n";
        return 1;
    }

    string fileName = argv[1];
    int num = stoi(argv[2]);

    EventDrivenSimulation simulation(fileName, num);
    simulation.run();

    return 0;
}
