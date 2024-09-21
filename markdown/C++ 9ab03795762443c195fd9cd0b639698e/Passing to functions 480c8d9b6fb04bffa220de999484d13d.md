# Passing to functions

## Calling

**Call by Value:**

```cpp
void increment(int x) {
    x = x + 1;
}

int main() {
    int a = 5;
    increment(a);
    std::cout << a << std::endl; // Outputs: 5
    return 0;
}
```

The function will not affect `a` because the function made a copy and killed it when the scope ended

**Call by reference and pointer:**

```cpp
void increment(int& x) {
    x = x + 1;
}

int main() {
    int a = 5;
    increment(a);
    std::cout << a << "\n"; // Outputs: 6
    return 0;
}
```

```cpp
void increment(int* x) {
    x = x + 1;
}

int main() {
    int a = 5;
    increment(&a);
    std::cout << a << "\n"; // Outputs: 6
    return 0;
}
```

Here because the reference is an alias to the same memory to the original variable or the pointer points to the same memory address, the original function will be affected by it.

## Other function parameters

**Array function parameters:**

```cpp
double sum(double scores[], size_t count){
	cout << "sizeof(scores): " << sizeof(scores) << endl;
	
	//cout << std::size(scores) << endl;
	//will not work
}

/*will always print `8` because 
it is decayed into a pointer*/
```

While passing an array to a function, it decays into a pointer hence we can’t determine its size via `size`. 

**Sized array function parameter:**

```cpp
double(double scores[5], size_t count);
```

even after specifying `scores[5]`, the compiler will not enforce this while passing an array. `5` in here will be ignored by the compiler.

**Passing sized arrays by reference:**

```cpp
double(const double (&scores)[10]);
```

By passing through reference we are ensuring the compiler enforces the number of elements ordered. Here you can only push an array with 10 elements, and we made this a `const` so that, we don't accidentally change the original array via the reference.

**Default function arguments:**

default arguments can be placed in the function declaration (only) and the function can be run without passing appropriate arguments.

```cpp
void compute
(int age = 27, double weight = 72.4, 
double distance = 12.5);
```

```cpp
int main(){
	compute(); //will run
	compute(32); //age will be plugged in as 32
	compute(32, 56.5) 
	//age and weight will be plugged in
}
```

Only add the defaults in the function declaration and not on the function body.

**Implicit conversions:**

```cpp
void print_sum(int a, int b){
	int sum = a + b;
}
```

```cpp
int main(){
    double a{4.5};
    double b{7.8};

    print_sum(a,b);
}
```

Instead of giving an error, the compiler will convert the doubles to integers without interference. (will simply chop off the decimal)

**Implicit conversion with references & pointers:**

The compiler will restrict the implicit conversions because of a conflict of interests. To pass a double to a function accepting integers via reference, the only method is to cast that to an integer manually.

```cpp
void increment(int& value);

int main(){
   double double_var{3.6};

// int data = double_var;

// increment(data); 
//will get compiler  error
    return 0;
}

void increment(int& value){
  value++;
	std::cout << "value incremented to : " 
	<< value << std::endl;
}
```

Similarly, the compiler doesn't support the same via pointers. the reason being, the pointer arithmetic. When the pointer moves from one double to another, it moves 8 addresses (because the size of a double is 8 bytes) and it moves 4 addresses while moving from int to int. 

**`constexpr` functions:**

`constexpr` functions are used to perform computations at compile-time rather than runtime.

```cpp
constexpr int get_value(int multiplier){
    return 3 * multiplier;
}
```

though if we call the function with a runtime variable, then the function will also be called on runtime.

**`consteval` functions:**

The only difference is that it will throw an error if it can’t be evaluated at runtime.

```cpp
consteval int get_value(int multiplier){
    return 3 * multiplier;
}
```

```cpp
get_value(4) 
/*will compile at runtime, 
because 4 is a literal and 
is known at compiletime*/

int value = 4
get_value(value); 
//will throw an error
```

## Returning

**Returning via references and pointers arguments:**

```cpp
void max_str
(const char* input1, 
const char* input2, 
std::string& output);
```

**Returning via `return`:**

```cpp
int add(int x, int y) {
    return x + y;
}
```

**Returning via references:**

```cpp
int& max_return_reference(int& a, int& b)
{
    if(a > b) {
        return a;
    } else {
        return b;
    }
}
```

```cpp
int main(){

	int x{15}
	int y{10}
	
	/*Will create a reference to the integer
	 which is greater. here x*/
	 
	/*hence using result for other operations 
	will directly result in changes to x*/
  int& result = max_input_by_value(x,y);
  
  
  /*Will create a copy and changing value 
  will not affect the value of larger variable
  - (here x)*/
  int value = max_input_by_value(x,y);
  
  
}
```

Returning reference of local variables:

```cpp
int& sum( int& a, int& b){
    int result = a + b; 
    return result;
    //Reference to local variable returned
}
```

This will produce a crash because the variable `result` will already die while returning it. Hence don't return references to local variables.

Not accepting references and returning references:

```cpp
int& max_input_by_value (int a, int b)
{
    if(a > b) {
        return a; 
        //Reference to local variable returned
    } else {
        return b; 
        //Reference to local variable returned
    }
}
```

Here `a` & `b` were copied at the local scope, hence they will die before returning and producing a crash.

**Returning via pointers:**

```cpp
int* max_return_pointer(int* a, int* b)
{
    if(*a > *b) {
        return a;
    } else {
        return b;
    }
}
```

Other issues are the same as references.

**Function return type deduction:**

```cpp

auto process_number(int value){
    if(value < 10){
        return 22; 
        //returning int literal
    }else{
        return 55; 
        //returning int literal
    }
}
```

The return types are not consistent here, hence the compiler will throw an error. to solve the issue, either replace the auto type deduction with double, or, `static_cast` the to a single consistent datatype. 

**Function definitions with return type deduction:**

```cpp
//Declaration
auto max(int& a, int& b);

int main(){/*...*/}

//Definition
auto max(int& a, int& b){
    if(a>b){
        return a;
    }else{
        return b; 
        // Will return a copy.
    }
}
```

Here the compiler's declaration is not able to see the return types via the definition, hence the compiler can’t determine an auto-type deduction.

**Arguments to main:**

The `main` function in C++ serves as the entry point for program execution and can accept command-line arguments. The standard signatures for the `main` function that allow for command-line arguments are:

```cpp
int main(int argc, char *argv[]);
```

Parameters:

- `argc`: This integer parameter represents the count of command-line arguments passed to the program, including the program's name itself. For example, if you run a program with the command `./rooster arg1 arg2`, `argc` will be 3.
- `argv`: This is an array of C-style strings (character pointers) where each element points to a command-line argument. The first element (`argv`) is the name of the program, and subsequent elements contain the actual arguments provided by the user.
    
    ```cpp
     for (size_t i = 0; i < argc; i++)
     {
        cout << agrv[i] << endl;
     }
    ```