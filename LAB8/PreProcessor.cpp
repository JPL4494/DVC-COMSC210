/************************************
LAB 8c: Use A Stack
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include<iostream>
#include<stack>
#include<fstream>
using namespace std;

#include<cstdlib>
#include<cstring>

struct Symbols
{
  char data;
  int line;
};

int main()
{
  cout << "LAB 8c: Use A Stack" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  string input;
  bool error = false;
  bool didPop = true;
  char buf[1000];
  stack<Symbols> track;
  int lineNumber = 1;

  cout << "Enter filename (H, CPP, JAVA, HTML, or JS): ";
  getline(cin,input);

  fstream source;
  source.open(input.c_str(), ios::in);

  if (source.fail())
  {
    cout << "ERROR-No file to get information from!" << endl << endl;
    exit(EXIT_FAILURE);
  }

  cout << endl;

  while(source.good() && error == false)
  {
    string line;
    getline(source, line);

    for(int i = 0; i < line.length(); i++)
    {
      if(!track.empty() && track.top().data == '(')
      {
        if(line[i] == ')')
        {
          track.pop();
          didPop = true;
        }
      }
      if(!track.empty() && track.top().data == '{')
      {
        if(line[i] == '}')
        {
          track.pop();
          didPop = true;
        }
      }
      if(!track.empty() && track.top().data == '[')
      {
        if(line[i] == ']')
        {
          track.pop();
          didPop = true;
        }
      }
      if(!track.empty() && track.top().data == '*')
      {
        if(line[i] == '*' && line[i+1] == '/')
        {
          track.pop();
          didPop = true;
        }
      }

      if(track.empty() && !didPop)
      {
        if(line[i] == ')')
        {
          cout << "Closing parentheses found, but no opening. Error on line " << lineNumber << endl;
          error = true;
        }
        else if(line[i] == '}')
        {
          cout << "Closing curly brace found, but no opening. Error on line " << lineNumber << endl;
          error = true;
        }
        else if(line[i] == ']')
        {
          cout << "Closing square found, but no opening. Error on line " << lineNumber << endl;
          error = true;
        }
        else if(line[i] == '*' && line[i+1] == '/')
        {
          cout << "Ending comment offset found, but no staring. Error on line " << lineNumber << endl;
          error = true;
        }
      }

      if(!track.empty() && !didPop)
      {
        if(line[i] == ')')
        {
          if(track.top().data != '(')
          {
            cout << "Closing parentheses found, but no opening. Error on line " << lineNumber << endl;
            error = true;
          }
        }
        else if(line[i] == '}')
        {
          if(track.top().data != '{')
          {
            cout << "Closing curly brace found, but no opening. Error on line " << lineNumber << endl;
            error = true;
          }
        }
        else if(line[i] == ']')
        {
          if(track.top().data != ']')
          {
            cout << "Closing square found, but no opening. Error on line " << lineNumber << endl;
            error = true;
          }
        }
        else if(line[i] == '*' && line[i+1] == '/')
        {
          if(track.top().data != '*')
          {
            cout << "Ending comment offset found, but no staring. Error on line " << lineNumber << endl;
            error = true;
          }
        }
      }

      if(line[i] == '(')
      {
        Symbols temp;
        temp.data = '(';
        temp.line = lineNumber;
        track.push(temp);
      }
      if(line[i] == '{')
      {
        Symbols temp;
        temp.data = '{';
        temp.line = lineNumber;
        track.push(temp);
      }
      if(line[i] == '[')
      {
        Symbols temp;
        temp.data = '[';
        temp.line = lineNumber;
        track.push(temp);
      }
      if(line[i] == '/' && line[i+1] == '*')
      {
        Symbols temp;
        temp.data = '*';
        temp.line = lineNumber;
        track.push(temp);
      }
      didPop = false;
    }

    lineNumber++;
  }

  source.close();

  if(!track.empty() && !error)
  {
    cout << "ERROR: Mismatching operators found!" << endl;
    if(track.top().data == '(')
    {
      cout << "No closing parentheses found for the opening one on line " << track.top().line << endl;
    }
    if(track.top().data == '{')
    {
      cout << "No closing curly brace found for the opening one on line " << track.top().line << endl;
    }
    if(track.top().data == '[')
    {
      cout << "No closing square bracket found for the opening one on line " << track.top().line << endl;
    }
    if(track.top().data == '*')
    {
      cout << "No ending comment offset found for the opening one on line " << track.top().line << endl;
    }
  }

  if(track.empty() && !error)
  {
    cout << "No mismatches found by my preprocessor in " << input << endl;
  }

  cout << endl << endl;
}
