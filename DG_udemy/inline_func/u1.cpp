#include <iostream>

inline int age {12};

inline void some_func(){
    std::cout << "age: " << age << std::endl;
    std::cout << "&age: " << &age << std::endl;
}

void printing_age_from_util1()
{
    std::cout << "age: " << age << std::endl;
    std::cout << "&age: " << &age << std::endl;
}