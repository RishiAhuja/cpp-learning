#include "cylinder.h"

cylinder::cylinder(double radius_param, double height_param) {
    radius = radius_param;
    height = height_param;
}

double cylinder::volume() {
    return PI * radius * radius * height;
}

// Setter and getter methods
double cylinder::get_radius() {
    return radius;
}

double cylinder::get_height() {
    return height;
}

void cylinder::set_radius(double radius_param) {
    radius = radius_param;
}

void cylinder::set_height(double height_param) {
    height = height_param;
}
