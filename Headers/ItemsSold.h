// Defines this header
#ifndef HEADERS_ITEMSSOLD_H
#define HEADERS_ITEMSSOLD_H

#include <string>
#include <map>

using namespace std;

// ItemsSold Class, map of items sold and their frequencies
class ItemsSold {
    public:
        // Default constructor
        ItemsSold();

        // Displays the number of times a specified item was sold
        void findQuantity();

        // Display a list of each item and its frequency
        void printMap();

        // Display the map in the form of a histogram
        void printHistogram();

    private:
        // Map of each item name and its frequency
        map<string, int> itemMap;

        // Uses input file to create item map
        void loadFromFile();

        // Create backup data file from item map
        void createBackup();
};

#endif