#include <iostream>

#include "Headers/ItemsSold.h"

using namespace std;

// Displays menu options to user
void displayMenu() {

    cout << "Menu Options:\n";    
    cout << "1 - Search how many times a specific item was sold\n";
    cout << "2 - \n";
    
    // ...
    cout << "Enter choice: ";
}

int main() {
    // Create map of all items sold using input file 
    ItemsSold itemMap;

    // Display menu to user

    int input = 0;

    while (input != 4) {
        // Display menu to user
        displayMenu();

        // Get user input
        cin >> input;

        switch (input) {
            // Menu option 1, find items quantity
            case 1:
                itemMap.getQuantity();
                break;
        }
    }
}