#include "MainCourse.h"
#include <string>
#include <memory>
#include <iomanip>
#include <sstream> 

using namespace std;

MainCourse::MainCourse(const string& name, int calories, double price) : Item(name, calories, price)//Constructor for the MainCourse class
{

}

string MainCourse::toString() const//Convert MainCourse object to a string for display
{
    //Build the string representation of the MainCourse object
    string result = "Main Course: " + name + "\n";
    ostringstream formattedPrice;
    formattedPrice << fixed << setprecision(2) << getPrice();
    result += "Price: $" + formattedPrice.str() + "\n";

    return result;
}

MainCourse::~MainCourse()//Destructor for the MainCourse class
{
}
