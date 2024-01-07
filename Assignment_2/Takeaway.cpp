/* ------------------------------------------------------
CMP2811 Applied Programming Paradigms
Driver program for "Takeaway" assignment
Autumn 2023

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"

#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <memory>

using namespace std;

int main()
{
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();

	while (userCommand != "exit")
	{
		getline(cin, userCommand);
		stringstream ss(userCommand);  // Add this line to create stringstream
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		string command = parameters[0];

		if (command.compare("menu") == 0) {
			cout << menu.toString();
		}
		else if (command.compare("add") == 0) {
			size_t itemNumber;
			if (parameters.size() > 1) {
				ss >> itemNumber;
				// Check if the item number is valid
				if (itemNumber > 0 && itemNumber <= menu.size()) {
					// Get the item type and add it to the order
					std::unique_ptr<Item> choice = menu.getMenuItem(itemNumber);
					order.add(choice.get());  // Pass the raw pointer

				}
				else {
					cerr << "Invalid item number. Please choose a valid item.\n";
				}
			}
			else {
				cerr << "Please provide an item number to add.\n";
			}
		}
		else if (command.compare("remove") == 0)
		{
			// Remove the item from the order
			order.remove(1);
		}
		else if (command.compare("checkout") == 0)
		{
			// Display the order details and total
			cout << order.toString();

			// Write the receipt to a file
			order.printReceipt();
		}
		else if (command.compare("help") == 0)
		{
			// Display help information
			cout << "Available commands:\n";
			cout << "  menu - Display the menu\n";
			cout << "  add - Add an item to the order\n";
			cout << "  remove - Remove an item from the order\n";
			cout << "  checkout - View and finalize the order\n";
			cout << "  help - Display available commands\n";
		}

		parameters.clear();

	}

	cout << "Press any key to quit...";
	getchar();

}