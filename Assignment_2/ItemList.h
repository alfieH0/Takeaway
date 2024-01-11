#ifndef ITEMLIST_H
#define ITEMLIST_H

#include <vector>
#include <memory>
#include <string>

using namespace std;

class Item;  //Forward declaration

class ItemList      //Definition of the ItemList class]
{
protected:
    vector<shared_ptr<Item>> items;    //Vector of smart pointers to Item objects

public:
    virtual ~ItemList() = default;    //Virtual destructor for ItemList class
    virtual string toString() const = 0;
    virtual size_t size() const    //Virtual function to get the size of the item list

    {
        return items.size();
    }
};

#endif
