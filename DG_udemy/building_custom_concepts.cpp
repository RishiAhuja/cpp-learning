// #include <iostream>
// #include <type_traits>
// #include <concepts>

// using namespace std;

// //syntax 1: using type traits

// template <typename T>
// concept Myintegral = std::is_integral_v<T>;

// template <typename T>
// requires Myintegral<T>
// T add(T a, T b);  // Forward declaration

// int main() {
//     int x{6};
//     int y{8};

//     add(x, y);

//     return 0;
// }

// template <typename T>
// requires Myintegral<T>
// T add(T a, T b) {
//     return (a + b);
// }f