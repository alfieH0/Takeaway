// Order.cpp

#include "Order.h"
#include "Item.h"
#include "Appetiser.h"
#include <iostream>
#include <fstream>
#include <memory>


using namespace std;

// Constructor implementation
Order::Order() : total(0.0) 
{
    // Initialize total to zero when the order is created
}

// Destructor implementation
Order::~Order() 
{
    // Order destructor can handle any additional cleanup if needed
}

// Function to calculate the total cost of items in the order, considering discounts
void Order::calculateTotal()
{
    total = 0.0;
    size_t appetiserCount = 0; // To count the number of eligible appetisers for discount

    for (const auto& item : items) 
    {
        total += item->getPrice();

        // Check if the item is an eligible appetiser for the "2-4-1" discount
        if (auto appetiser = dynamic_cast<const Appetiser*>(item.get())) 
        {
            if (appetiser->twoForOne) 
            {
                appetiserCount++;
            }
        }
    }

    // Apply "2-4-1" discount for eligible appetizers
    int discountCount = appetiserCount / 2;
    total -= discountCount * items.front()->getPrice(); // Assuming all eligible appetizers have the same price
}

// Function to print the receipt
void Order::printReceipt() const 
{
    ofstream outFile("receipt.txt");  // Create a new file for writing

    if (outFile.is_open()) 
    {
        outFile << "Receipt:\n";

        // Write each item to the file
        for (const auto& item : items) 
        {
            outFile << "- " << item->toString() << "\n";
        }

        // Display and write total price to the file
        outFile << "\nTotal: $" << total << "\n";

        // Calculate and display savings made by two-for-one discount
        size_t appetiserCount = 0;
        for (const auto& item : items) 
        {
            if (auto appetiser = dynamic_cast<const Appetiser*>(item.get())) 
            {
                if (appetiser->twoForOne) 
                {
                    appetiserCount++;
                }
            }
        }

        int discountCount = appetiserCount / 2;
        double savings = discountCount * items.front()->getPrice(); // Assuming all eligible appetizers have the same price

        // Display and write savings to the file
        outFile << "Savings: $" << savings << "\n";

        outFile.close();  // Close the file
        cout << "Receipt written to receipt.txt.\n";
    }
    else 
    {
        cerr << "Error: Unable to create receipt.txt for writing.\n";
    }
}

// Function to display the order
string Order::toString() const 
{
    string result;
    result += "Order:\n";
    for (const auto& item : items) 
    {
        result += "- " + item->toString() + "\n";
    }

    // Display total price
    result += "\nTotal Price: £" + to_string(total) + "\n";

    // Calculate and display savings made by two-for-one discount
    size_t appetiserCount = 0;
    for (const auto& item : items) 
    {
        if (auto appetiser = dynamic_cast<const Appetiser*>(item.get())) 
        {
            if (appetiser->twoForOne) 
            {
                appetiserCount++;
            }
        }
    }

    int discountCount = appetiserCount / 2;
    double savings = discountCount * items.front()->getPrice(); // Assuming all eligible appetizers have the same price

    result += "Savings: £" + to_string(savings) + "\n";

    return result;
}

// Function to add an item to the order by position in the item list
void Order::add(const Item* item) {
    items.push_back(std::make_unique<Item>(*item));
    calculateTotal();
    cout << "Item added to the order. New total: £" << total << "\n";
}



// Function to remove an item from the order by position in the item list
void Order::remove(size_t position) {
    if (position > 0 && position <= items.size()) {
        items.erase(items.begin() + position - 1);
        calculateTotal();
        std::cout << "Item removed from the order. New total: £" << total << "\n";
    }
    else {
        std::cerr << "Invalid position. Unable to remove item from the order.\n";
    }
}