/************************************
Lab 1a, Class Programming And Testing
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#ifndef Road_h
#define Road_h

class Road
{
  double width;
  double length;

public:
  void setWidth(double);
  void setLength(double);
  double getWidth() const;
  double getLength() const;
  double asphalt(double);
};

#endif // Road_h
