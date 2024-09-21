#include <iostream>
using namespace std;

class Dog{
    //by default the member variables are private:
    //can be easily overidden though
    string m_name;
};

struct Cat{
    //by default the member varibles are public: 
    string m_name;
    int age;
};

//size of class objects

//the size of an object is equal to the total size of the member variables
//and the size of the functions are not included in this because, they are the part of the classes as a bluprint for multiple objects

int main ()
{

}