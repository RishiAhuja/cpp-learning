#include <iostream>
#include "player.h"

using namespace std;

int main()
{
    //a base class 
    //PERSON

    //classes which are childer of PERSON in inheritance tree and will inherit the features of PERSON class
    //ENGINEER DOCTOR 

    Player p1("Badminton");
    p1.set_first_name("Rishi");
    p1.set_last_name("Ahuja");
    p1.print_info();
    
}