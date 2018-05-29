/************************************
Lab 10c: Perform Performance Confirmation On The ListedList Class Template
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include <iostream> /// for cout and endl
#include <string> /// for string
using namespace std;

#include <cassert> /// for assert
#include <cmath> /// for log and pow
#include <ctime> /// for clock() and clock_t
#include <cstdlib>

#include "LinkedList.h"

int main()
{
  cout << "Lab 10c: Perform Performance Confirmation On The ListedList Class Template" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
  /// problem setup goes here

  cout << "Assigning the first element" << endl;
  {
  /// programmer customizations go here
  int n = 1000; /// THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(1)"; /// YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS = 1000000; /// for timing fast operations, use REPS up to 100th of the starting n
  srand(time(0)); rand();

  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    /// more problem setup goes here -- the stuff not timed
    LinkedList<double> l;
    l.insert((double)rand());

    /// assert that n is the size of the data structure
    assert(l.getLength() == 1); /// or something like that...

    /// start the timer, do something, and stop the timer
    clock_t startTime = clock();
    for(int i = 0; i < REPS; i++)
    {
      l[0] = (double)2.1;
    }
    /// do something where n is the "size" of the problem
    clock_t endTime = clock();

    assert(l.isEmpty() == false);
    /// validation block -- assure that process worked

    /// compute timing results
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;

    /// reporting block
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  }

  cout << endl << "Assigning the 100 element" << endl;
  }

  {
  /// programmer customizations go here
  int n = 1000; /// THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(1)"; /// YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS = 1000000; /// for timing fast operations, use REPS up to 100th of the starting n
  srand(time(0)); rand();

  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    /// more problem setup goes here -- the stuff not timed
    LinkedList<double> l;
    for(int i = 0; i < 100; i++)l.insert((double)rand());

    /// assert that n is the size of the data structure
    assert(l.getLength() == 100); /// or something like that...

    /// start the timer, do something, and stop the timer
    clock_t startTime = clock();
    for(int i = 0; i < REPS; i++)
    {
      l[99] = (double)2.1;
    }
    /// do something where n is the "size" of the problem
    clock_t endTime = clock();

    assert(l.isEmpty() == false);
    /// validation block -- assure that process worked

    /// compute timing results
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;

    /// reporting block
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  }

  cout << endl << "Traversing the linked list" << endl;
  }

  {
  /// programmer customizations go here
  int n = 100000; /// THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(n)"; /// YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS = 1; /// for timing fast operations, use REPS up to 100th of the starting n
  srand(time(0)); rand();

  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    /// more problem setup goes here -- the stuff not timed
    LinkedList<double> l;
    for(int i = 0; i < n; i++)l.insert((double)rand());

    /// assert that n is the size of the data structure
    assert(l.getLength() == n); /// or something like that...

    /// start the timer, do something, and stop the timer
    clock_t startTime = clock();
    for(int i = 0; i < n; i++)
    {
      l[i];
    }
    /// do something where n is the "size" of the problem
    clock_t endTime = clock();

    assert(l.isEmpty() == false);
    /// validation block -- assure that process worked

    /// compute timing results
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;

    /// reporting block
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  }

  cout << endl << "Get length function" << endl;
  }

  {
  /// programmer customizations go here
  int n = 1000; /// THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(1)"; /// YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS = 200000; /// for timing fast operations, use REPS up to 100th of the starting n
  srand(time(0)); rand();

  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    /// more problem setup goes here -- the stuff not timed
    LinkedList<double> l;

    /// assert that n is the size of the data structure
    assert(l.isEmpty() == true); /// or something like that...

    /// start the timer, do something, and stop the timer
    clock_t startTime = clock();
    for(int i = 0; i < REPS; i++)
    {
      l.getLength();
    }
    /// do something where n is the "size" of the problem
    clock_t endTime = clock();

    assert(l.isEmpty() == true);
    /// validation block -- assure that process worked

    /// compute timing results
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;

    /// reporting block
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  }

  cout << endl << endl;
  }


  cout << endl << endl;
}
