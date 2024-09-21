#include <iostream>

int main (){

    int n1 {45};
    int n2 {60};

    std::cout << "Comparing variables" << std::endl;

    std::cout << std::boolalpha;
    std::cout << "n1 < n2: " << (n1 < n2) << std::endl;
    std::cout << "n1 >= n2: " << (n1 >= n2) << std::endl;
    std::cout << "n1 <= n2: " << (n1 <= n2) << std::endl;
    std::cout << "n1 > n2: " << (n1 > n2) << std::endl;

}