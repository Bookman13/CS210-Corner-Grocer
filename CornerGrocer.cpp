/*
 * CornerGrocer.cpp
 *
 * Date: 6/17/2026
 * Author: Uchenna Nwaogbe
 *
 * Purpose:
 * Implements the CornerGrocer class functions used to
 * load grocery data, create backup files, search item
 * frequencies, and display reports.
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include "CornerGrocer.h"

using namespace std;

void CornerGrocer::LoadData() {
    ifstream inputFile("CS210_Project_Three_Input_File.txt");

    string item;

    // Read each grocery item and count its frequency
    while (inputFile >> item) {
        itemFrequency[item]++;
    }

    inputFile.close();
}

void CornerGrocer::CreateBackupFile() {
    ofstream outputFile("frequency.dat");

    // Write all item frequencies to the backup file
    for (auto const& pair : itemFrequency) {
        outputFile << pair.first << " " << pair.second << endl;
    }

    outputFile.close();
}

int CornerGrocer::SearchItem(string item) {
    // Capitalize the first letter to match the item names in the input file
    if (!item.empty()) {
        item[0] = toupper(item[0]);
    }

    if (itemFrequency.find(item) != itemFrequency.end()) {
        return itemFrequency[item];
    }

    return 0;
}

void CornerGrocer::PrintAllFrequencies() {
    // Display each item and its frequency
    for (auto const& pair : itemFrequency) {
        cout << pair.first << " " << pair.second << endl;
    }
}

void CornerGrocer::PrintHistogram() {
    // Display each item followed by asterisks representing its frequency
    for (auto const& pair : itemFrequency) {
        cout << pair.first << " ";

        for (int i = 0; i < pair.second; i++) {
            cout << "*";
        }

        cout << endl;
    }
}