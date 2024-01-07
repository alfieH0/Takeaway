// MainCourse.cpp

#include "MainCourse.h"
#include <string>
#include <memory>

using namespace std;

// Constructor implementation
MainCourse::MainCourse(const string& name, int calories, double price)
    : Item(name, calories, price) {
    // Additional initialization if needed
}

// toString method implementation
string MainCourse::toString() const {

    // Create a string representation of the main course
    string result = "Main Course: " + name + "\n";
    result += "Price: $" + to_string(price) + "\n";

    return result;
}

MainCourse::~MainCourse() {
    // No additional cleanup needed for now
}