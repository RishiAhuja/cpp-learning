#include <iostream>
#include "person.h"

using namespace std;


int main()
{

    Person p1{"rishi", "ahuja", 20};
    Person p2{"ashu", "dev", 15};
    Person p3{"aastik", "abc", 22};

    Person array []{p1, p2, p3};

    for (Person s : array)
    {
        s.set_first_name("Rishabh");
    }
    
    cout << p1.get_first_name() << endl;


}