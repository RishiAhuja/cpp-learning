#include <iostream>
#include "cylinder.h"

using namespace std;

class Dog
{
private:
    std::string name;
    std::string breed;
    int *p_age{nullptr};

public:
    Dog() = default;
    Dog(std::string& name_param, std::string& breed_param, int age_param);

    // getter function:
    // std::string get_name() const
    // {
    //     return name;
    // };

    // std::string get_breed() const
    // {
    //     return breed;
    // };

    // int get_age() const
    // {
    //     return *p_age;
    // };

    // //setters

    // void set_name(string_view name){
    //     this->name = name;
    // }

    // void set_name(string_view breed){
    //     this->breed = breed;
    // }

    //getters as setters

    // std::string& name()
    // {
    //     return name;
    // }

    // a destructor
    ~Dog();
};

Dog::Dog(std::string& name_param, std::string& breed_param, int age_param)
{
    name = name_param;
    breed = breed_param;

    // made in heap memory
    p_age = new int;
    // p_age = &age_param;
    *p_age = age_param;
    cout << "Dog constructor called: " << name << " :constructed at: " << this << endl;
    // this provides the adress of the current constrcutor being used.
}

Dog::~Dog()
{
    // releasing memory to avoid memory leak
    delete p_age;
    cout << "Deleted heap memory via destructor: " << name << endl;
}

// void test_func(){

//     // cout << "constructing an object" << endl;
//     // Dog my_dog("Fluffy", "Pug", 5);
//     // cout << "object constructed sucessfully: " << my_dog.get_name() << endl;

//     // cout << "Scope of the test function is ending" << endl;

//     Dog *p_dog = new Dog("Fluffy", "pug", 3);
//     delete p_dog;
// }

// void accepting(const Dog &dog)
// {
// }

int main()
{
    // cylinder cylinder1(10, 10);

    // cout << "Volume: " << cylinder1.volume() << endl;

    // const Dog my_dog("Fluffy", "Pug", 5);
    // accepting(my_dog);
    // test_func();

    // Dog dog1("Doggy1", "pug", 2);
    // Dog dog2("Doggy2", "pug", 2);
    // Dog dog3("Doggy3", "pug", 2);
    // Dog dog4("Doggy4", "pug", 2);

    cout << "main function is ending, hence desctructor might be called after the end of scope" << endl;
}

/*

Dog constructor called: Doggy1
Dog constructor called: Doggy2
Dog constructor called: Doggy3
Dog constructor called: Doggy4
main function is ending, hence desctructor might be called after the end of scope
Deleted heap memory via destructor: Doggy4
Deleted heap memory via destructor: Doggy3
Deleted heap memory via destructor: Doggy2
Deleted heap memory via destructor: Doggy1

*/

/*
In C++, objects are destroyed in the reverse order of their construction when they go out of scope. This is known as the "stack unwinding" mechanism.
The object which was created early, here `doggy1`, other object might be depended on dog1 hence, this is latter.
*/