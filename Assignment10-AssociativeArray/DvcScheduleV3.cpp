// Programmer's name: Aurelia Kisanaga
// Programmer's ID: 1960007

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>

#include "AssociativeArray.h"
//#include "Queue.h"

using namespace std;


int main()
{
    // Display Programmer's Info
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "File: " << __FILE__ << "\n";
    cout << endl;

    AssociativeArray<string, AssociativeArray<string, int> >subjectCounts;
    AssociativeArray<string, AssociativeArray<string, bool> > seen;

    int duplicates = 0;
    int count = 0;

    char* token;
    char buffer[1000];
    const char* const tab = "\t";

    //open the input file
    ifstream fin;
    fin.open("dvc-schedule.txt");
    if (!fin.good())
        cout << "I/O Error: File not found\n";

    //read the input file
    while (fin.good())
    {

        //read the line
        string line;
        getline(fin, line);
        strcpy(buffer, line.c_str());

        if (buffer[0] == 0) continue; // skip blank lines

        //parse the line
        const string term(token = strtok(buffer, tab));
        const string section((token = strtok(0, tab)) ? token : "");
        const string course((token = strtok(0, tab)) ? token : "");
        const string instructor((token = strtok(0, tab)) ? token : "");
        const string whenWhere((token = strtok(0, tab)) ? token : "");
        if (course.find('-') == string::npos) continue; //invalid line: no dash in course name
        const string subjectCode(course.begin(), course.begin() + course.find('-'));

        // output dots for every 1000 parsed lines
        count++;
        if (count % 1000 == 0)
        {
            cout << ".";
            cout.flush();
        }

        // check duplicates
        if (seen[term][section])
        {
            duplicates++;
        }
        else
        {
            seen[term][section] = true;
            subjectCounts[subjectCode][course]++;
        }

    }

    fin.close();

    //cout << endl << "Duplicates: " << duplicates << "\n";
    cout << endl << endl;

    // copy subjectCounts keys in queue and copy to associative array
    AssociativeArray<int, string> keys;
    Queue<string> QueueKeys = subjectCounts.keys();
    for (int i = 0; !QueueKeys.empty(); i++)
    {
        keys[i] = QueueKeys.front();
        QueueKeys.pop();
    }

    // sort and swap subject keys in associative array
    AssociativeArray<int, string> subjectKey = keys;
    for (int i = 0; i < subjectKey.size(); i++)
        for (int j = i + 1; j < subjectKey.size(); j++)
            if (subjectKey[i] > subjectKey[j])
                swap(subjectKey[i], subjectKey[j]);

    // display subjectCode and number of courses
    for (int i = 0; i < subjectCounts.size(); i++)
    {
        cout << subjectKey[i] << ", " << subjectCounts[subjectKey[i]].size() << " course(s)\n";
        // create another associative array for sections number (subject key of subject counts)
        AssociativeArray<int, string> tempKeys;
        Queue<string> subQueueKeys = subjectCounts[subjectKey[i]].keys();
        for (int i = 0; !subQueueKeys.empty(); i++)
        {
            tempKeys[i] = subQueueKeys.front();
            subQueueKeys.pop();
        }

        // sort and swap courses keys in associative array
        AssociativeArray<int, string> coursesKey = tempKeys;
        for (int a = 0; a < subjectCounts[subjectKey[i]].size(); a++)
            for (int b = a + 1; b < subjectCounts[subjectKey[i]].size(); b++)
                if (coursesKey[a] > coursesKey[b])
                    swap(coursesKey[a], coursesKey[b]);

        // display number of sections
        for (int j = 0; j < coursesKey.size(); j++)
            cout << "  " << coursesKey[j] << ", " << subjectCounts[subjectKey[i]][coursesKey[j]] << " section(s)\n";
    }

    return 0;

}

