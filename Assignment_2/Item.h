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
    Item(const string& name, int calories, double price);    //Constructor for the Item class

    ~Item();    //Destructor for the Item class

    const string& getName() const { return name; }    //Get the name of the item
    int getCalories() const { return calories; }      //Get the calories of the item
    double getPrice() const { return price; }         //Get the price of the item
    virtual string toString() const;                  //Convert Item object to a string for display

};

#endif
