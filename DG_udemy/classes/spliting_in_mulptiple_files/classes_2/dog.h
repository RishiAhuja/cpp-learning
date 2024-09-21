#ifndef DOG_H
#define DOG_H

#include <string>
#include <iostream>

using namespace std;

class Dog
{
private:
    std::string m_name;
    std::string m_breed;
    unsigned int m_age;
    mutable size_t print_info_count{0};

public:
    Dog() = default;
    Dog(const string &name_param, const string &breed_param, unsigned int age_param);
    ~Dog();

    // member functions

    // working as both setters and getters
    std::string &name()
    {
        return m_name;
    }

    // overloading for const objects
    // will eturn a const reference hence it can't be used to change the member variable, hence this function can be flagged as const because it will never be used to change a memeber variable.
    const std::string &name() const
    {
        return m_name;
    }

    // example for dangling pointers and references

    // const string &dangling_references()
    // {
    //     const string &info{"LOL"};
    //     // here we will return a reference which to a varibale which will die after returning, hence we are ereferencing to a dangling pointer

    //     return info;
    // }

    // const string* dangling_pointers()
    // {
    //     const string info{"LOL"};
    //     // here we will return a reference which to a varibale which will die after returning, hence we are ereferencing to a dangling pointer
    //     return &info;
    // }

    void print_info () const{
        //might want to make and exception for debugging purposes in a const function then use mutable member variable.
        ++print_info_count;
        cout << 
            "Name: " << m_name << ", " << "breed: " << m_breed << ", " 
            << "age: " << m_age << ", " 
            << "print count: " << print_info_count << endl; 
    }
    // old getter
    //  std::string get_name()
    //  {
    //      return m_name;
    //  }
};

#endif