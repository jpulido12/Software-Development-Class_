/* 
Joemari Pulido, CSC104, April 08 2023, Lab 8
This problem is to work with polynomials. 
The expression is a sum of terms where each term has the form ax^n where a 
is a double number, x is a variable and n is a non negative integer number. 
the highest value of n is called the degree of the polynomial. 
it is easier if we always write and store the polynomial with the highest n
to the left and then the term with the next highest exponent and so on contains. 
the starter file contains the body of the function to overload the plus sign. 
you will have to put the header on it. 
Instructions: 
first, create a class polynomial. 
(a) the private portion of the class must have: 
- a double vector of the coefficients . 
- an int vector of the exponents
- an int num_terms
- an int degree
(b) the public portion of the class must have: 
- a generic constructor
- a method init which will prompt for and read a polynomial. 
you should read the terms in order from the largest exponent to the smallest. 
each term should be read as a coefficient exponent. Use input of 0 0 to stop the read in. 
- a method print which will print a polynomial. it is probably more convenient
to print the polynomial in the form 9x^3 + 3x^2+ -5. 
- a method get_degree of type int which returns the defree of the polynomial. 
- a method get_num_terms of type int which returns the number of terms in the polynomial. 
- methods get_exp(i) and get _coeff(i) which returnt he ith coeffecient and the ith exponent. 
- method add_term(douvle c, int e) which adds a new term to the polynomial by pushing 
the c onto the coef vector and the e onto the exp vector.
Second, complete the overload of + to add two polynomials by filling in the heading. 
input terms in order from largest exponenet to lowest exponent (00 to end) 
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
polynomial() {};
void init() {
double c;
int e;
cout << "input terms in order from largest exponent to lowest
exponent (00 to end) ";
cin >> c >> e;
while (c != 0 || e != 0) {
add_term(c, e);
cin >> c >> e;
}
set_degree(get_exp(0));
set_num_terms(get_exp.size());
}
void print() {
for (int i = 0; i < get_num_terms(); i++) {
cout << get_coef(i) << "x^" << get_exp(i) << " ";
}
}
int get_degree() {
return degree;
}
int get_num_terms() {
return num_terms;
}
int get_exp(int i) {
    
private:

// a double vector of the coefficients

// an int vector of the exponents
// an int num_terms
// an int degree
};
//THIS IS THE OVERLOAD OF ADD
//PUT THE HNEADING FOR IT HERE
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
cout << "degree of p1 is " << p1.get_degree() << " and number of
terms in p1 is "
<< p1.get_num_terms() << endl;
cout << "degree of p2 is " << p2.get_degree() << " and number of
terms in p2 is "
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