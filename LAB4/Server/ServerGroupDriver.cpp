/************************************
Lab 4a, Introduction To Dynamic Arrays
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include <iostream>
using namespace std;

#include <cassert>

#include "ServerGroup.h"
#include "ServerGroup.h"

int main()
{
  cout << "Lab 4a, Introduction To Dynamic Arrays" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << "Creating a ServerGroup with 5 servers" << endl;
  ServerGroup s(5);

  cout << "Checking serverFree function, expected: Good" << endl;
  cout << "Actual: ";
  if(s.serverFree())cout << "Good";
  else cout << "Error";

  cout << endl << endl;
  cout << "Adding 5 customers that will need 12 minutes" << endl;
  s.useServer(12);
  s.serverFree();
  s.useServer(12);
  s.serverFree();
  s.useServer(12);
  s.serverFree();
  s.useServer(12);
  s.serverFree();
  s.useServer(12);

  cout << "Checking if all servers are busy, expected: True" << endl;
  cout << "Actual: ";
  if(!s.serverFree())cout << "True";
  else cout << "False";

  cout << endl << endl;

  cout << "Checking if spServer is free, expected: True" << endl;
  cout << "Actual: ";
  if(s.spServerFree())cout << "True";
  else cout << "False";

  cout << endl << endl;

  cout << "Adding a customer that needs 22 minutes to spServer" << endl;
  s.usespServer(22);
  cout << "Checking if spServer is free, expected: False" << endl;
  cout << "Actual: ";
  if(s.spServerFree())cout << "True";
  else cout << "False";

  cout << endl << endl;

  cout << "Running the decServer 15 times" << endl;
  for(int i = 0; i < 15; i++)s.decServers();

  cout << "Now checking if servers are free, expected: True" << endl;
  cout << "Actual: ";
  if(s.serverFree())cout << "True";
  else cout << "False";

  cout << endl << endl;

  cout << "Now checking if spServer is free, expected: False" << endl;
  cout << "Actual: ";
  if(s.spServerFree())cout << "True";
  else cout << "False";

  cout << endl << endl;

  cout << "Now running decServer 7 times" << endl;
  for(int i = 0; i < 7; i++)s.decServers();
  cout << "Now checking if spServer is free, expected: True" << endl;
  cout << "Actual: ";
  if(s.spServerFree())cout << "True";
  else cout << "False";

  cout << endl << endl;
}
