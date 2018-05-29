/************************************
Lab 6a: Applying The STL deque
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
  cout << "Lab 6a: Applying The STL deque" << endl;
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
  deque<Check> doubleCheck;

  char* token;
  char buf[1000];
  const char* const tab = "\t";

  int check = 0;
  int counter = 0;
  int numOfDoubles = 0;

  clock_t startTime = clock();

  cout << "Populating database" << endl;
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
    doubleCheck.push_back(ctemp);

    int total = doubleCheck.size();
    bool doubleFound = false;

    for(int i = 0; i < total; i++)
    {
      for(int j = i + 1; j < total; j++)
      {
        if(doubleCheck[i].section == doubleCheck[j].section && doubleCheck[i].term == doubleCheck[j].term)
        {
          doubleFound = true;
          numOfDoubles++;
        }
      }
    }
    if(!doubleFound)
    {
      if(counter == 0)
      {
        SubjectCode temp;
        temp.name = doubleCheck[0].subject;
        temp.count = 1;
        dataBase.push_back(temp);
      }

      bool hit = false;
      int total2 = dataBase.size();

      for(int k = 0; k < total2; k++)
      {
        if(dataBase[k].name == subjectCode)
        {
          dataBase[k].count++;
          hit = true;
        }
      }
      if(!hit)
      {
        SubjectCode temp;
        temp.name = subjectCode;
        temp.count = 1;
        dataBase.push_back(temp);
      }
    }

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


  cout << endl << "Done, now organizing list" << endl;

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

  cout << "Number of double classes found: " << numOfDoubles << endl << endl;

  cout << "Classes are as follows: " << endl;
  for(int i = 0; i < total; i++)
  {
    cout << dataBase[i].name << " " << dataBase[i].count << endl;
  }

  double elapsedTime = (double)(clock() - startTime) / CLOCKS_PER_SEC;

  cout << "Time to process file: " << elapsedTime << endl;
  cout << endl << endl;
}
