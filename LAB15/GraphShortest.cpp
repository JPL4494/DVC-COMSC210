/************************************
Lab 15b: Write A Function For Shortest Route
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#include <cstdlib>

struct Vertex
{
  string name;

  bool isVisited;
  list<pair<int, double> > adjacentVertices;
  int prev;
  double cost;
};

pair<stack<int>, double> getShortestRoute(const int iStart, const int iEnd, vector<Vertex>& database)
{
  pair<stack<int>, double> result;
  list<pair<int, double> >::iterator it;/// to iterate over adjacentVertices
  /// TO DO -- write this function

  ///set cost=0 and previous index=-1 for all vertices, and mark all as not visited
  for(int i = 0; i < database.size(); i++)
  {
    database[i].cost = 0;
    database[i].prev = -1;
    database[i].isVisited = false;
  }
  ///create a queue to store "vertices to consider"
  queue<int> toConsider;
  ///mark start vertex as "visited" and push it onto the "vertices to consider" queue
  database[iStart].isVisited = true;
  toConsider.push(iStart);
  ///while the "vertices to consider" queue is not empty
  while(toConsider.empty() == false)
  {
    ///peek/pop a vertex from the "vertices to consider" queue
    int index = toConsider.front();
    toConsider.pop();
    ///for each of that vertex's neighbors
    for(it = database[index].adjacentVertices.begin(); it != database[index].adjacentVertices.end(); it++)
    {
      ///if neighbor has not yet been visited
      if((database[it->first].isVisited) == false)
      {
        ///mark neighbor as visited
        database[it->first].isVisited = true;
        ///set neighbor's cost to 1+cost of vertex under consideration
        database[it->first].cost = 1 + database[index].cost;
        ///set neighbor's previous vertex to the vertex under consideration
        database[it->first].prev = index;
        ///push neighbor into the "vertices to consider" queue
        toConsider.push(it->first);
      }
      ///if neighbor vertex contains the index of the end city
      if((it->first) == iEnd)
      {
        ///empty the "vertices to consider" queue
        while(toConsider.empty() == false)toConsider.pop();
      }
    }///exit for-loop
  }
  ///the route's cost equals the end vertex's cost
  result.second = database[iEnd].cost;
  ///build a stack of entries, starting from the end vertex, back towards the start
  int route = iEnd;
  while(route != iStart)
  {
    result.first.push(route);
    route = database[route].prev;
  }
  result.first.push(iStart);

  return result;
}

int main()
{
  cout << "Lab 15b: Write A Function For Shortest Route" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  ifstream fin;
  fin.open("cities.txt");
  if (!fin.good()) throw "I/O error";

  /// process the input file
  vector<Vertex> database;
  while (fin.good()) /// EOF loop
  {
    string fromCity, toCity, cost;

    /// read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    getline(fin, cost);
    fin.ignore(1000, 10); /// skip the separator
    /// TO DO -- code to eliminate whitespace
    fromCity.erase(remove_if(fromCity.begin(), fromCity.end(), ::isspace), fromCity.end());
    toCity.erase(remove_if(toCity.begin(), toCity.end(), ::isspace), toCity.end());

    /// add vertices for new cities included in the edge
    int iToVertex = -1, iFromVertex = -1, i;
    for (i = 0; i < database.size(); i++) /// seek "to" city
      if (database[i].name == fromCity)
        break;
    if (i == database.size()) /// not in database yet
    {
      /// store the vertex if it is new
      Vertex fromVertex;
      fromVertex.name = fromCity;
      database.push_back(fromVertex);
    }
    iFromVertex = i;

    for (i = 0; i < database.size(); i++) /// seek "from" city
      if (database[i].name == toCity)
        break;
    if (i == database.size()) /// not in vector yet
    {
      /// store the vertex if it is new
      Vertex toVertex;
      toVertex.name = toCity;
      database.push_back(toVertex);
    }
    iToVertex = i;

    /// store bi-directional edges
    double edgeCost = atof(cost.c_str());
    database[iFromVertex].adjacentVertices.push_back(pair<int, double>(iToVertex, edgeCost));
    database[iToVertex].adjacentVertices.push_back(pair<int, double>(iFromVertex, edgeCost));
  }
  fin.close();
  cout << "Input file processed\n\n";

  while (true)
  {
    string fromCity, toCity;
    cout << "\nEnter the source city [blank to exit]: ";
    getline(cin, fromCity);
    if (fromCity.length() == 0) break;

    /// find the from city
    bool there = false;
    int iFrom;
    for (iFrom = 0; iFrom < database.size(); iFrom++)
    {
      if (database[iFrom].name == fromCity)there = true;
      if(there)break;
    }

    if(!there)cout << "City not found, please enter a city on the list" << endl;
    else
    {
      there = false;
      cout << "Enter the destination city [blank to exit]: ";
      getline(cin, toCity);
      if (toCity.length() == 0) break;

      /// find the destination city
      int iTo;
      for (iTo = 0; iTo < database.size(); iTo++)
      {
        if (database[iTo].name == toCity)there = true;
        if(there)break;
      }

      /// TO DO -- skip the next code block if no matching cites are found
      if(!there)cout << "City not found, please enter a city on the list" << endl;
      else
      {
        cout << "Route";
        pair<stack<int>, double> result = getShortestRoute(iFrom, iTo, database);
        while (!result.first.empty()){cout << '-' << database[result.first.top()].name; result.first.pop();}
        cout << endl << "Total edges: " << result.second;
      }
    }
    cout << endl;
  }
}
