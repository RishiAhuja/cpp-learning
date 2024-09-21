#include <iostream>

using namespace std;

class cylinder
{
    private:
        double radius {1};
        double height {1};
    
    public: 

        //constructors
        /*.......*/

        cylinder() = default;
        cylinder(double radius_param, double height_param){
            height = height_param;
            radius = radius_param;
        };

        //Getters
        double get_radius()
        {
            return radius; //returning a copy
        }

        double get_height()
        {
            return height; //returning a copy
        }

        //Setters
        void set_radius(double radius_param)
        {
            radius = radius_param;
        }

        void set_height(double height_param)
        {
            height = height_param;
        }
};

int main()
{
    cylinder cylinder1(2, 3);
    
    cylinder1.set_height(10);
    cylinder1.set_radius(10);

    cout << cylinder1.get_height() << endl;
}