#include "point.h"
#include <cmath>
using namespace std;

size_t Point::m_point_count{0};

Point::Point(double p_x, double p_y) : m_x(p_x), m_y(p_y) {
    m_point_count++;
}

Point::Point(double xy_coords) : Point(xy_coords, xy_coords) {
    m_point_count++;

}


void Point::print_info() const{
    cout << "x: " << m_x << " | " << &m_x << endl;
    cout << "y: " << m_y << " | " << &m_y << endl;
    cout << "------------" << endl;
}

double Point::length(){
    return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2));
}
