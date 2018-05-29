/************************************
Lab 3a, const And Constructors
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
  Road(const double&,const double&);
  void setWidth(const double&);
  void setLength(const double&);
  double getWidth() const;
  double getLength() const;
  double asphalt(const double&)const;
};

#endif // Road_h
