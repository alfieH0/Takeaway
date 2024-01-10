#ifndef ORDER_H
#define ORDER_H

#include "ItemList.h"
#include "Item.h"
#include <iostream>
#include <memory>


class Order : public ItemList 
{
private:
    double total;
    double savings;
    string formatTo2DP(double value) const;
    void calculateDiscount();
public:
    Order();
    ~Order();
    void calculateTotal();
    void printReceipt() const;
    string toString() const override;
    void add(shared_ptr<Item> item);
    void remove(size_t position);
  
};
#endif
