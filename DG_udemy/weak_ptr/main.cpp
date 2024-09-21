#include <iostream>
#include <memory>
#include "dog.h"
#include "person.h"


using namespace std;

int main() {

    std::shared_ptr<Dog> shared_ptr1 = std::make_shared<Dog>("Puffy");
    std::weak_ptr<Dog> weak_ptr (shared_ptr1);

    // cout << weak_ptr << endl;

    //we dont have dereference operator or pointer reference operator for weak_ptr * ->

    //use lock to convert weak_ptr to shared_ptr to access the memory

    std::shared_ptr<Dog> weak_locked_to_shared = weak_ptr.lock();

    cout << weak_locked_to_shared.get() << endl;
    cout << weak_locked_to_shared->get_name() << endl;

    //weak pointers are mainly used to solve cyclic dependency problem.
    std::shared_ptr<Person> p1 = std::make_shared<Person>("Ali");
    std::shared_ptr<Person> p2 = std::make_shared<Person>("Beth");
    p1->set_friend(p2);
    p2->set_friend(p1);

    /*
    Now when p1 goes out of scope, it will not release memory of ali, 
    because another shared pointer which is a class member variable of object p2 is pointing to p1.

    And when p2 goes out of scope, it will not release the memory of beth, because shared pointer of person member class
    of object ali is pointing to the p2.

    here we will leak memory.
    */
   
    return 0;
}