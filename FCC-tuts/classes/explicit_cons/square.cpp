#include "square.h"
#include <iostream>

using namespace std;


// Square::Square(double side_param) : side(side_param){
//     cout << "One param constructor was called" << endl;
// }

// Square::Square(double side_param, const std::string& color_param, int shading_param)
//  : side(side_param), color(color_param), shading(shading_param){
//     cout << "Three param constructor was called" << endl;
// }

//delegation:
Square::Square(double side_param) : Square(side_param, "Black", 6){
    cout << "One param constructor was called" << endl;
}

Square::Square(double side_param, const std::string& color_param, int shading_param)
 : side(side_param), color(color_param), shading(shading_param){
    cout << "Three param constructor was called" << endl;
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

