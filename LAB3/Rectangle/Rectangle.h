/************************************
Lab 3c, const And Constructors, Part 3
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
  Rectangle(){}
  Rectangle(const DataType& l, const DataType& w){length = l; width = w;}
  void setLength(const DataType& l){length = l;}
  void setWidth(const DataType& w){width = w;}
  DataType getLength()const {return length;}
  DataType getWidth()const {return width;}
  bool isLengthGreater()const{return true ? length > width : false;}
  DataType perimeter()const{return ((2 * length)+(2 * width));}
  DataType area()const{return (length * width);}

};

#endif // RECTANGLE_H_INCLUDED
