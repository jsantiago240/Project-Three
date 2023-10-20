#include <string>
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
// #include <conio.h>
// #include <sstream>

#include "../Headers/ItemsSold.h"

using namespace std;

// Uses input file to create map of items
void ItemsSold::loadFromFile() {
    // Input file stream
    ifstream infile;

    // Open file
    infile.open("CS210_Project_Three_Input_File.txt");

    // Make sure file was opened properly
    if (!infile.is_open()) {
        cout << "Could not open file";
    }

    // Analyze each word in the text file
    while (!infile.eof()) {
        string itemName;

        infile >> itemName;

        // Ensure these were read properly
        if (!infile.fail()) {
            // If this item is already in the map
            if (itemMap.count(itemName) == 1) {
                // Increase the items quantity by 1
                itemMap.at(itemName) = itemMap.at(itemName) + 1;
            }
            // If this item is not already in the map
            else if (itemMap.count(itemName) == 0) {
                // Add it to the map, setting the quantity to 0
                itemMap.emplace(itemName, 1);
            }
        }
    }

    // Close the file
    infile.close();
}

// Displays the number of times a specified item was sold
void ItemsSold::getQuantity() {
    string itemToFind;

    cout << "Enter the name of the item you wish to look for: ";
    cin >> itemToFind;

    cout << "Frequency of this item: " << itemMap.at(itemToFind) << "\n\n";
}

// Default constructor
ItemsSold::ItemsSold() {
    // Use input file to create map
    loadFromFile();
}
