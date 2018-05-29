/************************************
Lab 3b, const And Constructors, Part 2
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include <iostream>

using namespace std;

#include <cassert>

#include "Time.h"
#include "Time.h"

int main()
{
  cout << "Lab 3b, const And Constructors, Part 2" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << "Creating 2 time objects" << endl;

  Time t1(1,45,32);
  Time t2;

  cout << endl << "Setting a time object using member functions" << endl;

  t2.setHours(12);
  t2.setMinutes(13);
  t2.setSeconds(1);

  cout << endl << "Getting set data members from time objects using member functions" << endl;
  cout << "Checking time object one, expected results: 1:45:32" << endl;
  cout << "Actual: " << t1.getHours() << ":" << t1.getMinutes() << ":" << t1.getSeconds() << endl;

  cout << endl << "Getting set data members from time objects using member functions" << endl;
  cout << "Checking time object one, expected results: 12:13:1" << endl;
  cout << "Actual: " << t2.getHours() << ":" << t2.getMinutes() << ":" << t2.getSeconds() << endl;

  cout << endl << "Now checking timeInHours function on time object one" << endl;
  cout << "Expected: 1.75889" << endl;
  cout << "Actual: " << t1.timeInHours() << endl;

  cout << endl << "Now checking timeInMinutes function on time object one" << endl;
  cout << "Expected: 100.533" << endl;
  cout << "Actual: " << t1.timeInMinutes() << endl;

  cout << endl << "Now checking timeInSeconds function on time object one" << endl;
  cout << "Expected: 6332" << endl;
  cout << "Actual: " << t1.timeInSeconds() << endl;

  cout << endl << "Now checking timeInHours function on time object two" << endl;
  cout << "Expected: 12.2169" << endl;
  cout << "Actual: " << t2.timeInHours() << endl;

  cout << endl << "Now checking timeInMinutes function on time object two" << endl;
  cout << "Expected: 733.017" << endl;
  cout << "Actual: " << t2.timeInMinutes() << endl;

  cout << endl << "Now checking timeInSeconds function on time object two" << endl;
  cout << "Expected: 43981" << endl;
  cout << "Actual: " << t2.timeInSeconds() << endl;

  {
    cout << endl << "Copying using inline copy" << endl;
    const Time copy = t1;
    cout << "Now checking copy using assert functions" << endl;
    assert(copy.getHours() == t1.getHours());
    assert(copy.getMinutes() == t1.getMinutes());
    assert(copy.getSeconds() == t1.getSeconds());
    assert(copy.timeInHours() == t1.timeInHours());
    assert(copy.timeInMinutes() == t1.timeInMinutes());
    assert(copy.timeInSeconds() == t1.timeInSeconds());
    cout << "Passed assert test" << endl;
  }

  {
    cout << endl << "Copying using after declaration copy" << endl;
    Time copy(1,1,1);
    copy = t2;
    cout << "Now checking copy using assert functions" << endl;
    assert(copy.getHours() == t2.getHours());
    assert(copy.getMinutes() == t2.getMinutes());
    assert(copy.getSeconds() == t2.getSeconds());
    assert(copy.timeInHours() == t2.timeInHours());
    assert(copy.timeInMinutes() == t2.timeInMinutes());
    assert(copy.timeInSeconds() == t2.timeInSeconds());
    cout << "Passed assert test" << endl;
  }

  cout << endl << endl;
}
