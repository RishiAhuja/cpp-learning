#include <iostream>

using namespace std;


class Dog
{

    friend void debug_dog_info(const Dog& d);
    friend class Cat;
    private:
        std::string m_name;
        int m_age;
    public:
        Dog(const std::string &name, int age) : m_name(name), m_age(age) {};

};
//to access the member variables of the class Dog, we need to make the function a friend of the class

void debug_dog_info(const Dog& d){

    cout << "Dog | name[" << d.m_name << ", age: " << d.m_age << "]" << endl;
}

class Cat{
    private:
        std::string m_name;
        int m_age;
    public:
        Cat(const std::string &name, int age) : m_name(name), m_age(age) {};

        void print_dog(const Dog& d){
            cout << "Dog | name[" << d.m_name << ", age: " << d.m_age << "]" << endl;
        }
};
int main() {
    Dog dog1("fluffy", 5);

    debug_dog_info(dog1);

    return 0;
}