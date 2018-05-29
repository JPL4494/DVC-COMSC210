/************************************
Lab 5a, Write A Static Array Class Template
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#ifndef STATICARRAY_H
#define STATICARRAY_H

template <class DataType, const int CAPACITY>
class Array
{
  DataType data[CAPACITY];
  DataType dummy;

public:
  Array(){}
  int getCapacity()const{return CAPACITY;}
  int lsearch(const DataType&)const;
  DataType& operator[](int);
};

template <class DataType, int CAPACITY>
int Array<DataType,CAPACITY>::lsearch(const DataType& lookFor)const
{
  for(int i = 0; i < CAPACITY; i++)
  {
    if(data[i] == lookFor)return i;
  }
  return -1;
}

template <class DataType, int CAPACITY>
DataType& Array<DataType,CAPACITY>::operator[](int index)
{
  if(index < 0)return dummy;
  if(index >= CAPACITY) return dummy;
  return data[index];
}

#endif // STATICARRAY_H
