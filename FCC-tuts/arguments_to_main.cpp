#include <iostream>

using namespace std;

int main(int argc, char* agrv[])
//(int agrc, char* argv[]) //array of character pointers
{
 cout << "We have " << argc << " parameters in our program" << endl; //1
 //the parameter is the name of the program

 for (size_t i = 0; i < argc; i++)
 {
    cout << "Parameters at the index: " << i << " : " << agrv[i] << endl;
 }
 
}