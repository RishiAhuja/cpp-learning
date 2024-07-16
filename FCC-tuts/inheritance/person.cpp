#include "person.h"

Person::Person(string_view& first_name_param, string_view& last_name_param){
    last_name = last_name_param;
    first_name = first_name_param;
}