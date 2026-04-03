/* 
youtube video notes, nested loops, code beauty, 
nesting loops, comnbining and nesting loops. 
*/

#include <iostream>

using namespace std;
// want user to enter three grades between 1 and 5 and write the average grade.

int main() 
{
    int grade, sum = 0; 
    for (int i = 0; i < 3; i++)
    {
        do 
        {
            cout << "enter grade: " << i + 1 << ": " << endl; 
            cin >> grade; 
        }
        while (grade < 1 || grade > 5); 
        sum += grade; 
    }
    cout << "average grade is: " << sum / 3.0 << endl;

}