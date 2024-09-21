# Function overloading

Function overloading is a feature in C++ that allows you to define multiple functions with the same name, as long as they have different parameters. When a function is called, the compiler determines which version of the function to use based on the arguments passed.

- Functions must have different parameters (number, type, or order of parameters).
- The return type can be the same or different.
- The compiler selects the most appropriate function based on the arguments passed.
- If the compiler cannot determine the best match, it results in a compile-time error.

```cpp
int add(int x, int y) {
    return x + y;
}

double add(double x, double y) {
    return x + y;
}

int main() {
    cout << add(2, 3) << endl;     // Calls int add(int, int) overload
    cout << add(2.5, 3.2) << endl; // Calls double add(double, double) overload
    return 0;
}

```

**Overloading with `const` by value:**

```cpp
int max(int a, int b){
  return (a > b) ? a : b;
}

//invalid overload
int max(const int a, const int b){
   return (a > b) ? a : b;
}
```

the `const` qualifier does not change the type of the parameter. Both int and `const` int are treated as the same type when it comes to function overloading.