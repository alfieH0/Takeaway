// Beverage.h

#ifndef BEVERAGE_H
#define BEVERAGE_H

#include "Item.h"
#include <memory>

using namespace std;

class Beverage : public Item {
private:
    double abv;     // Alcohol by Volume
    double volume;  // Volume in mL

public:
    // Constructor
    Beverage(const string& name, int calories, double price, double abv, double volume);

    // Method to check if the beverage is alcoholic
    bool isAlcoholic() const;

    // toString method
    string toString() const;

    ~Beverage();
};

#endif // BEVERAGE_H
