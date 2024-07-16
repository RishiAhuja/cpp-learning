#include <iostream>

using namespace std;


const double PI {3.14159265358979323846};

class cylinder{

    //member variables
    private: 
        double radius {1.0};
        double height {1.0};

    public:

        //defaulted constuctor: 
        cylinder() = default;


        //a constructor
        //constructors have no return types
        //needs to have same name as the class

        //default constructor which doesn't takes any value will be called.
        // cylinder(){
        //     radius = 2.0;
        //     height = 2.0;
        // }
        //if nothing is passed the above constructor will be called, but now using this constructor we can design our object.

        //if we create any constructor, the compiler will not make a default constructor that it used to make, hence we will loose our ability to form objects without passing args.
        
        cylinder(double radius_param, double height_param){
            radius = radius_param;
            height = height_param;
        }
        //If we don't provide a constructor, compiler will generate a empty constructor
        double volume(){
            return PI * radius * radius * height;
        }
};

int main()
{
    cylinder cylinder1(10, 5); //called the default constructor when no arguments are passed

    //because we have a constructor, which doesn't takes any parameters, the compiler automatically used that to make an object 
    cout << cylinder1.volume() << endl; //25.13
}