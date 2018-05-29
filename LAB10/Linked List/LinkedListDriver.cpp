/************************************
LAB 10a: Write And Test The ListedList Class Template
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include<iostream>
using namespace std;

#include <cassert>

#include "LinkedList.h"
#include "LinkedList.h"

int main()
{
  cout << "LAB 10a: Write And Test The ListedList Class Template" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << "Creating a linked list object" << endl;
  LinkedList<int> l;
  cout << "List created" << endl;

  cout << endl;
  cout << "Checking that the list is not empty" << endl;
  assert(l.isEmpty() == true);
  cout << "List is empty" << endl;

  cout << endl;
  cout << "Inserting 3 ints into the list" << endl;
  l.insert(0); l.insert(1); l.insert(2);
  cout << "Checking that the list is not empty" << endl;
  assert(l.isEmpty() == false);
  cout << "List is not empty, list has " << l.getLength() << " ints in it" << endl;

  int check;
  cout << endl;
  cout << "Checking first number in the list is 2" << endl;
  assert(l.first(check) == true);
  assert(check == 2);
  cout << "Passed assert test" << endl;

  cout << endl;
  cout << "Checking second number in the list is 1" << endl;
  assert(l.getNext(check) == true);
  assert(check == 1);
  cout << "Passed assert test" << endl;

  cout << endl;
  cout << "Checking last number in the list is 0" << endl;
  assert(l.getNext(check) == true);
  assert(check == 0);
  cout << "Passed assert test" << endl;

  cout << endl;
  cout << "Checking find function with the number 1" << endl;
  assert(l.find(1) == true);
  cout << "Passed assert test" << endl;

  cout << endl;
  cout << "Checking find function with the number 6" << endl;
  assert(l.find(6) == false);
  cout << "Passed assert test" << endl;

  cout << endl;
  cout << "Checking retrieve function with the number 2" << endl;
  check = 2;
  assert(l.retrieve(check) == true);
  cout << "Passed assert test" << endl;

  cout << endl;
  cout << "Checking replace function with the number 10" << endl;
  check = 10;
  assert(l.replace(check) == true);
  check = 0;
  assert(l.first(check) == true);
  assert(check == 10);
  cout << "Passed assert test" << endl;

  cout << endl;
  cout << "Checking remove function with the number 10" << endl;
  check = 10;
  assert(l.remove(check) == true);
  assert(l.first(check) == true);
  assert(check == 1);
  cout << "Passed assert test" << endl;

  cout << endl;
  cout << "Adding numbers to check the operator[] function" << endl;
  l.insert(2); l.insert(4); l.insert(6); l.insert(8);
  for(int i = 0; i < l.getLength(); i++)cout << l[i] << " ";
  cout << endl;

  {
    cout << endl << "Copying using inline copy" << endl;
    int copyCheck;
    LinkedList<int> copy = l;
    assert(copy.first(copyCheck) == l.first(check));
    assert(copyCheck == check);
    assert(copy.getNext(copyCheck) == l.getNext(check));
    assert(copyCheck == check);
    assert(copy.getNext(copyCheck) == l.getNext(check));
    assert(copyCheck == check);
    assert(copy.getNext(copyCheck) == l.getNext(check));
    assert(copyCheck == check);
    assert(copy.getNext(copyCheck) == l.getNext(check));
    assert(copyCheck == check);
    cout << "Passed assert tests" << endl;
  }

  {
    cout << endl << "Copying using after declaration copy" << endl;
    int copyCheck;
    LinkedList<int> copy;
    copy = l;
    assert(copy.first(copyCheck) == l.first(check));
    assert(copyCheck == check);
    assert(copy.getNext(copyCheck) == l.getNext(check));
    assert(copyCheck == check);
    assert(copy.getNext(copyCheck) == l.getNext(check));
    assert(copyCheck == check);
    assert(copy.getNext(copyCheck) == l.getNext(check));
    assert(copyCheck == check);
    assert(copy.getNext(copyCheck) == l.getNext(check));
    assert(copyCheck == check);
    cout << "Passed assert tests" << endl;
  }

  cout << endl;
  cout << "Checking make empty function" << endl;
  l.makeEmpty();
  assert(l.isEmpty() == true);
  cout << "Passed assert test" << endl;

  cout << endl << endl;
}
