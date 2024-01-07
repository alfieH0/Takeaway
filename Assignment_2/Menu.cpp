// Menu.cpp

#include "Menu.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>


// Constructor implementation
Menu::Menu(const std::string& filePath) {
    loadMenuFromFile(filePath);
}

// Destructor implementation
Menu::~Menu() {
    // Menu destructor can handle any additional cleanup if needed
}

// Function to load the menu from a file
void Menu::loadMenuFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << std::endl;
        return;
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        char itemType;
        iss >> itemType;

        // Extract data from the rest of the line
        std::vector<std::string> itemData;
        std::string itemInfo;
        while (getline(iss, itemInfo, ',')) {
            itemData.push_back(itemInfo);
        }

        // Create and add the item to the menu based on the type
        items.push_back(createItem(itemType, itemData));
    }

    file.close();
}

// Function to display the menu
std::string Menu::toString() const {
    std::string result;

    // Organize items by type
    std::vector<std::string> organizedMenu;
    organizedMenu.resize(3);  // Assuming three types: Appetizer, Main Course, Beverage

    for (const std::unique_ptr<Item>& item : items) {
        if (const Appetiser* app = dynamic_cast<const Appetiser*>(item.get())) {
            organizedMenu[0] += app->toString() + "\n";
        }
        else if (const MainCourse* mainCourse = dynamic_cast<const MainCourse*>(item.get())) {
            organizedMenu[1] += mainCourse->toString() + "\n";
        }
        else if (const Beverage* beverage = dynamic_cast<const Beverage*>(item.get())) {
            organizedMenu[2] += beverage->toString() + "\n";
        }
    }

    // Combine organized sections into the final result
    result += "Appetizers:\n" + organizedMenu[0] + "\n";
    result += "Main Courses:\n" + organizedMenu[1] + "\n";
    result += "Beverages:\n" + organizedMenu[2] + "\n";

    return result;
}

// Helper function to create an item based on type character
std::unique_ptr<Item> Menu::createItem(char itemType, const std::vector<std::string>& itemData) {
    switch (itemType) {
    case 'a':
        return std::make_unique<Appetiser>(itemData[0], std::stoi(itemData[1]), std::stod(itemData[2]), itemData[3] == "1", itemData[4] == "1");
    case 'm':
        return make_unique<MainCourse>(itemData[0], stoi(itemData[1]), stod(itemData[2]));
    case 'b':
        return std::make_unique<Beverage>(itemData[0], std::stoi(itemData[1]), std::stod(itemData[2]), std::stod(itemData[3]), std::stoi(itemData[4]));
    default:
        std::cerr << "Error: Unknown item type in the menu file." << std::endl;
        return nullptr;
    }
}


size_t Menu::size() const {
    return items.size();
}

std::unique_ptr<Item> Menu::getMenuItem(int itemNumber) const {
    if (itemNumber > 0 && static_cast<size_t>(itemNumber) <= items.size()) {
        // Return a unique_ptr owning the item using std::move
        return std::make_unique<Item>(*items[itemNumber - 1].get());
    }
    return nullptr;
}
