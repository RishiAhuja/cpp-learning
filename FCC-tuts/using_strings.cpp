#include <iostream>
#include <string>

using namespace std;

int main()
{
    std::string full_name;
    std::string planet {"Earth"};
    std::string preffered_planet {planet};

    std::string message {"Hello there", 5};
    //intialize with a part of a string literal

    std::string message2 {4, 'e'};
    //intialize with multiple copies of char

    std::string greeting {"Hello World"};

    std::string saying_world {greeting, 6, 5};
    //will pickup at 6th index of `greeting` and will continue till next 5 characters

    //lenght can be adjusted at runtime
    planet = "Lmao this is a very very very string";

    //using a raw array
    char *message3 {"This is a string"};
    message3 = "Changing this string";
    //here we are pointing to new string here, and wasting some memmory alloacted before, hence string is preferable


    cout << message2 << endl;
}
