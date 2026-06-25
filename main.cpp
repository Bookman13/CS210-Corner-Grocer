/*
 * main.cpp
 *
 * Date: 6/17/2026
 * Author: Uchenna Nwaogbe
 *
 * Purpose:
 * Displays a menu-driven grocery tracking program
 * for the Corner Grocer project.
 */

#include <iostream>
#include <limits>
#include "CornerGrocer.h"

using namespace std;

int main() {
    CornerGrocer grocery;

    grocery.LoadData();
    grocery.CreateBackupFile();

    int choice = 0;
    string item;

    while (choice != 4) {

        cout << "\n=================================" << endl;
        cout << "        CORNER GROCER MENU       " << endl;
        cout << "=================================" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Display all frequencies" << endl;
        cout << "3. Display histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "=================================" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid choice. Enter 1-4: ";
            cin >> choice;
        }

        switch (choice) {

        case 1:
            cout << "\nEnter item to search: ";
            cin >> item;

            cout << item << " was purchased "
                << grocery.SearchItem(item)
                << " time(s)." << endl;
            break;

        case 2:
            cout << "\nITEM FREQUENCIES\n" << endl;
            grocery.PrintAllFrequencies();
            break;

        case 3:
            cout << "\nHISTOGRAM\n" << endl;
            grocery.PrintHistogram();
            break;

        case 4:
            cout << "\nExiting program..." << endl;
            break;
        }
    }

    return 0;
}