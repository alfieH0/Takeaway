#ifndef ORDER_H
#define ORDER_H

#include "ItemList.h"
#include "Item.h"
#include <iostream>
#include <memory>

class Order : public ItemList
{
private:
    double total;          //Total cost of items in the order
    double savings;        //Savings from discounts
    string formatTo2DP(double value) const;    //Helper function to format values to 2 decimal places  
    void calculateDiscount();    //Function to calculate any applicable discounts


public:
    Order();    //Constructor for the Order class
    ~Order();    //Destructor for the Order class
    void calculateTotal();    //Function to calculate the total cost of items in the order
    void printReceipt() const;    //Function to print the receipt
    string toString() const override;    //Convert Order object to a string for display
    void add(shared_ptr<Item> item);    //Function to add an item to the order
    void remove(size_t position);    //Function to remove an item from the order
};

#endif
