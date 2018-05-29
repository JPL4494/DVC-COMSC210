/************************************
LAB 7b: Applying Advanced Linked-List Techniques
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

#include<cstdlib>
#include<cstring>
#include<ctime>

struct SubjectCode
{
  string name;
  int count;
};

struct Node
{
  SubjectCode data;
  Node* next;
};

struct Check
{
  string section;
  string term;
  string subject;
};

int main()
{
  cout << "LAB 7b: Applying Advanced Linked-List Techniques" << endl;
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

  Check doubleCheck[70000];

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
  source.close();

  check = 0;

  int doubleIndex[1000];

  Node* start = 0;
  Node* p;
  Node* prev;

  cout << endl;
  cout << "Checking for doubles" << endl;
  cout << "Progress:" << endl;

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
  cout << endl << "Now populating list" << endl;
  cout << "Progress:" << endl;

  bool isDouble = false;
  for(int i = 0; i < counter; i++)
  {
    isDouble = false;
    for(int j = 0; j < numOfDoubles; j++)
    {
      if(i == doubleIndex[j])isDouble = true;
    }

    if(!isDouble)
    {
      if(i == 0)
      {
        Node* node = new Node;
        node -> data.name = doubleCheck[i].subject;
        node -> data.count = 1;
        node -> next = start;
        start = node;
      }

      else
      {
        bool hit = false;
        for(prev = 0, p = start; p; prev = p, p = p->next)
        {
          if(p -> data.name == doubleCheck[i].subject)
          {
            p -> data.count++;
            hit = true;
          }
        }
        if(!hit)
        {
          string temp = doubleCheck[i].subject;
          for (prev = 0, p = start; p; prev = p, p = p->next)
          {
            if (p->data.name > temp)break;
          }

          // insert node here
          Node* node = new Node;
          node->data.name = temp;
          node->data.count = 1;
          node->next = p;
          if (prev) prev->next = node;
          else start = node;
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

  cout << endl << endl << "Number of double classes: " << numOfDoubles << endl << endl;
  cout << "Class list are as follows: " << endl;

  for(p = start; p; p = p->next)
  {
    cout << p -> data.name << " " << p -> data.count << " class(es)" << endl;
  }

  while (start)
  {
    p = start -> next;
    delete start;
    start = p;
  }

  double elapsedTime = (double)(clock() - startTime) / CLOCKS_PER_SEC;

  cout << "Time to process file: " << elapsedTime << endl;

  cout << endl << endl;
}
