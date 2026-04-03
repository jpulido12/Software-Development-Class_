#include <iostream>
#include <cmath>
using namespace std;
// PUT PROTOTYPES HERE
void input(double &accreal, double &accimag);
void output(double accreal, double accimag);
void add(double &accreal, double &accimag, double secreal, double secimag);
void sub(double &accreal, double &accimag, double secreal, double secimag);
void mult(double &accreal, double &accimag, double secreal, double secimag);
bool divide(double &accreal, double &accimag, double secreal, double secimag);
double magnitude(double accreal, double accimag);

int main()
{
double accreal, accimag, secreal, secimag;
char command;
cout << "Welcome to complex calculator:\n" <<
"Input the real and imaginary parts of accxumulator: ";
input(accreal, accimag);
while (1 == 1) {
output(accreal, accimag);
cout << "Command(+,-,*,/,M,R,X): ";
cin >> command;
if (command == 'X') {
break;
}
else if (command == '+') {
input(secreal, secimag);
add(accreal, accimag, secreal, secimag);
}
else if (command == '-') {
input(secreal, secimag);
sub(accreal, accimag, secreal, secimag);
}
else if (command == 'R') {
input(accreal, accimag);
}
else if (command == '*') {
input(secreal, secimag);
mult(accreal, accimag, secreal, secimag);
}
else if (command == '/') {
input(secreal, secimag);
if (divide(accreal, accimag, secreal, secimag)) {
cout << "Division by 0 error\n";
}
}
else if (command == 'M') {
cout << "Magnitude is " << magnitude(accreal, accimag) << 
endl;
}
else {
cout << "Illegal command\n";
}
}
}
// PUT FUNCTIONS HERE
void input(double &accreal, double &accimag){
    cin >> accreal >> accimag;
}
void output(double accreal, double accimag){
    cout << "Accumulator: " << accreal << " + " << accimag << "i" << endl;
}
void add(double &accreal, double &accimag, double secreal, double secimag){
    accreal += secreal;
    accimag += secimag;
}
void sub(double &accreal, double &accimag, double secreal, double secimag){
    accreal -= secreal;
    accimag -= secimag;
}
void mult(double &accreal, double &accimag, double secreal, double secimag){
    double temp = accreal;
    accreal = (accreal * secreal) - (accimag * secimag);
    accimag = (temp * secimag) + (accimag * secreal);
}
bool divide(double &accreal, double &accimag, double secreal, double secimag){
    if (secreal == 0 && secimag == 0){
        return true;
    }
    else{
        double temp = accreal;
        accreal = ((accreal * secreal) + (accimag * secimag)) / ((secreal * secreal) + (secimag * secimag));
        accimag = ((accimag * secreal) - (temp * secimag)) / ((secreal * secreal) + (secimag * secimag));
        return false;
    }
}

double magnitude(double accreal, double accimag){
    return sqrt((accreal * accreal) + (accimag * accimag));
}

