/*
practice problem 2 , test 2

in this problem assume that the upper left corner 
of teh rectangle E2 is inside rectangle R1 
Write a class rectangle with 
Private fields integer II_x, II_y, height, width. 
Public methods 
generic generator
generator rectangle (int x, int y, int h, int w)
get_II_x()
get_II_y()
get_height()
get_width()
print 
Area
Write an overload of - so that r1 - r2 = area of r1 - area of the part of r2 inside r1

*/

#include <iostream>
#include <cmath>
using namespace std; 

//write class rectangle
class rectangle
{
    private: 
    int II_x, II_y, height, width; 
    public: 
    rectangle() {
        II_x = 0;
        II_y = 0;
        height = 0;
        width = 0;
    }
    rectangle(int x, int y, int h, int w) {
        II_x = x;
        II_y = y;
        height = h;
        width = w;
    }
    int get_II_x() {
        return II_x;
    }
    int get_II_y() {
        return II_y;
    }
    int get_height() {
        return height;
    }
    int get_width() {
        return width;
    }
    void print() {
        cout << "II_x: " << II_x << endl;
        cout << "II_y: " << II_y << endl;
        cout << "height: " << height << endl;
        cout << "width: " << width << endl;
    }
    int area() {
        return height * width;
    }
    int operator-(rectangle r2) {
        int x = 0;
        if (II_x < r2.II_x && II_y < r2.II_y) {
            x = (II_x + width) - r2.II_x;
            x *= (II_y + height) - r2.II_y;
        }
        return area() - x;
    }


};


int main() { 
    rectangle r1(10, 15, 20, 25), r2(5, 18, 12, 30); 
    r1.print();
    r2.print();
    cout << "Area of r1: " << r1.area() << endl;
}
