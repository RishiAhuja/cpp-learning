#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
    //declaring a pointer
    int * p_number {};

    //explictely intializing to nullptr

    int * p_number1 {nullptr};

    //all pointers have the same size
    //an int and a double pointer have the same sizes

    cout << sizeof(p_number1) << endl; //8bytes


    int an_int_var {24};
    int *p_int {&an_int_var};
    //&an_int_var adresses to the adress of the this variable

    int *p_int1, some_int {};

    // cout << p_number1 << endl;
    // cout << p_int1 << endl;
    // cout << some_int << endl;


    //dereferencing a pointer
    //reading something stored in a pointer

    int an_int {93};
    int *p_int_to_an_int {&an_int};

    //cout << *p_int_to_an_int << endl; //93 //accessing the integer through it's adress in the memory


    //declaring pointers to a char


    //chracter pointer as a string literal'
    //char *p_message {"Hello World"};

    //here the Hello world string is converted into an array and the pointer is referecing to the adress of the first character, here H


    /*cout << p_message << endl; //going to print out the whole string
    cout << *p_message << endl; //goind to print out the first character of the array H
    */



    char random {'R'};
    char *p_random {&random};

    cout << p_random << endl;
    cout << *p_random << endl;

}