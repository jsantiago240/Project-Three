#ifndef HEADERS_ITEMSSOLD_H
#define HEADERS_ITEMSSOLD_H

#include <string>
#include <map>

using namespace std;

// ItemsSold Class, map containing each item sold and its quantity
class ItemsSold {
    public:
        // Default constructor
        ItemsSold();

        // Displays the number of times a specified item was sold
        void getQuantity();
       

    private:
        // Map of each item sold and its quantity
        map<string, int> itemMap;

        // Uses input file to create item map
        void loadFromFile();

};

#endif