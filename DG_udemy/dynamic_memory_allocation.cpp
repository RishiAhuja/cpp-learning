#include <iostream>
using namespace std;


int main ()
{
    /*
    //stack
    int number {22};

    int *p_number = &number;

    cout << "number (stack): " << number << endl;
    cout << "p_number (adress): " << p_number << endl;
    cout << "&number (adress): " << &number << endl;
    cout << "deference *p_number: " << *p_number << endl;

    */


   //dynamic heap memory allocation

/*
    int *p_number {nullptr};
   
    p_number = new int;

    cout << p_number << endl; 
    cout << *p_number << endl; 

    *p_number = 77;

    cout << *p_number << endl;

    //releasing memory to the system
    delete p_number;
*/

    int *p_number {new int};
    int *p_number2 {new int{22}};

    delete p_number2, p_number;
    p_number, p_number2 = nullptr;


    //we can resuse poimters again and allocate them new memory under same pointer

    p_number = new int {80};

    return 0;
}