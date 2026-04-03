/*
Joemari Pulido, CSC104, March 31, 2023 , Lab 7
Lab 7 asks to write two classes: 
class date: 
this class defines a data type date with two fields smonth and syear. 
the class provides a generic constructor and a constructor date(month, year). 
There are two methods: get_smonth and get_syear which are accessors. 
class loan: 
this class defines a data type loan. Objects of this type are bank loans from banks  
where a person has borrowed an amount of money at a yearly interest rate and promised 
to pay it back in a certain number of years. 
An object loan has five fields. Principal is the amount that was borrowed. Rate
is the yearly rate expressed as a decimal. Num_years is how long you have to pay back the money. 
smonth is the month you make the first payment. syear is the year you make the first payment. 
fields must be private. 
need the following public methods:
a. loan(); 
b. loan(amount, years, yearlyrate, startingdate); 
c. get_principal(); 
d. get_rate(); 
e. get_num_years(); 
f. get_month(); 
g. get_year(); 
h. double get_payment();
Finally, write a function int current_per(loanobject, currentdate) which returns 
the number of the payment you are making in the current month. 
*/
#include <iostream> 
#include <iomanip>
#include <cmath>
using namespace std;

class date //class date
{
    private: 
    int smonth; 
    int syear; 
    public: 
    date() //generic constructor
    {
        smonth = 0; 
        syear = 0; 
    }
    date(int month, int year) //constructor date(month, year)
    {
        smonth = month; 
        syear = year; 
    }
    int get_smonth() //accessor for smonth
    {
        return smonth; 
    }
    int get_syear() //accessor for syear
    {
        return syear; 
    }
};

class loan //class loan
{
    private: 
    double principal; 
    double rate; 
    int num_years; 
    int smonth; 
    int syear; 
    public: 
    loan() //generic constructor
    {
        principal = 0; 
        rate = 0; 
        num_years = 0; 
        smonth = 0; 
        syear = 0; 
    }
    loan(double amount, int years, double yearlyrate, date startingdate) //loan(amount, years, yearlyrate, startingdate)
    {
        principal = amount; 
        rate = yearlyrate; 
        num_years = years; 
        smonth = startingdate.get_smonth(); 
        syear = startingdate.get_syear(); 
    }
    double get_principal() //accessor for principal
    {
        return principal; 
    }
    double get_rate() //accessor for rate
    {
        return rate; 
    }
    int get_num_years() //accessor for num_years
    {
        return num_years; 
    }
    int get_month() //accessor for smonth
    {
        return smonth; 
    }
    int get_year() //accessor for syear
    {
        return syear; 
    }
    double get_payment() //accessor for payment
    {
        double payment = principal * (rate/12) / (1 - pow((1 + rate/12), -12 * num_years)); 
        return payment; 
    }
};
int current_per(loan exl, date currentdate) //function current_per(loanobject, currentdate)
{
    int current_period = 0; 
    int current_month = currentdate.get_smonth(); 
    int current_year = currentdate.get_syear(); 
    int start_month = exl.get_month(); 
    int start_year = exl.get_year(); 
    int num_years = exl.get_num_years(); 
    int num_months = num_years * 12; 
    int months_passed = (current_year - start_year) * 12 + (current_month - start_month); 
    if (months_passed > num_months)
    {
        current_period = num_months; 
    }
    else
    {
        current_period = months_passed; 
    }
    return current_period; 
}



int main() // testing program given in lab assignment
{
    loan exl(10000, 3, 0.03, date(3,22)); 
    cout << "principal rate years payment start month start year: " <<
    exl.get_principal() << " " << exl.get_rate() << " " << exl.get_num_years() << 
    " " << exl.get_payment() << " " << exl.get_month() << " " << exl.get_year() << endl;
    cout << "current period for (6,22), (8,23), (9,25): " << current_per(exl, date(6,22)) <<
    " " << current_per(exl, date(8,23)) << " " << current_per(exl, date(9,25)) << endl; 
    return 0; 
}