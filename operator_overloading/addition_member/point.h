#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cassert>

class Point
{
    friend Point operator+(const Point& left, const Point& right);
	friend std::ostream& operator<<(std::ostream& os, const Point& point);
	friend std::istream& operator>>(std::istream& is, Point& p);

public:
	Point() = default;
	Point(double x, double y) : 
		m_x(x), m_y(y){
	}
	Point(double x, double y, double rp) : 
		m_x(x), m_y(y), rand_ptr(&rp){
	}
	~Point() = default;

   Point operator+(const Point& right){
    return Point(this->m_x + right.m_x, this->m_y + right.m_y);
   }

	void print_info(){
		std::cout << "Point [ x : " << m_x << ", y : " << m_y << "]" << std::endl;
	}

	double& operator[] (size_t index){
		assert(index < 2);
		if(index == 0){
			return m_x;
		}
		if(index == 1){
			return m_y;
		}
	}

	//stream insertion operator as a member function
	std::ostream& operator<<(std::ostream& os){
		os << "Point [ x : " << m_x << ", y : " << m_y << "]";
		return os; //to allow chaining
	}

	//unary prefix and postfix

	void operator++() {
		std::cout << "called pre" << std::endl;
		++m_x;
		++m_y;
	}

	Point operator++(int){
		Point local_point(*this);
		++(*this);
		return local_point;
	}


	Point operator=(Point &right_operand){
		if(this!= &right_operand){
			delete rand_ptr;
			this->m_x = right_operand.m_x;
			this->m_y = right_operand.m_y;
			this->rand_ptr = right_operand.rand_ptr;

			// this->rand_ptr = new double(*right_operand.rand_ptr);
		}
	return *this;
	}
private: 
	double length() const;   // Function to calculate distance from the point(0,0)

private : 
	double m_x{};
	double m_y{};
	double* rand_ptr {nullptr};
};

//as non-member function

//global free standing function
//declared as inline because it is in the global scope of this header file, and this header can be used in multiple files, and to prevent multiple definition error, we need to declare it as inline
inline Point operator+(const Point& left, const Point& right){
    return Point(left.m_x + right.m_x, left.m_y + right.m_y);
}

//stream insertion operator as a free standing function
inline std::ostream& operator<<(std::ostream& os, const Point& point){
	os << "Point [ x : " << point.m_x << ", y : " << point.m_y << "]";
	return os;
}

//stream extraction operator as a free standing function

inline std::istream& operator>>(std::istream& is, Point& p){
	double x;
	double y;

	std::cout << "Please input [x,y] with spaces one by one: " << std::endl;
	is >> x >> y;

	p.m_x = x;
	p.m_y = y;
	return is;
}

#endif // POINT_H