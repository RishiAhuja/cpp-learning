// #ifndef POINT_H
// #define POINT_H 

// #include <iostream>

// namespace Geom {

//     class Point {
//         private:
//             double m_x;
//             double m_y;

//         public:
//             Point() = default;
//             Point(double x, double y){}
//             ~Point(){};
//             void print_info() const{
//                 std::cout << "Point(" << m_x << ", " << m_y << ")" << std::endl;
//             }
//     };
// }



// #endif




#ifndef POINT_H
#define POINT_H

#include <iostream>

namespace Geom{
    
    class Point
    {
    public:
        Point();
        Point(double x, double y);
        void print_info()const{
            std::cout << "Point [ x : " << m_x << ", y : " << m_y << "]" << std::endl;
        }
        ~Point();
    private : 
        double m_x;
        double m_y;
    };
    
}



#endif // POINT_H