/************************************
Lab 5b: Applying A Data Structure To A Database Program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#include<cstdlib>
#include<cstring>
#include<ctime>

#include "StaticArray.h"

struct SubjectCode
{
  string name;
  int count;
};

struct Check
{
  string section;
  string term;
  string subject;
};

int main()
{
  cout << "Lab 5b: Applying A Data Structure To A Database Program" << endl;
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

  Array<SubjectCode, 200> dataBase;
  Array<Check, 90000> doubleCheck;

  char* token;
  char buf[1000];
  const char* const tab = "\t";

  int counter, numOfSubjects, numOfDoubles;
  counter = 0;
  numOfSubjects = 0;
  numOfDoubles = 0;
  int doubleIndex[9000];
  int check = 0;

  clock_t startTime = clock();

  cout << "Scanning in file" << endl;
  cout << "Progress:" << endl;
  while (source.good())
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

    doubleCheck[counter].section = section;
    doubleCheck[counter].term = term;
    doubleCheck[counter].subject = subjectCode;

    counter++;
    int percent = ((counter / 64258.) * 100);
    if(percent != check)
    {
      cout << percent << " ";
      check = percent;
      if(percent % 10 == 0)cout << endl;
    }
  }
  source.close();

  check = 0;

  cout << endl;
  cout << "Checking for doubles" << endl;
  cout << "Progress:" << endl;

  for(int i = 0; i < counter; i++)
  {
    for(int j = i + 1; j < counter; j++)
    {
      if(doubleCheck[i].section == doubleCheck[j].section && doubleCheck[i].term == doubleCheck[j].term)
      {
        doubleIndex[numOfDoubles] = j;
        numOfDoubles++;
      }
    }
    int percent = ((i / 64258.) * 100);
      if(percent != check)
      {
        cout << percent << " ";
        check = percent;
        if(percent % 10 == 0)cout << endl;
      }
  }
  cout << endl << endl;
  cout << "Number of double classes: " << numOfDoubles << endl;

  bool doubleFound = false;

  for(int i = 0; i < counter; i++)
  {
    for(int j = 0; j < numOfDoubles; j++)
    {
      if(i == doubleIndex[j])
      {
        doubleFound = true;
      }
    }
    if(!doubleFound)
    {
        const string subjectCode = doubleCheck[i].subject;
        if(i == 0)
        {
          SubjectCode temp;
          temp.name = subjectCode;
          temp.count = 1;
          dataBase[i] =  temp;
          numOfSubjects++;
        }

        bool hit = false;

        for(int i = 0; i < numOfSubjects; i++)
        {
          if(dataBase[i].name == subjectCode)
          {
            dataBase[i].count++;
            hit = true;
          }
        }
        if(!hit)
        {
          SubjectCode temp;
          temp.name = subjectCode;
          temp.count = 1;
          dataBase[numOfSubjects] = temp;
          numOfSubjects++;
        }
      }
      doubleFound = false;
  }

  for(int i = 0; i < numOfSubjects; i++)
  {
    for(int j = i+1; j < numOfSubjects; j++)
    {
      if(dataBase[i].name > dataBase[j].name)
      {
        SubjectCode temp = dataBase[i];
        dataBase[i] = dataBase[j];
        dataBase[j] = temp;
      }
    }
  }

  cout << endl;
  cout << "Organized class list with number of classes below:" << endl;

  for(int i = 0; i < numOfSubjects; i++)
  {
    cout << dataBase[i].name << " " << dataBase[i].count << endl;
  }

  double elapsedTime = (double)(clock() - startTime) / CLOCKS_PER_SEC;

  cout << "Time to process file: " << elapsedTime << endl;
  cout << endl << endl;
}
