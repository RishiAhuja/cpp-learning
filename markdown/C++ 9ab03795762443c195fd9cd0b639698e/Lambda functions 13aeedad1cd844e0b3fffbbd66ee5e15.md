# Lambda functions

Lambda functions, also known as anonymous functions, are small, one-off functions that don't have a name. They are defined inline where they are used, rather than in a separate function declaration.

The key features of lambda functions in C++ are:

1. **Anonymous**: They don't have a named identifier like regular functions.
2. **Inline**: They are defined at the point of use, not in a separate function declaration.
3. **Capture Variables**: They can capture variables from the enclosing scope.
4. **Short Syntax**: They have a concise syntax compared to regular function declarations.

**Syntax:**

```cpp
[capture clause](parameters) -> return_type { function body };
```

- **Capture Clause**: Specifies which variables from the enclosing scope the lambda can access, and whether they are captured by value or by reference.
- **Parameters**: The parameters the lambda function takes, similar to a regular function.
- **Return Type**: The return type of the lambda function, which can be deduced by the compiler, hence providing return type may be optional.
- **Function Body**: The code that the lambda function executes.

```cpp
//example
auto func = [](int a, int b){
    cout << "Lambda functions" << endl;
    return (a+b);
};
```

**Calling inline:**

```cpp
[](double a, double b)-> double{
    return (a+b);
}(10.89, 50.9);
```

**Calling explicitly:**

```cpp
auto func = [](int a, int b){
    cout << "Lambda functions" << endl;
    return (a+b);
}; 

//function can be called manually
int newint = {func(10, 20)};
```

**Explicitly defining return type:**

```cpp
auto explicitly_defined_return = 
[](double a, double b) -> double{
    return (a+b);
};
```

**Capture lists/clauses:** 

- **Capture by Value**: Variables captured by value are copied into the lambda function. Changes made to the captured variables inside the lambda don't affect the original variables.
    - Syntax: `[x, y]` captures `x` and `y` by value.
- **Capture by Reference**:
Variables captured by reference allow the lambda function to directly access and modify the original variables in the enclosing scope.
    - Syntax: `[&x, &y]` captures `x` and `y` by reference.
- **Capture by Init-Capture**: This allows you to initialize new local variables within the lambda function using variables from the enclosing scope.
    - Syntax: `[x = 0, y = 0]` initializes new local variables `x` and `y` with the values 0.
- **Capture All by Value**: `[=]` captures all variables used in the lambda's body by value.
- **Capture All by Reference**: `[&]` captures all variables used in the lambda's body by reference.
- **Mixed Capture**: You can mix capture by value and capture by reference in the same lambda.
    - Syntax: `[&x, y]` captures `x` by reference and `y` by value.