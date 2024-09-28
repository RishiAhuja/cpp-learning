#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"
#include <iomanip>

using namespace std;

void draw_shape(Shape* p_shape){
    p_shape->draw();
}

int main() {

    Shape s1 ("my shape");
    // s1.draw();

    Oval o1 (10, 20, "my oval");
    // o1.draw();

    Circle c1 (5, "my shape");
    // c1.draw();


    //static binding 


    //base pointers
    Shape * shape_ptr = &s1;
    // shape_ptr->draw();

    shape_ptr = nullptr;
    
    shape_ptr = &o1;
    // shape_ptr->draw(); //called from shape class


    //managing memory of inheriting classes via base references:
    Shape& shape_ref = o1;
    // shape_ref.draw(); //called from shape class



    //dynamic binding with virtual functions

    //all we need to do to dynamically resolve the function call is to add the keyword virtual to the function in the members
    //now the compiler won't look at the type of the pointer rather the type of the object it is managing

    //draw_shape(&s1);
    //draw_shape(&o1);
    //draw_shape(&c1);

    //colleections with dynamic binding

    Shape* shapes[]
    {
        &s1,
        &o1,
        &c1
    };

    for (size_t i = 0; i < std::size(shapes); i++)
        shapes[i]->draw();
    
    

    //dynamic binding ain't no free
    //it costs memory and performance

    
    cout << "sizeof(Shape) : " << sizeof(Shape) << endl;
    cout << "sizeof(Oval) : " << sizeof(Oval) << endl;
    cout << "sizeof(Circle) : " << sizeof(Circle) << endl;

    //40 - 56 - 56


    //static binding = 32 - 48 - 48

    //the extra space is used by the vtable
    //vtable is a table of function pointers that the compiler generates for each class that has virtual functions

    //slicing

    //when we assign a derived class object to a base class object, the derived class object is sliced down to the base class object

    Shape s2 = o1;
    s2.draw(); //draw() from shape class
    return 0;
}