#include <iostream>

int main ()
{
    //2 bytes
    short int var1 {10}; 
    short int var2 {20};

    auto result {var1 + var2};

    std::cout << sizeof(result) << std::endl;

}

