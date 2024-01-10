#include "Appetiser.h"
#include <string>
#include <memory>
#include <iomanip>
#include <sstream> 
using namespace std;

Appetiser::Appetiser(const string& name, int calories, double price, bool shareable, bool twoForOne): Item(name, calories, price), shareable(shareable), twoForOne(twoForOne) 
{

}

string Appetiser::toString() const 
{
    string shareableStr = shareable ? "Yes" : "No";
    string twoForOneStr = twoForOne ? "Yes" : "No";

    string result = "Appetiser: " + getName() + "\n";
    ostringstream formattedPrice;
    formattedPrice << fixed << setprecision(2) << getPrice();
    result += "Price: \x9C" + formattedPrice.str() + "\n";
    result += "Shareable: " + shareableStr + "\n";
    result += "Two For One: " + twoForOneStr + "\n";

    return result;
}

Appetiser::~Appetiser() 
{

}