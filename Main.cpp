#include <iostream>

#include "Headers/ItemsSold.h"

using namespace std;

// Displays menu options to user
void displayMenu() {

    cout << "Menu Options:\n";    
    cout << "1 - Find the frequency of a specific item\n";
    cout << "2 - Display a list of each item and its frequency\n";
    cout << "3 - Display each item's frequency in the form of a histogram\n";
    cout << "4 - Exit program\n";

    cout << "Enter choice: ";
}

int main() {
    // Create map of all items sold using the input file 
    ItemsSold itemMap;

    int input = 0;

    while (input != 4) {
        // Display menu to user
        displayMenu();

        // Get user input
        cin >> input;

        switch (input) {
            // Menu option 1, find an item's quantity
            case 1:
                itemMap.findQuantity();
                break;
            // Menu option 2, print map
            case 2:
                itemMap.printMap();
                break;
            // Menu option 3, display the map in the form of a histogram
            case 3:
                itemMap.printHistogram();
                break;
            // Exit the program
            case 4:
                cout << "Exiting\n";
                break;
                
        }
    }
}