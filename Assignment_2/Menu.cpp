#include "Menu.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"
#include "Item.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


Menu::Menu(const string& filePath)      //Constructor implementation
{
    loadMenuFromFile(filePath);
}

Menu::~Menu() //Destructor implementation
{
    
}

// Function to load the menu from a file
void Menu::loadMenuFromFile(const string& filePath) 
{
    ifstream file(filePath);
    if (!file.is_open()) 
    {
        cerr << "Error: Unable to open file " << filePath << endl;
        return;
    }

    string line;
    while (getline(file, line)) 
    {
        try 
        {
            istringstream iss(line);
            char itemType;
            iss >> itemType;

            vector<string> itemData;        //Extract data from the rest of the line
            string itemInfo;
            while (getline(iss, itemInfo, ',')) 
            {
                itemData.push_back(itemInfo);
            }

            
            items.push_back(createItem(itemType, itemData));        //Create and add the item to the menu based on the type
        }
        catch (const exception& e) 
        {
            cerr << "Error while processing line: " << e.what() << endl;
        }
    }
    file.close();
}


string Menu::toString() const       //Function to display the menu
 {
    string result;
    int itemCount = 1;

    result += "-----Appetisers-----\n";
    for (const shared_ptr<Item>& item : items) 
    {
        if (const Appetiser* appetiser = dynamic_cast<const Appetiser*>(item.get())) 
        {
            ostringstream formattedPrice;
            formattedPrice << fixed << setprecision(2) << appetiser->getPrice();

            result += "(" + to_string(itemCount) + ") " + appetiser->getName() + ": \x9C" + formattedPrice.str();
            result += ", " + to_string(appetiser->getCalories()) + " cal";

            if (appetiser->shareable)             //Display shareable and two-for-one information
            {
                result += " (shareable";
                if (appetiser->twoForOne) 
                {
                    result += ", 2-4-1";
                }
                result += ")";
            }
            else if (appetiser->twoForOne) 
            {
                result += " (2-4-1)";
            }

            result += "\n";
            itemCount++;
        }
    }

    result += "-----Main dishes-----\n";
    for (const shared_ptr<Item>& item : items) 
    {
        if (const MainCourse* mainCourse = dynamic_cast<const MainCourse*>(item.get())) 
        {
            ostringstream formattedPrice;
            formattedPrice << fixed << setprecision(2) << mainCourse->getPrice();

            result += "(" + to_string(itemCount) + ") " + mainCourse->getName() + ": \x9C" + formattedPrice.str();

            result += ", " + to_string(mainCourse->getCalories()) + " cal\n";
            itemCount++;
        }
    }


    result += "-----Beverages-----\n";
    for (const shared_ptr<Item>& item : items) 
    {
        if (const Beverage* beverage = dynamic_cast<const Beverage*>(item.get())) 
        {
            ostringstream formattedPrice;
            formattedPrice << fixed << setprecision(2) << beverage->getPrice();

            ostringstream formattedVolume;
            formattedVolume << fixed << setprecision(0) << beverage->volume;

            ostringstream formattedAbv;
            formattedAbv << fixed << setprecision(2) << beverage->abv;

            result += "(" + to_string(itemCount) + ") " + beverage->getName() + ": \x9C" + formattedPrice.str() + ", " + to_string(beverage->getCalories()) + " cal ";

            result += "(" + formattedVolume.str() + "ml";

            if (beverage->isAlcoholic()) 
            {
                result += ", " + formattedAbv.str() + "% abv";
            }

            result += ")\n";
            itemCount++;
        }
    }





    return result;
}




// Helper function to create an item based on type character
shared_ptr<Item> Menu::createItem(char itemType, const vector<string>& itemData)
{
    try 
    {

        switch (itemType) 
        {
        case 'a':
            if (itemData.size() == 7) 
            {
                string name = itemData[1];
                double price = (itemData[2].empty() ? 0.0 : stod(itemData[2]));
                int calories = (itemData[3].empty() ? 0 : stoi(itemData[3]));
                bool shareable = (itemData[4] == "y");
                bool twoForOne = (itemData[5] == "y");
                return make_shared<Appetiser>(name, calories, price, shareable, twoForOne);
            }
            break;
        case 'm':
            if (itemData.size() == 7) 
            {
                string name = itemData[1];
                double price = (itemData[2].empty() ? 0.0 : stod(itemData[2]));
                int calories = (itemData[3].empty() ? 0 : stoi(itemData[3]));
                return make_shared<MainCourse>(name, calories, price);
            }
            break;
        case 'b':
            if (itemData.size() == 8) 
            {
                string name = itemData[1];
                double price = (itemData[2].empty() ? 0.0 : stod(itemData[2]));
                int calories = (itemData[3].empty() ? 0 : stoi(itemData[3]));
                double abv = (itemData[7].empty() ? 0.0 : stod(itemData[7]));
                int volume = (itemData[6].empty() ? 0 : stoi(itemData[6]));
                return make_shared<Beverage>(name, calories, price, abv, volume);
                
            }
            break;
        default:
            cerr << "Error: Unknown item type in the menu file." << endl;
            return nullptr;
        }
    }
    catch (const exception& e)
    {
        cerr << "Error while creating item: " << e.what() << endl;
    }

    // If execution reaches here, it means the input was invalid
    cerr << "Error: Invalid data for item type " << itemType << endl;
    return nullptr;

}


size_t Menu::size() const 
{
    return items.size();
}

shared_ptr<Item> Menu::getMenuItem(int itemNumber) const 
{
    if (itemNumber > 0 && static_cast<size_t>(itemNumber) <= items.size()) 
    {
        // Return a shared_ptr owning the item
        return items[itemNumber - 1];
    }
    return nullptr;
}
