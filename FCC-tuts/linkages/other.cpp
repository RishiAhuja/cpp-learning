#include <iostream>

using namespace std;

extern const int myVar;

void print_var(){

    cout << "Other file var" << myVar << endl;
    cout << "Other file adress" << &myVar << endl;

}