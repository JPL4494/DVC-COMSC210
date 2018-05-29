/************************************
Lab 1a, Class Programming And Testing
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include <iostream>

using namespace std;

#include <cassert>

#include "Road.h"
#include "Road.h"

int main()
{
  cout << "Lab 1a, Class Programming And Testing" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << "Creating 2 road objects" << endl;

  Road r1, r2;

  cout << endl << "Setting the two road objects using member functions" << endl;
  r1.setWidth(15.5);
  r1.setLength(12.34);
  r2.setWidth(55.125);
  r2.setLength(452.32);

  cout << endl << "Getting set data members from road objects using member functions" << endl;
  cout << "Checking road object one, expected results: 15.5 and 12.34" << endl;
  cout << "Actual: " << r1.getWidth() << " and " << r1.getLength() << endl;

  cout << endl << "Checking road object two, expected results: 55.125 and 452.32" << endl;
  cout << "Actual: " << r2.getWidth() << " and " << r2.getLength() << endl;

  cout << endl << "Now checking asphalt function for road object one with thickness 2" << endl;
  cout << "Expected: 168318" << endl;
  cout << "Actual: " << r1.asphalt(2) << endl;

  cout << endl << "Now checking asphalt function for road object two with thickness 3.14" << endl;
  cout << "Expected: 264259" << endl;
  cout << "Actual: " << r1.asphalt(3.14) << endl;

  {
    cout << endl << "Copying using inline copy" << endl;
    Road copy = r1;
    cout << "Now checking copy using assert functions" << endl;
    assert(copy.getLength() == r1.getLength());
    assert(copy.getWidth() == r1.getWidth());
    assert(copy.asphalt(2) == r1.asphalt(2));
    cout << "Passed assert test" << endl;
  }

  {
    cout << endl << "Copying using after declaration copy" << endl;
    Road copy;
    copy = r2;
    cout << "Now checking copy using assert functions" << endl;
    assert(copy.getLength() == r2.getLength());
    assert(copy.getWidth() == r2.getWidth());
    assert(copy.asphalt(0.13) == r2.asphalt(0.13));
    cout << "Passed assert test" << endl;
  }

  cout << endl << endl;
}
