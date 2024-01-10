#ifndef MENU_H
#define MENU_H

#include "Item.h"
#include <vector>
#include <string>
#include <memory>

class Menu 
{
private:
    vector<shared_ptr<Item>> items;
public:

    Menu(const string& filePath);   //Constructor
    ~Menu();    //Destructor
    void loadMenuFromFile(const string& filePath);    //Function to load the menu from a file
    string toString() const;  //Function to display the menu
    shared_ptr<Item> createItem(char itemType, const vector<string>& itemData);     //Helper function to create an item based on type character
    size_t size() const;
    shared_ptr<Item> getMenuItem(int itemNumber) const;
};

#endif
