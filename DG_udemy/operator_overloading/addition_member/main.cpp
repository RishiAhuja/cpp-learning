#include <iostream>
#include "point.h"

using namespace std;

int main() {

    Point p1(1, 2);
    Point p2(3, 4);
    //p1 + p2 = p1+operator(p2)
    Point p3 {p1 + p2};
    //p3.print_info();

    //(Point(10, 30) + Point(20, 40)).print_info();

    // cout << p1[0] << endl;
    // cout << p1[1] << endl;
    // p1[0] = 35; 
    // cout << p1[0] << endl;

    //std::cout << p1 << std::endl; //for free standing function
    //p1 << std::cout << std::endl; //for member function

    // //stream extraction
    // std::cin >> p1;
    // std::cout << p1 << std::endl;

    // cout << p1++ << endl;
    // ++p1;

    // std::cout << "p1 : " << p1++ << std::endl;

    Point p4(1, 2);
    Point p5(2, 4);

    // cout << p4 << endl;
    // cout << p5 << endl;

    // p4 = p5;

    // cout << p4 << endl;
    // cout << p5 << endl;
    cout << boolalpha;
    cout << (p4 > p5) << endl;
    return 0;
}