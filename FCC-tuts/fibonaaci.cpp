#include <iostream>
using namespace std;

int main()
{
 
    //fibonaaci series
//1 + 0 = 1
//1 + 1 = 2
//2 + 1 = 4
//1,1,2,3,5,8,13

    size_t intermediate {1};
    size_t sum {1};

    for (size_t i{}; i < 75; i++)
    {
        sum = sum + intermediate; //sum = 1
        intermediate = sum - intermediate;
        cout << sum << endl;
    }
    
}
