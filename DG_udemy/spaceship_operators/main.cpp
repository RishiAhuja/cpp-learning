#include <iostream>
#include <compare>
//only available in c++20 and above
using namespace std;

int main(){
    int n1 {45};
    int n2 {45};
    int n3 {0};

    auto result = (n1 <=> n2);    
    cout << boolalpha;

    cout << "n1 > n2: " << ((n1 <=> n2) > 0)  << endl;
    cout << "n1 > n2: " << ((n1 <=> n2) < 0)  << endl;
    cout << "n1 == n2: " << ((n1 <=> n2) == 0)  << endl;

    //we can only compare the output of the spaceship operator with a literal 0, but not a int containing 0, so the following code will not work
    //cout << "n1 > n2" << ((n1 <=> n2) > n3)  << endl;

    //weak ordering

    std::string m1{"Hello"};
    std::string m2{"HELLO"};

    std::cout << std::boolalpha;
    std::cout << "m1 > m2 : " << (m1 > m2) << std::endl; // 
    std::cout << "m1 == m2 : " << (m1 == m2) << std::endl; // equivalence
    std::cout << "m1 < m2 : " << (m1 < m2) << std::endl; //

    return 0;
}