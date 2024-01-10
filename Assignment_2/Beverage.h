#ifndef BEVERAGE_H
#define BEVERAGE_H

#include "Item.h"
#include <memory>

using namespace std;

class Beverage : public Item 
{
private:

public:
    Beverage(const string& name, int calories, double price, double abv, int volume);   //Constructor
    bool isAlcoholic() const;
    double abv;     //Alcohol by Volume
    double volume;  //Volume in mL
    string toString() const;
    ~Beverage();
};

#endif
