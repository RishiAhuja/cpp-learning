// Recursive Linear Search Algorithm

#include <iostream>
using namespace std;

// arr[]{10, 2, 5, 6, 3};
// key{6}

auto linear_search(int arr[], const int key, int arr_size)
{
    /*The std::size() function cannot determine the size of the array because the function parameter arr[] has been converted to a pointer, and the size information has been lost.*/

    // int index_arr{};
    // for (int i{}; i < arr_size; i++)
    // {
    //     if(arr[i] == key){
    //         index_arr = i;
    //     }
    // }
    // return index_arr;

    int index_arr[]{};

    for (int i{}; i < arr_size; i++)
    {
        if(arr[i] == key){
            int size_index_arr {sizeof(index_arr) / sizeof(index_arr[0])};
            index_arr[size_index_arr] = i;
        }
    }

    return index_arr;
};

int main()
{
    int my_arr[]{10, 5, 6, 67, 7, 3, 6, 2};
    int key {67};
    
    int size_of_return {
        sizeof(linear_search(my_arr, key, size(my_arr))) / sizeof(linear_search(my_arr, key, size(my_arr))[0])
    };

    for (size_t i{}; i < size_of_return; i++)
    {
        cout << "Found at index: " << linear_search(my_arr, key, size(my_arr))[i] << endl;
    }

}


//solved by using vectors