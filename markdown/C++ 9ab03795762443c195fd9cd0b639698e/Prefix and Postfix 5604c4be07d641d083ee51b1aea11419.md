# Prefix and Postfix

In C++, prefix and postfix operators are used to increment or decrement variables. The main difference between prefix and postfix operators lies in the order in which the increment or decrement operation is performed and the value returned.

**Increment & Decrement** 

```cpp
int value {5};

//for incrementing 

value = value + 1
value = value + 3

//for decrementing

value = value - 1
value = value - 3
```

**PostFix**

Postfix operators are used when the increment or decrement operation is performed after the value is used.

```cpp
int value {5};

std::cout << value << std::endl;
std::cout << value++ << std::endl;
std::cout << value << std::endl;
```

```cpp
//output

5
5
6
```

while reading the 2nd `std::cout` statement, it returned 5, but incremented after returning, hence in the next line, it returns 6.

**Prefix**

Prefix operators are used when the increment or decrement operation is performed before the value is used. This means that the value is incremented or decremented first, and then the updated value is returned.

```cpp
int value {5};

std::cout << value << std::endl;
std::cout << ++value << std::endl;
std::cout << value << std::endl;
```

```cpp
//output

5
4
4
```

while reading the 2nd `std::cout` statement, it returned 4 but incremented before returning.

**Compound operators**

The main compound assignment operators in C++ are:

- `+=` (addition assignment)
- `=` (subtraction assignment)
- `=` (multiplication assignment)
- `/=` (division assignment)
- `%=` (modulus assignment)