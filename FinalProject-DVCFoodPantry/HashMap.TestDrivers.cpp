// Programmer Name: Alex Kogan
// Programmer ID: 1865080
// Programmer 2 Name: Rachael Karim
// Programmer 2 ID: 0136068
// Programmer 3 Name: Aiman Al Sharai
// Programmer 3 ID: 1839435
// Programmer 4 Name: Aurelia Kisanaga
// Programmer 4 ID: 1960007
// Programmer 5 Name: Steven Dominic Sahar
// Programmer 5 ID: 1855840

#include <iostream>
#include <string>
using namespace std;

#include "HashTable.h"
#include "HashTable.h" // test for if-else correctness

#include "cassert"

void intHashTableTest( );
void doubleHashTableTest( );
void stringHashTableTest( );
void charHashTableTest( );

int hashTableTestMain( )
{
    intHashTableTest( );

    stringHashTableTest( );

    return 0;
}

int intHashFunction (const int& key)
{
    return key;
}

void intHashTableTest( )
{
    // initialize HashTable data
    HashTable<int, int, 20> data(intHashFunction);

    cout << "\nHashTable<int, int, 20> data\n";

    // HashTable::operator[ ] setter
    cout << "\nTesting HashTable::operator[ ] setter\n";
    cout << "Adding key:1 and value:11\n";
    data[1] = 11;
    cout << "Adding key:2 and value:22\n";
    data[2] = 22;
    cout << "Adding key:50 and value:500\n";
    data[50] = 500;
    cout << "Adding key:-4 and value:40\n";
    data[-4] = 40;
    cout << "Adding key:21 and value:2020\n";
    data[21] = 2020;

    // HashTable::size()
    cout << "\nTesting HashTable::size()\n";
    cout << "EXPECTED: 4\n";
    cout << "ACTUAL: " << data.size() << endl;
    assert (data.size() == 5);

    // HashTable::operator[ ] getter
    cout << "\nTesting HashTable::operator[ ] getter\n";
    cout << "EXPECTED: 11\n";
    cout << "ACTUAL: " << data[1] << endl;
    cout << "EXPECTED: 22\n";
    cout << "ACTUAL: " << data[2] << endl;
    cout << "EXPECTED: 500\n";
    cout << "ACTUAL: " << data[50] << endl;
    cout << "EXPECTED: 40\n";
    cout << "ACTUAL: " << data[-4] << endl;
    cout << "EXPECTED: 2020\n";
    cout << "ACTUAL: " << data[21] << endl;
    cout << "EXPECTED: 0\n";
    cout << "ACTUAL: " << data[6] << endl;
    assert(data[1] == 11);
    assert(data[2] == 22);
    assert(data[50] == 500);
    assert(data[-4] == 40);
    assert(data[21] == 2020);
    assert(data[6] == int());

    // HashTable::containsKey()
    cout << "\nTesting HashTable::containsKey()\n";
    cout << "EXPECTED: true\n";
    cout << "ACTUAL: " << (data.containsKey(1)? "true": "false") << endl;
    cout << "EXPECTED: true\n";
    cout << "ACTUAL: " << (data.containsKey(-4)? "true": "false") << endl;
    cout << "EXPECTED: false\n";
    cout << "ACTUAL: " << (data.containsKey(7)? "true": "false") << endl;
    assert(data.containsKey(1) == true);
    assert(data.containsKey(-4) == true);
    assert(data.containsKey(7) == false);

    // HashTable::deleteKey()
    cout << "\nTesting HashTable::deleteKey()\n";
    data.deleteKey(21);
    cout << "EXPECTED SIZE: 5\n";
    cout << "ACTUAL SIZE: " << data.size() << endl;
    assert (data.size() == 5);

    // HashTable::keys()
    cout << "\nTesting HashTable::keys()\n";
    Queue<int> keys = data.keys();
    cout << "EXPECTED SIZE: 1\n";
    cout << "ACTUAL SIZE: " << keys.front() << endl;
    assert(keys.front() == 1);
    keys.pop();
    cout << "EXPECTED SIZE: 2\n";
    cout << "ACTUAL SIZE: " << keys.front() << endl;
    assert(keys.front() == 2);

    // Copy object test
    cout <<"\nTesting copy object test\n";
    HashTable<int, int, 20> dataCopy = data;
    cout << "EXPECTED SIZE: 5\n";
    cout << "ACTUAL Size: " << dataCopy.size() << endl;
    assert(dataCopy.size() == 5);
    cout << "EXPECTED: 11 for dataCopy[11]\n";
    cout << "ACTUAL: " << dataCopy[1] << endl;
    assert(dataCopy[1] == 11);

    // Const copy object test
    cout <<"\nTesting const copy object test\n";
    const HashTable<int, int, 20> dataCopyB = data;
    cout << "EXPECTED SIZE: 5\n";
    cout << "ACTUAL Size: " << dataCopyB.size() << endl;
    assert(dataCopyB.size() == 5);
    cout << "EXPECTED: 11 for dataCopy[11]\n";
    cout << "ACTUAL: " << dataCopyB[1] << endl;
    assert(dataCopy[1] == 11);

    //dataCopyB[5]
    //dataCopyB.deleteKey(1); method for a constant object will throw an error which shows the correctness of implementation.

    // HashTable::clear()
    cout <<"\nTesting HashTable::clear()\n";
    data.clear();
    cout << "EXPECTED SIZE: 0\n";
    cout << "ACTUAL Size: " << data.size() << endl;
    assert(data.size() == 0);
}

