#include "Item.h"
#include <iostream>
#include <cstring>
#include <string>
#include <memory>

using namespace std;

// Constructor implementation
Item::Item(const string& name, int calories, double price)
    : name(name), calories(calories), price(price) {
    // No need for dynamic memory allocation for name
}

// Destructor implementation
Item::~Item() {
    // Clean up dynamically allocated memory

}

string Item::toString() const
{
    // Create a string representation of the item
    string result = "Item: " + getName() + "\n";
    result += "Calories: " + to_string(getCalories()) + "\n";
    result += "Price: $" + to_string(getPrice()) + "\n";

    return result;
}