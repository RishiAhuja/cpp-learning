# Dynamic memory allocation

**Stack Memory:**

The stack is a region of memory used for storing local variables and function call information. When a function is called, a new stack frame is created to hold the function's local variables and return address. The stack grows downward in memory.

Allocation and deallocation are automatic - variables are allocated when declared and deallocated when they go out of scope or the function returns. The developer has no control of allocation and deallocation and the memory is limited in nature.

Memory is allocated in contiguous blocks and stack variables can be accessed directly by their name.

```cpp
int main() {
    int a;      // a is allocated on the stack
    int b = 5;  // b is allocated and initialized on the stack
    
    if (b > 0) {
        int c = 10;  // c is allocated on the stack
        // c goes out of scope and is deallocated here
    }
    // b goes out of scope and is deallocated here
    
    return 0;  // main's stack frame is deallocated
}

```

**Heap memory:**

The heap is a region of memory used for dynamic memory allocation. Memory is allocated on the heap using the `new` operator and freed using the `delete` operator.

Allocation and deallocation are manual - the programmer is responsible for allocating and freeing memory. The size of memory needed may not be known at compile-time. Heap memory must be accessed through a pointer. It persists until it is explicitly freed or the program ends. It’s slower than stack allocation. 

Heap memory can lead to memory leaks if not properly managed

```cpp
int main() {
    int* p {new int};  // allocate an integer on the heap
    *p = 10;           // assign a value to the integer
    
    delete p;          // free the memory on the heap
    p = nullptr;       // set the pointer to null to avoid dangling pointers
    
    return 0;
}
```

**Direct initialization:**

```cpp
int *p_number {new int{22}}; 

//clearing memory
delete p_number;
p_number = nullptr;
```

Pointers can be reused after deletion and can be pointed to a new address.

```cpp
//redirected to new address after deletion:
p_number = new int {80};
```