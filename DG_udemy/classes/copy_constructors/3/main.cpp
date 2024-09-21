#include <iostream>
#include "point.h"
int main() {

    Point p1(10.0, 15.0);


    //creating a file from a temporary object


    //by default without a move constrcutor, it will use a copy constructor
    Point p2 (std::move(Point(20.0, 25.0)));

    Point p3 {10.6, 5.6};
    p3.print_info();


    return 0;
}