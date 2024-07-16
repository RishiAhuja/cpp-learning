#include <iostream>
using namespace std;

int main ()
{

    char message [] {'H', 'e', 'l', 'l', 'o'};

    // for (char element : message){
    //     cout << element << endl;
    // }

    //improper null termination
    cout << message << endl;


    //compiler automatically adds a null correction
    //these are called literal C-strings
    char m2 [] = "Hello";
    cout << m2 << endl;
    
    for (size_t i {0}; i < std::size(m2); ++i)
    {
        cout << m2[i] << endl;
    }

    //manually adding null termination

    char m3 [] {'H', 'e', 'l', 'l', 'o', '\0'};

    cout << m3 << endl;

    //: Null-terminated strings are memory-efficient because 
    //the length of the string does not need to be stored separately.
    // The null terminator marks the end of the string, so the length 
    //can be determined as needed. This is in contrast to length-prefixed strings,
    // which require additional storage for the length. 

    //another way of null termination

    char m4[6] {'H', 'e', 'l', 'l', 'o'};
    //we made a 6 size array, and defined only 5, hence the 6th character is 
    //automatically initialized with 0, and 0 is `ASCII` table is a null char

    cout << m4 << endl;

}