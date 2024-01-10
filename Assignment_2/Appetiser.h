#ifndef APPETISER_H
#define APPETISER_H

#include "Item.h"
#include <memory>

class Appetiser : public Item 
{
private:
   

public:
    Appetiser(const string& name, int calories, double price, bool shareable, bool twoForOne);    //Constructor
    bool twoForOne;
    bool shareable;
    string toString() const;

    ~Appetiser();
};

#endif
