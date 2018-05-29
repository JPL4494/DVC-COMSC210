/************************************
Lab 1a, Class Programming And Testing
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include "Road.h"

void Road::setWidth(double w)
{
  width = w;
}

void Road::setLength(double l)
{
  length = l;
}

double Road::getWidth() const
{
  return width;
}

double Road::getLength() const
{
  return length;
}

double Road::asphalt(double t)
{
  double result;
  result = (t / 12) * width * (length * 5280);

  return result;
}
