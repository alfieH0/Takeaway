#include "Order.h"
#include "Item.h"
#include "Appetiser.h"
#include <iostream>
#include <fstream>
#include <memory>
#include <algorithm>
#include <iomanip>
#include <sstream> 

using namespace std;

Order::Order() 
{
   
}

Order::~Order() 
{
    
}

void Order::calculateDiscount()
{
    savings = 0.0;  

    size_t eligibleAppetiserCount = count_if(items.begin(), items.end(), [](const shared_ptr<Item>& item) //Checks for two-for-one discount
    {
        if (const auto appetiser = dynamic_pointer_cast<const Appetiser>(item)) 
        {
            return appetiser->twoForOne;
        }
        return false;
    });

    if (eligibleAppetiserCount >= 2) 
    {
        
        size_t discountPairs = eligibleAppetiserCount / 2;      //Apply two-for-one discount for every pair of eligible appetisers

       
        double cheapestPrice = numeric_limits<double>::max(); //Find the price of the cheapest eligible appetiser
        for (const auto& item : items)
        {
            if (const auto appetiser = dynamic_pointer_cast<const Appetiser>(item)) 
            {
                if (appetiser->twoForOne && appetiser->getPrice() < cheapestPrice) 
                {
                    cheapestPrice = appetiser->getPrice();
                }
            }
        }
        savings = discountPairs * cheapestPrice;
    }
}




void Order::calculateTotal()        //Function to calculate the total cost of items in the order
{
    total = 0.0;
    size_t appetiserCount;

    for (const auto& item : items)
    {
        total += item->getPrice();
    }

    calculateDiscount();
    total -= savings;
}

void Order::printReceipt() const        //Function to print the receipt
{
    ofstream outFile("receipt.txt");     //Create a new file for recept

    if (outFile.is_open())
    {
        outFile << "Receipt:\n";
       
        for (const auto& item : items)  //Write each item to the file
        {
            outFile << "- " << item->toString() << "\n";
        }

        outFile << "\nTotal: \x9C" << total << "\n";        //Display and write total price to the file
        outFile << "Savings: \x9C" << savings << "\n";         //Display and write savings to the file

        outFile.close();  //Close the file
        cout << "Receipt written to receipt.txt.\n";
    }
}

string Order::toString() const          //Function to display the order
{
    string result;
    result += "Order:\n";
    for (const auto& item : items)
    {
        result += "- " + item->toString() + "\n";
    }

    result += "\nTotal Price: \x9C" + formatTo2DP(total) + "\n";
    result += "Savings: \x9C" + formatTo2DP(savings) + "\n";

    return result;
}

string Order::formatTo2DP(double value) const 
{
    ostringstream formattedValue;
    formattedValue << fixed << setprecision(2) << value;
    return formattedValue.str();
}

void Order::add(shared_ptr<Item> item) {
    items.push_back(item);
    calculateTotal();

    size_t itemNumber = items.size();  //Get the corresponding number for the added item
    cout << "Added #" << itemNumber << " " << item->getName() << " to the order. New total: \x9C" << total << "\n";    //Display the item number and name

}

void Order::remove(size_t position) {
    if (position > 0 && position <= items.size()) {
        items.erase(items.begin() + position - 1);
        calculateTotal();
        cout << "Item #" << position << " removed from the order. New total: \x9C" << total << "\n";
    }
    else {
        cerr << "Invalid position. Unable to remove item from the order.\n";
    }
}
