/************************************
LAB 12a: Write And Test A Priority Queue Template
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include<iostream>
using namespace std;

#include <cassert>

#include "PriorityQueue.h"
#include "PriorityQueue.h"

int main()
{
  cout << "LAB 12a: Write And Test A Priority Queue Template" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;


  cout << "Creating priority queue object" << endl;
  PriorityQueue<int> pq;

  cout << endl << "Filling object with 10 numbers" << endl;
  pq.enqueue(-10); pq.enqueue(10); pq.enqueue(-1); pq.enqueue(34); pq.enqueue(-2);
  pq.enqueue(-100); pq.enqueue(0); pq.enqueue(-1001); pq.enqueue(-1); pq.enqueue(13);
  cout << "Checking that there are now ten numbers in queue" << endl;
  assert(pq.getSize() == 10);
  cout << "Passed assert test, 10 numbers in queue AND getSize function works" << endl;

  cout << endl << "Checking dequeue function by removing 3 numbers" << endl;
  assert(pq.dequeue() == 34);
  assert(pq.dequeue() == 13);
  assert(pq.dequeue() == 10);
  assert(pq.getSize() == 7);
  cout << "Passed assert test" << endl;

  {
    cout << endl << "Copying using inline copy" << endl;
    PriorityQueue<int> copy = pq;
    int size = pq.getSize();
    assert(pq.getSize() == copy.getSize());
    for(int i = 0; i < size; i++)assert(pq.dequeue() == copy.dequeue());
    cout << "Passed assert tests" << endl;
  }

  cout << endl << "Filling object back up for next test" << endl;
  pq.enqueue(-10); pq.enqueue(10); pq.enqueue(-1); pq.enqueue(34); pq.enqueue(-2);
  pq.enqueue(-100); pq.enqueue(0); pq.enqueue(-1001); pq.enqueue(-1); pq.enqueue(13);

  {
    cout << endl << "Copying using after declaration copy" << endl;
    PriorityQueue<int> copy;
    copy = pq;
    int size = pq.getSize();
    assert(pq.getSize() == copy.getSize());
    for(int i = 0; i < size; i++)assert(pq.dequeue() == copy.dequeue());
    cout << "Passed assert tests" << endl;
  }

  cout << endl << endl;
}
