# Enum classes

An enum class (also known as a scoped enumeration) is a user-defined data type that represents a set of named constants.

**Syntax:**

```cpp
enum class EnumName : underlying_type {enumerator1, enumerator2, ..., enumeratorN};
```

**Initializing:**

```cpp
enum class Month{
    Jan, Feb, Mar, 
    Apr, May, Jun,
    Jul, Aug, Sep, 
    Oct, Nov, Dec
};
```

`Jan` will be considered as 0 and will be incremented to 1 by default.

```cpp
enum class Month{
    Jan = 1, Feb, Mar, 
    Apr, May, Jun,
    Jul, Aug, Sep, 
    Oct, Nov, Dec
};
```

any enum can be given an integer and it will continue from there by incrementing with one.

```cpp
enum class Month{
    Jan = 1, Feb, Mar, 
    Apr, May, Jun,
    Jul = 20, Aug, Sep, 
    Oct, Nov, Dec
};
```

`Jul` = 20, `Aug` = 21, `Sep` = 22…

**Can be called:**

```cpp
Month month {Month::Feb};

//CAN'T be printed directly
// cout << month << endl;

//CAN be printed after casting to an integer
cout << static_cast<int>(month) << endl; 
```

**More flexibility:** 

```cpp
enum class Month{
    Jan = 1, January = Jan, Feb, Mar, 
    Apr, May, Jun,
    Jul = 20, Aug, Sep, 
    Oct, Nov, Dec
};
```

Now `Jan` and `January` can both be used via 1. 

**Changing underlying type:** 

```cpp
enum class Month : unsigned char{
    Jan = 1, January = Jan, Feb, Mar, 
    Apr, May, Jun,
    Jul = 20, Aug, Sep, 
    Oct, Nov, Dec
};
```

the **underlying type** refers to the integral type that is used to represent the values of the enumerators in the enumeration. By default, the underlying type of an enum class is `int`, but you can specify a different integral type (such as `char`, `short`, `long`, or any other integral type) when defining the enum class.

**Using enum:**

this can be replaced with: 

```cpp
switch (month)
{
        
    case Month::Jan : return "January";
    case Month::Feb : return "February";
    case Month::Mar : return "March";
    case Month::Apr : return "April";
    case Month::May : return "May";
    case Month::Jun : return "June";
    case Month::Jul : return "July";
    case Month::Aug : return "August";
    case Month::Sep : return "September";
    case Month::Oct : return "October";
    case Month::Nov : return "November";
    case Month::Dec : return "December";
    default : return "None";
}
```

with this:

```cpp
    using enum Month;
    case Jan : return "January";
    case Feb : return "February";
    case Mar : return "March";
    case Apr : return "April";
    case May : return "May";
    case Jun : return "June";
    case Jul : return "July";
    case Aug : return "August";
    case Sep : return "September";
    case Oct : return "October";
    case Nov : return "November";
    case Dec : return "December";
    default : return "None";
```

**Legacy enum types:**

```cpp
//can be initialized 
enum Tool {
    Marker, Pen, Pencil
};
```

**Type aliases:**

a **type alias** is a synonym for an existing data type, allowing developers to create alternate names for types to enhance code readability and maintainability.

```cpp
unsigned long long int huge_number {230'766'777'899'222ull};
//A type alias can be created

using HugeInt = unsigned long long int;
HugeInt huge_int {230'766'777'899'222ull};
```

Legacy type aliases using `typedef`:

```cpp
typedef unsigned long long int HugeInt2;
HugeInt2 huge_int2 {230'766'777'899'222ull};
```