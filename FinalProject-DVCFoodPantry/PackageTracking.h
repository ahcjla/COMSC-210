// Programmer Name (Programmer ID)
// Aiman Al Sharai (1839435)
// Steven Dominic Sahar (1855840)
// Aurelia Kisanaga (1960007)
// Rachael Karim (0136068)
// Alex Kogan (1865080)

#ifndef PACKAGE_TRACKING_DEMO_H
#define PACKAGE_TRACKING_DEMO_H

#include "PackageTracker.h"

int studentHashFunction(const string& name);
int mealIDHashFunction(const int& id);
void packageTracking(PackageTracker<100, 1000>& tracker);

#endif // !PACKAGE_TRACKING_DEMO_H
