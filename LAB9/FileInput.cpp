/************************************
LAB 9a: Perform A Simple Timing Study
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include <iostream> /// for cout and endl
#include <string> /// for string
#include<fstream>
using namespace std;

#include <cassert> /// for assert
#include <cmath> /// for log and pow
#include <ctime> /// for clock() and clock_t
#include<cstdlib>
#include<cstring>

int main()
{
  cout << "LAB 9a: Perform A Simple Timing Study" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
  /// problem setup goes here

  /// programmer customizations go here
  int n = 5000; /// THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(n)"; /// YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS = 1; /// for timing fast operations, use REPS up to 100th of the starting n

  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    fstream source;
    int counter = 0;
    char* token;
    char buf[1000];
    const char* const tab = "\t";

    source.open("dvc-schedule.txt", ios::in);
    if (source.fail())
    {
      cout << "ERROR-No file to get information from!";
      exit(EXIT_FAILURE);
    }

    /// more problem setup goes here -- the stuff not timed

    /// assert that n is the size of the data structure
    ///assert(a.size() == n); /// or something like that...

    /// start the timer, do something, and stop the timer
    clock_t startTime = clock();
    while (counter != n)
    {
      /// read the line
      string line;
      getline(source, line);
      strcpy(buf, line.c_str());
      if (buf[0] == 0) continue;

      /// parse the line
      const string term(token = strtok(buf, tab));
      const string section(token = strtok(0, tab));
      const string course((token = strtok(0, tab)) ? token : "");
      const string instructor((token = strtok(0, tab)) ? token : "");
      const string whenWhere((token = strtok(0, tab)) ? token : "");
      if (course.find('-') == string::npos) continue; /// invalid line
      const string subjectCode(course.begin(), course.begin() + course.find('-'));

      counter++;
    }
    /// do something where n is the "size" of the problem
    clock_t endTime = clock();

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
    source.close();
  }
  cout << endl << endl;
}
