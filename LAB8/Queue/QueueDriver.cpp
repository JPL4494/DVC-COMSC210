/************************************
LAB 8b: Write And Test A Queue Template
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include<iostream>
using namespace std;

#include <cassert>

#include "Queue.h"
#include "Queue.h"

int main()
{
  cout << "LAB 8b: Write And Test A Queue Template" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << "Creating two queue objects" << endl;
  Queue<float> q1, q2;

  cout << endl << "Checking that both started empty" << endl;
  assert(q1.isEmpty() == true);
  assert(q2.isEmpty() == true);
  cout << "Both queues are empty" << endl;

  cout << endl << "Pushing two numbers into both queues" << endl;
  float temp1 = 1.234; float temp2 = 5.678; float temp3 = 100.000; float temp4 = 0.00001;
  q1.push(temp1); q1.push(temp2);
  q2.push(temp3); q2.push(temp4);
  cout << "Checking if the four numbers were pushed into the stack" << endl;
  assert(q1.isEmpty() == false);
  assert(q2.isEmpty() == false);
  cout << "Both queues are not empty" << endl;

  cout << "Now printing out both queues" << endl;
  cout << "Expected: 1.234 5.678" << endl << "Actual: ";
  q1.operator<<(cout);
  cout << endl << "Expected: 100 1e-005" << endl << "Actual: ";
  q2.operator<<(cout);
  cout << endl;

  cout << endl << "Now checking the peek function" << endl;
  assert(q1.peek() == temp1);
  assert(q2.peek() == temp3);
  cout << "Peek function works" << endl;

  cout << endl << "Now checking pop function" << endl;
  assert(q1.pop(temp1) == true);
  assert(q2.pop(temp2) == true);
  cout << "Pop function works" << endl;

  cout << endl << endl;
}
