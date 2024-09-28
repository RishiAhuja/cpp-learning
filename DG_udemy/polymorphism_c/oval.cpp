#include "oval.h"

Oval::Oval(double p_x, double p_y, std::string p_description) : 
Shape(p_description), m_x(p_x), m_y(p_y){};

Oval::~Oval(){};