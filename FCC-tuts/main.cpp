#include <iostream>


int addNumbers(int first_param, int second_param) {
    int result = first_param + second_param;
    return result;
}

int main(){
    int sum = addNumbers(10, 12);
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Sum: " << addNumbers(10, 1) << std::endl;

} 