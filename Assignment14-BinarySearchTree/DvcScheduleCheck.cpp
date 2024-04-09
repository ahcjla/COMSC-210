// Programmer: Aurelia Kisanaga
// Programmer's ID: 1960007

#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>

using namespace std;

int main()
{
    // Programmer's Identification
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "File: " << __FILE__ << endl;

    // for parsing input file
    char* token;
    char buf[1000];
    const char* const tab = "\t";

    // open the input file
    ifstream fin;
    fin.open("dvc-schedule.txt");
    if (!fin.good())
        cout << "I/O Error: File not found\n";

    // declarations
    map<string, set<string>> courseCode;
    int duplicates = 0;

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

        const string key = term + ", section " + section;
        courseCode[key].insert(course);
        if (courseCode[key].size() == 2) duplicates++;
    }
    fin.close();
    cout << endl;

    if (duplicates == 0)
    {
        cout << "There are no term-section pairs with multiple courses associated with them." << endl << endl;
    }
    else
    {
        cout << "There are " << duplicates << " term-section pairs with multiple courses associated with them." << endl << endl;
    }
    
    // output
    map<string, set<string>>::const_iterator it;
    for (it = courseCode.begin(); it != courseCode.end(); it++)
    {
        if (it->second.size() > 1)
        {
            set<string>::const_iterator it2;
            cout << "In " << it->first << " can be found in multiple courses: " << endl;
            for (it2 = it->second.begin(); it2 != it->second.end(); it2++)
            {
                cout << *it2 << endl;
            }
            cout << endl;
        }
    }
    return 0;
}