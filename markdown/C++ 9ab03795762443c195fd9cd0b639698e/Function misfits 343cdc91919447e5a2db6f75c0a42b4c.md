# Function misfits

## Static variables:

1. global variables.

```cpp
#include <bits/stdc++.h>
using namespace std;

int student_count_global{0};
```

Global variables are also static, they live till the end of the function.

1. specified statics

```cpp
unsigned int add_student()
{
  static int student_count{0};
  ++student_count;
  return student_count;
}
```

This variable will live through the entire lifetime of the program. Hence, whenever you call the function the `student_count` will increase invariably. 

## Inline functions:

Inline functions in C++ serve several practical purposes that enhance programming performance and efficiency.

- **Reduced Function Call Overhead**: Inline functions are designed to minimize the overhead associated with function calls. When a function is declared as inline, the compiler attempts to replace the function call with the actual code of the function at compile time. This eliminates the need for the CPU to perform the usual steps of storing the return address, pushing arguments onto the stack, and transferring control to the function. This is particularly beneficial for small, frequently called functions, where the overhead of the function call can exceed the execution time of the function itself.
- **Context-Specific Optimizations**: By inlining a function, the compiler can optimize the function's code in the context of the calling function. This allows for more efficient use of registers and memory, as the compiler can make decisions based on the specific usage patterns of the code.
- **Small Functions**: Inline functions are most effective when used for small, simple functions, such as getters and setters, or mathematical operations. These functions are called frequently, and the performance gains from inlining can be significant.
- **Compiler Discretion**: The inline keyword is merely a suggestion to the compiler. The compiler may choose not to inline a function if it deems inlining to be inefficient (e.g. if the function contains loops or static variables) or if the function is too large. Therefore, developers should not rely solely on the inline keyword for performance improvements.
- **Code Size Increase**: Excessive use of inline functions can lead to code bloat, as the same function code may be duplicated at multiple call sites. This can increase the size of the binary executable, potentially leading to cache misses and reduced performance.
- **Recompilation Overhead**: Changes to inline functions necessitate recompilation of all code that calls the function, which can increase build times during development.

```cpp
inline int max(int a, int b){
	return (a > b) ? a : b;
}
```

## Recursive functions:

Recursion occurs when a function calls itself directly or indirectly until it reaches a base case, which stops the recursive calls. The recursive function typically consists of two main components:

- **Base Case**: This is the condition under which the recursion terminates. It prevents infinite recursion and allows the function to return a value.
- **Recursive Case**: This part of the function contains the logic that calls the function itself with modified arguments, gradually moving towards the base case.

```cpp
//syntax
return_type recursive_function(parameters) {
    // Base condition
    if (base_condition) {
        return base_case_value; // Termination
    }
    // Recursive case
    return recursive_function(modified_parameters);
}
```

**Program to find factorial:**

```cpp
#include <iostream>

using namespace std;

int factorial(int n) {
  if (n > 1) {
    return n * factorial(n - 1);
  } else {
    return 1;
  }
}

int main() {
  cout << factorial(5) << endl;
}
```