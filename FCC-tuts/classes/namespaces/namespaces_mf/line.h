#ifndef LINE_H
#define LINE_H 

#include "point.h"


namespace Geom {
        class Line {
            private:
                Point m_start;
                Point m_end;
            
            public: 
                Line() = default;
                Line(const Point& start, const Point& end);
                ~Line(){};

                void print_info(){
                    std::cout << "Line(";
                    m_start.print_info();
                    std::cout << ", ";
                    m_end.print_info();
                    std::cout << ")" << std::endl;
                }

        };


}

#endif