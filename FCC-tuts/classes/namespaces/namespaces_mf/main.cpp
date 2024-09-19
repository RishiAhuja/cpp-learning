#include <iostream>

// #include "point.h"
// #include "line.h"

using namespace std;

double add(double a, double b){
    return a + b;
}


namespace my_random
{
    double add(double a, double b){
        return a + b - 1;
    }

    void print_add(){
        std::cout << add(10, 20) << std::endl;
        std::cout << ::add(10, 20) << std::endl;
    }
} // namespace random


namespace Hello {
    unsigned int age {10};


    void print(){
        std::cout << World::add(10) << std::endl;
    }


    namespace World{
        double add (double a) {
            return a + age;
        }
    }
}

namespace Level1 {
    namespace Level2 {
        namespace Level3 {
            void print(){
                std::cout << "Hello from Level3" << std::endl;
            }
        }
    }
}

int main (){
    
    // Geom::Point p1(1, 2);
    // Geom::Point p2(5, 6);

    // p1.print_info();
    // p2.print_info();

    // Geom::Line l1(p1, p2);

    // l1.print_info();  

    // cout << my_random::add(10, 20) << endl;  
    // cout << add(10, 20) << endl;  

    my_random::print_add();

    return 0;
}