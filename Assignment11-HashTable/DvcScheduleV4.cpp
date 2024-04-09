// Programmer's name: Aurelia Kisanaga
// Programmer's ID: 1960007

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <ctime>
using namespace std;

#include <cstring>

#include "HashTable.h"

int hashCode(const string&);

int main()
{
    // Display Programmer's Info
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "File: " << __FILE__ << "\n";
    cout << endl;

    // parse file
    char* token;
    char buf[1000];
    const char* const tab = "\t";

    // open the input file
    ifstream fin;
    fin.open("dvc-schedule.txt");
    if (!fin.good())
        cout << "I/O Error: File not found\n";

    HashTable<string, bool, 75000> alreadySeen(hashCode);
    HashTable<string, int, 100> record(hashCode);

    int duplicates = 0;
    int count = 0;
    int unique = 0;
    int subjectNum = 0;

    clock_t startTime = clock();

    // read the input file
    while (fin.good())
    {
        // read the line
        string line;
        getline(fin, line);
        strcpy(buf, line.c_str());
        if (buf[0] == 0) continue; // skip blank lines

        // parse the line
        const string term(token = strtok(buf, tab));
        const string section(token = strtok(0, tab));
        const string course((token = strtok(0, tab)) ? token : "");
        const string instructor((token = strtok(0, tab)) ? token : "");
        const string whenWhere((token = strtok(0, tab)) ? token : "");
        if (course.find('-') == string::npos) continue; // invalid line: no dash in course name
        const string subjectCode(course.begin(), course.begin() + course.find('-'));

        string key = term + section;
        if (alreadySeen[key])
        {
            duplicates++;
        }
        else
        {
            alreadySeen[key] = true;
            record[subjectCode]++;
            unique++;
        }

        // output dots for every 1000 parsed lines
        count++;
    }
    fin.close();

    clock_t endTime = clock();
    double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    // sort
    set<string> sKeys;
    Queue<string> qKeys = record.keys();
    while (!qKeys.empty())
    {
        sKeys.insert(qKeys.front());
        qKeys.pop();
        subjectNum++;
    }

    cout << "Finish!" << endl;
    cout << "HashTable CAP = 75000/100" << endl;
    cout << "Total runtime: " << elapsedSeconds << endl;
    cout << "The load factor for the duplication check: " << record.loadFactor() << endl;
    cout << "The load factor for the subject code: " << alreadySeen.loadFactor() << endl;
    cout << "Total duplicates: " << duplicates << "\n";
    cout << "Total records: " << count << "\n";
    cout << "Total unique records: " << unique << "\n";
    cout << "Total number of subjects: " << subjectNum << endl;

    set<string>::const_iterator it;
    for (it = sKeys.begin(); it != sKeys.end(); it++)
    {
        cout << *it << ", " << record[*it] << " section(s)" << endl;
    }
}

int hashCode(const string& key)
{
    int result = 0;
    long long unsigned int i = 0;

    if (key.length() > 4)
    {
        for (i = 0; i < key.length() - 4; i++)
            result += key.at(i);
        for (long long unsigned int j = 0; j <4; j++)
            result += (int)(key.at(i + j)) * pow(10, j);
    }
    else
    {
        for (long long unsigned int j = 0; j < key.length(); j++)
            result += (int)(key.at(i + j)) * pow(10, j);
    }
    return result;
}