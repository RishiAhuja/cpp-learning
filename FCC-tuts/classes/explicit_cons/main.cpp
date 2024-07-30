#include <iostream>
#include "square.h"
using namespace std;

bool compare (const Square& s1, const Square& s2)
{
    return (s1.area() > s2.area()) ? true : false;
}

int main()
{
    Square s1(10); //will call one param constructor

    s1.print_info();

    //control will call the three param constructor, then the one param constructor
}