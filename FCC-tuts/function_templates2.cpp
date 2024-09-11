#include <iostream>
#include <cstring>

using namespace std;


template <typename T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}

//specialization in function

template <>
const char* maximum<const char*>(const char* a, const char* b)
{
    return (strcmp(a, b) > 0) ? a : b;
}

//template with multiple typenames
//bad design, because of hardcoded return type
template <typename T, typename P>
T maximum2(T a, P b)
{
    return (a > b) ? a : b;
}

//better to add a third typename for the return type

template <typename ReturnType, typename P, typename R>
ReturnType maximum3(P a, R b)
{
    return (a > b) ? a : b;
}

//non-type template parameters
template <typename T, int size>
T maximum4(T a, T b)
{
    cout << size << endl;
    return (a > b) ? a : b;
}

//decltype

template <typename T>
auto some_function(T a, T b) -> decltype((a > b) ? a : b)
{
    return a;
}

//typenames with lambda functions

auto func = [] <typename T>(T a, T b) -> T {
    return a + b;
};  

//type traiting

template <typename T>
void some_func(T a){
    static_assert(std::is_integral<int>::value, "Fuck off");

    cout << a << endl;
}

int factorial(int n)
{
    if(n > 1)
    {
        return n * factorial(n-1);
    }
    else{
        return 1;
    }
}


enum class my_class{
    Jan, Feb, March
};



enum class Month : char{
    Jan, Feb
}; 

//type aliases

using HugeInt = unsigned long long int;

HugeInt huge_int = 10000000000000;

typedef unsigned long long int HugeI;

int main()
{
    // cout << maximum(10, 20.4) << endl;

    // cout << maximum<double>(10, 20.4) << endl; //will explicitly call the double specialization

    // cout << maximum3<double>(10, 20.4) << endl;
    // cout << maximum4<double, 10>(10, 20.4) << endl;

    // // cout << std::is_integral_v<int> << endl;

    // some_func(20);
    // some_func("Rishi");
    // some_func(20.0003);

    cout << factorial(5) << endl;

    my_class MyClass {my_class::Feb};

    Month month {Month::Feb};

    cout << huge_int << endl;
};
