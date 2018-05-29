/************************************
Term Project: Part 1
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include<iostream>
#include<string>
#include<map>
#include<fstream>
using namespace std;

#include<cstdlib>
#include<cstring>
#include<ctime>

int main()
{
  cout << "Term Project: Part 1" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  fstream source;
  source.open("dvc-schedule.txt", ios::in);
  if (source.fail())
  {
    cout << "ERROR-No file to get information from!";
    exit(EXIT_FAILURE);
  }

  map<const string, map<const string, int> > outerMap;
  map<string, pair<string, string> > check;
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  clock_t startTime = clock();

  while (source.good())
  {
    string line;
    getline(source, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue;
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; /// invalid line
    const string subjectCode(course.begin(), course.begin() + course.find('-'));

    if(check.size() == 0)
    {
      check[term] = make_pair(section,course);
      outerMap[subjectCode][course]++;
    }
    map<string, pair<string, string> >::iterator it = check.find(term);
    if(it == check.end())
    {
      check[term] = make_pair(section,course);
      outerMap[subjectCode][course]++;
    }
    else
    {
      if(it->second.first != section)
        if(it->second.second != course)
        {
          check[term] = make_pair(section,course);
          outerMap[subjectCode][course]++;
        }
    }
  }
  double elapsedTime = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  cout << "Time to process file: " << elapsedTime << endl;
  for(map<string, map<const string, int> >::iterator it = outerMap.begin(); it != outerMap.end(); it++)
  {
    cout << it->first << endl;
    for(map<const string, int>::iterator itInner = it->second.begin(); itInner != it->second.end(); itInner++)
      cout << "  " << itInner->first << ' ' << itInner->second << endl;
  }
}
