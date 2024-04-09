// Programmer 1: Aurelia Kisanaga
// Programmer's 1 ID: 1960007

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "DynamicArray.h"
#include "StaticArray.h"

using namespace std;

struct subject
{
    string subjectCode;
    int count = 0;
};

struct SectionForTerm
{
    string term;
    int numberOfSectionsSeen;
    DynamicArray<string> seenSectionNumber;
};

int main()
{   
    // Display Programmer's Info
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "File: " << __FILE__ << "\n";
    cout << endl;

    DynamicArray<subject> subjectCount(200);    // array to store amount of classes in each subject
    StaticArray<SectionForTerm, 200> alreadySeen;

    int count = 0;  // Count for number of lines read
    int index = 0; // Index for alreadySeen array
    int duplicates = 0; // Duplicate records
    int subjectIndex = 0;   // Index for subjectCount array
    int alreadySeenIndex = 0; // Index for alreadySeen array

    // for parsing the inputfile
    char* token;
    char buf[1000];
    const char* const tab = "\t";

    // declare dynamic array
    DynamicArray<string> term;
    DynamicArray<string> section;
    DynamicArray<string> course;
    DynamicArray<string> instructor;
    DynamicArray<string> timeLocation;
    DynamicArray<string> subjectCode;

    // flag to check if subjectCode exist
    bool codeFound = true;

    // open the input file
    ifstream fin;
    fin.open("dvc-schedule.txt");
    if (!fin.good())
        cout << "I/O error. File not found!\n";

    while (fin.good())
    {
        // read the line
        string line;
        getline(fin, line);
        strcpy(buf, line.c_str());

        if (buf[0] == 0) continue; // skip blank lines

        //parse the line
        const string terms(token = strtok(buf, tab));
        const string sections((token = strtok(0, tab)) ? token : "");
        const string courses((token = strtok(0, tab)) ? token : "");
        const string instructors((token = strtok(0, tab)) ? token : "");
        const string timeLocations((token = strtok(0, tab)) ? token : "");
        if (courses.find('-') == string::npos) continue; // invalid line: no dash in course name
        const string subjectCodes(courses.begin(), courses.begin() + courses.find('-'));

        // assigning values
        term[index] = terms;
        section[index] = sections;
        course[index] = courses;
        instructor[index] = instructors;
        timeLocation[index] = timeLocations;
        subjectCode[index] = subjectCodes;
        index++;    // increment 

        // check for subject and count for subject
        for (int i = 0; i <= subjectIndex; i++)
        {
            if (subjectCount[i].subjectCode == subjectCodes)
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
            subjectCount[subjectIndex].subjectCode = subjectCodes;
            subjectCount[subjectIndex].count++;
            subjectIndex++;
        }
    }

    // Check duplicates
    for (int i = 0; i < index; i++)
    {
        codeFound = false; // false means term hasn't been added to the list
        // check term
        for (int j = 0; j < alreadySeenIndex; j++)
        {
            // Term found
            if (term[i] == alreadySeen[j].term)
            {
                // Check section
                for (int k = 0; k < alreadySeen[j].numberOfSectionsSeen; k++)
                {
                    // Section found
                    if (section[i] == alreadySeen[j].seenSectionNumber[k])
                    {
                        duplicates++;
                        codeFound = true;
                        break;
                    }
                }
                if (codeFound == true)
                {
                    break;
                }
                // Section not found
                alreadySeen[j].seenSectionNumber[alreadySeen[j].numberOfSectionsSeen] = section[i];
                alreadySeen[j].numberOfSectionsSeen++;
                codeFound = true;
                break;
            }
        }
        // Term not found
        if (codeFound == false)
        {
            alreadySeen[alreadySeenIndex].term = term[i];
            alreadySeen[alreadySeenIndex].seenSectionNumber[alreadySeen[alreadySeenIndex].numberOfSectionsSeen] = section[i];
            alreadySeen[alreadySeenIndex].numberOfSectionsSeen++;
            alreadySeenIndex++;
        }
        count++;

        // Displaying dots for every 1000 lines of code
        if (count % 1000 == 0)
        {
            cout << '.';
            cout.flush();
        }

    }
    fin.close();

    // output unique courses
    cout << endl << endl << "Unique number of courses is " << count - duplicates << "\n";
    
    // amount of count for each sections
    int sectionsCount = 0;
    for (int i = 0; i < subjectIndex; i++)
    {
        for (int j = 0; j < subjectIndex; j++)
        {
            if (subjectCount[j].subjectCode == subjectCount[i].subjectCode)
            {
                sectionsCount = subjectCount[j].count;
                break;
            }
        }
        cout << subjectCount[i].subjectCode << " " << sectionsCount << " sections\n";
    }

    // Outputting amount of duplicates, number lines, and subjects
    cout << endl;
    cout << "Total duplicates: " << duplicates << "\n";
    cout << "Total count: " << count << "\n";
    cout << "Total subjects: " << subjectIndex << "\n";

    return 0;
}