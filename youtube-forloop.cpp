// youtube video c++ for beginners for loop 
//how to calculate factorial of a number using for loop Codebeauty

#include <iostream>
using namespace std; 

//for loop used when know number of iterations 

int main() // function to calculate factorial of a number 
//6! = 6*5*4*3*2*1 = 720
{
    int number; 
    cout << "Number: " << endl; 
    cin >> number; 
    int factorial = 1; 

   /* for (int i = 1; i <= number; i++) // three things to include in for loop: initialization, condition and incrementor/decrementor
    {
        factorial = factorial * i;  // factorial *= i;
        return 0;

    }*/
    //another way to write for loop is to decrease the number of iterations by 1
    for (int i = number; i >= 1; i--) 
    {
        factorial = factorial * i; // factorial *= i;
        return 0;
    }
    cout << number << "! = " << factorial << endl;

}
