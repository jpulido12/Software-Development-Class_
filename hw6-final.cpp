/* 
Joemari Pulido, CSC104, March 24 2023, Lab 6
Suppose a drunken sailor is on shore leave is staying at hotel 666
he went out on the town and is walking eratically, he is walking randomly. 
he is win a well laid out city like new york where the streets and the avenues
meet at right angles and we can model the street layout as a simple lattice. 
we assume the city has 10 streets numbered 1 to 10 with 1 at the north edge of the city
and 10 avenues numbered street 1 to 10 with avenue 1 at the west edge of the city. 
hotel666 is at the corner of avenue 7 ans street 4, we write this as (7,4). 
and our sailor's bar where he starts his walk at avenue 8 and street 9 (8,9). 
a shore patrol officer is at avenue 3 and street 10, (3,10). at each step the sailor moves once 
block N, S, E, or W randomly. his mind is a 4 sided die in which he rolls before each step. 
If the roll is 1, he goes N. if he rolls 2, he goes E. if the rolls is 3, he goes S. if he 
rolls 4, he goes W. Our city is a walled city. if he hits the edge, he bounces off and 
tries to move again from the same spot. 

Instruction: write a c++ program which will show the sailor's progress as he tries 
to get to his hotel. if he gets to his hotel, write at the end of the output that "sailor
is sleeping in his room at hotel666." if he gets to where the shore patrol officer is, 
write at the end of the report that "sailor is on his way to the brig."
values can not exceed 10 or be less than 1.
exit the program when the sailor is at the hotel or the patrol officer.
*/

#include <iostream> 
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int street, avenue, roll, patrolStreet, patrolAvenue, hotelStreet, hotelAvenue; //declare variables
    srand(time(0)); //seed random number 
    street = 9; //initialize street to bar street 
    avenue = 9; // initiliaze avenue to bar avenue 
    patrolStreet = 10; //declare patrolStreet with given value of 10
    patrolAvenue = 3; //declare patrolAvenue with given value of 3
    hotelStreet = 4; //declare hotelStreet with given value of 4
    hotelAvenue = 8; //declare hotelAvenue with given value of 8
    //output initial position of sailor at the bar
    cout << "Sailor is at " << "(" << avenue << "," << street << ")" << endl; 
    //while loop to keep sailor moving and output current position until he reaches hotel or shore patrol
    while(street != hotelStreet || avenue != hotelAvenue || street != patrolStreet || avenue != patrolAvenue)
    {
        roll = rand() % 4 + 1; //generate random number between 1 and 4
        //if statement to determine direction of sailor's movement
        if(roll == 1)
        {
            street++; //move sailor one block north
            //if statement to determine if sailor is at the edge of the city
            if(street > 10)
            {
                street--; //bounce sailor back to previous position
            }
            //output current position of sailor
            cout << "Sailor is at " << "(" << avenue << "," << street << ")" << endl;
        }
        else if(roll == 2)
        {
            avenue++; //move sailor one block east
            //if statement to determine if sailor is at the edge of the city
            if(avenue > 10)
            {
                avenue--; //bounce sailor back to previous position
            }
            //output current position of sailor
            cout << "Sailor is at " << "(" << avenue << "," << street << ")" << endl;
        }
        else if(roll == 3)
        {
            street--; //move sailor one block south
            //if statement to determine if sailor is at the edge of the city
            if(street < 1)
            {
                street++; //bounce sailor back to previous position
            }
            //output current position of sailor
            cout << "Sailor is at " << "(" << avenue << "," << street << ")" << endl;
        }
        else if(roll == 4)
        {
            avenue--; //move sailor one block west
            //if statement to determine if sailor is at the edge of the city
            if(avenue < 1)
            {
                avenue++; //bounce sailor back to previous position
            }
            //output current position of sailor
            cout << "Sailor is at " << "(" << avenue << "," << street << ")" << endl;
        }
        //if statement to check if sailor is at hotel and output given output
        if(street == hotelStreet && avenue == hotelAvenue)
        {
            //output sailor is sleeping in his room at hotel666
            cout << "Sailor is sleeping in his room at hotel666." << endl;
            break; //exit program

}
        //if statement to check if sailor is at shore patrol and output given output
        if(street == patrolStreet && avenue == patrolAvenue)
        {
            //output sailor is on his way to the brig
            cout << "Sailor is on his way to the brig." << endl;
            break; //exit program
        }
    }
    return 0;
}
