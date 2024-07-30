#ifndef SQUARE_H
#define SQUARE_H

#include <string>

class Square{
    private: 
        double side{0};
        std::string color;
    public: 

        Square() = default;
        //constructor:
        explicit Square(double side_param, const std::string& color_param = "black");
        ~Square();

        //getter setter
        double& use_side();

        double area() const;
};

#endif