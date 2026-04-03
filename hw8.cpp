/*
Joemari Pulido, CSC104, April 08 2023, Lab 8
This problem is to work with the concept of polynomials. 
a polynomial is an expression such as 9x^3 + 3x^2 + 5. 
The expression is a sum of terms where each term has the form ax^n 
where a is a double numner, x is a variable and n is a non-negative integer number. 
the highest value of n is called the degree of the polynomial. 
In the example, the polynomial is of degree 3. It is easier if we always write and store
the polynomial with the highest n to the left and then the term with the next highest exponent and so on contains
the start file contains the body of the function to overload plus sign. 
You will have to put the header on it. 

First, create a class polynomial. 
(a) the private portion of the class must have: 
- a double vector of the coefficients
- an int vector of the exponents
- an int num_terms
- an int degree
(b) the public portion of the class must have:
- a generic constructor
- a method init which will prompt for and read a polynomial.
you should read the terms in order from the largest exponent to the smallest.
each term should be read as a coefficient exponent. Use input of 0 0 to stop the read in.
- a method print which will print a polynomial. It is probably more convenient
to print the polynomial in the form 9x^3 + 3x^2 + -5.
- a method get_degree of type int which returns the degree of the polynomial.
- a method get_num_terms of type int which returns the number of terms in the polynomial.
- methods get_exp(i) and get_coeff(i) which return the ith coefficient and the ith exponent.
- method add_term(double c, int e) which adds a new term to the polynomial by pushing
the c onto the coef vector and the e onto the exp vector.

Second, complete the overload of + to add two polynomals by filling in the heading. 
input terms in order rom largest exponent to lowest exponent (00 to end)
7 4
6 3
2 1
0 0
input terms in order from largest exponent to lowest exponent (00 to end)
6 6
4 3
7 1
8 0
0 0
degree of p1 is 4 and number of terms in p1 is 3
degree of p2 is 6 and number of terms in p2 is 4
p1 is 7x^4 + 6x^3 + 2x^1
p2 is 6x^6 + 7x^4 + 4x^3 + 8x^0
p3 is 6x^6 + 7x^4 + 6x^3 + 2x^1 + 8x^0
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
using namespace std;
class polynomial {
public:
polynomial() {
num_terms = 0;
degree = 0;
}
void init() {
double c;
int e;
cout << "input terms in order from largest exponent to lowest exponent (00 to end)" << endl; // prompt values from user
cin >> c >> e; // read in values
while (c != 0 || e != 0) {
add_term(c, e);
cin >> c >> e;
}
}
void print() { // print 
for (int i = 0; i < num_terms; i++) {
if (i == 0) {
cout << coef[i] << "x^" << exp[i];
}
else {
cout << " + " << coef[i] << "x^" << exp[i];
}
}
}
int get_degree() { // returns degree 
return degree;
}
int get_num_terms() { // returns number of terms in polynomial
return num_terms;
}
int get_exp(int i) { // returns ith coefficient and exponent
return exp[i];
}
double get_coef(int i) {
return coef[i];
}
void add_term(double c, int e) { //which adds a new term to the polynomial by pushing the c onto the coef vector and the e onto the exp vector.
coef.push_back(c);
exp.push_back(e);
num_terms++;
if (e > degree) {
degree = e;
}
}
void set_degree(int d) {
degree = d;
}
void set_num_terms(int n) {
num_terms = n;
}


private:
vector<double> coef; // double vector of coeff
vector<int> exp; // int vector of exponents
int num_terms; // int num of terms
int degree; // int degree
};
    
//THIS IS THE OVERLOAD OF ADD
polynomial operator+(polynomial a, polynomial b) // added header to overload 

{
int nexta = 0, nextb = 0, nterms = 0;
polynomial ans;
while (nexta < a.get_num_terms() && nextb < b.get_num_terms()) {
if (a.get_exp(nexta) == b.get_exp(nextb)) {
if (a.get_coef(nexta) + b.get_coef(nextb) != 0) {
ans.add_term(a.get_coef(nexta) + b.get_coef(nextb),
a.get_exp(nextb));
nexta++;
nextb++;
nterms++;
}
else {
nexta++;
nextb++;
}
}
else if (a.get_exp(nexta) > b.get_exp(nextb)) {
ans.add_term(a.get_coef(nexta),a.get_exp(nexta));
nexta++;
nterms++;
}
else {
ans.add_term(b.get_coef(nextb), b.get_exp(nextb));
nextb++;
nterms++;
}
}
if (nextb < b.get_num_terms()) {
for (int t = nextb; t < b.get_num_terms(); t++) {
ans.add_term(b.get_coef(t), b.get_exp(t));
nterms++;
}
}
if (nexta < a.get_num_terms()) {
for (int t = nexta; t < a.get_num_terms(); t++) {
ans.add_term(a.get_coef(t), a.get_exp(t));
nterms++;
}
}
ans.set_degree(ans.get_exp(0));
ans.set_num_terms(nterms);
return ans;
};
int main()
{
polynomial p1, p2;
p1.init();
p2.init();
cout << "degree of p1 is " << p1.get_degree() << " and number of terms in p1 is " << p1.get_num_terms() << endl;
cout << "degree of p2 is " << p2.get_degree() << " and number of terms in p2 is "
<< p2.get_num_terms() << endl;
cout << "p1 is ";
p1.print();
cout << endl;
cout << " p2 is ";
p2.print();
cout << endl;
polynomial p3 = p1 + p2;
cout << " p3 is ";
p3.print();
cout << endl;
return 0;
}

