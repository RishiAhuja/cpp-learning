#include <iostream>

using namespace std;

const double PI {3.14159265358979323846};

class cylinder {

    //part 1: will model the properties of the object
    //Member variables
    public : //if public is not specified, the functions of classes are private and can;t be accessed in the main function
        double base_radius {1.0};
        double height {1.0};
        //these can be stack variables or pointers but not references 
        //because reference can't be left uninitialized by any means and 
        //we will loose that ability

    //part 2: beheviours and functions which do things on the class using the properties
    public :
        double volume(){
            return (3.1459 * base_radius * base_radius * height);
        }
}; //semicolon!

int main()
{
    cylinder cylinder1; //object 1


    cout << cylinder1.volume() << endl;

    //object's runtime information
    // cylinder1.height = 2;
    // cylinder1.base_radius = 4;
    //can't access because the member varibles are private in the class

    cout << cylinder1.volume() << endl;

    double final_volume {cylinder1.volume()};

    cout << final_volume << endl;
}
