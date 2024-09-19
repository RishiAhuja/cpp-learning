#include <iostream>


const double adjustment {0.45};


namespace funcs {
    double add(double a, double b) {
        return a + b;
    }
    double subtract(double a, double b) {
        return a - b;
    }
    double multiply(double a, double b) {
        return a * b;
    }
    double divide(double a, double b) {
        return a / b;
    }
}

namespace noadjust {
    double add(double a, double b) {
        return a + b;
    }
}

namespace adjust {
    double add(double a, double b);
}


int main() {

    std::cout << noadjust::add(1.0, 2.0) << std::endl;
    std::cout << adjust::add(1.0, 2.0) << std::endl;
    
    return 0;
}

namespace adjust {
    double add(double a, double b) {
        return a + b + adjustment;
    }
}