/* 
youtube practice, classes, constructors, class methods, how to use them
code beauty
to solve problem of not having to repeat use constructor
constructor has the same name as the class
constructor does not have a return type
class methods describe the behavior of the class
*/

#include <iostream>
#include <list> 
#include <string>

using namespace std;

class YoutubeChannel  // created class YoutubeChannel
{
    public: 
    string name;
    string ownerName; 
    int Subscribercount; 
    list<string> publishedVideoTitles;

    YoutubeChannel(string name, string ownerName) //constructor two parameters that will be passed to constructor
    {
        name = name; 
        ownerName = ownerName;
        Subscribercount = 0; 
    }
    void GetInfo()
    {
    cout << "Name: " << name << endl; 
    cout << "Owner Name: " << ownerName<< endl; 
    cout << "Subscriber Count: " << Subscribercount << endl; 
    cout << "Videos: " << endl; 
    for (string videoTitle : publishedVideoTitles)
    {
        cout << videoTitle << endl; 
    }
    }

};

int main()
{
    YoutubeChannel ytChannel("CodeBeauty", "Joemari"); // created object of class YoutubeChannel which is an instance of the class
    ytChannel.publishedVideoTitles.push_back("C++ for beginners");
    ytChannel.publishedVideoTitles.push_back("html for intermediate");
    ytChannel.publishedVideoTitles.push_back("oop for advanced");
    ytChannel.GetInfo();
    
}