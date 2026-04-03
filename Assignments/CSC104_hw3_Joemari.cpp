#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int howMany, first, second, third, count;
    cout << "how many fibonacci numbers do you want to see? ";
    cin >> howMany;
    first = 1;
    second = 0;
    for (int i = 0; i < howMany; i++){
        third = first + second;
        first = second;
        second = third;
        cout << setw(5) << third ;
        count++; 
        if(count % 6 == 0){
            cout << endl;
        }
    }
    return 0;
}