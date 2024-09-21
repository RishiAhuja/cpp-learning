#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cassert>

class Point
{
private : 
	double* x{};
	double* y{};
	
	void invalidate(){
		x = nullptr;
		y = nullptr;
	}
public:
	Point(double x_param, double y_param);
	~Point();

	Point(std::initializer_list<double> list){


		//will not work because size of list is not known at compile time and hence the static_assert will fail
		//static_assert(list.size() == 2, "initializer list must have 2 elements");

		//for runtime check 
		assert(list.size() == 2, "only pass 2 elements in the initializer list");
		std::cout << "called initializer list constructor" << std::endl;

		std::cout << "size of list: " << list.size() << std::endl;


		std::cout << "list.begin() : " << list.begin() << std::endl;
		std::cout << "*list.begin() : " << *(list.begin()) << std::endl;

		for (auto i = list.begin(); i != list.end(); i++)
		{
			std::cout << "i : " << i << " : " << *i << std::endl;
		}
		
		x = new double {*(list.begin())};
		y = new double {*(list.begin() + 1)};
	}
	
    //Copy constructor
	Point(const Point& source_point);

    //Move constructor
    // Point( Point&& source_point);

	
	//Setters
	void set_x(double x){
		*(this->x) = x; // Dereference and assign
	}
	void set_y(double y){
		*(this->y) = y; // Dereference and assign
	}
	
	//Getters
	double * get_x()const{
		return x;
	}
	
	double * get_y()const{
		return y;
	}

    //special getters to steal

    double * steal_x(){
        double* new_x = x;
        x = nullptr;
        return new_x;
    }

    double * steal_y(){
        double* new_y = y;
        y = nullptr;
        return new_y;
    }

	//Utilities
	void print_info()const{
			std::cout << "Point [ x : " << *x << ", y: " << (*y) << "]" << std::endl;
	}


    //move constructors

    Point(Point&& source_point);
};

#endif // POINT_H