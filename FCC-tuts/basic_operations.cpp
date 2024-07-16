#include <iostream>

int main () {

    int v1 {12};
    int v2 {37};

    int v3 {v2/v1};
    int v4 {v2%v1};

    std::cout << v3 << std::endl;
    std::cout << v4 << std::endl;

}

