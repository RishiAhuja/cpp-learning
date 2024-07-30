#include <iostream>
#include "square.h"
using namespace std;

bool compare (const Square& s1, const Square& s2)
{
    return (s1.area() > s2.area()) ? true : false;
}

int main()
{
    // Square sq1(10);
    // Square sq2(12);

    // cout << compare(sq1, sq2) << endl;

    //implicit conversion


    //as the object is just taking a single double parameter,
    //the compiler will try to impicitly convert the double to a temporary square object for comparison
    // cout << compare(sq1, 45.6) << endl;
    // cout << compare(sq1, 5.6) << endl;

    //To avoid this, we can make the constructor explicit

    // cout << compare(sq1, sq2) << endl;


    Square s1(10);

    s1.print_info();
}