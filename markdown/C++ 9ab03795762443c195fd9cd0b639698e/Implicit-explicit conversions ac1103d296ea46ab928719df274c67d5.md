# Implicit-explicit conversions

**Implicit conversions:**

Implicit conversion, also known as automatic type conversion or coercion, occurs when the compiler automatically converts one data type to another without explicit instructions from the programmer. This usually happens in situations where a smaller data type is assigned to a larger data type to prevent data loss.

```cpp
double price {45.6};
int units {10};

auto total = price * units;
```

Implicit conversions occurs from smaller to larger, hence converting `int` to `double`. 

**Explicit conversions:**

Explicit conversion, also known as type casting, requires the programmer to specify the conversion. This is done using casting operators or functions, allowing for precise control over how data types are converted. 

- C++ Named Casts:
    
    ```cpp
    double x1{25.6};
    double y1{22.5};
    int sum;
    
    sum = static_cast<int>(x1) + static_cast<int>(y1);
    ```
    
- C-style Casting:
    
    ```cpp
    double PI{3.14};
    int int_pi = (int)(PI);
    ```
    

**Overflow:**

Overflow happens when the result of an operation is too large to 
be stored in a variable of a particular data type. For example, if you 
try to store a value greater than the maximum value of an `int` (typically 2,147,483,647 on a 32-bit system), an overflow will occur.

```cpp
int x = 2147483647;
x = x + 1; 
// Overflow occurs, x becomes -2147483648
```

**Underflow:**

Underflow occurs when the result of an operation is too small to 
be stored in a variable of a particular data type. This typically 
happens when you try to store a value smaller than the minimum value of a signed data type. For example, if you subtract 1 from the minimum value of a `short` (usually -32,768), an underflow will occur.

```cpp
short y = -32768;
y = y - 1; 
// Underflow occurs, y becomes 32767
```