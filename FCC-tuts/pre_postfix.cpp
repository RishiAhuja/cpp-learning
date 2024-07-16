#include <iostream>

int main(){


    //postfix 

    int value {5};

    std::cout << "postfixing" << std::endl;

    std::cout << value << std::endl;
    std::cout << value++ << std::endl;
    std::cout << value << std::endl;

    std::cout << "----------------" << std::endl;

    value = 5;
    std::cout << value << std::endl;
    std::cout << value-- << std::endl;
    std::cout << value << std::endl;


    std::cout << "----------------" << std::endl;

    value = 5;

    std::cout << "prefixing" << std::endl;

    std::cout << value << std::endl;
    std::cout << ++value << std::endl;
    std::cout << value << std::endl;

    std::cout << "----------------" << std::endl;

    value = 5;

    std::cout << value << std::endl;
    std::cout << --value << std::endl;
    std::cout << value << std::endl;
}