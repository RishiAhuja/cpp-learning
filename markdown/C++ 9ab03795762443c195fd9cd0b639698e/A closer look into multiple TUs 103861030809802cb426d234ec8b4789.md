# A closer look into multiple TUs

The multiple C++ files are first processed by a preprocessor which further creates compiler-readable translation units for each file which are fed to the compiler and the compiler creates object files for each TU which are further fed into a linker that combines these objects files into single TU.

To create object files the following commands can be used:

```cpp
gcc -c main.cpp dog.cpp
```

This will generate two object files `main.o`, `dog.o`.

To compile these files

```cpp
gcc -o rooster.out main.o dog.o
```

Declarations will be checked at the linkage stage.

**Linkages:**

1. No linkages:
    
    Identifiers with no linkage can only be accessed within the scope where they are declared. This typically applies to local variables within functions or blocks.
    
    ```cpp
    void function() {
        int localVar = 20; // no linkage
        /* localVar is accessible only 
        within this function*/
    }
    
    void anotherFunction() {
        int localVar = 30; 
        // different localVar, also no linkage
        /* this localVar is separate 
        from the one in function()*/
    }
    ```
    

1. Internal Linkages:
    
    Identifiers with internal linkage are only visible within the translation unit where they are defined. This means that the same identifier can exist in multiple translation units without conflict.
    
    Global `const` variables, `constexpr` variables, and variables declared with the `static` keyword have internal linkage by default.
    
    ```cpp
    // file1.cpp
    static int internalVar = 5; 
    // internal linkage
    
    // file2.cpp
    static int internalVar = 10; 
    /*another internalVar, 
    separate from file1.cpp*/
    ```
    

1. External Linkage:
    
    Identifiers with external linkage can be accessed from any translation unit in a program. This means that if a variable or function is declared with external linkage, it can be used in other source files using `extern` keyword. 
    
    Non-const global variables and functions have external linkage by default.
    
    ```cpp
    // file1.cpp
    int globalVar = 10; 
    // external linkage by default
    
    // file2.cpp
    extern int globalVar; 
    // can access globalVar from file1.cpp
    ```
    

**Flipping linkages:**

According to the above discussion, we can’t just use `const` variables in other TUs. To make this possible we can flip the linkages from internal to external or vice-versa. 

```cpp
//file1.cpp

extern const int myVar {0};
/*declared and defined the variable using 
the extern keyword to flip to linkage*/
//internal -> external

//file2.cpp
extern const int myVar;
/*can be accessed globally, and we created
a declaration to use the variable in another file*/

```

Similarly, we can flip the linkages from external to internal, let’s flip the linkage of functions that are defaulted to external linkage. This can be achieved either by using a `static` keyword in function declaration or by adding the function to an anonymous namespace.

```cpp
static void print_distance(){ 
//flipped linkage
    cout << myVar << endl;
} 
```

**Inline variables and functions:**

Sometimes we might want to use the same variables or functions with the same names in different files. We can violate the one-definition rule here using the `inline` keyword.

`utility1.cpp` 

```cpp
#include <iostream>
inline int age {12}; 
//unified definition
//confined the this TU

inline void some_func(){
    std::cout << "age: " << age << std::endl;
    std::cout << "&age: " << &age << std::endl;
}

void printing_age_from_util1()
{
    std::cout << "age: " << age << std::endl;
    std::cout << "&age: " << &age << std::endl;
}
```

`utility2.cpp` 

```cpp
#include <iostream>
inline int age {12};

inline void some_func(){
    std::cout << "age: " << age << std::endl;
    std::cout << "&age: " << &age << std::endl;
}

void printing_age_from_util1()
{
    std::cout << "age: " << age << std::endl;
    std::cout << "&age: " << &age << std::endl;
}
```

The variables and functions will be restricted to the TU where they are declared. but we can try to print the address of the variable to `main.cpp` using the non-inline functions and we will find out that the variables are registered on the same memory address. `inline` just unifies and optimizes the variables but essentially we are addressing the same memory address.

We might want to do this when We want to use a single utility file in multiple files, if we don’t `inline` the functions we will create multiple definitions in object files, and the linker will omit an error. 

Using inline vs anonymous namespace or statics is that, `inline` will just make them unified and we will be addressing the same memory in different TUs, though, anon namespaces will create different memory addresses in different TUs.

**Forward declarations:**

Forward declaration for classes is a powerful technique that allows you to declare a class before defining it. This is particularly useful for resolving circular dependencies and optimizing compile times.

Here in the farm class, we are only using a declaration of `Dog` class, hence we don’t need to import the full dog header file, We can just import the declaration to reduce overhead and compile time, but if we are creating a member variable of the dog class or using a function of the class then we need to import the full dog header.

```cpp
#ifndef FARM_H
#define FARM_H

class Dog; // Forward declaration
//#include "dog.h"

class Farm
{
public:
	Farm();
	~Farm();
	
	void use_dog(const Dog& dog_param); 
	// Doesn't require the definition

  //void do_something(const Dog& dog_param){
  //   dog_param.print_info();
  //}
private : 
    //Dog dog_member;
};

#endif //FARM_H
```