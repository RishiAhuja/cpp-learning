#include <iostream>
using namespace std;

int main ()
{
    //references are alaisis to original varibales

    int num {38};
    int& r_num {num};

    cout << num << endl;
    cout << r_num << endl;
    cout << &num << endl;
    cout << &r_num << endl;
    
    r_num = 10;

    cout << num << endl;

    cout << sizeof(num) << endl;
    cout << sizeof (r_num) << endl;

    //you can't make a reference refer to something else once initialized
    // though you can make pointer point to some other address
    //hence refereces are somwwhat like const pointers

    //const references

    int number {80};

    const int& r_number {number};
    //cant use reference to change the original value

    /* const int*: This is a pointer to a constant integer. The pointer itself is not constant, 
    but the value it points to is constant and cannot be modified.
    const: This is the second const keyword, and it makes the pointer itself constant. 
    This means that the pointer cannot be modified to point to a different address.
    const_ptr_to_const_age: This is the name of the pointer variable, 
    which is a constant pointer to a constant integer.
    {&age}: This initializes the const_ptr_to_const_age
     pointer with the address of the age variable.*/

     int age {27};
    const int* const const_ptr_to_const_age {&age}

    //similar behavior to const reference

}