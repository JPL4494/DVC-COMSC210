/************************************
Term Project: Part 3
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
  cout << "Term Project: Part 3" << endl;
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

  map<string, string> outerMap;
  map<string, pair<string, string> > check;
  char* token;
  char buf[1000];
  const char* const tab = "\t";

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

    ///READ IN AS FOLLOWS
    ///TERM           SECTION    COURSE    INSTRUCTOR         WHENWHERE                 SUBJECTCODE
    ///Spring 2005	   1022  	  MATH-110	   Abadia	    MTWTHF 9:00-9:50am MA-240           MATH

    if(outerMap.size() == 0)
      outerMap[course] = term;
    else
    {
      map<string, string>::iterator it = outerMap.find(course);
      if(it == outerMap.end())
        outerMap[course] = term;
      else
      {
        size_t pos1 = it->second.find(' ');
        size_t pos2 = term.find(' ');
        string oldTerm = it->second.substr(pos1);
        string newTerm = term.substr(pos2);
        if(oldTerm < newTerm)
          it->second = term;
        else if(it->second[0] == term[0])
        {
          if(it->second[1] < term[1])
            it->second = term;
        }
        else if(it->second[0] > term[0])
          it->second = term;
      }
    }
  }

  string buff = " ";
  while(buff[0] != 'x' && buff[0] != 'X')
  {
    cout << "Enter a class to search for(ex:COMSC-210): ";
    getline(cin,buff);
    if(buff[0] == 'x' || buff[0] == 'X')break;

    map<string, string>::iterator it = outerMap.find(buff);
    if(it == outerMap.end())
    {
      cout << "Class entered, " << buff << ", was not found in the database" << endl;
      cout << "If the class was offered at one time at DVC, it has not been offered since 2000" << endl;
    }
    else
    {
      cout << "Class enetered, " << buff << ", has last been offered at DVC in the term " << it->second << endl;
    }
    cout << endl << "Enter x or X to exit" << endl;
    buff = " ";
  }
}
