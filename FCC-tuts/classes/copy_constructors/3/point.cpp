#include "point.h"

Point::Point(double x_param, double y_param) 
	: x(new double(x_param)),
		y(new double(y_param))
{
    std::cout << "Point constructed  : " << this << std::endl;

}

//Copy constructor
Point::Point(const Point& source_point)
	: x(new double(*(source_point.get_x()))),
		y(new double(*(source_point.get_y())))
{
	std::cout << "copy constructor called" << std::endl;
}


//move constructor

//here we dont want to create overhead to make a new memory location, 
//we will steal the memory location from the source object
// Point::Point(Point&& source_point) : x(source_point.x), y(source_point.y){
//     source_point.invalidate();
//     std::cout << "Move constructor called" << std::endl;

// }

Point::Point(Point&& source_point) : x(source_point.steal_x()), y(source_point.steal_y()){
    // source_point.invalidate();
    std::cout << "Move constructor called" << std::endl;

}

Point::~Point()
{
	delete x;
	delete y;
}