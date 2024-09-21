#include <iostream>
#include "person.h"

Person::Person(std::string p_fn, std::string p_ln, int p_age): m_first_name(p_fn), m_last_name(p_ln), m_age(new int(p_age)) {
    std::cout << "Constructor was called: " << this << std::endl;
}
Person::~Person(){
    delete this->m_age;
};

//getters as setter
std::string& Person::getFirstName() {
    return this->m_first_name;
}
std::string& Person::getLastName() {
    return this->m_last_name;
}
int& Person::getAge() {
    return *(this->m_age);
}

std::ostream& operator<<(std::ostream& os, const Person& p){
    os << "Person: [First name: " << p.m_first_name << ", Last name: " << p.m_last_name << ", Age: " << *(p.m_age) << "]";
    return os;
}