#ifndef POINT_H
#define POINT_H


#include <iostream>


class Point {
private:
    double m_x;
    double m_y;

public:
    static size_t m_point_count; //intialize even without creating an object

    Point(double p_x, double p_y);
    Point(double xy_coords);
    double length();

    void print_info() const;
    size_t get_point_info() const{
        return m_point_count;
    }   

};

#endif // POINT_H