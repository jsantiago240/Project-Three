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

// Create backup data file from item map
void ItemsSold::createBackup() {
    // Initialize output file stream and create file
    ofstream outfile;
    outfile.open("frequency.dat");

    // Ensure file was opened successfully
    if (!outfile.is_open()) {
        cout << "Error opening file\n";
        exit(1);
    }

    // For each item in the map
    for (auto item = itemMap.begin(); item != itemMap.end(); item++) {
        // Print the item's name
        outfile << item->first << ' ';

        // Print the item's frequency
        outfile << item->second << endl;
    }

    // Close the file
    outfile.close();
}

// Displays the number of times a specified item was sold
void ItemsSold::findQuantity() {
    string itemToFind;

    cout << "Enter the name of the item you wish to look for: ";
    cin >> itemToFind;

    cout << "Frequency of this item: " << itemMap.at(itemToFind) << "\n\n";
}

// Display a list of each item and its frequency
void ItemsSold::printMap() {
    // For each item in the map
    for (auto i = itemMap.begin(); i != itemMap.end(); i++) {
        // Print the name of the item and its frequency
        cout << i->first << ' ' << i->second << endl;
    }

    // Print blank line
    cout << endl;
}

// Print the map in the form of a histogram
void ItemsSold::printHistogram() {
    // For each item in the map
    for (auto i = itemMap.begin(); i != itemMap.end(); i++) {
        // Print the name of the item
        cout.width(20);
        cout << setfill(' ') << left << i->first << ' ';

        // Print characters to represent item's frequency
        cout << setfill('*') << setw(i->second + 1) << ' ' << endl;
    }

    // Print blank line
    cout << endl;
}

// Default constructor
ItemsSold::ItemsSold() {
    // Use input file to create map
    loadFromFile();

    // Create backup data file
    createBackup();
}

