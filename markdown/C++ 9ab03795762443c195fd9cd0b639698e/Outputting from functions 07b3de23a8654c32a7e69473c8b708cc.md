# Outputting from functions

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
  (here x)*/
  int value = max_input_by_value(x,y);
  
  
}
```

Returning reference of local variables:

```cpp
int& sum( int& a, int& b){
    int result = a + b; 
    return result;
    // Reference to local variable returned
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

## **Using `std::optional`:**

It provides a type-safe way to represent a value that may or may not be present.

**Declaration and initialization:**

```cpp
std::optional<T> opt_var;
std::optional<std::string> name {"Rishi Ahuja"};
```

where `T` represents the optional value to be stored.

Empty Initialization:

```cpp
std::optional<std::string> dog_name {}; 
//Initializes to std::nullopt
std::optional<int> age {std::nullopt};
```

**Methods:**

- `has_value()`: checks whether the object contains a value
    - Printing `optionally` with `nullopt` may cause a compiler crash.
        
        ```cpp
        if(dog_name.has_value()){
            cout << dog_name.value() << endl;
        }
        ```
        
- `value()`: returns the contained value
- `value_or()`: returns the contained value if available, another value otherwise

**Usage:**

std::optional is useful when a function can return a valid value or indicate failure. Instead of using sentinel values like -1 to indicate failure, std::optional allows returning a valid value or an empty optional to indicate failure.

```cpp
std::optional<size_t> find_character
(const std::string& str, 
std::optional<char> c == std::nullopt)
{

	/*checks if it contains something, 
	if it contains nothing, 
	it will omit out our specified character, 
	here `z`*/	
	char char_to_find = c.value_or('z');	
	for(size_t i{}; i < str.size(); i++)
	{
			//.c_str converts in a char pointer
			if(str.c_str()[i] == c)
			{
				return i;
			}
	}
	return {}; //std::nullopt
}
```

checks if the string contains `c`