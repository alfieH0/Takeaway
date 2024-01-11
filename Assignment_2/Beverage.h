#ifndef BEVERAGE_H
#define BEVERAGE_H

#include "Item.h"
#include <memory>

class Beverage : public Item
{
public:
    Beverage(const string& name, int calories, double price, double abv, int volume);    //Constructor for the Beverage class

    bool isAlcoholic() const;   //Checks if the beverage is alcoholic
    double abv;                 //Alcohol by Volume
    double volume;              //Volume in mL
    string toString() const;    //Convert Beverage object to a string for display

    ~Beverage();    //Destructor for the Beverage class

};

#endif
