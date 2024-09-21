#include <iostream>

inline int age {12}; //unified definition
//confined the this TU


inline void some_func(){
    std::cout << "age: " << age << std::endl;
    std::cout << "&age: " << &age << std::endl;
}

void printing_age_from_util2()
{
    std::cout << "age: " << age << std::endl;
    std::cout << "&age: " << &age << std::endl;
}