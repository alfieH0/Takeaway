// Appetiser.h
#ifndef Appetiser_H
#define Appetiser_H

#include "Item.h"
#include <memory>

using namespace std;

class Appetiser : public Item {
private:
    bool shareable;
    

public:
    // Constructor
    Appetiser(const string& name, int calories, double price, bool shareable, bool twoForOne);
    bool twoForOne;
    // toString method
    string toString() const;

    ~Appetiser();
};

#endif // Appetiser_H
