/************************************
Lab 3a, const And Constructors
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include "Road.h"

Road::Road(const double& l,const double& w)
:width(w), length(l)
{}

void Road::setLength(const double& l)
{
  length = l;
}

void Road::setWidth(const double& w)
{
  width = w;
}

double Road::getWidth() const
{
  return width;
}

double Road::getLength() const
{
  return length;
}

double Road::asphalt(const double& t)const
{
  double result;
  result = (t / 12) * width * (length * 5280);

  return result;
}
