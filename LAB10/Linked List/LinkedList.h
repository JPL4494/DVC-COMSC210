/************************************
LAB 10a: Write And Test The ListedList Class Template
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#ifndef NODE
#define NODE
template <class DataType>
struct Node
{
  DataType data;
  Node<DataType>* next;
};
#endif

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class DataType>
class LinkedList
{
  Node<DataType>* start;
  Node<DataType>* current;
  DataType dummy;
  int size;
  int currentIndex;

public:
  LinkedList();
  void insert(const DataType&);
  bool first(DataType&);
  bool getNext(DataType&);
  bool find(const DataType&);
  bool retrieve(DataType&);
  bool replace(const DataType&);
  bool remove(DataType&);
  bool isEmpty()const {return !start;}
  void makeEmpty();
  int getLength()const {return size;}
  DataType& operator[](const int&);

  ~LinkedList();
  LinkedList(const LinkedList<DataType>&);
  LinkedList<DataType>& operator=(const LinkedList<DataType>&);
};

template <class DataType>
LinkedList<DataType>::LinkedList()
{
  start = 0;
  current = 0;
  size = 0;
  currentIndex = 0;
}

template <class DataType>
void LinkedList<DataType>::insert(const DataType& add)///O(1)
{
  current = 0;
  Node<DataType>* node = new Node<DataType>;
  node->data = add;
  node->next = start;
  start = node;
  size++;
}

template <class DataType>
bool LinkedList<DataType>::first(DataType& first)/// O(1)
{
  if (!start) return false;
  first = start->data;
  current = start;
  return true;
}

template <class DataType>
bool LinkedList<DataType>::getNext(DataType& parameter)/// O(1)
{
  if (!current) return false;
  current = current->next;
  if (!current) return false;
  parameter = current->data;
  currentIndex++;
  return true;
}

template <class DataType>
bool LinkedList<DataType>::find(const DataType& parameter)/// O(n)
{
  DataType temp;
  currentIndex = 0;
  if (first(temp)) do
  {
    if (parameter == temp) return true; /// found it
    currentIndex++;
  } while (getNext(temp));
  return false; /// no match
}

template <class DataType>
bool LinkedList<DataType>::retrieve(DataType& parameter)/// O(n)
{
  if (!find(parameter)) return false;
  parameter = current->data; /// set in find
  return true;
}

template <class DataType>
bool LinkedList<DataType>::replace(const DataType& parameter)/// O(1)
{
  if (!current) return false;
  current->data = parameter;
  return true;
}

template <class DataType>
bool LinkedList<DataType>::remove(DataType& parameter)/// O(n)
{
  /// find node to remove
  Node<DataType>* p;
  Node<DataType>* prev;
  for (prev = 0, p = start; p; prev = p, p = p->next)
    if (p->data == parameter)
      break;

  /// deallocate node here
  if (!p) return false; /// no match
  if (prev) prev->next = p->next; else start = p->next;
  if (p == current)
    {
      current = current->next;
      currentIndex++;
    }
  parameter = p->data;
  delete p;
  size--;
  return true;
}

template <class DataType>
void LinkedList<DataType>::makeEmpty()/// O(n)
{
  while (start)
  {
    current = start->next;
    delete start;
    start = current;
  }
  size = 0;
  currentIndex = 0;
}

template <class DataType>
DataType& LinkedList<DataType>::operator[](const int& index)
{
  if(index == 0)
  {
    current = start;
    currentIndex = 0;
    return start->data;
  }
  if(index > size || index < 0)return dummy;

  if(index == currentIndex)return current->data;
  if((currentIndex+1) == index)
  {
    if((currentIndex+1) != size)
    {
      current = current->next;
      currentIndex++;
    }
    return current->data;
  }

  Node<DataType>* p;
  currentIndex = 0;
  current = start;
  for (p = start; p; p = p->next)
  {
    if(index == currentIndex)return current->data;

    currentIndex++;
    current = current->next;
  }
  return current->data;
}

template <class DataType>
LinkedList<DataType>::~LinkedList()
{
  Node<DataType>* p;
  while (start)
  {
    p = start->next;
    delete start;
    start = p;
  }
  size = 0;
  currentIndex = 0;
}

template <class DataType>
LinkedList<DataType>::LinkedList(const LinkedList<DataType>& a)///O(n)
:start(0), current(0), size(a.size), currentIndex(a.currentIndex)
{
  Node<DataType>* p;
  Node<DataType>* end = 0;
  for (p = a.start; p; p = p->next)
  {
    Node<DataType>* node = new Node<DataType>;
    node->data = p->data;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
    if (p == a.current) current = node;
  }
}

template <class DataType>
LinkedList<DataType>& LinkedList<DataType>::operator=(const LinkedList<DataType>& a)
{
  if (this != &a)
  {
    current = 0;
    Node<DataType>* p;
    Node<DataType>* end = 0;
    while (start)
    {
      p = start->next;
      delete start;
      start = p;
    }
    for (p = a.start; p; p = p->next)
    {
      Node<DataType>* node = new Node<DataType>;
      node->data = p->data;
      node->next = 0;
      if (end) end->next = node;
      else start = node;
      end = node;
      if (p == a.current) current = node;
    }
  }
  size = a.size;
  currentIndex = a.currentIndex;
  return *this;
}

#endif // LINKEDLIST_H
