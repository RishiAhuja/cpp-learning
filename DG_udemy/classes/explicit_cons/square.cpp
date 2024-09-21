#include "square.h"

Square::Square(double side_param, const std::string& color_param = "black") : side(side_param), color(color_param){
    //empty
}

double& Square::use_side(){
    return side;
};

double Square::area() const{
    return side * side;
}

Square::~Square(){};

