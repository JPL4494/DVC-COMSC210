/************************************
Lab 4b, Introduction To Dynamic Array Doubling And Deallocation
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include<iostream>
#include<string>

using namespace std;

#include <cstdlib>

#include "Checkbook.h"

int main()
{
  cout << "Lab 4b, Introduction To Dynamic Array Doubling And Deallocation" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Checkbook<float> c;
  string buf = "1";
  int check;
  float amount;

  while(buf != "5")
  {
    cout << "1: Deposit check" << endl;
    cout << "2: Write check" << endl;
    cout << "3: Get checking balance" << endl;
    cout << "4: Get checking history" << endl;
    cout << "5: Quit" << endl;

    cout << "Enter option, 1-5: ";
    getline(cin,buf);
    check = atof(buf.c_str());

    switch(check)
    {
    case 1:
      cout << "Deposit checks:" << endl;
      cout << "Enter check amount to deposit: " << endl;
      getline(cin,buf);
      amount = atof(buf.c_str());

      buf = " ";

      c.makeDeposit(amount);
      break;
    case 2:
      cout << "Write check:" << endl;
      cout << "Enter the amount for check: " << endl;
      getline(cin,buf);
      amount = atof(buf.c_str());

      buf = " ";

      c.writeCheck(amount);
      break;
    case 3:
      cout << "Get checking balance:" << endl;
      cout << "Total amount in account: " << c.getBalance() << endl;

      cout << endl << "Hit enter to continue" << endl;
      cin.ignore();
      break;
    case 4:
      cout << "Get checking history" << endl << endl;

      float* history = c.getChecks();

      for(int i = 0; i < c.getSize(); i++)
      {
        if(history[i] > 0)cout << "Deposit: ";
        else cout << "Withdrawl: ";

        cout << history[i] << endl;
      }

      cout << endl << "Hit enter to continue" << endl;
      cin.ignore();

      delete[] history;
      break;
    }

    cout << endl << endl << endl;
  }

  cout << endl << endl;
}
