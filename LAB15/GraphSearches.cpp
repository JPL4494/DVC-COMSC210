/************************************
Lab 15a: Write A Function For Depth-First Search, DFS
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct Vertex
{
  string name;

  bool isVisited;
  list<int> adjacentVertices;
};

queue<int> doBreadthFirstSearch(int iOriginVertex, vector<Vertex>& database)
{
  /// TO DO -- write this function

  ///create an empty result queue to return at end of function call
  queue<int> searchOrder; /// return this queue of indexes
  ///create another queue to store "vertices to consider"
  queue<Vertex> toConsider;
  ///initialize each vertex in database: set to "not visited"
  for(int i = 0; i < database.size(); i++)database[i].isVisited = false;
  ///mark starting vertex as "visited"
  database[iOriginVertex].isVisited = true;
  ///push start vertex's index onto the result queue
  searchOrder.push(iOriginVertex);
  ///push start vertex's index onto "vertices to consider" queue
  toConsider.push(database[iOriginVertex]);
  ///while "vertices to consider" queue is not empty
  while(!toConsider.empty())
  {
    ///peek/pop a vertex from the "vertices to consider" queue
    Vertex temp = toConsider.front();
    toConsider.pop();
    ///for each of that vertex's "neighbors"
    list<int> j = temp.adjacentVertices;
    for(int i = 0; i < temp.adjacentVertices.size(); i++)
    {
      int k = j.front();
      j.pop_front();
      ///if neighbor has not yet been visited
      if(database[k].isVisited == false)
      {
        ///mark neighbor as visited
        database[k].isVisited = true;
        ///push neighbor onto the result queue
        searchOrder.push(k);
        ///push neighbor onto the "vertices to consider" queue
        toConsider.push(database[k]);
      }
    }
  }

  return searchOrder;
}

queue<int> doDepthFirstSearch(int iOriginVertex, vector<Vertex>& vertices)
{
  /// TO DO -- write this function

  ///create an empty result queue for returning at the end
  queue<int> searchOrder;
  ///create a stack to store "vertices to consider"
  stack<int> toConsider;
  ///initialize each vertex in database: set to "not visited"
  for(int i = 0; i < vertices.size(); i++)vertices[i].isVisited = false;
  ///push start vertex's index onto the "vertices to consider" stack
  toConsider.push(iOriginVertex);
  ///while "vertices to consider" stack is not empty
  while(toConsider.empty() == false)
  {
    ///peek/pop a vertex from the "vertices to consider" stack
    int temp = toConsider.top();
    toConsider.pop();
    ///if that vertex has not yet been visited
    if(vertices[temp].isVisited == false)
    {
      ///mark the vertex as visited
      vertices[temp].isVisited = true;
      ///push vertex onto the result queue
      searchOrder.push(temp);
      ///for each of that vertex's "neighbors" (in reverse order)
      list<int> j = vertices[temp].adjacentVertices;
      for(int i = 0; i < vertices[temp].adjacentVertices.size(); i++)
      {
        int k = j.back();
        j.pop_back();
        ///if neighbor has not yet been visited
        if(vertices[k].isVisited == false)
        {
          ///push neighbor onto the "vertices to consider" stack
          toConsider.push(k);
        }
      }
    }
  }

  return searchOrder;
}

int main()
{
  cout << "Lab 15a: Write A Function For Depth-First Search, DFS" << endl;
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
    string fromCity, toCity;

    /// read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    fin.ignore(1000, 10); /// skip the line with distance
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
    database[iFromVertex].adjacentVertices.push_back(iToVertex);
    database[iToVertex].adjacentVertices.push_back(iFromVertex);
  }
  fin.close();
  cout << "Input file processed\n\n";

  while (true)
  {
    /// get the start city for the search
    string startCity;
    cout << "\nEnter the start city [blank to exit]: ";
    getline(cin, startCity);
    if (startCity.length() == 0) break;

    /// find the start city
    int i;
    bool there = false;
    for (i = 0; i < database.size(); i++)
    {
      if (database[i].name == startCity)there = true;
      if(there)break;
    }

    /// TO DO -- skip the next code blocks if no matching city is found/////////////////////////////////////////////
    if(!there)cout << "City not found, please enter a city on the list" << endl;
    else
    {
      /// BFS result
      cout << "BFS";
      queue<int> q = doBreadthFirstSearch(i, database);
      while(!q.empty())
      {
        cout  << '-'<< database[q.front()].name;
        q.pop();
      }
      cout << endl << endl;

      cout << "DFS";
      q = doDepthFirstSearch(i, database);
      while(!q.empty())
      {
        cout  << '-'<< database[q.front()].name;
        q.pop();
      }
    }
    cout << endl;;
  }
}
