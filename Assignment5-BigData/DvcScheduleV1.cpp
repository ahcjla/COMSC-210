// Programmer: Aurelia Kisanaga
// Programmer's ID: 1960007

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

#include "DynamicArray.h"
#include "StaticArray.h"

using namespace std;

// structs
struct subject
{
    string subjectCode;
    int count=0;
};

// prototypes
bool checkDuplicates(const string, const DynamicArray<string>&, int);
bool compare(string, string);

int main()
{
    // Display Programmer's Info
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "File: " << __FILE__ << "\n";
    cout << endl;

    DynamicArray<string> uniqueClasses(100);    // array to store unique classes
    DynamicArray<subject> subjectCount(100);    // array to store amount of classes in each subject

    // for parsing the inputfile
    char* token;
    char buf[1000];
    const char* const tab = "\t";

    int count = 0;  // count for total number of lines/records
    int duplicates = 0; // Duplicate records
    int classIndex = 0; // Index for uniqueClasses array
    int subjectIndex = 0;   // Index for subjectCount array

    // check if subjectCode is already in the array or not
    bool codeFound = true;

    // open the input file
    ifstream fin;
    fin.open("dvc-schedule.txt");
    if (!fin.good())
        cout << "I/O error. File can't find!\n";

    // read the input file
    while (fin.good())
    {
        // read the line
        string line;
        getline(fin, line);
        strcpy(buf, line.c_str());

        if (buf[0] == 0) continue; // skip blank lines

        //parse the line
        const string term(token = strtok(buf, tab));
        const string section((token = strtok(0, tab)) ? token : "");
        const string course((token = strtok(0, tab)) ? token : "");
        const string instructor((token = strtok(0, tab)) ? token : "");
        const string whenWhere((token = strtok(0, tab)) ? token : "");
        if (course.find('-') == string::npos) continue; // invalid line: no dash in course name
        const string subjectCode(course.begin(), course.begin() + course.find('-'));

        // storing record 
        string record = term + " " + section;
        codeFound = true;

        // check for duplicates record
        if (!checkDuplicates(record, uniqueClasses, classIndex))
        {
            uniqueClasses[classIndex] = record;
            for (int i = 0; i <= subjectIndex; i++)
            {
                if (subjectCount[i].subjectCode == subjectCode)
                {
                    subjectCount[i].count++;
                    codeFound = true;
                    break;
                }
                else 
                    codeFound = false;
            }
            if (!codeFound)
            {
                subjectCount[subjectIndex].subjectCode = subjectCode;
                subjectCount[subjectIndex].count++;
                subjectIndex++;
            }
            classIndex++;
        }
        else
            duplicates++;
        count++;

        // displaying dots for every 1000 lines of code
        if (count % 1000 == 0)
        { 
            cout << '.'; 
            cout.flush();
        }
            
    }
    fin.close();

    // Arrange alphabetically
    vector<string> place;
    for (int i = 0; i < subjectIndex; i++) {
        place.push_back(subjectCount[i].subjectCode);
    }
    sort(place.begin(), place.end(), compare);

    // Output unique number of courses
    cout << endl << endl << "Uniqute number of courses is " << classIndex << "\n";

    // amount of count for each sections
    int sectionsCount = 0;
    for (int i = 0; i < subjectIndex; i++) 
    {
        for (int j = 0; j < subjectIndex; j++) 
        {
            if (subjectCount[j].subjectCode == place[i]) 
            {
                sectionsCount = subjectCount[j].count;
                break;
            }
        }
        cout << place[i] << " " << sectionsCount << " sections\n";
    }

    cout << "Total duplicates: " << duplicates << "\n";
    cout << "Total count: " << count << "\n";
    cout << "Total subjects: " << subjectIndex << "\n";

    return 0;
}

bool checkDuplicates(const string subject, const DynamicArray<string>& arr, int index)
{
    bool result = false;
    for (int i = 0; i <= index; i++)
        if (subject == arr[i])
            result = true;
    return result;
};

bool compare(string a, string b) 
{
    return a < b;
};