/************************************
LAB 13: Write A Customer Service Simulation
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<queue>

using namespace std;

#include<cmath>
#include<ctime>
#include<cstdlib>
#include<cstring>

/// requires cmath and cstdlib (and srand and rand to seed the random number generator)
int getRandomNumberOfServiceRequests(double averageRequestsPerTimeStep)
{
  int requests = 0;
  double probOfnRequests = exp(-averageRequestsPerTimeStep);
  for (double randomValue = (double)rand() / RAND_MAX;
    (randomValue -= probOfnRequests) > 0.0;
    probOfnRequests *= averageRequestsPerTimeStep / (double)++requests);
  return requests;
}

struct Customer
{
  char ID;
  int arrival;
  int service;
  int complete;
};

struct serviceEvent
{
  int clockTime;
  int serverNumber;
  friend bool operator<(const serviceEvent&, const serviceEvent&);
};

bool operator<(const serviceEvent& a, const serviceEvent& b)
{
  if(a.clockTime < b.clockTime)return false;
  else return true;
}

int main()
{
  srand(time(0));

  cout << "LAB 13: Write A Customer Service Simulation" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  fstream source;
  source.open("simulation.txt", ios::in);

  if (source.fail())
  {
    cout << "ERROR-No file to get information from!";
    exit(EXIT_FAILURE);
  }

  int numOfServers, maxWait, minService, maxService, stopTime;
  float avgArrival;
  vector<string> info;
  char buf[1000];
  char* token;

  /// read the input values from a text file, one per line, in the order specified above.
  while(source.good())
  {
    string line;
    getline(source, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue;
    const string temp(token = strtok(buf, "\n"));
    info.push_back(temp);
  }
  numOfServers = atoi(info[0].c_str());
  avgArrival = atof(info[1].c_str());
  maxWait = atoi(info[2].c_str());
  minService = atoi(info[3].c_str());
  maxService = atoi(info[4].c_str());
  stopTime = atoi(info[5].c_str());

  cout << "Number of servers: " << numOfServers << endl;
  cout << "Customer arrival rate: " << avgArrival << " per minute, for " << stopTime << " minutes" << endl;
  cout << "Maximum queue length:  " << maxWait << endl;
  cout << "Minimum service time:  " << minService << " minutes" << endl;
  cout << "Maximum service time:  " << maxService << " minutes" << endl;
  cout << endl;

  /// declare and create and assign arrays and queues to be used in the solution
  Customer* servers = new Customer[numOfServers];
  bool* isBusy = new bool[numOfServers];
  for(int i = 0; i < numOfServers; i++)isBusy[i] = false;
  queue<Customer> waiting;
  priority_queue<serviceEvent> service;
  vector<Customer> served;
  float turnedAway = 0;
  int n = 0;
  Customer temp;

  /// the clock time loop
  for (int time = 0;; time++) /// the clock time
  {
    /// handle all service events scheduled to complete at this clock time
    ///while (event queue is not empty AND clock time of the top service event equals the current clock time)
    while(service.empty() == false && service.top().clockTime == time)
    {
      ///remove the top service event from the queue
      serviceEvent top = service.top();
      service.pop();
      ///determine the server associated with the removed service event
      int topServer = top.serverNumber;
      ///set this server's current customer's completion time to the current clock time
      servers[topServer].complete = time;
      ///copy this server's current customer to the served customers queue
      served.push_back(servers[topServer]);
      ///set this server to idle
      isBusy[topServer] = false;
    }

    /// handle new arrivals -- can be turned away if wait queue is at maximum length!
    ///if time is less than the time at which new arrivals stop
    if(time <= stopTime)
    {
      ///get the #of of arrivals from the Poisson process (a whole number >= 0) -- see the lecture topic notes!
      int arrival = getRandomNumberOfServiceRequests(avgArrival);
      ///for each new arrival
      for(int i = 0; i < arrival; i++)
      {
        ///if the wait queue is full
        if(waiting.size() == maxWait)
        {
          ///"turn away the customer" by adding one to the count of turned away customers
          turnedAway++;
        }
        else
        {
          ///create a new customer object, setting its arrival time equal to the current clock time
          temp.ID = (char)('A' + (n++ % 26));
          temp.arrival = time;
          ///copy the new customer to the wait queue
          waiting.push(temp);
        }
      }
    }

    /// for idle servers, move customer from wait queue and begin service
    ///for each server
    for(int i = 0; i < numOfServers; i++)
    {
      ///if (server is idle AND the wait queue is not empty)
      if(isBusy[i] == false && waiting.empty() == false)
      {
        ///remove top customer from wait queue
        temp = waiting.front();
        waiting.pop();
        ///copy it to the server array
        servers[i] = temp;
        ///set the copied customer's service time to the current clock time
        servers[i].service = time;
        ///use random number generation to determing the service time interval for the customer
        int serveTime = minService + rand() % (maxService - minService + 1);
        ///create a new service event for the server, for the current clock time PLUS the service time interval
        serviceEvent add;
        add.clockTime = time + serveTime;
        add.serverNumber = i;
        ///add the service event to the event queue
        service.push(add);
        isBusy[i] = true;
      }
    }

    /// output the summary
    cout << "Time: " << time << endl;
    cout << "---------------------------" << endl;
    ///output a heading for the visual prepresentation of the servers and the wait queue
    cout << "line now serving wait queue" << endl;
    cout << "---- ----------- ----------" << endl;
    ///for each server
    for(int i = 0; i < numOfServers; i++)
    {
      ///output the server's index number (zero-based)
      cout << " " << i << "       ";
      ///show the ID of the customer being served by that server (blank if idle)
      if(isBusy[i] == true)cout << servers[i].ID;
      else cout << ' ';

      cout << "        ";
      ///for server 0 only, show the IDs of customers in the wait queue
      if(i == 0 && waiting.size() > 0) for(queue<Customer>print = waiting; !print.empty(); print.pop())cout << print.front().ID;
      cout << endl;
    }

    /// summarize performance
    float average = 0;
    ///iterate over the served customers to get the average time between arrival and completion
    for(int i = 0; i < served.size(); i++)
    {
      average += (served[i].complete - served[i].arrival);
    }
    if(served.size() > 0)
    {
      ///and if any, output the average of their "completion time" minus their "arrival time"
      average = average / served.size();
    }
    cout << "Avg time: " << average;
    ///output the rate of customers turned away
    cout << " Turned away per minute: ";
    if(turnedAway > 0)cout << (turnedAway / time);
    else cout << '0';

    cout << endl;

    /// if the user wants to quit, break out of this loop
    string buf = " ";
    cout << "Press ENTER to continue, X-ENTER to exit" << endl;
    getline(cin,buf);
    if(buf[0] == 'x' || buf[0] == 'X')break;
    cout << endl << endl;
  }

  delete [] servers;
  delete [] isBusy;

  cout << endl << endl;
}
