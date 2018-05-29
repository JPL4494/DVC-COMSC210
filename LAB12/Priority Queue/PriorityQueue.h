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
  ///set index = size
  int index = size;
  ///if index >= capacity, double the capacity
  if(index >= capacity)doubleSize();
  ///copy new value into array at index
  data[index] = add;
  bool good = true;
  ///start loop
  while(good)
  {
    ///parentIndex = (index+1)/2 - 1
    int parentIndex = (index + 1)/2 - 1;
    ///if parentIndex < 0, exit loop
    if(parentIndex < 0)good = false;
    ///if value at parentIndex >= value at index, exit loop
    if(data[parentIndex] >= data[index])good = false;
    ///swap values at parentIndex and index
    if(good)
    {
      DataType temp = data[parentIndex];
      data[parentIndex] = data[index];
      data[index] = temp;
      ///set index = parentIndex
      index = parentIndex;
    }
  }///repeat to top of loop

  ///increment size
  size++;
}

template <class DataType>
DataType PriorityQueue<DataType>::dequeue()
{
  ///save value at index 0 to return at end
  DataType result = data[0];
  ///set index to zero
  int index = 0;
  bool good = true;
  ///start loop
  while(good)
  {
    ///index of left child = 2*index+1
    int lChild = 2 * index + 1;
    ///index of right child = 2*index+2
    int rChild = 2 * index + 2;
    ///if left child index >= size, exit loop
    if(lChild >= size)break;
    ///if left child index = size-1 OR value of left child >= value of right child
    if(lChild == (size - 1) || data[lChild] >= data[rChild])
    {
      ///set value at index to value of left child
      data[index] = data[lChild];
      ///set index = index of left child
      index = lChild;
    }
    ///else
    else
    {
      ///set value at index to value of right child
      data[index] = data[rChild];
      ///set index = index of right child
      index = rChild;
    }
  }///end loop
  ///decrement size
  size--;
  ///if size < capacity/4, halve the capacity
  if(size < (capacity / 4)) capacity = capacity / 2;
  ///copy value at size into array at index
  data[index] = data[size];
  ///start loop
  while(good)
  {
    ///parentIndex = (index+1)/2 - 1
    int parentIndex = (index + 1)/2 - 1;
    ///if parentIndex < 0, exit loop
    if(parentIndex < 0)good = false;
    ///if value at parentIndex >= value at index, exit loop
    if(data[parentIndex] >= data[index])good = false;
    ///swap values at parentIndex and index
    if(good)
    {
      DataType temp = data[parentIndex];
      data[parentIndex] = data[index];
      data[index] = temp;
      ///set index = parentIndex
      index = parentIndex;
    }
  }///repeat to top of loop
  ///return saved value
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
