// Menu.h

#ifndef MENU_H
#define MENU_H

#include "Item.h"
#include <vector>
#include <string>
#include <memory> 

class Menu {
private:
    std::vector<std::unique_ptr<Item>> items;
    

public:
    // Constructor
    Menu(const std::string& filePath);

    // Destructor
    ~Menu();

    // Function to load the menu from a file
    void loadMenuFromFile(const std::string& filePath);

    // Function to display the menu
    std::string toString() const;

    // Helper function to create an item based on type character
    std::unique_ptr<Item> createItem(char itemType, const std::vector<std::string>& itemData);
    size_t size() const;
    std::unique_ptr<Item> getMenuItem(int itemNumber) const;
};

#endif // MENU_H
