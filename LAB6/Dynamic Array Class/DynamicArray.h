/************************************
Lab 6c: Write Dynamic Array Class Template
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template<class DataType>
class Array
{
  int capacity;
  DataType* data;
  DataType dummy;

public:
  Array(const int&);
  Array(const Array&);
  ~Array(){delete [] data;}
  void changeCapacity(const int&);
  Array<DataType>& operator=(const Array&);
  DataType& operator[](int);
  int lsearch(const DataType&)const;
};

template <class DataType>
Array<DataType>::Array(const int& initialCapacity)
{
  capacity = initialCapacity;

  if (capacity <= 0)
  {
    data = 0;
    capacity = 0;
  }
  else
    data = new DataType[capacity];
}

template <class DataType>
Array<DataType>::Array(const Array<DataType>& a)
{
  capacity = a.capacity;
  data = 0;

  if (capacity > 0)
  {
    data = new DataType[capacity];

    for (int i = 0; i < capacity; i++)data[i] = a.data[i];
  }
}

template <class DataType>
void Array<DataType>::changeCapacity(const int& newCapacity)
{
  if (newCapacity <= 0)
  {
    delete [] data;
    data = 0;
    capacity = 0;
  }
  else
  {
    DataType* newData = new DataType[newCapacity];
    int limit = newCapacity > capacity ? capacity : newCapacity;

    for (int i = 0; i < limit; i++)newData[i] = data[i];

    delete [] data;

    data = newData;

    capacity = newCapacity;
  }
}

template <class DataType>
Array<DataType>& Array<DataType>::operator=(const Array<DataType>& a)
{
  if (this == &a) return *this;

  delete [] data;
  capacity = a.capacity;
  data = 0;

  if (capacity > 0)
  {
    data = new DataType[capacity];

    for (int i = 0; i < capacity; i++)data[i] = a.data[i];
  }
  return *this;
}

template <class DataType>
DataType& Array<DataType>::operator[](int index)
{
  if(index < 0)return dummy;
  if(index >= capacity) return dummy;
  return data[index];
}

template <class DataType>
int Array<DataType>::lsearch(const DataType& lookFor)const
{
  for(int i = 0; i < capacity; i++)
  {
    if(data[i] == lookFor)return i;
  }
  return -1;
}

#endif // DYNAMICARRAY_H
