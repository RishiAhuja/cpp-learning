#include <iostream>

using namespace std;

const double PI {3.14159};

class Circle
{
    private: 
        double radius;

    public:

        Circle() = default;
        Circle(double radius_param){
            radius = radius_param;
        }

        double get_area(){
            return PI * radius * radius;
        }

        double get_circum(){
            return 2 * PI * radius;
        }

        //getter & setters

        double get_radius() {
            return radius;
        }

        void set_radius(double rad_param){
            radius = rad_param;
        }
};

int main()
{
    Circle my_circle(10);

    cout << "Area: " << my_circle.get_area() << endl;
    my_circle.set_radius(20);
    cout << "Circumfrence: " << my_circle.get_circum() << endl;
    cout << "Getting radius: " << my_circle.get_radius() << endl;
    
}