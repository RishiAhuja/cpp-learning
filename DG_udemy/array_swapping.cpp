#include <iostream>

using namespace std;

//traditional method, and can be inefficient with large arrays.

void swapping_array_via_array(int arr1[], int arr2[], int size)
{
    int temp[size]{};

    for (size_t i{}; i < size; i++)
    {
        arr1[i] = temp[i];
        arr1[i] = arr2[i];
        arr2[i] = temp[i];
    }
    
    for (size_t i {}; i < size; i++)
    {
        cout << arr1[i] << endl;
    }
    
}

void swapping_array_via_pointers(int arr1[], int arr2[], int size)
{
    int *p_arr1[]{arr1}; //adressing to the first index of arr1
    int *p_arr2[]{arr2}; //adressing to the first index of arr2

    int *temp[]{};

    *temp = *p_arr1;
    *p_arr1 = *p_arr2;
    *p_arr2 = *temp;

    for (size_t i{}; i < size; i++)
    {
        cout << (*p_arr1)[i]<< endl;
    }

    cout << "-----------------------" << endl;
    
    for (size_t i{}; i < size; i++)
    {
        cout << (*p_arr2)[i]<< endl;
    }

    
}



int main()
{
    //swapping array via a arrays;
    int array1[]{1,2,3,4,5};
    int array2[]{6,7,8,9,0};

    // swapping_array_via_array(array1, array2, size(array1));

    //swapping via pointers
    swapping_array_via_pointers(array1, array2, size(array1));
}