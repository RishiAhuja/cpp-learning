#include <iostream>
#include "dog.h"

using namespace std;

int main()
{

   Dog dog1("Fluffy", "Shepherd", 2);

   cout << dog1.name() << endl;
   dog1.name() = "Oreo"; 

   const Dog dog2("Milou", "Shepherd", 3);

   dog2.print_info();

    
}