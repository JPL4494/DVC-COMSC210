/************************************
LAB 8b: Write And Test A Queue Template
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

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

template<class DataType>
class Queue
{
  Node<DataType>* front;
  Node<DataType>* end;
  DataType dummy;

public:
  Queue<DataType>();
  Queue<DataType>(const Queue<DataType>&);
  ~Queue<DataType>();

  bool isEmpty()const {return 0 == front;}
  void push(const DataType&);
  DataType peek()const;
  bool pop(DataType&);
  DataType topPop();
  void makeEmpty();

  Queue<DataType>& operator=(const Queue<DataType>&);
  ostream& operator<<(ostream&);
};

template <class DataType>
Queue<DataType>::Queue()
: front(0), end(0)
{}

template <class DataType>
Queue<DataType>::Queue(const Queue<DataType>& a)
: front(0), end(0)
{
  Node<DataType>* p;
  for (p = a.front; p; p = p->next)
  {
    Node<DataType>* node = new Node<DataType>;
    node->data = p->data;
    node->next = 0;
    if (end) end->next = node;
    else front = node;
    end = node;
  }
}

template <class DataType>
Queue<DataType>::~Queue()
{
  Node<DataType>* p;
  while (front)
  {
    p = front->next;
    delete front;
    front = p;
  }
}

template <class DataType>
void Queue<DataType>::push(const DataType& parameter)
{
  Node<DataType>* node = new Node<DataType>;
  node->data = parameter;
  node->next = 0;
  if (end) end->next = node;
  else front = node;
  end = node;
}

template <class DataType>
DataType Queue<DataType>::peek()const
{
  if(front == 0)return dummy;

  return (front->data);
}

template <class DataType>
bool Queue<DataType>::pop(DataType& parameter)
{
  if (0 == front) return false; /// failed
  parameter = front->data;
  Node<DataType>* p = front->next;
  delete front;
  front = p;
  if (front == 0) end = 0;
  return true; /// success
}

template <class DataType>
DataType Queue<DataType>::topPop()
{
  if (0 == front) return dummy; /// failed
  DataType temp = front->data;
  Node<DataType>* p = front->next;
  delete front;
  front = p;
  if (front == 0) end = 0;
  return temp; /// success
}

template <class DataType>
void Queue<DataType>::makeEmpty()
{
  end = 0;
  Node<DataType>* p;
  while (front)
  {
    p = front->next;
    delete front;
    front = p;
  }
}

template <class DataType>
Queue<DataType>& Queue<DataType>::operator=(const Queue<DataType>& a)
{
  if (this != &a)
  {
    Node<DataType>* p;

    /// deallocate existing queue
    end = 0; /// data member end pointer
    while (front)
    {
      p = front->next;
      delete front;
      front = p;
    }

    /// build new queue
    for (p = a.front; p; p = p->next)
    {
      Node<DataType>* node = new Node<DataType>;
      node->data = p->data;
      node->next = 0;
      if (end) end->next = node;
      else front = node;
      end = node;
    }
  }
  return *this;
}

template <class DataType>
ostream& Queue<DataType>::operator<<(ostream& out)
{
  for(Node<DataType>* p = front; p; p = p -> next)
  {
    out << p -> data << " ";
  }
  return out;
}

#endif // QUEUE_H_INCLUDED
