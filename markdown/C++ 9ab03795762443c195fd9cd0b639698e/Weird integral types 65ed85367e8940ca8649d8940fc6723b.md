# Weird integral types

Compilers are designed in a certain way that, you can’t perform arithmetic operations. hence the compiler automatically convert `short int` or `char` to a `int`:

```cpp
#include <iostream>

int main ()
{
    //2 bytes
    short int var1 {10}; 
    short int var2 {20};

    auto result {var1 + var2};
		//auto will be of 4 bytes due to conversion
		
    std::cout << sizeof(result) << std::endl;

}
```

```cpp
//output 

4
```