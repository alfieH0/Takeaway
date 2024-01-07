#ifndef ORDER_H
#define ORDER_H

#include "ItemList.h"
#include "Item.h"
#include <iostream>
#include <memory>


class Order : public ItemList {
private:
    double total;

public:
    Order();
    ~Order();
    void calculateTotal();
    void printReceipt() const;
    std::string toString() const override;
    void add(const Item* item);
    void remove(size_t position);
};
#endif // ORDER_H
