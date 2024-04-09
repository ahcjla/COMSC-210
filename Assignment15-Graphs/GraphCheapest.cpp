// Programmer: Aurelia Kisanaga
// Programmer's ID: 1960007

#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;

#include <cstdlib>

struct Node
{
    string name;

    bool isVisited;
    list<pair<int, double> > neighbors;
    int prev;
    double cost;
};

// the path to a node and the cost of that path
struct Terminus
{
    int index;
    int prev;
    double cost;
};

bool operator < (const Terminus& a, const Terminus& b)
{
    return b.cost < a.cost;     // reverse logic for lo-to-hi
}

pair<stack<int>, double> getCheapestRoute(int iStart, int iEnd, vector<Node>& database)
{
    pair<stack<int>, double> result;
    list<pair<int, double> >::iterator it; // to iterate over neighbors
  // TO DO -- write this function
    // All Nodes - set cost to zero, prev = -1 and isVisited=false
    for (unsigned int i = 0; i < database.size(); i++)
    {
        database[i].cost = 0;
        database[i].prev = -1;
        database[i].isVisited = false;
    }

    // to-do list
    priority_queue<Terminus> todo;

    Terminus startNode;
    startNode.index = iStart;
    startNode.cost = 0;
    startNode.prev = -1;

    todo.push(startNode);

    while (!todo.empty())
    {
        Terminus NodeUnderCons = todo.top(); // Node Under Considertion
        todo.pop();
        if (database[NodeUnderCons.index].isVisited) continue;
        database[NodeUnderCons.index].isVisited = true;
        database[NodeUnderCons.index].cost = NodeUnderCons.cost;
        database[NodeUnderCons.index].prev = NodeUnderCons.prev;
        if (NodeUnderCons.index == iEnd) break;
        for (it = database[NodeUnderCons.index].neighbors.begin(); it != database[NodeUnderCons.index].neighbors.end(); it++)
        {
            Terminus neighbor; 
            neighbor.index = (*it).first;
            neighbor.prev = NodeUnderCons.index;
            neighbor.cost = (*it).second + NodeUnderCons.cost;
            todo.push(neighbor);
        }
    }

    //the route's cost equals the end node's cost
    result.second = database[iEnd].cost;

    //build a stack of entries, starting from the end node, back towards the start
    for (int endNode = iEnd; endNode >= 0; endNode = database[endNode].prev)
    {
        result.first.push(endNode);
    }

    return result;
}

int main()
{
    // Programmer's Identification
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "Cheapest Route\n";
    cout << "File: " << __FILE__ << endl;

    ifstream fin;
    fin.open("cities.txt");
    if (!fin.good()) throw "I/O error";

    // process the input file
    vector<Node> database;
    while (fin.good()) // EOF loop
    {
        string fromCity, toCity, cost;

        // read one edge
        getline(fin, fromCity);
        getline(fin, toCity);
        getline(fin, cost);
        fin.ignore(1000, 10); // skip the separator

        // add nodes for new cities included in the edge
        unsigned int iToNode = -1, iFromNode = -1, i;
        for (i = 0; i < database.size(); i++) // seek "to" city
            if (database[i].name == fromCity)
                break;
        if (i == database.size()) // not in database yet
        {
            // store the node if it is new
            Node fromNode;
            fromNode.name = fromCity;
            database.push_back(fromNode);
        }
        iFromNode = i;

        for (i = 0; i < database.size(); i++) // seek "from" city
            if (database[i].name == toCity)
                break;
        if (i == database.size()) // not in vector yet
        {
            // store the node if it is new
            Node toNode;
            toNode.name = toCity;
            database.push_back(toNode);
        }
        iToNode = i;

        // store bi-directional edges
        double edgeCost = atof(cost.c_str());
        database[iFromNode].neighbors.push_back(pair<int, double>(iToNode, edgeCost));
        database[iToNode].neighbors.push_back(pair<int, double>(iFromNode, edgeCost));
    }
    fin.close();
    cout << "Input file processed\n\n";

    while (true)
    {
        string fromCity, toCity;

        cout << "\nEnter the source city [blank to exit]: ";
        getline(cin, fromCity);
        if (fromCity.length() == 0) break;

        // find the from city
        unsigned int iFrom;
        for (iFrom = 0; iFrom < database.size(); iFrom++)
            if (database[iFrom].name == fromCity)
                break;

        cout << "Enter the destination city [blank to exit]: ";
        getline(cin, toCity);
        if (toCity.length() == 0) break;

        // find the destination city
        unsigned int iTo;
        for (iTo = 0; iTo < database.size(); iTo++)
            if (database[iTo].name == toCity)
                break;

        //cout << "Route";
        pair<stack<int>, double> result = getCheapestRoute(iFrom, iTo, database);
        cout << "Total miles: " << result.second;
        for (; !result.first.empty(); result.first.pop())
            cout << '-' << database[result.first.top()].name;
        cout << endl;
    }
    cout << "Done!" << endl;
    return 0;
}