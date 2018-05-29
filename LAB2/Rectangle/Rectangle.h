/************************************
Lab 2b, Writing Templated Classes
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

template <class DataType>
class Rectangle
{
  DataType length;
  DataType width;

public:
  void setLength(const DataType& l){length = l;}
  void setWidth(const DataType& w){width = w;}
  DataType getLength()const {return length;}
  DataType getWidth()const {return width;}
  bool isLengthGreater(){return true ? length > width : false;}
  DataType perimeter(){return ((2 * length)+(2 * width));}
  DataType area(){return (length * width);}

};

#endif // RECTANGLE_H_INCLUDED
