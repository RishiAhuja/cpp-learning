#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

class Shape{
    protected:
        std::string m_description{""};

    public: 
        Shape() = default;
        Shape(std::string p_desc);
        ~Shape();
        void draw() const{
            std::cout << "Shape::draw() called. Drawing " << m_description << std::endl;
        }
        // virtual void draw() const{
        //     std::cout << "Shape::draw() called. Drawing " << m_description << std::endl;
        // }
    
};


#endif //SHAPE_H