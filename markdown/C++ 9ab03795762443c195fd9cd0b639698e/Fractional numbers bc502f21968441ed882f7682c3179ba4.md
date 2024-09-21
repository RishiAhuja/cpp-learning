# Fractional numbers

or floating point types

used to represent numbers with fractional parts in C++

| Type  | Size | Precision |
| --- | --- | --- |
| float  | 4 | 7 |
| double (default) | 8 | 15 |
| long double | 12 | >double |

**Precision:** 

```cpp
1.234567
```

the given number has a precision of 6 in decimal places

**Declaration and initialization of the variables:**

```cpp
float n1 {1.01010101010101010101f};
double n2 {1.01010101010101010101};
long double n3 {1.01010101010101010101L};
```

to initialize float, the initializer f should be given.

to initialize float, the initializer L should be given.

and double is the default. 

default precision g++ has a 5 decimal precision. to `std::cout` the full length, we need to set the precision high manually. 

we need to import a library called `iomanip`

```cpp
#include <iomanip>

std::cout << std::setprecision(20);
```

**Narrowing conversions:**

```cpp
std::cout << "n1: " << n1 << std::endl;
std::cout << "n2: " << n2 << std::endl;
std::cout << "n3: " << n3 << std::endl;
```

```cpp
//output

n1: 1.0101009607315063477
n2: 1.0101010101010101661
n3: 1.010101010101010101
```

in the output, n1 is no longer accurate after 7 precision because float is 7 precise

similarly with double. it gets inaccurate after 15 precision.

**Scientific notations:**

Handy for really large numbers.

```cpp
double n1 {1924000023}
double n2 {1.92400023e8}
```

$$
e8 = 10^8

$$

$$
e-8 = 1/10^8
$$

**Infinity & NaN:**

```cpp
    double n1 {5.6};
    double n2 {0};
    double n3 {0};

    double result {n1/n2};
    double result1 {n2/n3};
    std::cout << result << std::endl;
    std::cout << result1 << std::endl;
```

```cpp
//output

inf
-nan
```