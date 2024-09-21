# Multiple files and compilation model

**Splitting Functions Across Files:**

In C++, it is common to split functions across multiple files to 
make the code more modular and easier to manage. The typical approach 
is:

1. **A function declaration** (prototype) goes in a header file (`.h` or `.hpp`)
2. **A function definition** (implementation) goes in a source file (`.cpp`)

**add.h**

```cpp
int add(int x, int y);
```

**add.cpp**

```cpp
int add(int x, int y) {
    return x + y;
}
```

**main.cpp**

```cpp
#include <iostream>
#include "add.h"

int main() {
    int result = add(3, 4);
    std::cout << "The sum is: " << result << "\n";
    return 0;
}
```

**Compilation Model:**

C++ uses a separate compilation model, where each source file (`.cpp`) is compiled independently by the compiler into an object file (`.o` or `.obj`). The linker then combines these object files into the final executable.

A preprocessor finds the functions from the other header files that are requested and places them in the main.cpp file, and then the linker makes a final executable independently.

**Linking Multiple Object Files**:

To create an executable from multiple object files:

```cpp
g++ main.cpp add.cpp
```