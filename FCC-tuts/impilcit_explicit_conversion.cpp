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

}