#ifndef ITEMLIST_H
#define ITEMLIST_H

#include <vector>
#include <memory>  // Include for smart pointers (unique_ptr)
#include<string>
#include <stdexcept>

using namespace std;

class Item;  // Forward declaration

class ItemList {
protected:
     vector<unique_ptr<Item>> items;  // Vector of smart pointers to Item objects

public:
    virtual ~ItemList() = default;  // Virtual destructor

   
    
    // Pure virtual function for the toString method
    virtual string toString() const = 0;

    virtual size_t size() const 
    {
        return items.size();
    }

    virtual const Item* getItemByPosition(size_t position) const {
        if (position > 0 && position <= items.size()) {
            return items[position - 1].get();
        }
        return nullptr;
    }
};

#endif // ITEMLIST_H
