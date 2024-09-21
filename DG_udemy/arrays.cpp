#include <iostream>
using namespace std;

int main (){
/*
    //declaring an array

    int scores[10]; //declared a array with 10 integers

    //intializating array at declaration
    int numbers[5] {1, 3, 4, 7, 9};


    for (size_t i{0}; i < 5; ++i){
        cout << i << ": " << numbers[i] << endl;
    }


    //remaining elements initialing to zero

    int lists[6] {1, 4, 8};

    for (size_t i{0}; i < 6; ++i){cout << lists[i] << endl;}

    //auto ommiting sizes
    //compiler will automatically omit the size of the array
    int lists2 []{1, 2, 4, 6, 9};

    //range based for loop
    for (auto value : lists2){
        cout << value << endl;
    }


    //array can be declared constant
    const int lists3 []{1, 3, 5};

    // lists3[1] = 10; cant change 


    int sum_array [] {1,4,45,2,4,56,3,2,5,2,42};
    int sum {0};

    for(size_t element : sum_array){
        cout << element << endl;
        sum += element;
    }

    cout << sum << endl;

*/

//Querying size of an array on runtime

int my_array [] {0,4,4,3,2,6,4,4,9,4,2,8};

cout << std::size(my_array) << endl;

//ranged based
for (size_t element : my_array){
    cout << element << endl;
}


cout << endl;
//manual range based array

for(size_t i{0}; i < std::size(my_array); ++i){
    cout << my_array[i] << endl;
}


//alternative but hard way to find size of an array
cout << sizeof(my_array) << endl;

int no_of_elements = sizeof(my_array) / sizeof (my_array[0]);
cout << no_of_elements << endl;

}