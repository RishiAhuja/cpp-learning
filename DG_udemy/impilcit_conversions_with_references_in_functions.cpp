#include <iostream>

void increment(int& value);
void print_out(const int & value);

int main(){
   double double_var{3.6};

//    int data = double_var;

//    increment(data); ///will get compiler  error
   print_out(double_var);
    
    return 0;
}

void increment(int& value){
    value++;
	std::cout << "value incremented to : " << value << std::endl;
}

void print_out(const int& value){
    std::cout << "value : " << value << std::endl;
}