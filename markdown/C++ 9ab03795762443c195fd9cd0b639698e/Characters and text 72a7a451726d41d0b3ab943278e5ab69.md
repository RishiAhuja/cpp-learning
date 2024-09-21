# Characters and text

A `char` is a C++ data type designed for the storage of letters. It is an abbreviation for an 
alphanumeric character and is an integral data type, meaning the value is stored as an integer.

these integral storage in the character can be mapped to an `ASCII` table.

![Untitled](Characters%20and%20text%2072a7a451726d41d0b3ab943278e5ab69/Untitled.png)

```cpp
char a {'1'};
char a {31};
```

if we `std::cout` both will print, 1. & 31 can be mapped via 1 as a character in C++

**Getting ASCII value:** The ASCII value of a character can be obtained by using the `int()` function.

```cpp
char ch = 'a';
std::cout << "The ASCII value of " << ch << " is " << int(ch);
```

```cpp
//output

The ASCII value of a is 97
```

**Memory allocation:** 

- Chars are defined to always be 1 byte in size
- Chars can store values between 0 and 127, which includes all ASCII characters.

```cpp
char a {65};

std::cout << sizeof(char) << std::endl;
```

```cpp
//output 
1
```

**Interpreting as a integer** 

`static_cast<int>` can be used to interpret the char as an ASCII integer. 

```cpp
char a {65};
std::cout << "Value(int): " << static_cast<int>(a) << std::endl;
```

```cpp
//output
65
```