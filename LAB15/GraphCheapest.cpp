/************************************
Lab 15c: Write A Function For Cheapest Route
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

struct Container /// vertex container, for multiple ways to get to a vertex
{
  int vertex; /// index in database array
  int prev; /// index in database array
  double cost;

  bool operator<(const Container& v) const
  {
    return cost > v.cost;
  }
};

pair<stack<int>, double> getCheapestRoute(int iStart, int iEnd, vector<Vertex>& database)
{
  pair<stack<int>, double> result;
  list<pair<int, double> >::iterator it;/// to iterate over adjacentVertices
  /// TO DO -- write this function

  ///reset the cost and previous indices for all vertices, isVisited to false
  for(int i = 0; i < database.size(); i++)
  {
    database[i].isVisited = false;
    database[i].prev = -1;
    database[i].cost = 0;
  }
  ///create priority queue of Container objects
  priority_queue<Container> toConsider;
  ///create a Container object for the start vertex, with 0 cost and negative prev index
  Container temp;
  temp.vertex = iStart;
  temp.prev = -1;
  temp.cost = 0;
  ///push the start vertex's container onto the priority queue
  toConsider.push(temp);
  ///while the priority queue is not empty
  while(toConsider.empty() == false)
  {
    ///peek/pop a container object from the priority queue
    Container top = toConsider.top();
    toConsider.pop();
    ///if contained object's been visited, "continue"
    if(database[top.vertex].isVisited == true)continue;

    else
    {
      ///mark contained object as visited
      database[top.vertex].isVisited = true;
      ///set its cost to that of its container
      database[top.vertex].cost = top.cost;
      ///set its prev to that of its container
      database[top.vertex].prev = top.prev;
    }
    ///if contained vertex is the end vertex, exit while-loop
    if(top.vertex == iEnd)
      break;

    ///for each of that vertex's unvisited neighbors
    list<pair<int, double> > neighbor;
    for(neighbor = database[top.vertex].adjacentVertices; neighbor.empty() == false; neighbor.pop_back())
    {
      ///create a container object for neighbor
      Container nextTo;
      nextTo.vertex = neighbor.back().first;
      ///set its cost to that of the vertex, plus edge cost
      nextTo.cost = neighbor.back().second + database[top.vertex].cost;
      ///set its previous to the vertex
      nextTo.prev = top.vertex;
      ///push container onto priority queue
      toConsider.push(nextTo);
    }
  }
  ///the route's cost equals the end vertex's cost
  result.second = database[iEnd].cost;
  ///build a stack of entries, starting from the end vertex, back towards the start
  int index = iEnd;
  while(index != iStart)
  {
    result.first.push(index);
    index = database[index].prev;
  }

  result.first.push(iStart);

  return result;
}

int main()
{
  cout << "Lab 15c: Write A Function For Cheapest Route" << endl;
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
        pair<stack<int>, double> result = getCheapestRoute(iFrom, iTo, database);
        while (!result.first.empty()){cout << '-' << database[result.first.top()].name; result.first.pop();}
        cout << endl << "Total edges: " << result.second;
      }
    }
    cout << endl;
  }
}
