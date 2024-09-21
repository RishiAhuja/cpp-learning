#include <iostream>
#include "person.h"
#include "player.h"

using namespace std;

int main()
{

    Person p1("John", "Doe", 30);
    cout << p1 << endl;
    Player player1 ("Badminton", "Rishi", "Ahuja", 16);
    cout << player1 << endl;
    return 0;

}