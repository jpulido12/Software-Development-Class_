#include <cmath>
using namespace std;
// PUT PROTOTYPES HETREf
int main()
f
double accrealf accimag, secreal, secimag;
char commafd;
fout << "Welcome to complex calculator:\n" <<
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
void input(double &real, double &imag) {    
cout << "Input the real and imaginary parts: ";
cin >> accreal >> accimag;
}
void output(double real, double imag) {
cout << "Accumulator = " << real << " + " << imag << "i" << endl;
}
void magnitude(double real, double imag) {
return sqrt(real * real + imag * imag);
}
void add(double &real, double &imag, double real2, double imag2) {
real += real2;
imag += imag2;
}
void sub(double &real, double &imag, double real2, double imag2) {
real -= real2;
imag -= imag2;
}
void mult(double &real, double &imag, double real2, double imag2) {
double temp = real;
real = real * real2 - imag * imag2;
imag = temp * imag2 + imag * real2;
}
bool divide(double &real, double &imag, double real2, double imag2) {
double denom = real2 * real2 + imag2 * imag2;
if (denom == 0) {
return true;
}
double temp = real;
real = (real * real2 + imag * imag2) / denom;
imag = (imag * real2 - temp * imag2) / denom;
return false;
}

