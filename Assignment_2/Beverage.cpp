#include "Beverage.h"
#include <string>
#include <memory>
#include <iomanip>
#include <sstream> 

using namespace std;

//Constructor for the Beverage class
Beverage::Beverage(const string& name, int calories, double price, double abv, int volume) : Item(name, calories, price), abv(abv), volume(volume)
{

}

bool Beverage::isAlcoholic() const      //Check if the beverage is alcoholic based on Alcohol by Volume (ABV)
{
    return abv > 0.0;
}


string Beverage::toString() const       //Convert Beverage object to a string for display
{
    string isAlcoholicStr = isAlcoholic() ? "Yes" : "No";    //Convert isAlcoholic to string for display

    //Create a string representation of the beverage
    string result = "Beverage: " + name + "\n";
    ostringstream formattedPrice;
    formattedPrice << fixed << setprecision(2) << getPrice();
    result += "Price: \x9C" + formattedPrice.str() + "\n";
    ostringstream formattedAbv;
    formattedAbv << fixed << setprecision(2) << abv;
    result += "Alcohol by Volume (ABV): " + formattedAbv.str() + "%\n";
    ostringstream formattedVolume;
    formattedVolume << fixed << setprecision(2) << volume;
    result += "Volume: " + formattedVolume.str() + " ml\n";
    result += "Is Alcoholic: " + isAlcoholicStr + "\n";

    return result;
}

Beverage::~Beverage()       //Destructor for the Beverage class
{

}
