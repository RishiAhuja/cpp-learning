# More in constructors

**Default parameters for constructors:**

Class in question:

```cpp
class Cylinder {
    public : 
        //Constctors
        Cylinder() = default;
        Cylinder(double rad_param, 
        double height_param);

        double volume();
        
        //Setter and getter methods
        double get_base_radius();
        double get_height();

        void set_base_radius(double rad_param);
        void set_height(double height_param);
    private : 
        //Member variables
        double base_radius{1};
        double height{1};
};
```

Default parameters can be added similarly to functions.

```cpp
Cylinder(double rad_param, 
        double height_param = 5);
```

Now the object can be called by only passing a single argument.

```cpp
Cylinder c1(10);
//radius: 10
//height: 5
```

Adding all the arguments as default:

```cpp
Cylinder() = default;
Cylinder(double rad_param = 10, 
      double height_param = 5);
```

Now the following call `cylinder c1;` without parameters can be serviced by both the constructors, hence the compiler will throw an error: `class "Cylinder" has more than one default constructor.` To solve the issue, we need to kill `Cylinder() = default;` 

**Initializer lists for constructors:**

A member initializer list is defined after the constructor's parameter list, starting with a colon (`:`), followed by the member variables to initialize and their corresponding values.

Old syntax with member-wise copy initialization:

```cpp
Cylinder::Cylinder(double radius_param, 
double height_param) {
    radius = radius_param;
    height = height_param;
}
```

New syntax with initializer lists:

```cpp
Cylinder(double radius_param, 
double height_param) 
: radius(radius_param), height(height_param){
    // Empty body
}
```

Difference between member-wise copy vs initializer lists:

| Member-wise copy | Initializer lists |
| --- | --- |
| Two-step initialization: object creation and member variable assignment. | Initialization occurs at real object creation. |
| Potential unnecessary copies of data, and expensive overhead by using more CPU cycles and memory. | Unnecessary copies can be avoided. |
| The order of variable assignment doesn’t matter and the developer has full flexibility.  | The order of member variables should be the same as the order of parameters accepted.  |

**Explicit constructors:**

the **explicit** keyword is used with a constructor to prevent it from performing implicit conversions. An **`explicit`** constructor is marked to not convert types implicitly, which is important because implicit conversions often lead to unexpected results.

Class in question:

```cpp
class Square{
    private: 
        double side{0};
        std::string color;
    public: 
        Square() = default;
        //constructor:
        Square(double side_param);
        ~Square();

        //getter-setter
        double& use_side();
        //utility
        double area() const;
};
```

Compare function in main.cpp

```cpp
bool compare (const Square& s1, 
const Square& s2)
{
    return (s1.area() > s2.area())
     ? true : false;
}
```

Now if we call the function, and put the second parameter, say a `double`, the compiler will try to convert the double to `Square` object, as the object only accepts a single `double` parameter, hence it is an easy implicit conversion for the compiler.

```cpp
//this will work
//accurate comparison 
cout << compare(sq1, 45.6) << endl
```

To avoid this, we can make the constructor explicit:

```cpp
explicit Square(double side_param);
```

Now this will `cout << compare(sq1, 45.6) << endl` will omit a compiler error.

**Constructor delegation:**

In C++, constructor delegation allows a constructor to call another constructor of the same class in its initializer list.

- One constructor calls another constructor of the same class using the initializer list syntax.
- The called constructor is responsible for initializing the object.
- Constructor delegation is different from calling a constructor from inside the body of another constructor, which creates a new object and initializes it separately.

```cpp
Square::Square(double side_param) 
: Square(side_param, "Black", 6){
    cout << "One param constructor" << endl;
}

Square::Square(double side_param, 
const std::string& color_param, 
int shading_param)
 : side(side_param), 
 color(color_param), 
 shading(shading_param){
    cout << "Three param constructor\n";
}
```

Chronology: 

*>Three param constructor will be called*

*>Code inside three param constructor*

*>First param constructor will be called*

>Code *inside one param constructor*

**Constructor delegation** helps avoid code duplication and makes the code more readable and maintainable.

**Copy constructors:**

A copy constructor in C++ is a special type of constructor used to create a new object as a copy of an existing object of the same class. 

```cpp
Person p1("Rishi", "Ahuja", 16);
Person p2(p1);
```

While doing this, the compiler will do a memberwise copy, and Let’s say the age is stored as a pointer as defined in the member variables, hence while doing a member wise copy, the address of the age will directly be copied, and while modifying age on one object might modify the age of both the objects.

```cpp
Person::Person(const Person source_p)
    : last_name(source_p.get_last_name()),
        first_name(source_p.get_last_name()),
        age(source_p.get_age()){}
```

We can create a new copy constructor, which accepts a person object and initializes a new object.

But this might get stuck in a loop. because here we are passing by value, because while passing by value, the compiler calls a copy constructor, hence this will be stuck in a recursion.

```cpp
Person::Person(const Person& source_p)
    : last_name(source_p.get_last_name()),
        first_name(source_p.get_last_name()),
        age(source_p.get_age()){}
```

We can accept this object by reference but we are still directly copying the pointer address, to resolve this, we can assign new memory from the heap, by dereferencing the data from the old pointer.

