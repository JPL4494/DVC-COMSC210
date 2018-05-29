/************************************
LAB 8a: Write And Apply A Stack Template
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include<iostream>
using namespace std;

#include <cassert>

#include "Stack.h"
#include "Stack.h"

int main()
{
  cout << "LAB 8a: Write And Apply A Stack Template" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << "Creating two stacks" << endl;

  Stack<float> s1;
  Stack<float> s2;

  cout << endl << "Checking if both stacks are empty" << endl;
  assert(s1.isEmpty() == true);
  assert(s2.isEmpty() == true);
  cout << "Both stacks are empty" << endl;

  cout << endl << "Pushing two numbers into each stack" << endl;
  s1.push(1.234); s1.push(5.678);
  s2.push(100.000); s2.push(0.00001);
  cout << "Checking if the four numbers were pushed into the stack" << endl;
  assert(s1.isEmpty() == false);
  assert(s2.isEmpty() == false);
  cout << "Both stacks are not empty" << endl;

  cout << "Now printing out both stacks" << endl;
  cout << "Expected: 5.678 1.234" << endl << "Actual: ";
  s1.operator<<(cout);
  cout << endl << "Expected: 1e-005 100" << endl << "Actual: ";
  s2.operator<<(cout);
  cout << endl;

  cout << endl << "Peeking into the stacks to see if numbers entered are there" << endl;
  float temp1 = 5.678; float temp2 = 0.00001;
  assert(s1.peek(temp1) == true);
  assert(s2.peek(temp2) == true);
  cout << "Both numbers are in the stacks" << endl;

  cout << endl << "Peeking into the stacks to see if numbers not entered are there" << endl;
  float temp3 = 1.00000; float temp4 = 5.000;
  assert(s1.peek(temp3) == false);
  assert(s2.peek(temp4) == false);
  cout << "Both numbers are not in the stacks" << endl;

  cout << endl << "Popping the stacks and checking the values were removed" << endl;
  assert(s1.pop(temp1) == true);
  assert(s2.pop(temp2) == true);
  assert(s1.pop(temp1) == false);
  assert(s2.pop(temp2) == false);
  cout << "Both numbers were in the stacks and are now removed" << endl;

  cout << endl << "Emptying stack 2 and checking that it is empty" << endl;
  s2.makeEmpty();
  assert(s2.isEmpty() == true);
  cout << "Stack 2 is now empty" << endl;

  cout << endl << "Pushing two numbers into stack 2 to check topPop function" << endl;
  float topPop1 = 3.14; float topPop2 = 4.13;
  s2.push(topPop1); s2.push(topPop2);
  cout << "Now checking topPop function" << endl;
  assert(s2.topPop() == topPop2);
  assert(s2.topPop() == topPop1);
  cout << "topPop function works" << endl;

  {
    cout << endl << "Copying using inline copy" << endl;
    Stack<float> copy = s1;
    cout << "Now checking copy using assert functions" << endl;
    assert(s1.isEmpty() == copy.isEmpty());
    assert(s1.peek(temp3) == copy.peek(temp3));
    cout << "Passed assert test" << endl;
  }

  {
    cout << endl << "Copying using after declaration copy" << endl;
    Stack<float> copy;
    copy = s1;
    cout << "Now checking copy using assert functions" << endl;
    assert(s1.isEmpty() == copy.isEmpty());
    assert(s1.peek(temp3) == copy.peek(temp3));
    cout << "Passed assert test" << endl;
  }

  cout << endl << endl;
}
