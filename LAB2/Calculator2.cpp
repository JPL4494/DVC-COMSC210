/************************************
Lab 2c, Using Templated Classes
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

#include<cstdlib>

int main()
{
  cout << "Lab 2c, Using Templated Classes" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  string buf;
  stack<float> s;
  float readIn;

  cout << "Enter: ";
  getline(cin,buf);

  while(buf[0] != 'Q' && buf[0] != 'q')
  {
    readIn = atof(buf.c_str());
    if(readIn != 0 || buf[0] == '0')
    {
      s.push(readIn);
    }
    if(s.size() >= 2)
    {
      if(buf[0] == '+' || buf[0] == '-' || buf[0] == '*' || buf[0] == '/')
      {
        float operand2 = s.top();
        s.pop();

        if(operand2 == 0 && buf[0] == '/')
        {
          cout << "Error: Divide by zero" << endl;
          break;
        }

        float operand1 = s.top();
        s.pop();

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
    for(stack<float> copy = s; !copy.empty(); copy.pop())
    {
      cout << copy.top() << " ";
    }
    getline(cin,buf);
  }

  cout << endl << endl;
}
