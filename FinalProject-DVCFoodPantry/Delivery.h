// Programmer Name (Programmer ID)
// Aiman Al Sharai (1839435)
// Steven Dominic Sahar (1855840)
// Aurelia Kisanaga (1960007)
// Rachael Karim (0136068)
// Alex Kogan (1865080)

#ifndef DELIVERY_DEMO_H
#define DELIVERY_DEMO_H

#include <map>
using namespace std;

struct Calendar
{
    int day;
    int month;
    int year;
};

struct Status
{
    Calendar deliveryDate = { 0, 0, 0 };
    Calendar deliveredDate = { 0, 0, 0 };
    bool deliveredStatus = false;
    string deliveryCompany = "";
    string trackingNumber = "";
};

void delivery(map<string, Status>&);

#endif // !DELIVERY_DEMO_H
