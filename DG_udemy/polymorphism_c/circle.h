#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "oval.h"
class Circle : public Oval{
    private: 
        // double m_radius{0};

    public: 
        Circle() = default;
        Circle(double p_radius, std::string p_desc);
        ~Circle();

        // virtual void draw(){
        // std::cout << "Circle::draw() called. Drawing " << m_description <<
        //     " radius: " << get_x()
        //             << std::endl;
        // }
        void draw(){
        std::cout << "Circle::draw() called. Drawing " << m_description <<
            " radius: " << get_x()
                    << std::endl;
        }

};


#endif //CIRCLE_H