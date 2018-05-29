/************************************
Term Project: Part 2
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

int main()
{
  cout << "Term Project: Part 2" << endl;
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

  map<string, string> check;
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  int counter = 1;

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

    if(check.size() == 0)check[section] = term;
    else
    {
      map<string, string>::iterator it = check.find(section);
      if(it != check.end())
        if(it->second == term)
        {
          cout << "Conflicting courses found on line: " << counter << endl;
          cout << "Course: " << term << ' ' << section << ' ' << course << ' ' << whenWhere << endl << endl;
        }
      if(it == check.end()) check[section] = term;
    }
    counter++;
  }

  cout << endl << endl;
}
