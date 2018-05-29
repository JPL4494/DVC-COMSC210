/************************************
Lab 6c: Write Dynamic Array Class Template
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include<iostream>
#include<string>
using namespace std;

#include <cstdlib>

#include"DynamicArray.h"

int main()
{
  cout << "Lab 6c: Write Dynamic Array Class Template" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Array<float> a(1000);
  string buf = " ";
  int index = 0;

  while(buf != "Q" && buf != "q")
  {
    cout << "Enter a value to the array: ";
    getline(cin,buf);

    if(buf != "Q" && buf != "q")
    {
      a[index] = atof(buf.c_str());
      index++;
    }
  }

  cout << endl << "Number of data entered: " << index << endl;
  cout << endl << "Data unsorted are as follows: " << endl;
  for(int i = 0; i < index; i++)
  {
    cout << a[i] << " ";
    if(i % 9 == 0 && i != 0) cout << endl;
  }

  cout << endl << endl << endl;

  buf = " ";

  while(buf != "Q" && buf != "q")
  {
    cout << "Enter data to search for: ";
    getline(cin,buf);

    if(buf != "Q" && buf != "q")
    {
      float temp = atof(buf.c_str());

      if(a.lsearch(temp) != -1 && a.lsearch(temp) < index)
      {
        cout << "Data found to be in array at number " << (a.lsearch(atoi(buf.c_str())) + 1);
      }

      else cout << "Error: Data entered, " << buf << " not found";
    }

    cout << endl << endl;
  }

  cout << endl << endl;
}
