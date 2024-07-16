#include <iostream>
#include "constants.h"
#include "cylinder.h"

using namespace std;

int main()
{

    //Making object in stack memory
    cylinder c1(10, 4);

    cout << "C1 volume: " << c1.volume() << endl;


    //Making object in heap memory

    cylinder* c2 = new cylinder(10, 5);

    cout << "C2 volume: " << (*c2).volume() << endl;
    cout << "C2 volume: " << c2->volume() << endl;

    delete c2;
}