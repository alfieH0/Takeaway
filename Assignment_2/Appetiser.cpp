#include "Appetiser.h"
#include <string>
#include <memory>

using namespace std;

// Constructor implementation
Appetiser::Appetiser(const string& name, int calories, double price, bool shareable, bool twoForOne)
: Item(name, calories, price), shareable(shareable), twoForOne(twoForOne) {
    // Additional initialization if needed
}

// toString method implementation
string Appetiser::toString() const {
    // Convert shareable and twoForOne to string for display
    string shareableStr = shareable ? "Yes" : "No";
    string twoForOneStr = twoForOne ? "Yes" : "No";

    // Create a string representation of the Appetiser
    string result = "Appetiser: " + getName() + "\n";
    result += "Price: $" + to_string(getPrice()) + "\n";
    result += "Shareable: " + shareableStr + "\n";
    result += "Two For One: " + twoForOneStr + "\n";

    return result;
}

Appetiser::~Appetiser() {
    // No additional cleanup needed for now
}