#include "person.h"

Person::Person(const std::string &first_name_param, const std::string &last_name_param, int age_param) : first_name(first_name_param), last_name(last_name_param), age(&age_param)

Person::get_first_name()
{
    return first_name;
}

Person::~Person()
{
    delete age;
}

Person::get_last_name {
        return first_name; 
    }

Person::get_age(){
        return *age;
    }

Person::Person(const Person &source_p){
    first_name = source_p.get_first_name();
    last_name = source_p.get_last_name();
    age = new int(source_p.get_age());

}
