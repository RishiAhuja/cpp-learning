#include <iostream>
using namespace std;


const int circle {10};
const int ellipse {20};
const int hyperbola {30};
const int rectangle {40};


int main ()
{
    int tool {rectangle};

    switch (tool)
    {
    case (circle): case (ellipse): case (hyperbola):
        {cout << "This is a shape" << endl;}
    break;
    
    // case (ellipse):
    // {cout << "This is a ellipse" << endl;}
    // break;

    // case (hyperbola):
    // {cout << "This is a hyperbola" << endl;}
    // break;
    
    default:
    {cout << "something else" << endl;}
        break;
    }


    //ternary expressions:

    //is else

    bool result {true};

    result = (20 > 10) ? true : false;

}