#include <iostream>
#include <cmath>

using namespace std; 

int main () {

    float test = 7.7f;
    
    //rounding down and up using floor and ceil
    cout << "floor: " << floor(test) << endl;
    cout << "ceil: " << ceil(test) << endl;


    //absolute values

    double d1 {-500};
    cout << "abs: " << abs(d1) << endl;
    cout << "abs: " << abs(test) << endl;


    //exponential values
    int exp1 {3};
    cout << "exp: " << exp(exp1) << endl;

    //powers
    int p1 {2};
    int p2 {10};
    cout << "power: " << pow(p1,p2) << endl;


    //log
    float l1 {2.71f};
    int l2 {100};
    cout << "log: " << log(l1) << endl;
    cout << "log: " << log10(l2) << endl;

    //sqrt
    int sq1 {81};
    cout << "sqrt: " << sqrt(sq1) << endl;


    //round
    float f1 {2.34f};
    float f2 {2.5f};
    cout << "round: " << round(f1) << endl;
    cout << "round: " << round(f2) << endl;


    //trigonometric functions

    cout << "arcsin: " << asin(1) << endl;
    return 0;
}