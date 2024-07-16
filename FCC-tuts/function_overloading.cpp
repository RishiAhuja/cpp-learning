#include <iostream>

using namespace std;

//only changing the return type wont make it overload, because, to make the signature unique we also need to change the argument types

//three overloads of a same function
int max(int a, int b){
    cout << "Integer overload called" << endl;
    return (a > b) ? a : b;
}

double max(double a, double b){
    cout << "Double overload called" << endl;
    return (a > b) ? a : b;
}

std::string_view max(std::string_view a, std::string_view b){
    cout << "string_view overload called" << endl;
    return (a > b) ? a : b;
}

int main()
{

    auto result {max(1235.566, 22.45)};

}
