#include <iostream>
#include <memory>
#include "dog.h"

using namespace std;

//multiple pointer willl point to the same pointers
//say four pointers are pointing to the same data, and we will also have a reference count to keep track of how many pointers are pointing to the data
//when the reference count is 0, The data will be deleted

std::unique_ptr<Dog> get_dog()
{
    std::unique_ptr<Dog> dog = std::make_unique<Dog>("Tommy");
    return dog;
}

std::shared_ptr<int> int_ptr_accept(std::shared_ptr<int> p){
    cout << "int_ptr_accept: " << p.use_count() << endl;
    return p;
}


int main() {

    std::shared_ptr<int> shared_ptr {new int{100}};

    // cout << "shared_ptr: " << *shared_ptr << endl;
    // cout << "shared_ptr: " << shared_ptr.get() << endl;
    // cout << "shared_ptr: " << shared_ptr.use_count() << endl;


    //copying shared pointer
    std::shared_ptr<int> shared_ptr2 = shared_ptr;

    // cout << "shared_ptr2: " << shared_ptr2 << endl;
    // cout << "shared_ptr2: " << shared_ptr2.use_count() << endl;


    //using std::make_shared

    std::shared_ptr<int> shared_ptr3 = std::make_shared<int>(200);


    //using shared pointer to manage already existing memory

    int *p = new int{300};

    std::shared_ptr<int> ptr_managing_raw{p};

    //we can reset the shared pointer which will reduce the reference count

    ptr_managing_raw.reset();

    //shared pointers are also casteable to bools, if the pointer is pointing to something, it will return true, else false

    // if(shared_ptr) {
        // cout << "shared_ptr is pointing to something" << endl;
    // } else {
        // cout << "shared_ptr is not pointing to anything" << endl;
    // }



    //converting unique pointer to shared pointer

    std::unique_ptr<Dog> dog_up = std::make_unique<Dog>("Phil");
    std::shared_ptr<Dog> converted_shared_ptr = std::move(dog_up);

    // cout << "converted_shared_ptr: " << converted_shared_ptr->get_name() << endl;
    // cout << "converted_shared_ptr: " << converted_shared_ptr.use_count() << endl;
    // cout << "converted_shared_ptr: " << dog_up.get() << endl;

    //we can't do vice versa, we can't convert shared pointer to unique pointer

    //we can't directly assign unique pointer to shared pointer, we have to use std::move
    //though we can directly assign a uniques pointer to shared pointer which is returning from a function, this will do a implicit move

    std::shared_ptr<Dog> dog2 = get_dog();

    // cout << shared_ptr << endl;


    //settings array using shared pointers

    // std::shared_ptr<int[]> shared_ptr_arr = std::make_shared<int[]>(5, 5, 6); //not supported

    std::shared_ptr<int[]> shared_ptr_arr {new int[5]{5, 6, 7, 8, 9}};

    // cout << shared_ptr_arr[0] << endl;


    //passing shared pointers to functions

    std::shared_ptr<int> shared_ptr4 = std::make_shared<int>(400);
    cout << shared_ptr4.use_count() << endl;
    cout << int_ptr_accept(shared_ptr4) << endl;  
    cout << shared_ptr4.use_count() << endl;

    //passing by value or reference is valid
    //but returning from reference is not valid because the reference count will be increased by 1, and when the function goes out of scope, the reference count will be decreased by 1, which will make the reference count 0, and the data will be deleted

    return 0;
}