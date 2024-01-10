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

	Menu menu = Menu("menu.csv");	//Create a menu object from a CSV file
	
	Order order = Order();	//Create an order object

	while (userCommand != "exit")
	{
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}
		
		if (!parameters.empty()) {
			string command = parameters[0];


			if (command.compare("menu") == 0) 
			{
				cout << menu.toString();
			}
			else if (command.compare("add") == 0)
			{
				size_t itemNumber;

				cout << "Enter the item number to add to the order: ";

				if (cin >> itemNumber) 
				{
					if (itemNumber > 0 && itemNumber <= menu.size()) 
					{
						
						shared_ptr<Item> choice = menu.getMenuItem(itemNumber);		//Get the item type and add it to the order
						order.add(choice);
					}
					else 
					{
						cerr << "Invalid item number. Please choose a valid item.\n";
					}
				}
				else 
				{
					cerr << "Invalid input. Please enter a valid item number.\n";
					
					cin.clear();		//Clear the input stream in case of non-numeric input
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

			else if (command.compare("remove") == 0) {
				size_t itemNumberToRemove;

				cout << "Enter the item number to remove from the order: ";
				if (cin >> itemNumberToRemove) {
					order.remove(itemNumberToRemove);
				}
				else {
					cerr << "Invalid input. Please enter a valid item number.\n";
					cin.clear();					//Clear the input stream in case of non-numeric input
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

			else if (command.compare("checkout") == 0)
			{
				
				cout << order.toString();		//Display the order details and total

				
				cout << "Do you want to print a receipt? (y/n): ";		//Ask the user if they want a receipt printed
				string printReceipt;
				cin >> printReceipt;

				if (printReceipt == "y" || printReceipt == "Y")
				{
					
					order.printReceipt();		//Write the receipt to a file
				}
				else
				{
					cout << "Receipt not printed.\n";
				}
			}

			else if (command.compare("help") == 0)		//Display help information
			{
				
				cout << "Available commands:\n";
				cout << "  menu - Display the menu\n";
				cout << "  add - Add an item to the order\n";
				cout << "  remove - Remove an item from the order\n";
				cout << "  checkout - View and finalize the order\n";
				cout << "  help - Display available commands\n";
			}

			parameters.clear();

		}
	}
	cout << "Press any key to quit...";
	getchar();

}