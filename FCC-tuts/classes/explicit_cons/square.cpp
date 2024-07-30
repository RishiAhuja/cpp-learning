#include "square.h"
#include <iostream>

using namespace std;

Square::Square(double side_param) : side(side_param){
    //empty
}

Square::Square(double side_param, const std::string& color_param, int shading_param)
 : side(side_param), color(color_param), shading(shading_param){
    //empty
}

double& Square::use_side(){
    return side;
};

double Square::area() const{
    return side * side;
}

void Square::print_info() const{
            cout << "Side: " << side << endl;
            cout << "color: " << color << endl;
            cout << "shading: " << shading << endl;
            cout << "position: " << position << endl;
        };
Square::~Square(){};

