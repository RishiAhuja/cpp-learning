#include <iostream>
#include <limits>

int main () {
    
    std::cout << "range of short is from: " << std::numeric_limits<short>::min() << " to " << std::numeric_limits<short>::max() << std::endl;
    std::cout << "range of unsigned short is from: " << std::numeric_limits<unsigned short>::min() << " to " << std::numeric_limits<unsigned short>::max() << std::endl;


    std::cout << "range of unsigned int is from: " << std::numeric_limits<unsigned int>::min() << " to " << std::numeric_limits<unsigned int>::max() << std::endl;


    std::cout << "range of unsigned long is from: " << std::numeric_limits<unsigned long>::min() << " to " << std::numeric_limits<unsigned long>::max() << std::endl;
    std::cout << "range of unsigned long long is from: " << std::numeric_limits<unsigned long long>::min() << " to " << std::numeric_limits<unsigned long long>::max() << std::endl;


    long long unsigned int rangel {std::numeric_limits<unsigned long long>::max()};

    std::cout << std::scientific << rangel << std::endl;

    std::cout << std::scientific << 1.2345 << std::endl;

    int tester {127489};

    std::cout << std::boolalpha;
    std::cout << std::numeric_limits<int>::is_signed << std::endl;
    std::cout << std::numeric_limits<int>::has_infinity << std::endl;
}
