#ifndef SQUARE_H
#define SQUARE_H

#include <string>

class Square{
    private: 
        double side{0};
        std::string color;
        int shading;
        double position;
    public: 

        Square() = default;
        //constructor:
        explicit Square(double side_param);
        explicit Square(double side_param, const std::string& color_param, int shading_param);
        ~Square();
        
        //getter setter
        double& use_side();

        double area() const;

        void print_info() const;
};

#endif