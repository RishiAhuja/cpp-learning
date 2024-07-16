#ifndef CYLINDER_H
#define CYLINDER_H

#include "constants.h"

class cylinder
{
    private:
        double radius {1};
        double height {1};
    
    public: 

        //constructors
        /*.......*/

        cylinder() = default;
        cylinder(double radius_param, double height_param);

        //Getters
        double get_radius();
        double get_height();

        //Setters
        void set_radius(double radius_param);
        void set_height(double height_param);

        //function
        double volume();
};

#endif