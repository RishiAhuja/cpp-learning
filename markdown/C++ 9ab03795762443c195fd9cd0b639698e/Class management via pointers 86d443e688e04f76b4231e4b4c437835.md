# Class management via pointers

Class objects can also be made in heap memory, just like other data types in C++.

Making objects in stack memory:

```cpp
cylinder c1(10, 4);
cout << c1.volume() << endl;
```

Making objects in heap memory:

You can directly use `->` notation to point to a member function from the pointer without de-referencing it.

```cpp
{ 	
	cylinder* c2 = new cylinder(10, 5);
  cout << (*c2).volume() << endl;
  cout << c2->volume() << endl;
	delete c2;
}
```

## Using this pointer:

the `this` pointer is a 
special pointer available within non-static member functions of a class. It points to the object for which the member function is called, 
allowing access to the object's members and methods.

Class in question:

```cpp
class Dog{
private:
    std::string name;
    std::string breed;
    int *p_age{nullptr};
public:
    Dog() = default;
    Dog(std::string_view name_param, 
    std::string_view breed_param, 
    int age_param);

    /*getter-functions ..*/
       
    //use case of `this` for conflicting names
    Dog set_name(std::string name){
        this->name = name;
        return this;
    }
    /*...*/
    ~Dog();
};
```

1. Disambiguation of Member Names:
    
    When a parameter name is the same as a member variable name, the `this` pointer can be used to distinguish between them.
    
    ```cpp
    Dog set_name(std::string name){
        this->name = name;
        return this;
    }
    ```
    
    Here `this->name` refers to the non-static member variable of this object.
    
2. Returning `this` for Method chaining:
    
    We can return `this` pointer in each setter function, to chain the use of them. The return type will be a pointer of an object to this class, here `Dog*`
    
    ```cpp
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
        return this;
    }
    ```
    
    Now we can perform Method chaining:
    
    Here, every member function can be used as a pointer to the current object, and use that to access another member function.
    
    ```cpp
    dog1.set_age(10)->
    set_breed("shepherd")->set_name("oreo");
    ```