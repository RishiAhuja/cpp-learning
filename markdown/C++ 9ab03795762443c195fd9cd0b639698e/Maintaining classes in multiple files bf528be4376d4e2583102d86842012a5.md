# Maintaining classes in multiple files

A class can be separated into 2 files. A header `h` file and a `cpp` file.

## cylinder.h

```cpp
#ifndef CYLINDER_H
#define CYLINDER_H
#include "constants.h"

class Cylinder {
    public : 
        //Constructor
        Cylinder() = default;
        Cylinder(double rad_param, 
        double height_param);
        
        //Functions (methods)
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

The code snippet, `#ifndef CYLINDER_H` followed by `#define CYLINDER_H`, is used to prevent multiple inclusions of the same header file. This technique is known as an **include guard**.

Include guards are used to prevent the same header file from being included multiple times in a single compilation unit during pre-processing. This is important because including the same header file more than once can lead to redefinition errors and increase compilation time.

Respective `.cpp` file:

## cylinder.cpp

```cpp
#include "cylinder.h"

Cylinder::Cylinder(double rad_param, 
double height_param){
    base_radius = rad_param;
    height = height_param;
}

double Cylinder::volume(){
    return PI * base_radius * base_radius * height;
}

//Setter and getter methods
//syntax: 
double Cylinder::get_base_radius(){
    return base_radius;
}
/*...*/
void Cylinder::set_height(double height_param){
    height = height_param;
}
```

## main.cpp

```cpp
#include <iostream>
#include "cylinder.h"
using namespace std;

int main(){
    Cylinder cylinder1(10,10);
    cout << cylinder1.volume() << :endl;
    return 0;
}
```