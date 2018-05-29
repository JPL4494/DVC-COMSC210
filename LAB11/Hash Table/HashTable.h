/************************************
LAB 11a: Write And Test The HashTable Class Template
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include<list>
#include<algorithm>
using namespace std;

#include <cassert>

#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

template <class DataType, const int CAPACITY>
class HashTable
{
  list<DataType> data[CAPACITY];
  typename list<DataType>::iterator itCurrent;
  int count;
  int current;

public:
  HashTable();
  int size()const {return count;}
  bool first(DataType&);
  bool getNext(DataType&);
  bool insert(DataType&);
  bool remove(DataType&);
  bool replace(DataType&);
  bool retrieve(DataType&);
  void clear();

private:
  int getWrappedIndex(DataType&);
};

template <class DataType, const int CAPACITY>
HashTable<DataType, CAPACITY>::HashTable()
{
  current = -1;
  count = 0;
}

template <class DataType, const int CAPACITY>
bool HashTable<DataType, CAPACITY>::first(DataType& parameter)
{
  assert(current >= -1 && current < CAPACITY);
  for (current = 0; current < CAPACITY; current++)
  {
    if (!data[current].empty())
    {
      itCurrent = data[current].begin();
      break;
    }
    }
  if (current == CAPACITY) current = -1;
  if (current == -1) return false;
  parameter = *itCurrent;
  return true;
}

template <class DataType, const int CAPACITY>
bool HashTable<DataType, CAPACITY>::getNext(DataType& parameter)
{
  assert(current >= -1 && current < CAPACITY);
  if (current == -1) return false;
  assert(!data[current].empty());
  if (++itCurrent == data[current].end())
  {
    for (current = current + 1; current < CAPACITY; current++)
    {
      if (!data[current].empty())
      {
        itCurrent = data[current].begin();
        break;
      }
    }
  }
  if (current == CAPACITY) current = -1;
  else parameter = *itCurrent;
  return current >= 0;
}

template <class DataType, const int CAPACITY>
bool HashTable<DataType, CAPACITY>::insert(DataType& parameter)
{
  int i = getWrappedIndex(parameter);
  typename list<DataType>::iterator it;
  it = find(data[i].begin(), data[i].end(), parameter);
  if (it != data[i].end()) *it = parameter; /// replace
  else {data[i].push_back(parameter); ++count;}
  return true;
}

template <class DataType, const int CAPACITY>
bool HashTable<DataType, CAPACITY>::remove(DataType& parameter)
{
  int i = getWrappedIndex(parameter);
  typename list<DataType>::iterator it; /// const_ for retrieve only!
  it = find(data[i].begin(), data[i].end(), parameter);
  if (it == data[i].end()) return false;

  parameter = *it;
  data[i].erase(it);
  count--;
  return true;
}

template <class DataType, const int CAPACITY>
bool HashTable<DataType, CAPACITY>::replace(DataType& parameter)
{
  int i = getWrappedIndex(parameter);
  typename list<DataType>::iterator it; // const_ for retrieve only!
  it = find(data[i].begin(), data[i].end(), parameter);
  if (it == data[i].end()) return false;

  *it = parameter;
  return true;
}

template <class DataType, const int CAPACITY>
bool HashTable<DataType, CAPACITY>::retrieve(DataType& parameter)
{
  int i = getWrappedIndex(parameter);
  typename list<DataType>::const_iterator it; /// const_ for retrieve only!
  it = find(data[i].begin(), data[i].end(), parameter);
  if (it == data[i].end()) return false;

  parameter = *it;
  return true;
}

template <class DataType, const int CAPACITY>
int HashTable<DataType, CAPACITY>::getWrappedIndex(DataType& parameter)
{
  int DI = parameter.hashCode();
  int wrapped = DI % CAPACITY;
  if(wrapped < 0)wrapped += CAPACITY;
  return wrapped;
}

template <class DataType, const int CAPACITY>
void HashTable<DataType, CAPACITY>::clear()
{
  for(int i = 0; i < CAPACITY; i++)data[i].clear();

  count = 0;
}

#endif // HASHTABLE_H_INCLUDED
