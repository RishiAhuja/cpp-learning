//Program to find sum of elements in a given array

#include <iostream>

using namespace std;

int main()
{
    int input[]{10, 30, 34, 53, 5, 32, 42};
    int result {};
    for (size_t i{}; i < std::size(input); i++)
    {
        result += input[i];
    }
    
    cout << "Sum: " << result << endl;
}