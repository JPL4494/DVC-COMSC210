/************************************
LAB 12a: Write And Test A Priority Queue Template
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

template <class DataType>
class PriorityQueue
{
  DataType* data;
  int size;
  int capacity;

public:
  PriorityQueue();
  int getSize()const {return size;}
  void enqueue(const DataType&);
  DataType dequeue();

  PriorityQueue<DataType>(const PriorityQueue<DataType>&);
  PriorityQueue<DataType>& operator=(const PriorityQueue<DataType>&);
  ~PriorityQueue();

private:
  void doubleSize();
};

template <class DataType>
PriorityQueue<DataType>::PriorityQueue()
{
  size = 0;
  capacity = 1;
  data = new DataType[capacity];
}

template <class DataType>
PriorityQueue<DataType>::PriorityQueue(const PriorityQueue<DataType>& pq)
{
  capacity = pq.capacity;
  data = 0;
  size = pq.size;

  if (capacity > 0)
  {
    data = new DataType[capacity];

    for (int i = 0; i < size; i++)data[i] = pq.data[i];
  }
}

template <class DataType>
PriorityQueue<DataType>& PriorityQueue<DataType>::operator=(const PriorityQueue<DataType>& pq)
{
  if (this == &pq) return *this;

  delete [] data;
  capacity = pq.capacity;
  size = pq.size;
  data = 0;

  if (capacity > 0)
  {
    data = new DataType[capacity];

    for (int i = 0; i < size; i++)data[i] = pq.data[i];
  }
  return *this;
}

template <class DataType>
void PriorityQueue<DataType>::enqueue(const DataType& add)
{
  int index = size;
  if(index >= capacity)doubleSize();
  data[index] = add;
  bool good = true;
  while(good)
  {
    int parentIndex = ((index+1)/2) - 1;
    if(parentIndex < 0)good = false;

    if(data[parentIndex] >= data[index])good = false;

    if(good)
    {
      DataType temp = data[index];
      data[index] = data[parentIndex];
      data[parentIndex] = temp;
      index = parentIndex;
    }
  }
  size++;
}

template <class DataType>
DataType PriorityQueue<DataType>::dequeue()
{
  DataType result = data[0];
  int index = 0;
  bool good = true;
  while(good)
  {
    int lChild = (2 * index) + 1;
    int rChild = (2 * index) + 2;
    if(lChild >= size)break;

    if(lChild == (size - 1) || data[lChild] >= data[rChild])
    {
      data[index] = data[lChild];
      index  = lChild;
    }
    else
    {
      data[index] = data[rChild];
      index  = rChild;
    }
  }

  size--;
  if(size < (capacity / 4))capacity = capacity / 2;
  data[index] = data[size];
  good = true;
  while(good)
  {
    int parentIndex = (index+1)/2 - 1;
    if(parentIndex < 0)good = false;
    if(data[parentIndex] >= data[index])good = false;

    if(good)
    {
      DataType temp = data[index];
      data[index] = data[parentIndex];
      data[parentIndex] = temp;
      index = parentIndex;
    }
  }
  return result;
}

template <class DataType>
void PriorityQueue<DataType>::doubleSize()
{
  DataType* newData = new DataType[2*capacity];
  for(int i = 0; i < capacity; i++)newData[i] = data[i];
  delete [] data;
  data = newData;
  capacity *= 2;
}

template <class DataType>
PriorityQueue<DataType>::~PriorityQueue()
{
  delete [] data;
  size = 0;
  capacity = 0;
}

#endif // PRIORITYQUEUE_H_INCLUDED
