#include <iostream>
using namespace std;

class Dog
{
private:
    std::string name;
    std::string breed;
    int *p_age{nullptr};

public:
    Dog() = default;
    Dog(std::string_view name_param, std::string_view breed_param, int age_param);

    // getter function:
    std::string get_name()
    {
        return name;
    };
    //usecase of `this` for conflicting names

    Dog* set_name(std::string name){
        this->name = name;
        return this;
    }
    Dog* set_breed(std::string breed){
        this->breed = breed;
        return this;
    }
    Dog* set_age(int age){
         *p_age = age;
        return this; //returning pointers of the current object, so that we can do chained changes.
    }

    void print_info()
    {
        cout << "Name: " << name << endl;
        cout << "Breed: " << breed << endl;
        cout << "Age: " << *p_age << endl;
    }

    // a destructor
    ~Dog();
};

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param)
{
    name = name_param;
    breed = breed_param;

    // made in heap memory
    p_age = new int;
    // p_age = &age_param;
    *p_age = age_param;
    // cout << "Dog constructor called: " << name << " :constructed at: " << this << endl;
    // this provides the adress of the current constrcutor being used.
}

Dog::~Dog()
{
    // releasing memory to avoid memory leak
    delete p_age;
    // cout << "Deleted heap memory via destructor: " << name << endl;
}

int main()
{
    Dog dog1("Doggy1", "pug", 2);
    Dog dog2("Doggy2", "pug", 2);
    Dog dog3("Doggy3", "pug", 2);
    Dog dog4("Doggy4", "pug", 2);
    
    dog1.print_info();
    //setting things via chain
    dog1.set_age(10)->set_breed("shepherd")->set_name("Yugam");
    dog1.print_info();

    cout << "main function is ending, hence desctructor might be called after the end of scope" << endl;
}