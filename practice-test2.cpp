/* 
practice problem 1, test 2 
write a class circle with :
private field center_x, center_y, radius. these are all double.
public methods:
generic generator
generator_circle(c_x, c_y, rad)
get_center_x()
get_center_y()
get_radius()
read which returns a cricle 
print which prints a circle

Write a function 
bool inside(circle c, double px, doubly py)
which returns true if (px, py) is inside the circle and false if it is not. 
this function is not a method of the class

*/

#include <iostream>
#include <cmath>
using namespace std;

//write class circle 
class circle {
    private: 
        double center_x, center_y, radius;
    public:
        circle() {
            center_x = 0;
            center_y = 0;
            radius = 0;
        }
        circle(double c_x, double c_y, double rad) {
            center_x = c_x;
            center_y = c_y;
            radius = rad;
        }
        double get_center_x() {
            return center_x;
        }
        double get_center_y() {
            return center_y;
        }
        double get_radius() {
            return radius;
        }
        void read() {
            cout << "Enter center x: ";
            cin >> center_x;
            cout << "Enter center y: ";
            cin >> center_y;
            cout << "Enter radius: ";
            cin >> radius;
        }
        void print() {
            cout << "Center: (" << center_x << ", " << center_y << ")" << endl;
            cout << "Radius: " << radius << endl;
        }
};
bool inside(circle c, double px, double py) {
    double distance = sqrt(pow(px - c.get_center_x(), 2) + pow(py - c.get_center_y(), 2));
    if (distance < c.get_radius()) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    circle c1, c2(5,3,1); 
    c1.read();
    c1.print();
    c2.print();
    if (inside(c2, 2, 1.5)){
        cout << "inside" << endl; 
    }
    else {
        cout << "outside" << endl; 
    }
}