# Memory leaks & Dynamic arrays

Memory leaks in C++ occur when dynamically allocated memory is not properly deallocated, leading to a gradual loss of available memory. Here are the key points about memory leaks in C++

Memory leaks happen when memory allocated with `new` is not freed with `delete` or `delete[]`. Forgetting to call `delete` on a pointer that points to dynamically allocated memory results in a memory leak

Example: 

```cpp
int *p_num = new(std::nothrow) int {37};

int leak_num {80};

*p_num = &leak_num
//here we lost access to the memory we allocated before 
//Now we have no way to deallocate the old memory
```

**Dynamic Arrays:**

arrays can also be assigned in heap memory:

```cpp
double *p_salaries {new(std::nothrow) double[size]{1, 3, 5, 8, 5, 4, 3, 7, 7, 2}};
```

Dereferencing: 

```cpp
cout << *p_salaries << endl
//will point to the first element of the array

cout << *(p_salaries + 1) << endl;
//will point to the second element of the array
```

Releasing memory of a dynamic array:

```cpp
delete[] p_salaries;
p_salaries = nullptr;
```

Dynamic arrays are different from arrays they don't work with `std::size`. here an array decaying into a pointer and for the same reason we can’t run a ranged based loop.