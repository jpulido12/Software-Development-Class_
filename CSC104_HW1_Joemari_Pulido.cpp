# include <iostream>
using namespace std; 
int main() {
    int a, b, c, d, e, f, g, year;
    double result;
   
    cout << " Enter the year " << endl;
    cin >> year; 
    a = year % 19 + 1;
    b = year / 100 + 1;
    c = (3 * b) / 4 - 12;
    d = (8 * b + 5) / 25 - 5;
    e = (year * 5) / 4 - 10 - c;
    f = ((11 * a + 20 + d - c) % 30 + 30) % 30;
    if (f == 24  || f == 25 && a > 11) {
        f = f + 1;
    }
    g = 44 - f;
    if (g < 21) {
        g = g + 30;
    }
    result = g + 7 - (e + g) % 7;
    if (result > 31) {
        result = result - 31;
        cout << " Easter is on " << "April " << result << " " << year << endl;
        
    } else {
       cout << " Easter is on " << "March " << result << " " << year << endl; 
    }
    
}