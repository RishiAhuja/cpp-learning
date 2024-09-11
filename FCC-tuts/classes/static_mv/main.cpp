#include <iostream>
#include "point.h"
using namespace std;


//Static member variables are shared by all objects of the class
// they die when the program ends not when the object dies.
//Static member functions are not tied to an object, they are tied to the class.


int main() {

    cout << "Point count: " << Point::m_point_count << endl;
    Point p1(3, 4);
    Point p2(21.8, 56.7);

    p1.print_info();
    p2.print_info();
    
    cout << "Point count: " << Point::m_point_count << endl;

    return 0;
}