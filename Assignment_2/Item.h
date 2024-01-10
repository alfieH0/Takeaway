#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <memory>

using namespace std;
class Item 
{
protected:
    string name;
    int calories;  
    double price;

public:
    Item(const string& name, int calories, double price);    //Constructor
    ~Item();    // Destructor
    const string& getName() const { return name; }
    int getCalories() const { return calories; }
    double getPrice() const { return price; }
    virtual string toString() const;
};
#endif
