// Pair with given Sum (Two Sum)

/*

Given an array A[] of n numbers and another number x,
the task is to check whether or not there exist two elements in A[] whose sum is exactly x.

*/

#include <iostream>

using namespace std;

bool check_sum(int arr[], int key, int size_arr)
{
    bool result = true;
    // arr[]={1, 4, -3, 5, 6} -> 1
    for (size_t i{}; i < size_arr; i++)
    {
        for (size_t j = 0; j < size_arr; j++)
        {
            if ((arr[j] + arr[i]) == key)
            {
                result = true;
                return result;
            }
        }
    }
    return 0;
}

int main()
{
    int my_arr[]{-2, 0, 4};
    int key{2};
    cout << std::boolalpha << check_sum(my_arr, key, size(my_arr)) << endl;
}
