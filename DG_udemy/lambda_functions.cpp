#include <iostream>

using namespace std;

int main ()
{
    //lambda functions 
    
    // [] brackets = catchlist
    // () brackets = parameters
    // -> optional return type

    auto func = [](int a, int b){
        cout << "Lambda functions" << endl;
        return (a+b);
    }; 


    //function can be called manually
    int newint = {func(10, 20)};

    //expilcityly speciying return type

   auto explicitly_defined_return = 
    [](double a, double b)-> double{
        return (a+b);
    };


    //using capture lists
    
    int a = 10;
    int b = 20;

    auto capture_list_func = [a, b](){

        //global variable requested via capture lists can be edited in the scope of this lambda function
        cout << (a+b) << endl;

        //if we capture by value, we will have a copy of the variable inside the lambda func
        //similarly, if we capture by reference or pointer, we will be adressing to the same memory
    };


    //passing by value

    int c = 40;

    auto func2 = [c](){
        cout << "inner value: " << c << endl;
    };

    for (size_t i{}; i < 5; i++)
    {
        cout << "Outer value: " << c << endl;
        func2();
        //no change in inner value, because a copy was made at initalization inside func2
        ++c;
    }
    
    cout << endl;
    cout << "=================================" << endl;
    cout << endl;

    //passing by reference

    int d = 30;

    auto func3 = [&d](){
        cout << "Inner value: " << d << endl;
    };

    for (size_t i {}; i < 5; i++)
    {
        cout << "Outer value: " << d << endl;
        func3();
        ++d;
    }


    //to capture everything out of the scope of the lambda function

    // auto func4 = [=](){

    //     cout << a << endl;
    //     cout << b << endl;
    //     cout << c << endl;
    //     cout << d << endl;
    // };
    // func4();
    

    //to capture all by reference 
  auto func4 = [&](){

        cout << a << endl;
        cout << b << endl;
        cout << c << endl;
        cout << d << endl;
    };
    func4();

}