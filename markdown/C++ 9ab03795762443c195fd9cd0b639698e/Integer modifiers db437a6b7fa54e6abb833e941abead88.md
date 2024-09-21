# Integer modifiers

1. **Signed:** Used for both positive and negative values. `int` by default is signed.
    
    ```cpp
    int var1 = -100
    signed var1 = -100
    ```
    
    so these both are same. The difference between `int var1 = -100;` and `signed int var1 = -100;` is minimal and mainly a matter of historical and technical considerations.
    
    **Historical context:** The `int` type in C++ is signed by default, meaning it can represent both positive and negative values. This is because the original C standard did not specify whether `int` should be signed or unsigned, leaving it up to the implementation. As a result, most implementations defaulted to signed integers. This convention has been carried forward in modern C++ standards.
    
2. **Unsigned:** Used for only positive values. It is used to increase the range of positive values.
    
    ```cpp
    unsigned int a = 9;
    unsigned int b = 0;
    ```
    
3. **Ranges of signed & unsigned** 
    
    
    | Unsigned range | 0 to 2^n - 1 |
    | --- | --- |
    | Signed range | - 2^(n-1) to 2^(n-1) - 1 |
    
    | type with modifier | bytes in memory | range |
    | --- | --- | --- |
    | unsigned int | 4 | [0, 4294967296] |
    | signed int  | 4 | [-2147483648, 2147483648] |

1. **Short:** Used for small integers. It reduces the memory size and is used for integers in the range -32768 to 32767.
    
    ```cpp
    short int short_var {-32767};
    
    std::cout << "Variable value: " << short_var << std::endl;
    std::cout << "Variable size: " << sizeof(short_var) << std::endl;
    ```
    
    ```cpp
    //output
    Variable value: -32767
    Variable size: 2
    ```
    
    only stores 2 bytes of memory 
    
    so the range for short is:
    
    | type with modifier | bytes in memory | range |
    | --- | --- | --- |
    | unsigned int | 2 | [0, 65535] |
    | signed int  | 2 | [-32768, 32767] |

1. **Long:** Used for large integers. It increases the memory size and is used for integers in the range -2147483647 to 2147483647.
    
    ```cpp
    long int long_var {-2147483647};
    
    std::cout << "Variable value: " << long_var << std::endl;
    std::cout << "Variable size: " << sizeof(long_var) << std::endl;
    ```
    
    ```cpp
    //output
    Variable value: -2147483647
    Variable size: 8
    ```
    
    only stores 2 bytes of memory 
    
    so the range for short is:
    
    | type with modifier | bytes in memory | range |
    | --- | --- | --- |
    | unsigned int | 4 or 8 | [0, 4,294,967,295] |
    | signed int  | 4 or 8 | [-2147483647, 2147483647] |
    
    The size of a `long` variable in C++ can vary depending on the architecture and operating system. On a 64-bit system, a `long` variable can be 4 bytes or 8 bytes, depending on the compiler and the specific architecture.
    
    1. **long long**:
        
        
        | type with modifier | bytes in memory | range |
        | --- | --- | --- |
        | unsigned int | 8 | [0, 9223372036854775807] |
        | signed int  | 8 | [-18,446,744,073,709,551,615, 18,446,744,073,709,551,615] |
        

**Numeric Limits library:** 

importing the library: 

```cpp
#include <limits>
```

can provide maximum and minimum values of an auto can store.

```cpp
    std::cout << "range of short is from: " << std::numeric_limits<short>::min() << " to " << std::numeric_limits<short>::max() << std::endl;
    std::cout << "range of unsigned short is from: " << std::numeric_limits<unsigned short>::min() << " to " << std::numeric_limits<unsigned short>::max() << std::endl;
    std::cout << "range of unsigned int is from: " << std::numeric_limits<unsigned int>::min() << " to " << std::numeric_limits<unsigned int>::max() << std::endl;
    std::cout << "range of unsigned long is from: " << std::numeric_limits<unsigned long>::min() << " to " << std::numeric_limits<unsigned long>::max() << std::endl;
    std::cout << "range of unsigned long long is from: " << std::numeric_limits<unsigned long long>::min() << " to " << std::numeric_limits<unsigned long long>::max() << std::endl;
```

```cpp
range of short is from: -32768 to 32767
range of unsigned short is from: 0 to 65535
range of unsigned int is from: 0 to 4294967295
range of unsigned long is from: 0 to 4294967295
range of unsigned long long is from: 0 to 18446744073709551615
```