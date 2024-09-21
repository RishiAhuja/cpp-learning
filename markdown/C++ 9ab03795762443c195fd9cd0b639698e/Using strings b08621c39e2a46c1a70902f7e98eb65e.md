# Using strings

The `std::string` class in C++ is the standard representation for text strings. 

**Defining a `std::string`**:

```cpp
#include <iostream>
#include <string>

int main() {
    std::string str {"C++ String"};
    std::cout << str << std::endl; // Outputs: C++ String
}
```

Can be initialized as a part of string literal: 

```cpp
std::string message ("Hello there", 5);
//only the first 5 characters will be considered
```

Can be initialized with multiple copies of `char`:

```cpp
std::string message (4, 'e');
//will be initialized with eeee
```

Other ways:

```cpp
std::string saying_world (greeting, 6, 5);
//will pick up at the 6th index of `greeting` 
//and will continue till the next 5 characters
```

**Using raw arrays:**

Here we are pointing to a new string at 2nd line, and wasting the allocated memory of the pointer:

```cpp
char *message3 {"This is a string"};
message3 = "Changing this string";
```

**Advantages of `std::string` over C-style strings**:
`std::string` provides automatic memory management, avoiding the need to manually allocate and free memory.

`std::string` has built-in length and other useful properties, whereas with C-style strings you need to use functions like `strlen()` to get the length.

```cpp
//Lenght can be changed at the runtime

std::string planet {"Earth"};
planet = "Lmao this is a very very very string";
```