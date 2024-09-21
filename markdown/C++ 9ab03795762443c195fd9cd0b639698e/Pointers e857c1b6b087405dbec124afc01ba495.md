# Pointers

Pointers in C++ are variables that store memory addresses. They allow you to indirectly access and manipulate data by referencing its location in memory

Pointers are declared using the `*` operator, e.g. `int *ptr{};` which declares a pointer `ptr` that points to an integer’s address.

**Explicitly initializing a pointer to `nullptr`:**

```cpp
int * p_number {nullptr};
```

All types of pointers have the same size in memory which is `8 bytes` 

**Assigning a valid address:**

A valid address of an integer can be accessed via `&an_int` 

```cpp
int an_int_var {24};
int *p_int {&an_int_var};
```

**Dereferencing a pointer:**

Dereferencing a pointer in C++ refers to the process of accessing the value stored at the memory address that the pointer is pointing to

The dereference operator `*` is used to access the value stored at the address a pointer is pointing to.

`cout << *p_int << endl;` is basically accessing the integer through its address in the memory.

**Declaring pointer to `char`:**

With C-literals:

```cpp
char *p_message {"Hello World"};
```

Here the `Hello World` string is converted into an array and the pointer is referencing the address of the first character, here `H` 

```cpp
cout << p_message << endl; 
//will print the whole C-literal string.
```

```cpp
cout << *p_message << endl; 
//will derefer to the first character.
//*(p_message + 1) will defer to second character
```

Incrementing a pointer moves it to the next memory location based on the size of the data type it points to.

Normally: 

```cpp
char random {'R'};
char *p_random {&random};
```

**Pointers and arrays together:**

an array name can be considered as a pointer pointing to the first character of the array, hence array name can be used to initialize a pointer.

```cpp
int scores[3]{2, 3, 4};
int *p_scores{scores};

//print the addresses:

cout << scores << " = " << p_scores << 
<< " = " << &scores[0] << endl;
```

Hence dereferencing the `scores` will give us `2`.

all 

- `*scores`
- `*p_scores`
- `scores[0]`
- `p_scores[0]`

will give us `2`. 

However, you can’t make the array name point to another address, so it acts like a `const` pointer.

and we also can’t access the size of the array via the pointer, because when the pointer decays to an array, it loses some information. 

```cpp
std::size(scores); //valid
std::size(p_scores); //notvalid
```

**Differences with `const char*` and `const char*[]`:**

1. Type:
- **`const char*`**:
    - This is a pointer to a `const char`. It points to a single character or the first character of a string literal, which is immutable.
- **`const char*[]`**:
    - This is an array of pointers to `const char`. It can hold multiple pointers, each of which can point to different string literals.
1. Memory layout & dereferencing:
- **`const char*`**:
    - Allocates memory for a single pointer that references a character or the first character of a string literal.
    - Here `8` bytes for a 64-bit system.
        
        ```cpp
        const char* a = "Hello";
        ```
        
    - Deferencing:
        - Will print the full literal:
            
            ```cpp
            cout << a << endl; 
            ```
            
        - Will print the first character of the literal, Here `H`:
            
            ```cpp
            cout << *a << endl;
            ```
            
        - Will move to the second character of the literal, Here `e`:
            
            ```cpp
            cout << *(a+1) << endl;
            ```
            
- **`const char*[]`:**
    - Allocates memory for an array of pointers. Each element in the array can point to a different string literal.
    - Here `16` bytes due to 2 pointers in a 64-bit system.
        
        ```cpp
        const char* a[] = {"Hello", "World"};
        ```
        
    - Deferencing:
        - Will print address to first and second pointer respectively
            
            ```cpp
            cout << b << endl;
            cout << b + 1 << endl;
            
            //0x7ffda3a7fb40
            //0x7ffda3a7fb48
            //Jumped 8 bytes
            ```
            
        - Will print the Literal pointed by the first pointer and the second pointer respectively
            
            ```cpp
            cout << *(b) << endl;
            cout << *(b+1) << endl;
            
            //Hello
            //World
            ```
            
        - Will print the first and second character of the literal pointed by the first pointer and second pointer respectively
            
            ```cpp
            cout << (*b)[0] << endl; //H
            cout << (*b)[1] << endl; //e
            
            cout << (*(b + 1))[0] << endl; //W
            cout << (*(b + 1))[1] << endl; //o
            
            ```
            

**`const` pointer and pointer to `const`:**

Case 1:

Can both change the data of the integer to from thee pointer, and make the pointer point somewhere else.

![Untitled](Pointers%20e857c1b6b087405dbec124afc01ba495/Untitled.png)

Case 2:

Can’t change the `int` data using the pointer, but can make the pointer point somewhere else.

![Untitled](Pointers%20e857c1b6b087405dbec124afc01ba495/Untitled%201.png)

Case 3:

neither can we change `int` data via the pointer, nor can we make the pointer point somewhere else.

![Untitled](Pointers%20e857c1b6b087405dbec124afc01ba495/Untitled%202.png)

Case 4:

Can make the point point somewhere else, though we can change the data via the pointer.

![Untitled](Pointers%20e857c1b6b087405dbec124afc01ba495/Untitled%203.png)

**Pointer arithmetic:** 

Pointer arithmetic in C++ allows you to perform arithmetic operations on pointers to access memory addresses.

- Incrementing a pointer (e.g. `ptr++`) moves it to the next memory location based on the size of the data type it points to.
- Decrementing a pointer (e.g. `ptr--`) moves it to the previous memory location based on the size of the data type

`std::ptrdiff_t` is a signed integer type that is used to represent the result of subtracting two pointers.

Pointers can also be compared, the higher the index of the iteration, the bigger the address.

**Array swapping via pointers:**

A poor inefficient method purely using arrays:

```cpp
void swapping_array_via_array
(int arr1[], int arr2[], int size)
{
    int temp[size]{};

    for (size_t i{}; i < size; i++)
    {
        arr1[i] = temp[i];
        arr1[i] = arr2[i];
        arr2[i] = temp[i];
    }    
    for (size_t i {}; i < size; i++)
    {
        cout << arr1[i] << endl;
    }
}
```

Looping like this with large array is certainly inefficient and register heavy.

More efficient approach will be to just swap the addresses where both the arrays are stored by replacing the pointers.

```cpp
void swapping_array_via_pointers
(int arr1[], int arr2[], int size)
{
    int *p_arr1[]{arr1}; 
    //adressing to the first index of arr1
    int *p_arr2[]{arr2}; 
    //adressing to the first index of arr2

    int *temp[]{};

    *temp = *p_arr1;
    *p_arr1 = *p_arr2;
    *p_arr2 = *temp;
}
```