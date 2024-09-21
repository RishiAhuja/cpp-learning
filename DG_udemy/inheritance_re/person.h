#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person{
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
    //private:  //will change the access specifier to protected
    protected:
    //still inaccesible from outside but accessible from the inherited classes.
        std::string m_first_name {"default fn"};
        std::string m_last_name {"default ln"};
        int * m_age = new int{40};

    public:
        Person() = default;
        Person(std::string p_fn, std::string p_ln, int p_age);
        ~Person();

        //getters as setter
        std::string& getFirstName();
        std::string& getLastName();
        int& getAge();
};

//stream insertion operator

std::ostream& operator<<(std::ostream& os, const Person& p);

#endif