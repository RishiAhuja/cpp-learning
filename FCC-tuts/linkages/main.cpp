#include <iostream>


using namespace std;

int myDistance {0};

extern const int myVar {0};

void print_var(); //internal linnkage by defualt


//flipped the linkage to internal
static void print_distance(){ //internal linkage

    cout << "Distance" << myDistance << endl;

} 



int main() {

    cout << "var" << myVar << endl;
    cout << "adress" << &myVar << endl;

    print_var();

    
    return 0;
}