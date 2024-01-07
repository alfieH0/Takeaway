// Beverage.cpp

#include "Beverage.h"
#include <string>
#include <memory>

using namespace std;

// Constructor implementation
Beverage::Beverage(const string& name, int calories, double price, double abv, double volume)
    : Item(name, calories, price), abv(abv), volume(volume) {
    // Additional initialization if needed
}

// isAlcoholic method implementation
bool Beverage::isAlcoholic() const {
    return abv > 0.0;
}

// toString method implementation
string Beverage::toString() const {
    // Convert isAlcoholic to string for display
    string isAlcoholicStr = isAlcoholic() ? "Yes" : "No";

    // Create a string representation of the beverage
    string result = "Beverage: " + name + "\n";
    result += "Price: $" + to_string(price) + "\n";
    result += "Alcohol by Volume (ABV): " + to_string(abv) + "%\n";
    result += "Volume: " + to_string(volume) + " mL\n";
    result += "Is Alcoholic: " + isAlcoholicStr + "\n";

    return result;
}

Beverage::~Beverage() {
    // No additional cleanup needed for now
}