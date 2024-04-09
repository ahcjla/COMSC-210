// Programmer: Aurelia Kisanaga
// Programmer's ID: 1960007
// Programmer: Aiman Al sharai
// Programmer's ID: 1839435

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <set>

using namespace std;

int season(const string);

int main() 
{

    // Programmer's Identification
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "File: " << __FILE__ << endl;

    // for parsing the input file
    char* token;
    char buf[1000];
    const char* const tab = "\t";

    // open the input file
    ifstream fin;
    fin.open("dvc-schedule.txt");
    if (!fin.good())
        cout << "I/O Error: File not found\n";

    // declarations
    map<string, set<int>> courseCode;

    // read the input file
    while (fin.good()) {

        // read the line
        string line;
        getline(fin, line);
        strcpy(buf, line.c_str());

        if (buf[0] == 0) continue; // skip blank lines

        // parse the line
        const string term(token = strtok(buf, tab));
        const string section((token = strtok(0, tab)) ? token : "");
        const string course((token = strtok(0, tab)) ? token : "");
        const string instructor((token = strtok(0, tab)) ? token : "");
        const string whenWhere((token = strtok(0, tab)) ? token : "");
        if (course.find('-') == string::npos) continue; // invalid line: no dash in course name
        const string subjectCode(course.begin(), course.begin() + course.find('-'));

        courseCode[course].insert(season(term));
        
    }
    fin.close();
    cout << endl;

    string userInput;   // for user input
    
    // user input prompt
    while (true) 
    {
        cout << "Enter a course to search for the first and last terms offered" << endl;
        cout << "Format input: SUBJECTCODE - ### (e.g: COMSC - 210)" << endl;
        cout << "Enter X or x to exit: ";
        getline(cin, userInput);
        if (userInput == "X" || userInput == "x") break;
        if (!courseCode[userInput].empty())
        {
            cout << userInput << " was first offered in ";
            if (*courseCode[userInput].begin() % 10 == 3) cout << "Fall ";
            else if (*courseCode[userInput].begin() % 10 == 2) cout << "Summer ";
            else if (*courseCode[userInput].begin() % 10 == 1) cout << "Spring";
            cout << *courseCode[userInput].begin() / 10;
            cout << " and last offered in ";
            if (*courseCode[userInput].rbegin() % 10 == 3) cout << "Fall ";
            else if (*courseCode[userInput].rbegin() % 10 == 2) cout << "Summer ";
            else if (*courseCode[userInput].rbegin() % 10 == 1) cout << "Spring";
            cout << *courseCode[userInput].rbegin() / 10 << endl;
        }
        else
        {
            cout << userInput << " could not be found as far back as the year 2000" << endl;
        }
        cout << endl;
    }
    return 0;
}

int season(const string s)
{
    string term = s.substr(0, s.find(" "));
    size_t pos = s.find(" ");
    string year = s.substr(pos);

    if (term == "Spring") return stoi(year) * 10 + 1;
    else if (term == "Summer") return stoi(year) * 10 + 2;
    else if (term == "Fall") return stoi(year) * 10 + 3;
    else return 0;
}