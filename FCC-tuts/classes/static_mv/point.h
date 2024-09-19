#ifndef POINT_H
#define POINT_H


#include <iostream>


class Point {
private:
    double m_x;
    double m_y;
    //Point m_origin_point; //this will cause an error because the size of the object is not known and lead to infinite recursion
    Point * m_origin_point;
    inline static int value {0};
    //pointer to Point is not really a Point object, it is just a memory address
    //or use static Point m_origin_point; //this will make the variable to be shared by all objects of the class

public:
    static size_t m_point_count; //intialize even without creating an object
    //or
    //writing inline will make the variable to be initialized in the header files
    // inline static size_t m_point_count{0}; 
    Point(double p_x, double p_y);
    Point(double xy_coords);
    double length();

    void print_info() const;
    size_t get_point_info() const{
        return m_point_count;
    }   
    void initialize_pointer(double x, double y){
        m_origin_point = new Point(x, y);
    }   

    static void print_value(){
        std::cout << value << std::endl;
        //obv cant access non static member variables or functions
    }

};

#endif // POINT_H