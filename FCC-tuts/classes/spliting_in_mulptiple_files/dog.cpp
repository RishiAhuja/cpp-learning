#include "dog.h"

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param){
    name = name_param;
    breed = breed_param;
    
    //made in heap memory
    p_age = new int;
    // p_age = &age_param;
    *p_age = age_param;
}