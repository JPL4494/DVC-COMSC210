/************************************
LAB 11a: Write And Test The HashTable Class Template
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#include <cstdlib>
#include <cstring>
#include <cassert>

#include "HashTable.h"
#include "HashTable.h"

struct Code
{
  string course;
  string term;
  string section;
  string instructor;

  int size()const;
  bool operator==(const Code);
  int hashCode()const;
};

int Code::size()const
{
  int result = 0;
  result+= course.size();
  result+= term.size();
  result+= section.size();

  return result;
}

bool Code::operator==(const Code check)
{
  bool result = true;

  if(check.course != course)result = false;
  if(check.term != term)result = false;
  if(check.section != section)result = false;

  return result;
}

int Code::hashCode()const
{
  int result = 0;
  for(int i = 0; i < course.size(); i++)result+= course[i];
  for(int i = 0; i < term.size(); i++)result+= term[i];
  for(int i = 0; i < section.size(); i++)result+= section[i];
  return result;
}

int main()
{
  cout << "LAB 11a: Write And Test The HashTable Class Template" << endl;
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

  cout << "Creating a hashed table of size 1009" << endl;
  HashTable<Code, 1009> h;
  cout << "Checking that the table is empty" << endl;
  assert(h.size() == 0);
  cout << "Passed assert test, size is 0" << endl;

  char* token;
  char buf[1000];
  const char* const tab = "\t";

  cout << endl;
  cout << "Now reading from DVC schedule file for 800 lines" << endl;
  int count = 0;
  while(count < 800)
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

    Code temp;
    temp.course = course;
    temp.section = section;
    temp.instructor = instructor;
    temp.term = term;

    h.insert(temp);

    count++;
  }

  cout << endl;
  cout << "Checking that the table is not empty" << endl;
  assert(h.size() > 0);
  cout << "Passed assert test, table not empty" << endl;

  {
    cout << endl;
    cout << "Testing upon declaration copy" << endl;
    HashTable<Code, 1009> copy = h;
    cout << "Testing the copy against the original" << endl;
    Code temp1, temp2;
    assert(copy.size() == h.size());
    assert(copy.first(temp1) == h.first(temp2));
    for(int i = 0; i < copy.size(); i++)
    {
      assert(copy.getNext(temp1) == h.getNext(temp2));
      assert(temp1 == temp2);
    }
    cout << "Passed assert test" << endl;
  }

  {
    cout << endl;
    cout << "Testing after declaration copy" << endl;
    HashTable<Code, 1009> copy;
    copy = h;
    cout << "Testing the copy against the original" << endl;
    Code temp1, temp2;
    assert(copy.size() == h.size());
    assert(copy.first(temp1) == h.first(temp2));
    for(int i = 0; i < copy.size(); i++)
    {
      assert(copy.getNext(temp1) == h.getNext(temp2));
      assert(temp1 == temp2);
    }
    cout << "Passed assert test" << endl;
  }



  cout << endl;
  cout << "Running through text file again to delete the same classes" << endl;
  count = 0;
  source.clear();
  source.seekg(0, ios::beg);
  while(count < 800)
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

    Code temp;
    temp.course = course;
    temp.section = section;
    temp.instructor = instructor;
    temp.term = term;

    if(h.retrieve(temp))h.remove(temp);
    count++;
  }
  source.close();

  cout << endl;
  cout << "Checking that the table is empty" << endl;
  assert(h.size() == 0);
  cout << "Passed assert test, table is empty" << endl;

  cout << endl << endl;
}