```cpp
Person::Person(const Person& source_p) 
    : last_name(source_p.get_last_name()),
        first_name(source_p.get_first_name()),
        age(new int(*(source_p.get_age()))){}
```

Copy constructors are also called while storing objects in an array.

The discussion we had earlier is formally referred to as shallow and deep copies.

A shallow copy means copying member-wise, even the pointers as it, however, explicitly creating a new address for a pointer in the copy constructor is called deep copy. 

**Move Constructors:**

Move constructors enable the transfer of resources from one object to another without the overhead of copying. We will directly steal memory instead of using the source memory to allocate new memory. This is particularly useful for optimizing performance when dealing with temporary objects or objects that manage dynamic resources.

This is a copy constructor, Here we are using the original source, and then creating a new memory location, and then assigning that memory the new copy constructors, but sometimes, we might want to directly move the resources of the object (maybe the object will soon die in a case anyway) and harvest that object to decrease the overhead.

```cpp
Point::Point(const Point& source_point)
	: x(new double(*(source_point.get_x()))),
		y(new double(*(source_point.get_y())))
{
	std::cout << "copy constructor called" << std::endl;
}
```

Move constructor:

If we don't have a move constructor initialized, the compiler will use a copy constructor even if we feed it a temporary object, for example:

```cpp
Point p2 (std::move(Point(20.0, 25.0)));
```

`std::move` is used to specify the compiler to use the move constructor:

`&&` is the representation for a move constructor.

```cpp
Point::Point(Point&& source_point) : x(source_point.x), y(source_point.y){
    source_point.invalidate();
    std::cout << "Move constructor called" << std::endl;
}
```

Here we are simply assigning the memory address returned by the getters and assigning it a new object.

Here is the getter:

```cpp
double * get_x()
{
	return x;
}
```

We are also using an `invalidate()` member function to nullify the pointer originally pointing to the memory location in the temporary object.

```cpp
void invalidate()
{
	x = nullptr;
	y = nullptr;
}
```

We can also avoid the use of the invalidate function and make the code more readable by creating steal getters, where we also fetch value and invalidate the temporary object's memory address. 

```cpp
double * steal_x(){
	double * new_x = x;
	x = nullptr;
	return new_x;	
}
```

**Deleted constructors:**

A deleted constructor is declared using the `= delete` syntax. When a constructor is deleted, any attempt to use that constructor will result in a compile-time error. This provides a clear and intentional way to restrict the usage of a class.

```cpp
Point() = default;
```

Reasons to Use Deleted Constructors:

1. Prevent Default Construction: You may want to prevent objects from being created without specific parameters. For example, if a class requires a certain initialization value, you can delete the default constructor.
2. Control Object Lifetimes: By deleting constructors, you can manage how objects are created and destroyed, particularly in resource management scenarios.
3. Clarify Inten**t**: Deleted constructors make it clear to other developers that certain operations
are not allowed, improving code readability and maintainability.
4. Prevent Unintended Usage: Deleting constructors can help avoid mistakes, such as accidentally
copying objects that should remain unique, which is particularly
important in resource management classes.

Comparison with Private Constructors:

While you can also use private constructors to achieve similar goals, deleted constructors provide clearer error messages and prevent the compiler from generating implicit constructors. This can lead to more understandable code and easier debugging.

**Initializer lists in C++:** 

`std::initializer_list` is a lightweight proxy object introduced in C++11 that provides access to an array of objects of a specified type. It allows for easier initialization of containers and custom classes using a braced initialization syntax. This feature enhances the flexibility and readability of code, particularly when dealing with collections or complex data structures.

```cpp
class Point{
	private : 
		double* x{};
		double* y{};
	public:
		Point(std::initializer_list<double> list){}
		//initializer lists
}
```

`list.begin()` will provide a pointer to the first element of the list, we can loop through the list like this:

```cpp
for (auto i = list.begin(); i != list.end(); i++)
{
		cout << i << " : " << *i << endl;
}
```

oi

We can initialize the member variable like this:

```cpp
x = new double {*(list.begin())};
y = new double {*(list.begin() + 1)};
```

To enforce the use of initializer list constructors, we need to pass the data using brace initialization:

```cpp
Point p3 {10.6, 5.6};
```

To enforce only 2 values to be accepted in the list, we can’t use standard `static_assert` because the size of list is not known at compile time and hence the `static_assert` will fail.

We can use include `<cassert>` header file to use `assert` which works even for compile time.

```cpp
assert(list.size() == 2, "only pass 2 values");
```

**Aggregates:**

Aggregates are a special category of types, defined by the following criteria:

1. It is an array type or a class type (struct, or class).
2. It has no user-provided, inherited, or explicit constructors.
3. It has no private or protected non-static data members.
4. They are initialized by braced initialization

**Designated constructors:**

Designated constructors, also known as designated initializers, allow for more explicit and readable initialization of aggregate types. This feature is particularly useful when you want to initialize specific members of a struct or class without having to provide values for all members, especially when there are many members or when their order is not intuitive.

```cpp
Type obj = { .memberName = value, 
.memberName2 = value2, ... };
```

```cpp
struct Component{
    int x;
    int y;
    int z;
}
int main()
{
    Component c1{.x= 10, .y = 20, .z = 30};
    Component c2{.x= 10, .z = 30};
    Component c3{.z=10, .x =30};
    //this will give a compiler error
    //the values should be assigned in order
}
```