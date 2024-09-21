# Static members

Static member variables are variables that are associated with the class itself rather than with individual objects of the class. Here are the key points about static member variables:

Only one copy of the variable is created:

for the entire class, regardless of how many objects are created

- They are initialized before any object of the class is created and before the main function is executed.
    
    ```cpp
    static size_t m_point_count;
    ```
    
- They can be accessed using the scope resolution operator **(::)** with the class name or with an object of the class
    
    ```cpp
    size_t Point::m_point_count{0}; 
    //in implementation file
    ```
    
- They can be declared in the class definition but must be defined and initialized outside the class in the global scope
- They have static storage duration and persist for the lifetime of the program
- They can be declared as public, private, or protected based on the access specifier used

You can’t initialize it in the class declaration, like this, `static size_t m_point_count {0};`, we need to either initialize them in the implementation file like this `size_t Point::m_point_count{0};` or we can make them inline to initialize in the declaration file.

```cpp
inline static size_t m_point_count{0}; 
```

Before C++17 we could only initialize `int` and `enum` classes as `const` static member variables, and others are required to be initialized 

**Member variables of self-type:**

```cpp
class Point{
public: 
	double m_x;
  double m_y;
  Point m_origin_point; 
}
```

This will cause an error because the size of the object is not known and lead to infinite recursion.

But the pointer to `Point` is not really a `Point` object, it is just a memory address that can be initialized later after creating the object.

```cpp
Point * m_origin_point;
```

Can be initialized like this:

```cpp
Point::Point(double p_x, double p_y) : 
m_x(p_x), m_y(p_y), m_origin_point(nullptr) {
    m_point_count++;
}
```

**Static member functions:**

Similarly, we can create static member functions like this, though we can’t access non-static member variables in the function.

```cpp
static void print_value(){
        std::cout << "printing" << std::endl;
}
```

```cpp
cout << Point::print_value() << endl;
```

**Nested classes:**

A nested class is a class defined within the scope of another class, known as the enclosing class. This structure allows the nested class to be treated as a member of the enclosing class, inheriting its access rights. Here are some key points about nested classes

- **Access Rights**: A nested class has the same access rights to the enclosing class's members as any other member. However, the enclosing class does not have special access to the private members of the nested class.
- **Scope Resolution**: To create an object of a nested class from outside the enclosing class, you must use the scope resolution operator `::`. For example, if `B` is a nested class within `A`, you would instantiate it as `A::B`.
- **Encapsulation**: Nested classes can help in logically grouping classes that are only used in one place, which can enhance encapsulation and reduce namespace pollution.
- **Member Functions**:
Member functions of a nested class can access the private members of the enclosing class, but not vice versa. This means that while the nested class can interact with the enclosing class, the enclosing class cannot directly access the nested class's private members.