#include <iostream>
#include <concepts>

using namespace std;

//syntax 1:
// template <typename T>
// requires std::integral<T>
// T add(T a, T b)
// {
//     return (a+b);
// }

//#syntax 2:
// auto add(auto a, auto b){
//     return a+b;
// }

//syntax 3: 
template <typename T>
T add(T a, T b) requires std::integral<T>
{
    return (a+b);
}

int main()
{
    char a_0{10};
    char a_1{20};

    auto result_a = add(a_0, a_1);

    cout << "result_a" << static_cast<int>(result_a) << endl;

    int b_0{10};
    int b_1{20};

    auto result_b = add(b_0, b_1);

    cout << "result_b" << static_cast<int>(result_b) << endl;

    double c_0{10};
    double c_1{20};
    //can't build with double because we applied a constraint using concepts
    // auto result_c = add(c_0, c_1);

    // cout << "result_c" << static_cast<int>(result_c) << endl;
}