/************************************
LAB 9c: Perform A Timing Study On The STL Array Sort Function
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include <iostream> /// for cout and endl
#include <string> /// for string
#include <vector>
#include <algorithm>
using namespace std;

#include <cassert> /// for assert
#include <cmath> /// for log and pow
#include <ctime> /// for clock() and clock_t
#include <cstdlib>

int main()
{
  cout << "LAB 9c: Perform A Timing Study On The STL Array Sort Function" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
  /// problem setup goes here

  /// programmer customizations go here
  int n = 20000; /// THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(n log n)"; /// YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS = 1; /// for timing fast operations, use REPS up to 100th of the starting n
  srand(time(0)); rand();

  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    /// more problem setup goes here -- the stuff not timed
    double a[n];
    int total = n;
    for(int i = 0; i < total; i++) a[i] = (double)rand();

    /// assert that n is the size of the data structure
    assert(total == n); /// or something like that...

    /// start the timer, do something, and stop the timer
    clock_t startTime = clock();
    sort(a, a + n);
    /// do something where n is the "size" of the problem
    clock_t endTime = clock();

    for (int i = 1; i < n; i++) assert (a[i - 1] <= a[i]);
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
} }
