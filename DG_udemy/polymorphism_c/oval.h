#ifndef OVAL_H
#define OVAL_H

#include <iostream>
#include "shape.h"
class Oval : public Shape {
    private:
        double m_x{0};
        double m_y{0};
    public: 
        Oval() = default;
        Oval(double p_x, double p_y, std::string p_description);
        ~Oval();

        //member functions
        //getters as setters
        double& get_x(){
            return m_x;
        }
        double& get_y(){
            return m_x;
        }

        void draw() const{
        std::cout << "Oval::draw() called. Drawing " << m_description <<
            " with m_x_radius : " << m_x << " and m_y_radius : " << m_y 
                    << std::endl;
        }
        // virtual void draw() const{
        // std::cout << "Oval::draw() called. Drawing " << m_description <<
        //     " with m_x_radius : " << m_x << " and m_y_radius : " << m_y 
        //             << std::endl;
        // }
};

#endif