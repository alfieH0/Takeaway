#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <memory>

using namespace std;
class Item {
protected:
    string name;
    int calories;  // Adding calories member
    double price;

public:
    // Constructor
    Item(const string& name, int calories, double price);

    // Destructor
    ~Item();

    // Public accessors for name, calories, and price
    const string& getName() const { return name; }
    int getCalories() const { return calories; }
    double getPrice() const { return price; }
    virtual string toString() const;
};
#endif // ITEM_H
