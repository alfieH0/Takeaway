#include "Item.h"
#include <iostream>
#include <cstring>
#include <string>
#include <memory>
#include <iomanip>
#include <sstream> 
using namespace std;

Item::Item(const string& name, int calories, double price): name(name), calories(calories), price(price) {
}

Item::~Item() 
{

}

string Item::toString() const
{
    string result = "Item: " + getName() + "\n";
    result += "Calories: " + to_string(getCalories()) + "\n";
    ostringstream formattedPrice;
    formattedPrice << fixed << setprecision(2) << getPrice();
    result += "Price: \x9C" + formattedPrice.str() + "\n";

    return result;
}