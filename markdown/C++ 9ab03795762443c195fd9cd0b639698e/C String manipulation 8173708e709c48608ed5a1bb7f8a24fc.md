# C String manipulation

C++ provides several functions for manipulating C-style strings, defined in the `<cstring>` header. Some of the most commonly used functions are:

**`std::strlen()`**: Returns the length of the string, not including the null terminator.

```cpp
const char message1[]{"The sky is blue."};

//will not account for null character
cout << std::strlen(message1) << endl;

//these will also account null character
cout << std::size(message1) << endl; 
cout << sizeof(message1) << endl
```

**`std::strcmp()`**: Compares two strings. 

- If the return value is less than 0, `str1` is lexicographically less than str2.
- If the return value is 0, `str1` is lexicographically equal to str2.
- If the return value is greater than 0, `str1` is lexicographically greater than str2.

```cpp
char s1[]{"Alabama"};
char s2[]{"Alabamb"};

cout << "std::strcmp(" << s1 << ", " << s2 << "): " << std::strcmp(s1, s2)
     << endl;
```

**`std::strncmp`: This a**lso compares two strings but the number of characters that are required to be compared can be provided. ****

```cpp
const char *s5{"aaarishi"};
const char *s6{"aaabishi"};

size_t n{3};

// will give 0, because will only compare first 3 characters
cout << "std::strncmp(" << s5 << ", " << s6 << "): " << std::strncmp(s5, s6, n)
     << endl;
```

extra: about the `const char*` 

This means that the contents of the string cannot be modified through, this pointer, but the pointer can be modified to point to a different string.

Here: will get an error: s5[0] = 'a'

**`std::strchr()`**: Searches for the first occurrence of a character in a string.

will accept a target and if it finds that target, it will return a pointer to that target, else will return a null pointer.

```cpp
const char *str {"Try not. Do, or do not. There is no Try."};

char target {'T'};
const char *result = str;
int iterations{};

//adding result to the value provided by the strchr, by this the loop will
//run for only the amount of time, the times we find a target character
while ((result = std::strchr(result, target)) != nullptr)
{
    cout << "Found: " << target << " " << result << endl;
    ++result;
    cout << result << endl;
    ++iterations;
}

cout << iterations << endl;
```

**`std::strrchr()`:** is used to find the last occurrence of a character in a string.

```cpp
char address [] {"/home/rishi/main.cpp"};

char *output = std::strrchr(address, '/');

if(output){
    cout << output << endl; //will give /main.cpp
    cout << output + 1 << endl; //using pointer array arithmetic to output main.cpp
}else{
    cout << "Can't find" << endl;
}
```

**`std::strcat()`:** function is used to concatenate two strings.

```cpp
//syntax: char *strcat(char *dest, const char *src);

char desc [50] = "Hello ";
char src [50] = "World";

//WARNING: add sufficient amount of padding (here: 50) to make sure after appending
//the array doesn't exceed the limit to throw a compiler error

std::strcat(desc, src);

//desc will be appended to Hello World from Hello 
```

From Heap memory:

```cpp
char *dest1 = new char [30]{'F', 'i', 'r', 'e', 'l', 'o', 'r', 'd', '\0'};
char *source1 = new char[30]{',',' ','T','h','e',' ','P','h','e','n','i','x',' ','K','i','n','g','!','\0'};

std::strcat(dest1, source1);

cout << dest1 << endl;

delete [] dest1, source1;
dest1, source1 = nullptr;
```

**`std::strncat()`:**  is used to concatenate a specified number of characters from one string to the end of another string.

```cpp
char dest [50] {"Hello"};
char source[50] {" There is a bird in my window"};

std::strncat(dest, source, 6);

//will take the first 6 characters from the source (here:  There) and will append it to dest
```

**`std::strcpy()`:** is used to copy one string to another.

```cpp
const char *src {"Hello"};
//creating dest as the same size as src using strlen and adding 1 to consider for null safety
char *dest = new char[std::strlen(src4) + 1]{};

std::strcpy(dest, src);
```