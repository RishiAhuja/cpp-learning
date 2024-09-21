#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using namespace std;

class Person{
    // private:
    protected:
        //protected access specifiers will allow to access private memeber variables of the base to to inherited class but still be inaccessible from outside
        string last_name{"person"};
        string first_name{"mysterious"};
    
    public: 
        Person() = default;
        Person(string_view& first_name_param, string_view& last_name_param);
        ~Person(){};

        //getters
        string get_first_name(){return first_name;}
        string get_last_name(){return last_name;}


        //setters
        void set_first_name(string_view first_name_param){first_name = first_name_param;}
        void set_last_name(string_view last_name_param){last_name = last_name_param;}
};

#endif