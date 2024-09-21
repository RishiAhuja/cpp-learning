# Defining Functions

To define a function in C++, use the following syntax:

```cpp
returnType functionName(parameters) {
    // function body
    return;
}
```

- **Return Type**: Specify the data type of the value returned by the function.
- **Function Name**: Choose a descriptive name for your function.
- **Parameters**: List the variables that will be passed to the function when it is called. A comma separates each parameter.

Example: 

```cpp
int max(int a, int b){
    return (a>b) ? a : b;
}
```

Copies of variables are made (which are inputted) and those copies get killed as the scope of the function ends, and these don't affect the outside variables unless we intentionally do this via references and pointers

**Function prototypes:**

If a function is defined after its first use, you need to provide a function prototype before the first use. The prototype has the same syntax as the function definition, but without the body:

```cpp
void enter_bar(unsigned int age);
```

```cpp
#include <iostream>
using namespace std;

void enter_bar(unsigned int age);
/*decleration or prototype doesn't 
cares about input variables*/

//hence this is also valid: 
//void enter_bar(unsigned int);

int main()
{
    return 0;
}

//write the logic here;
//function definition
void enter_bar(unsigned int age)
{
    (age >= 18) ? 
    cout << "Allowed, Age: " << age << endl 
    : cout << "Not allowed" <<  endl;
}
```

**Calling a function:**

To call a function, use its name followed by parentheses with any required arguments:

```cpp
int max(int a, int b){
    if(a>b){return a;}else{return b;}
}

int main(){
	int max_value {max(10,20)};
}
```

**One definition rule:**

The one definition rule states that:
In a C++ program, an entity (such as a function, variable, class, etc.) must have exactly one definition across all translation units (source files) that make up the program. 

This means you cannot have multiple definitions of the same entity in different source files. If you try to do this, the linker will report an error.