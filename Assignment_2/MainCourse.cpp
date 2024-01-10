#include "MainCourse.h"
#include <string>
#include <memory>
#include <iomanip>
#include <sstream> 
using namespace std;

MainCourse::MainCourse(const string& name, int calories, double price): Item(name, calories, price) 
{

}

string MainCourse::toString() const 
{
    string result = "Main Course: " + name + "\n";
    ostringstream formattedPrice;
    formattedPrice << fixed << setprecision(2) << getPrice();
    result += "Price: $" + formattedPrice.str() + "\n";

    return result;
}

MainCourse::~MainCourse() 
{
    
}