#include <iostream>

using namespace std;

int main()
{
    //impilicit conversions

    double price {45.6};
    int units {10};

    auto total = price * units;

    //impilicit coversion here occur from smaller to larger, to multiply both, 
    //compiler will convert int to double

    cout << "Total: " << total << endl;
    cout << "Total size: " << sizeof(total) << endl;
    

    //impilict connversion in assignements
    int x;
    double y {45.67};

    x = y;
    //will chop down decimals from y to make in an integer
    cout << "X: " << x << endl;
    cout << "Y: " << y << endl;

    //explicit coversion

    double x1{25.6};
    double y1{22.5};

    int sum;

    sum = static_cast<int>(x1) + static_cast<int>(y1);
    cout << sum << endl;

    sum = static_cast<int>(x1+y1);
    cout << sum << endl;


    //Old style C-Cast
    double PI{3.14};
    int int_pi = (int)(PI);
    cout << "PI: " << int_pi << endl;

    //overflow and underflow
    unsigned char data {250}; //can store till 255, after overflowing it will revert back from 0

    ++data;
    std::cout << "data : " << static_cast<int>(data) << std::endl;

    ++data;
    std::cout << "data : " << static_cast<int>(data) << std::endl;

    ++data;
    std::cout << "data : " << static_cast<int>(data) << std::endl;

    ++data;
    std::cout << "data : " << static_cast<int>(data) << std::endl;

    ++data; 
    std::cout << "data : " << static_cast<int>(data) << std::endl; // 255

    ++data;  // Overflow
    std::cout << "data : " << static_cast<int>(data) << std::endl; // 0


    data = 1;

    --data;
    std::cout << "data : " << static_cast<int>(data) << std::endl; //0

    --data;
    std::cout << "data : " << static_cast<int>(data) << std::endl; //255
}