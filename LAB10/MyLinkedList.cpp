/************************************
Lab 10b: Write And Test The ListedList Class Template
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include<iostream>
#include<string>
using namespace std;

#include <cstdlib>

#include "LinkedList.h"

int main()
{
  cout << "Lab 10b: Write And Test The ListedList Class Template" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  LinkedList<float> l;
  string buf = " ";
  int index = -1;

  while(buf != "Q" && buf != "q")
  {
    cout << "Enter a number to be entered into the linked list: ";
    getline(cin,buf);
    if(buf != "Q" && buf != "q")
    {
      index++;
      l.insert(atof(buf.c_str()));
    }

    cout << endl;
  }

  cout << endl;

  cout << "Total numbers entered: " << (index+1) << endl << endl;

  cout << "Now printing stored values..." << endl;
  for(int i = 0; i <= index; i++)
  {
    cout << l[i] << " ";
    if(i % 9 == 0 && i != 0)cout << endl;
  }

  cout << endl << endl;
  buf = " ";

  while(buf != "Q" && buf != "q")
  {
    cout << "Enter a value to search for: ";
    getline(cin,buf);

    if(buf != "Q" && buf != "q")
    {
      float temp = atof(buf.c_str());
      if(l.find(temp))
      {
        cout << "Data found to be in the linked list";
      }

      else cout << "Error: Data entered, " << buf << " not found";
    }
    cout << endl << endl;
  }

  cout << endl << endl;
}
