/************************************
Lab 4b, Introduction To Dynamic Array Doubling And Deallocation
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#ifndef CHECKBOOK_H
#define CHECKBOOK_H

template <class DataType>
class Checkbook
{
  int capacity, numOfChecks;
  DataType* checks;

  void doubleArray();

public:
  Checkbook();
  DataType* getChecks() const;
  DataType getBalance() const;
  void writeCheck(const DataType&);
  void makeDeposit(const DataType&);
  int getSize()const {return numOfChecks;}
};

template <class DataType>
Checkbook<DataType>::Checkbook()
{
  capacity = 2;
  numOfChecks = 0;
  checks = new DataType[capacity];
}

template <class DataType>
void Checkbook<DataType>::doubleArray()
{
  DataType* temp = new DataType[capacity * 2];
  for(int i = 0; i < capacity; i++)temp[i] = checks[i];
  delete [] checks;
  checks = temp;
  capacity *= 2;
}

template <class DataType>
DataType* Checkbook<DataType>::getChecks() const
{
  DataType* temp = new DataType[(numOfChecks+1)];
  for(int i = 0; i < (numOfChecks+1); i++)temp[i] = checks[i];
  return temp;
}

template <class DataType>
DataType Checkbook<DataType>::getBalance() const
{
  DataType total = 0;
  for(int i = 0; i < numOfChecks; i++)
  {
    total += checks[i];
  }
  return total;
}

template <class DataType>
void Checkbook<DataType>::writeCheck(const DataType& check)
{
  if((numOfChecks+1) == capacity)doubleArray();

  checks[numOfChecks] = (-1 * check);
  numOfChecks++;
}

template <class DataType>
void Checkbook<DataType>::makeDeposit(const DataType& check)
{
  if((numOfChecks+1) == capacity)doubleArray();

  checks[numOfChecks] = check;
  numOfChecks++;
}

#endif // CHECKBOOK_H
