#ifndef ITEMLIST_H
#define ITEMLIST_H

#include <vector>
#include <memory>
#include <string>

using namespace std;
class Item;  //Forward declaration

class ItemList 
{
protected:
    vector<shared_ptr<Item>> items;  //Vector of smart pointers to Item objects

public:
    virtual ~ItemList() = default;  //Virtual destructor
    virtual string toString() const = 0;

    virtual size_t size() const 
    {
        return items.size();
    }

    virtual const Item* getItemByPosition(size_t position) const 
    {
        if (position > 0 && position <= items.size()) 
        {
            return items[position - 1].get();
        }
        return nullptr;
    }
};

#endif
