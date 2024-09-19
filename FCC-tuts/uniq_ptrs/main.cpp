#include <iostream>
#include <memory>
#include <iomanip>
#include "dog.h"
#include "person.h"

using namespace std;


void some_function(std::unique_ptr<Dog> dog){
    dog->print_dog();
}

void some_function2(std::unique_ptr<Dog> &dog){
    dog->print_dog();
}

std::unique_ptr<Dog> create_dog(){
    return std::make_unique<Dog>("Buddy");
}


int main(){
    //raw pointer

    // int * raw_pointer = new int {10};

    // cout << "pointer adress: " << raw_pointer << endl;
    // cout << "pointer adress: " << *raw_pointer << endl;

    // Dog * pdog1 {new Dog("Gunner")};

    // cout << "Dog name is: " << pdog1->get_name() << endl;
    // //unique pointer

    // std::unique_ptr<Dog> unique_pointer {new Dog("Fluffy")};

    // unique_pointer->get_name();


    // cout << "raw pointer managed by unique pointer: " << unique_pointer.get() << endl;
    


    // //avoiding the use of new in modern c++

    // std::unique_ptr<Dog> udogp2 = std::make_unique<Dog>("Rex");

    // cout << "Dog name is: " << udogp2->get_name() << endl;


    // //you can't copy unique pointers or make two unique pointers point the same memory location

    // //std::unique_ptr<Dog> updog3 = udogp2; //this will give an error

    // //though we can move the unique pointer and make a new pointer manage the same memory

    // //we can move the ownership of the memory to another unique pointer
    // cout << udogp2.get() << endl;


    // std::unique_ptr<Dog> updog3 = std::move(udogp2);
    // //now udogp2 is nullptr automatically

    // cout << updog3.get() << " | " << udogp2.get() << endl;


    // //resetting the unique pointer

    // updog3.release(); //this will release the memory and make the pointer nullptr

    // cout << updog3.get() << endl;

    // delete pdog1;
    // delete raw_pointer;



    // //will give error, because this will copy the unique pointer which is not allowed

    // std::unique_ptr<Dog> dog_up = std::make_unique<Dog>("Buddy");

    // // some_function(dog_up);

    // //solution 1 is to move the ownership of the unique pointer to the copied pointer in function scope, though this will make the original pointer nullptr

    // some_function(std::move(dog_up));

    // cout << "dog_up: " << dog_up.get()  << endl;

    // //we can perform a implicit move

    // some_function(std::make_unique<Dog>("Buddy"));

    // //we can pass the unique pointer by reference

    // std::unique_ptr<Dog> dog_up2 = std::make_unique<Dog>("Buddy2");
    // some_function2(dog_up2);

    // //making arrays and shit like that

    //stack

    // Dog stack_arr[] {Dog("Dog1"), Dog("Dog2"), Dog("Dog3"), Dog("Dog4")};

    // for(Dog elem : stack_arr){
    //     cout << elem.get_name() << endl;
    // }

    //heap

    // Dog* heap_arr = new Dog[2]{Dog("Dog1"), Dog("Dog2")};

    // for (size_t i = 0; i < 2; i++)
    // {
    //     heap_arr[i].print_dog();
    // }
    
    // delete[] heap_arr;

    //unique

    auto uniq_arr = std::unique_ptr<Dog[]>(new Dog[2]{Dog("Dog1"), Dog("Dog2")});

    for (size_t i{0} ; i < 2 ; ++i){
        uniq_arr[i].print_dog();
    }












    std::unique_ptr<Dog[]> dog_up_arr = std::unique_ptr<Dog[]>(new Dog[3]{Dog("1"), Dog("2"), Dog("3")});
}