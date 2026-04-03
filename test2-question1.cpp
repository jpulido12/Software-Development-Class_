/*
Joemari Pulido, CSC 104, test 2, question 1
define a clas 'mat'. this class represents a 3 by 3 array. 
your class must have: 
public methods: 
generic generator
generator which is given the 9 values of the mat
accessor get_val(r,c) which return the value in row r and column c 
modifier set_val(r,c, num) which sets the value in row r and column c to num 
read mat 
print mat in form shown in the example: 
6 12 3
9 4 7 
2 8 15 
method mult(num) which returns a new mat with all the elements of the original multiplied by num
the private section of the class has an array vals[3[[3]]]
print m1 which print the mat 1 

*/

#include <iostream> 
using namespace std;
class mat {
    private: // private section of the class has an array vals[3][3]
    int vals [3][3]; 
    public: // public section of the class, declare methods
    mat(){
        for (int i = 0; i < 3; i++){
            for (int j = 0; i < 3; j++){
                vals = 0;
            }
       }
    }    mat(int a, int b, int c, int d, int e, int f, int g, int h, int i) // generator which is given the 9 values of the mat
    {
        vals[0][0] = a; // set the values of the array to the values given
        vals[0][1] = b; 
        vals[0][2] = c;

    }
    int get_val(int r, int c) // accessor get_val(r, c) which returns the value in row r, column c
    {
        return vals[r][c]; // return value in the array at row r and column c
    }
    void set_val(int r, int c, int num) // modifier set_val(r, c, num) which sets the value in row r, column c, to num
    {
        vals[r][c] = num; // set the value in the array at row r and column c to num 
    }
    void read() // read mat
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << "enter value for row " << i << "column "<< j << "j: "; // read in values
                cin >> vals[i][j];
            }
        }
    }
    void print() // print mat in form requested
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++) 
            {
                cout << vals[i][j] << " "; // print values in the array
            }
            cout << endl; // print a new line after each row
        }
    }
    mat mult(int num) // method mult(num) which returns a new mat with all the elements of the original multiplied by num
    {
        mat m; // create the new mat
        for (int i = 0; i < 3; i++) // loop through the new mat
        {
            for( int j = 0; j < 3; j++)
            {
                m.set_val(i, j, vals[i][j] * num); //set the value of the new mat to the original values multiplied by num
            }
        }
    }
};

int main() // program given to test the class 
{
    mat m1, m2(3,5,2,6,4,1,10,9, 11), m3;
    m1.read(); 
    cout << "m1 is " << endl;
    m1.print(); 
    cout << "m2 is " << endl; 
    m2.print();
    m3 = m2.mult(4); 
    cout << "m3 is " << endl; 
    m3.print(); 
}