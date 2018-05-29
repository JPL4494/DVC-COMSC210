/************************************
Lab 6b: Using A Data Structure As A Data Member
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include<iostream>
#include<fstream>
#include<string>
#include<deque>
using namespace std;

#include<cstdlib>
#include<cstring>
#include<ctime>

struct Course
{
  string name;
  int count;
};

struct SubjectCode
{
  string name;
  deque<Course> course;
};

struct Check
{
  string section;
  string term;
  string subject;
  string course;
};

int main()
{
  cout << "6b: Using A Data Structure As A Data Member" << endl;
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

  deque<SubjectCode> dataBase;
  Check doubleCheck[100000];
  int counter = 0;
  int numOfDoubles = 0;
  int check = 0;
  int doubleIndex[1000];

  char* token;
  char buf[1000];
  const char* const tab = "\t";

  clock_t startTime = clock();

  cout << "Checking database and populating classes" << endl;
  cout << "Progress: " << endl;

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

    Check ctemp;
    ctemp.section = section;
    ctemp.term = term;
    ctemp.subject = subjectCode;
    ctemp.course = course;
    doubleCheck[counter] = ctemp;

    counter++;
    int percent = ((counter / 64258.) * 100);
    if(percent != check)
    {
      cout << percent << " ";
      check = percent;
      if(percent % 10 == 0)cout << endl;
    }
  }

  check = 0;
  cout << endl << "Checking for doubles" << endl;
  cout << "Progress: " << endl;
  for(int i = 0; i < counter; i++)
  {
    for(int j = i+1; j < counter; j++)
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

  check = 0;
  cout << endl << endl << "Now adding classes" << endl;
  cout << "Progress: " << endl;
  bool isDouble;
  bool hit;
  for(int i = 0; i < counter; i++)
  {
    isDouble = false;
    hit = false;
    for(int j = 0; j < numOfDoubles; j++)
    {
      if(i == doubleIndex[j])isDouble = true;
    }
    if(!isDouble)
    {
      if(i == 0)
      {
        SubjectCode temp;
        temp.name = doubleCheck[i].subject;
        Course temp2;
        temp2.name = doubleCheck[i].course;
        temp2.count = 1;
        temp.course.push_back(temp2);
        dataBase.push_back(temp);
      }
      else
      {
        int total = dataBase.size();
        for(int k = 0; k < total; k++)
        {
          if(dataBase[k].name == doubleCheck[i].subject)
          {
            hit = true;
            int totalCourse = dataBase[k].course.size();
            bool sameCourse = false;
            for(int l = 0; l < totalCourse; l++)
            {
              if(dataBase[k].course[l].name == doubleCheck[i].course)
              {
                dataBase[k].course[l].count++;
                sameCourse = true;
              }
            }
            if(!sameCourse)
            {
              Course temp;
              temp.name = doubleCheck[i].course;
              temp.count = 1;
              dataBase[k].course.push_back(temp);

            }
          }
        }
        if(!hit)
        {
          SubjectCode temp;
          temp.name = doubleCheck[i].subject;
          Course temp2;
          temp2.name = doubleCheck[i].course;
          temp2.count = 1;
          temp.course.push_back(temp2);
          dataBase.push_back(temp);
        }
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

  check = 0;
  cout << endl << endl << "Done, now organizing list" << endl;
  int total = dataBase.size();
  for(int i = 0; i < total; i++)
  {
    for(int j = i+1; j < total; j++)
    {
      if(dataBase[i].name > dataBase[j].name)
      {
        SubjectCode temp = dataBase[i];
        dataBase[i] = dataBase[j];
        dataBase[j] = temp;
      }
    }
  }
  for(int i = 0; i < total; i++)
  {
    int total2 = dataBase[i].course.size();
    for(int j = 0; j < total2; j++)
    {
      for(int k = j+1; k < total2; k++)
      {
        if(dataBase[i].course[j].name > dataBase[i].course[k].name)
        {
          Course temp = dataBase[i].course[j];
          dataBase[i].course[j] = dataBase[i].course[k];
          dataBase[i].course[k] = temp;
        }
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

  cout << endl << "Number of double classes: " << numOfDoubles;
  cout << endl << "Classes are as follows:" << endl;
  for(int i = 0; i < total; i++)
  {
    int total2 = dataBase[i].course.size();
    cout << dataBase[i].name << " number of classes: " << total2 << endl;
    for(int j = 0; j < total2; j++)
    {
      cout << "  " << dataBase[i].course[j].name << " - "  << dataBase[i].course[j].count << " class(es)" << endl;
    }
    cout << endl;
  }

  double elapsedTime = (double)(clock() - startTime) / CLOCKS_PER_SEC;

  cout << "Time to process file: " << elapsedTime << endl;
  cout << endl << endl;
}
