/************************************
LAB 8a: Write And Apply A Stack Template
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


#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

template <class DataType>
class Stack
{
  Node<DataType>* start;
  DataType dummy;

public:
  Stack<DataType>() {start = 0;}
  Stack<DataType>(const Stack<DataType>&);
  ~Stack();

  bool isEmpty()const {return 0 == start;}
  void push(const DataType&);
  bool peek(DataType&) const;
  bool pop(DataType&);
  void makeEmpty();

  Stack<DataType>& operator=(const Stack<DataType>&);

  ostream& operator<<(ostream&);
  DataType topPop();
};

template <class DataType>
void Stack<DataType>::push(const DataType& parameter)
{
  Node<DataType>* node = new Node<DataType>;
  node->data = parameter;
  node->next = start;
  start = node;
}

template <class DataType>
Stack<DataType>::Stack(const Stack<DataType>& a)
: start(0)
{
  Node<DataType>* p;
  Node<DataType>* end = 0; // temporary end pointer
  for (p = a.start; p; p = p->next)
  {
    Node<DataType>* node = new Node<DataType>;
    node->data = p->data;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
  }
}

template <class DataType>
Stack<DataType>::~Stack()
{
  Node<DataType>* p;
  while (start != NULL)
  {
    p = start->next;
    delete start;
    start = p;
  }
}

template <class DataType>
bool Stack<DataType>::peek(DataType& parameter) const
{
  if (start == 0) return false;
  if(parameter == start->data)return true;
  else return false;
}

template <class DataType>
bool Stack<DataType>::pop(DataType& parameter)
{
  if (start == 0) return false;

  if(start->data == parameter)
  {
    parameter = start->data;
    Node<DataType>* p = start->next;
    delete start;
    start = p;
    return true;
  }
  return false;
}

template <class DataType>
void Stack<DataType>::makeEmpty()
{
  Node<DataType>* p;
  while (start)
  {
    p = start->next;
    delete start;
    start = p;
  }
}

template <class DataType>
Stack<DataType>& Stack<DataType>::operator=(const Stack<DataType>& a)
{
  if (this != &a)
  {
    Node<DataType>* p;
    Node<DataType>* end = 0; // temporary end pointer

    // deallocate existing queue
    while (start)
    {
      p = start->next;
      delete start;
      start = p;
    }

    // build new queue
    for (p = a.start; p; p = p->next)
    {
      Node<DataType>* node = new Node<DataType>;
      node->data = p->data;
      node->next = 0;
      if (end) end->next = node;
      else start = node;
      end = node;
    }
  }
  return *this;
}

template <class DataType>
ostream& Stack<DataType>::operator<<(ostream& out)
{
  for(Node<DataType>* p = start; p; p = p -> next)
  {
    out << p -> data << " ";
  }
  return out;
}

template <class DataType>
DataType Stack<DataType>::topPop()
{
  if (start == 0) return dummy;

  DataType temp = start->data;
  Node<DataType>* p = start->next;
  delete start;
  start = p;

  return temp;
}

#endif // STACK_H_INCLUDED
