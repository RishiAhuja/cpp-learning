# Character manipulations

to use the manipulators you need to import `<string>` library by `#include <string>`

`std::isblank` :

The `std::isblank()` function is used to determine if a given character is a blank character. A blank character is defined as either a space character (' ') or a horizontal tab character ('\t').
Simple program to identify blank characters in a `char` array: 

```cpp
char message []{"Hello, My name is Rishi. I am a retard"};

int blank_char{};

for (size_t i{0}; i < std::size(message); i++)
{
    if(std::isblank(message[i])){
        cout << "Found an blank character at index: " << i << endl;
        blank_char++;
    }
    else{
        cout << "Not a blank character, index: " << i << endl;
    }
}
```

`std::islower` and `std::isupper` :

The `std::islower()` function checks if a given character is a lowercase letter. It returns a non-zero value if the character is lowercase, and zero otherwise

Program to identify upper and lower case characters in a `char` array:

```cpp
int lower_case_char{};
int upper_case_char{};
int is_digit{};
blank_char = 0;

for (size_t i{0}; i < std::size(message); i++)
{
    if(std::islower(message[i])){
        cout << "Lower case character found at index: " << setw (5) << i << endl;
        lower_case_char++;
    }else if(std::isupper(message[i])){
        cout << "Upper case character found at index: " << setw (5) << i << endl;
        upper_case_char++;
    }else if(std::isdigit(message[i])){
        cout << "A digit found at index: " << setw (5) << i << endl;
        is_digit++;
    }
    else{
        cout << "Blank character found at index: " << setw (5) << i << endl;
        blank_char++;
    }
}
```

`std::tolower` and `std::toupper` change a character to lower and upper case respectively:

code to change each character of a `char` array to lower and upper case

```cpp
  char original_str [] {"Rishi is learning Character Manipulations in C++"};
  char destination_str [std::size(original_str)];

    for (size_t i{0}; i < std::size(original_str); i++)
    {
        destination_str[i] = std::toupper(original_str[i]);
    }
    
    
    cout << "Original string: " << original_str << endl;
    cout << "Altered string 1: " << destination_str << endl;

    for (size_t i{0}; i < std::size(original_str); i++)
    {
        destination_str[i] = std::tolower(original_str[i]);
    }

    cout << "Altered string 2: " << destination_str << endl;
```

`std::isalnum` is used to check if the character provided is `alphanumeric` 

this returns `0` or `1` as true or false. for example: 

```cpp
cout << std::isalnum('C') << endl;
cout << std::isalnum('^') << endl;
```