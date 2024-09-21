#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
class Person
{

private: 
    std::string first_name;
    std::string last_name;
    int * age;
public: 
    Person() = default;
    ~Person();
    Person(const std::string &first_name_param, const std::string &last_name_param, int age_param);
    Person(const Person &source_p);

    //setter and getters

    std::string& get_first_name();
    std::string& get_last_name();
    int get_age();

    // Utilities
    void print_info()
    {
        std::cout << "Person object at : " << this
                  << " [ Last_name : " << last_name
                  << ", First_name :  " << first_name
                  << " ,age : " << *age
                  << " , age address : " << age
                  << " ]" << std::endl;
    }

};

#endif