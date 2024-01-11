#ifndef MENU_H
#define MENU_H

#include "ItemList.h"  //Include the header for ItemList
#include "Item.h"
#include <vector>
#include <string>
#include <memory>

class Menu : public ItemList//Definition of the Menu class, inheriting from ItemList
{
private:
    void loadMenuFromFile(const string& filePath);    //Function to load the menu from a file
    shared_ptr<Item> createItem(char itemType, const vector<string>& itemData);    //Helper function to create an item based on type character
public:
    Menu(const string& filePath);    //Constructor for the Menu class
    ~Menu();    //Destructor for the Menu class
    string toString() const override;    //Function to convert Menu object to a string for display
    size_t size() const;    //Function to get the size of the menu
    shared_ptr<Item> getMenuItem(int itemNumber) const;    //Function to get an item by position in the menu
};

#endif
