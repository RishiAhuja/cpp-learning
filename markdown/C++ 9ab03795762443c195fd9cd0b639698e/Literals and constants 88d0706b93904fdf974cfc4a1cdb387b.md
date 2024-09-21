# Literals and constants

Literals are values that are directly written into your code.

Literals in C++ are "burnt into the binary" of your code, meaning the compiler treats them as a specific type without additional information.

For example, when you write `42`, the compiler knows it's an integer without needing any additional 
information. However, if you want to specify that you are initializing a variable with a different type of literal, such as a character or a string, you must use special prefixes or suffixes.

Here are some examples:

1. **Integer Literals**:
    - `42` is an integer literal.
    - `0x2A` is an integer literal in hexadecimal notation.
2. **Character Literals**:
    - `'a'` is a character literal.
    - `L'a'` is a wide character literal (requires `wchar_t` type).
3. **String Literals**:
    - `"Hello"` is a string literal.
    - `L"Hello"` is a wide-string literal (requires `wchar_t` type).
4. **Floating-Point Literals**:
    - `3.14` is a floating-point literal.
    - `3.14e-1` is a floating-point literal in scientific notation.

**Constants:**

Constants are variables with fixed values that cannot be changed once they are defined. They are used to represent values that remain unchanged throughout the program's execution. 

1. Using the `const` Keyword:
    
    The `const` keyword is used to declare a variable as constant. Once a variable is declared as `const`, its value cannot be changed.
    
2. Using the `constexpr` Keyword:
    - The `constexpr` keyword is used to declare a constant expression. These constants are evaluated at compile time, ensuring that their values/results are directly baked in the binary, and we don’t need to compile again and again while executing the binary hence saving processing.
    - You can’t use a runtime variable to initialize a `constexpr` variable.
    
    ```cpp
    int leg_count {2};
    //will give a compiler error
    constexpr arm_count{leg_count};
    ```
    
    - However we can check if the `constexpr` is valid at runtime, and if the text fails the code will not compile. This can be achieved via `static_assert`. You can only assign something in static assert which is a `const` because it is a compile-time check.
    
    ```cpp
    int MAJOR_LIB_VERSION {123};
    static_assert(MAJOR_LIB_VERSION == 123);
    
    //this will compiler
    ```
    
    - `constinit` is a new C++20 feature, `constinit` can only be used before the `main` functions, and these are not `const` by default, though they can be merged with `const` and is also used to bake information in executable in compile time.
        - `constexpr` variables are constant expressions that can be evaluated at compile-time and can be used for both functions and variables.
        - `constinit` variables are statically initialized, but their values are not necessarily constant expressions, can only be used for variables.
3. Using the `#define` preprocessor:
    
    The `#define` directive is used to define a macro, which is a text substitution mechanism.
    `#define LENGTH 10`