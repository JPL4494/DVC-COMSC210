/************************************
LAB 8a: Write And Apply A Stack Template
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include <iostream>
#include <string>
using namespace std;

#include<cstdlib>

#include "Stack.h"

int main()
{
  cout << "LAB 8a: Write And Apply A Stack Template" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  string buf;
  Stack<float> s;
  float readIn;
  int count = 0;

  cout << "Enter: ";
  getline(cin,buf);

  while(buf[0] != 'Q' && buf[0] != 'q')
  {
    readIn = atof(buf.c_str());
    if(readIn != 0 || buf[0] == '0')
    {
      s.push(readIn);
      count++;
    }
    if(count >= 2)
    {
      if(buf[0] == '+' || buf[0] == '-' || buf[0] == '*' || buf[0] == '/')
      {
        float operand2 = s.topPop();

        if(operand2 == 0 && buf[0] == '/')
        {
          cout << "Error: Divide by zero" << endl;
          break;
        }

        float operand1 = s.topPop();

        count = count - 1;

        if(buf[0] == '+')
        {
          s.push((operand1+operand2));
        }
        else if(buf[0] == '-')
        {
          s.push((operand1-operand2));
        }
        else if(buf[0] == '*')
        {
          s.push((operand1*operand2));
        }
        else if(buf[0] == '/')
        {
          s.push((operand1/operand2));
        }
        else
        {
          cout << "No input!" << endl;
          break;
        }
      }
    }
    cout << "Enter: ";
    s.operator<<(cout);
    getline(cin,buf);
  }

  cout << endl << endl;
}
