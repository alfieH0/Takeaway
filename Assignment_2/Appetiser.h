#ifndef APPETISER_H
#define APPETISER_H

#include "Item.h"
#include <memory>

class Appetiser : public Item
{
public:
    //Constructor for the Appetiser class
    Appetiser(const string& name, int calories, double price, bool shareable, bool twoForOne);

    bool twoForOne;    //Indicates if there's a two-for-one offer
    bool shareable;     //Indicates if the appetiser is shareable
    string toString() const;    //Convert Appetiser object to a string for display

    ~Appetiser();    //Destructor for the Appetiser class
};

#endif
