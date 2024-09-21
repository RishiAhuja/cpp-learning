#include <iostream>

using namespace std;

int pass_by_value(int age);
int pass_by_pointer(int *age);
int pass_by_reference(int& an_alias_to_age);
int main ()
{   
    //pass by value
    int age {20};
    cout << "age: " << age << " " << " Adress: " << &age << endl;
    pass_by_value(age);
    cout << "age: " << age << " " << " Adress: " << &age << endl;

    //no effect on the actual age, because the age formed in the function was a copy and was killed as the scope ended.

    //pass by reference
    int age_inc {20};
    cout << "age: " << age_inc << " " << " Adress: " << &age_inc << endl;
    pass_by_pointer(&age_inc);
    cout << "age: " << age_inc << " " << " Adress: " << &age_inc << endl;

    //will affect the original varibale because it is changed with a memory adress


    //pass by reference
    int age3 {20};
    cout << "age: " << age3 << " " << " Adress: " << &age3 << endl;
    pass_by_reference(age3);
    cout << "age: " << age3 << " " << " Adress: " << &age3 << endl;    

    //will affect the original variable because it is changes with a reference pointing to the same memory adress
}

int pass_by_value(int age){
    cout << "Local incremented age: " << ++age << " " << " Adress: " << &age << endl;
    return 0;
}

int pass_by_pointer(int *age){
    cout << "incremented age by pointing to memory location: " << ++(*age) << " " << " Adress: " << &(*age) << endl;
    return 0;
}

int pass_by_reference(int& an_alias_to_age){
    cout << "An alias pointing to the same memory location: " << ++an_alias_to_age << " " << " Adress: " << &an_alias_to_age << endl;
    return 0;
}

