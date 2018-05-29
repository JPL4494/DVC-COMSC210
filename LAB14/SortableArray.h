/************************************
Lab 14a: Write A Sortable Array Class Template
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#ifndef STATICARRAY_H
#define STATICARRAY_H

template <class DataType, const int CAPACITY>
class SortableArray
{
  DataType data[CAPACITY];
  DataType dummy;

public:
  SortableArray(){}
  int getCapacity()const{return CAPACITY;}
  int lsearch(const DataType&, int = -1)const;
  DataType& operator[](int);
  int bsearch(DataType, int = 0, int = -1)const;
  void sort(int = -1);

private:
  void heapInsert(DataType[], DataType&, const int&, const int&);
};

template <class DataType, int CAPACITY>
int SortableArray<DataType,CAPACITY>::lsearch(const DataType& lookFor, int limit)const
{
  if(limit < 0)limit = CAPACITY;
  for(int i = 0; i < limit; i++)
  {
    if(data[i] == lookFor)return i;
  }
  return -1;
}

template <class DataType, int CAPACITY>
DataType& SortableArray<DataType,CAPACITY>::operator[](int index)
{
  if(index < 0)return dummy;
  if(index >= CAPACITY) return dummy;
  return data[index];
}

template <class DataType, int CAPACITY>
int SortableArray<DataType,CAPACITY>::bsearch(DataType value, int s, int e)const
{
  /// "a" is an array of type DataType
  /// "value" is the DataType value to be matched
  /// "s" is the starting index of the array (usually 0)
  /// "e" is the ending index of the array (usually size-1)
  int m = (s + e) / 2; /// the middle element
  if (value == data[m]) /// got lucky -- matches middle element
  {
    value = data[m]; /// copy whole struct (if DataType's a struct)
    return m; /// return index of found element
  }
  else if (s == e) /// 1-element array
    return -1; /// only element in array did not match
  else if (value < data[m]) /// look between s and m-1
  {
    if (s == m) return -1; /// but that range is empty, no match
    else return bsearch2(value, s, m - 1); /// look in s to m-1
  }
  else /// look between m+1 and e
  {
    if (m == e) return -1; /// but that range is empty, no match
    else return bsearch2(value, m + 1, e); /// look in m-1 to e
  }
}

template <class DataType, int CAPACITY>
void SortableArray<DataType,CAPACITY>::sort(int limit)
{
  /// "a" is an array of type DataType
  /// "size" is the #of values stored in the array
  /// rearrange the array into a heap

  if(limit <= 0)limit = CAPACITY;

  int i;
  for (i = limit / 2 - 1; i >= 0; i--)
  {
    DataType removed = data[i];
    heapInsert(data, removed, i, limit - 1);
  }

  /// sort the heap
  for (i = 0; i < limit; i++)
  {
    int e = limit - i - 1;
    DataType removed = data[e];
    data[e] = data[0];
    heapInsert(data, removed, 0, e - 1);
  }
}

template <class DataType, int CAPACITY>
void SortableArray<DataType,CAPACITY>::heapInsert(DataType a[], DataType& insertThis, const int& s, const int& e)
{
  /// "a" is an array of type DataType
  /// "insertThis" is the value of type DataType to be inserted
  /// "s" is the starting index of the array (usually 0)
  /// "e" is the ending index of the array (usually size-1)
  int i = s;
  while (true)
  {
    /// indexes if i's children for heap starting at s
    int iLeft = 2 * i + 1; /// left-side child (if any)
    int iRight = 2 * i + 2; /// right-side child (if any)
    if (iLeft > e) /// "i" has no children
    {
      a[i] = insertThis; /// easy solution: insert here
      break; /// done
    }
    else if (iLeft == e) /// "i" has one child
    {
      if (insertThis < a[iLeft]) /// promote only child
      {
        a[i] = a[iLeft];
        a[iLeft] = insertThis;
      }
      else ///insert ahead of lesser child
        a[i] = insertThis;
    break; /// done either way
    }
    else if (a[iLeft] < insertThis && a[iRight] < insertThis)
    {
      a[i] = insertThis; /// reinsert above lesser children
      break; /// done
    }
    else if (a[iLeft] < a[iRight]) /// which child to promote?
    {
      a[i] = a[iRight]; /// promote child...
      i = iRight; /// ...and continue
    }
    else
    {
      a[i] = a[iLeft]; /// promote child...
      i = iLeft; /// ...and continue
    }
  }
}

#endif // STATICARRAY_H
