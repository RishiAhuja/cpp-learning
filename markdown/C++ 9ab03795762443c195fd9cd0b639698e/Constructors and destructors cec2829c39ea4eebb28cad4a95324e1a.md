# Constructors and destructors

Constructors in C++ are special member functions that are automatically invoked when an object of a class is created. They are essential for initializing the object's data members and setting up its initial state.

Constructors have no return types and they need to be named after their respective class.

1. Default constructor:
    
    A default constructor is a constructor that does not take any 
    parameters. It initializes the object with default values. If no 
    constructor is defined, the C++ compiler automatically provides a 
    default constructor. But if you provide any other kind of constructor, the C++ compiler revokes its own default constructor.
    
    ```cpp
    class cylinder{
        //member variables
        private: 
            double radius {1.0};
            double height {1.0};
        public:
            //default constructor: 
            cylinder() = default;
            double volume(){
                return PI * radius * 
                radius * height;
            }
    };
    ```
    

1. Parameterized Constructor:
    
    A parameterized constructor allows you to pass parameters to initialize the object with specific values. This is useful for creating objects with different initial states.
    
    ```cpp
    class cylinder{
        private: 
            double radius {1.0};
            double height {1.0};
        public:
            //default constructor: 
            cylinder() = default;
            cylinder(double radius_param, 
            double height_param){
                radius = radius_param;
                /*member variables 
                accessible in class*/
                height = height_param;
            }
            double volume(){
                return PI * radius * 
                radius * height;
            }
    };
    ```
    
    ```cpp
    //Making an object with constructor
    
    int main()
    {
        cylinder cylinder1(10, 5);
        cout << cylinder1.volume() << endl; 
        //25.13
    }
    ```
    

**Destructors:** are special member functions that are automatically invoked when an object of a class goes out of scope or is explicitly deleted. They are essential for resource management, allowing for the cleanup of resources before an object is destroyed.

A destructor has the same name as the class but is preceded by a tilde (`~`). For example, for a class named `Dog`, the destructor would be defined as `~Dog()`.

Destructors are called automatically when:

- An object goes out of scope (for local objects).
- The `delete` operator is called on a pointer to an object created with `new` in heap memory.
- The program ends and the objects are destroyed.

**Order of destruction:**

```cpp
Dog dog1("Doggy1", "pug", 2);
Dog dog2("Doggy2", "pug", 2);
Dog dog3("Doggy3", "pug", 2);
```

This will be the order of construction and destruction:

```cpp
constructor called: Doggy1
constructor called: Doggy2
constructor called: Doggy3

scope ending

destructor called: Doggy3
destructor called: Doggy2
destructor called: Doggy1
```

In C++, objects are destroyed in the reverse order of their construction when they go out of scope. This is known as the "stack unwinding" mechanism. The object that was created early, here `doggy1`, is another object that might be dependent on `doggy1` hence, this is deleted later.

## Setters and getters

Setters and getters are essential components of data encapsulation in C++. They provide a way to access and modify private data members of a class while maintaining control over the data integrity.

Getters, also known as accessors, are public member functions that allow you to retrieve the values of private data members.

```cpp
//Getters
double get_radius() const{
    return radius; 
    //returning a copy
}
double get_height() const{
    return height; 
    //returning a copy
}
```

Setters, also known as mutators, are public member functions that allow you to modify the values of private data members. 

```cpp
//Setters
void set_radius(double radius_param){
    radius = radius_param;
}
void set_height(double height_param){
    height = height_param;
}
```

Setters and getters are part of the encapsulation principle in object-oriented programming, which aims to hide the internal implementation details of a class.