int stringHashFunction(const string& key)
{
    int hash = 0;

    for (char i : key)
    {
        hash += i;
    }

    return hash;
}

void stringHashTableTest( )
{
    // initialize HashTable data
    HashTable<string, string, 20> data(stringHashFunction);

    cout << "\nHashTable<string, string, 20> data\n";

    // HashTable::operator[ ] setter
    cout << "\nTesting HashTable::operator[ ] setter\n";
    cout << "Adding key:AA and value:aa\n";
    data["AA"] = "aa";
    cout << "Adding key:BB and value:bb\n";
    data["BB"] = "bb";
    cout << "Adding key:XX and value:xx\n";
    data["XX"] = "xx";
    cout << "Adding key:YY and value:yy\n";
    data["YY"] = "yy";
    cout << "Adding key:ZZ and value:zz\n";
    data["ZZ"] = "zz";


    // HashTable::size()
    cout << "\nTesting HashTable::size()\n";
    cout << "EXPECTED: 4\n";
    cout << "ACTUAL: " << data.size() << endl;
    assert (data.size() == 5);

    // HashTable::operator[ ] getter
    cout << "\nTesting HashTable::operator[ ] getter\n";
    cout << "EXPECTED: aa\n";
    cout << "ACTUAL: " << data["AA"] << endl;
    cout << "EXPECTED: bb\n";
    cout << "ACTUAL: " << data["BB"] << endl;
    cout << "EXPECTED: xx\n";
    cout << "ACTUAL: " << data["XX"] << endl;
    cout << "EXPECTED: yy\n";
    cout << "ACTUAL: " << data["YY"] << endl;
    cout << "EXPECTED: zz\n";
    cout << "ACTUAL: " << data["ZZ"] << endl;
    cout << "EXPECTED: string()\n";
    cout << "ACTUAL: " << data[string()] << endl;
    assert(data["AA"] == "aa");
    assert(data["BB"] == "bb");
    assert(data["XX"] == "xx");
    assert(data["YY"] == "yy");
    assert(data["ZZ"] == "zz");
    assert(data[string()] == string());

    // HashTable::containsKey()
    cout << "\nTesting HashTable::containsKey()\n";
    cout << "EXPECTED: true\n";
    cout << "ACTUAL: " << (data.containsKey("AA")? "true": "false") << endl;
    cout << "EXPECTED: true\n";
    cout << "ACTUAL: " << (data.containsKey("ZZ")? "true": "false") << endl;
    cout << "EXPECTED: false\n";
    cout << "ACTUAL: " << (data.containsKey("WW")? "true": "false") << endl;
    assert(data.containsKey("AA") == true);
    assert(data.containsKey("ZZ") == true);
    assert(data.containsKey("WW") == false);

    // HashTable::deleteKey()
    cout << "\nTesting HashTable::deleteKey()\n";
    data.deleteKey("ZZ");
    cout << "EXPECTED SIZE: 5\n";
    cout << "ACTUAL SIZE: " << data.size() << endl;
    assert (data.size() == 5);

    // HashTable::keys()
    cout << "\nTesting HashTable::keys()\n";
    Queue<string> keys = data.keys();
    assert(keys.size() == 5);
    keys.pop();
    assert(keys.size() == 4);

    // Copy object test
    cout <<"\nTesting copy object test\n";
    HashTable<string, string, 20> dataCopy = data;
    cout << "EXPECTED SIZE: 5\n";
    cout << "ACTUAL Size: " << dataCopy.size() << endl;
    assert(dataCopy.size() == 5);
    cout << "EXPECTED: aa for dataCopy[AA]\n";
    cout << "ACTUAL: " << dataCopy["AA"] << endl;
    assert(dataCopy["AA"] == "aa");

    // Const copy object test
    cout <<"\nTesting const copy object test\n";
    const HashTable<string, string, 20> dataCopyB = data;
    cout << "EXPECTED SIZE: 5\n";
    cout << "ACTUAL Size: " << dataCopyB.size() << endl;
    assert(dataCopyB.size() == 5);
    cout << "EXPECTED: aa for dataCopy[AA]\n";
    cout << "ACTUAL: " << dataCopyB["AA"] << endl;
    assert(dataCopy["AA"] == "aa");

    //dataCopyB[5]
    //dataCopyB.deleteKey(1); method for a constant object will throw an error which shows the correctness of implementation.

    // HashTable::clear()
    cout <<"\nTesting HashTable::clear()\n";
    data.clear();
    cout << "EXPECTED SIZE: 0\n";
    cout << "ACTUAL Size: " << data.size() << endl;
    assert(data.size() == 0);


}
