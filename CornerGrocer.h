#ifndef CORNERGROCER_H
#define CORNERGROCER_H

/*
 * CornerGrocer.h
 *
 * Date: 6/17/2026
 * Author: Uchenna Nwaogbe
 *
 * Purpose:
 * Defines the CornerGrocer class used to read grocery
 * purchase data, track item frequencies, create a backup
 * file, and display reports.
 */

#include <string>
#include <map>

using namespace std;

class CornerGrocer {
private:
    map<string, int> itemFrequency;

public:
    void LoadData();
    void CreateBackupFile();

    int SearchItem(string item);

    void PrintAllFrequencies();
    void PrintHistogram();
};

#endif