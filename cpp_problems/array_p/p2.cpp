//Program to find largest element in an Array

#include <iostream>
using namespace std;

int main()
{
    int input[]{559, 554, 3, 5, 3, 233, 533, 555, 33};
    int max {input[0]};

    for (size_t i{}; i < size(input); i++)
    {
        if(max < input[i]){
            max = input[i];
        }
    }

    cout << "Largest number: " << max << endl;
}
