/************************************
Lab 1b, More Class Programming And Testing
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include "Time.h"

void Time::setHours(double h)
{
  hour = h;
}

void Time::setMinutes(double m)
{
  minute = m;
}

void Time::setSeconds(double s)
{
  second = s;
}

double Time::getHours() const
{
  return hour;
}

double Time::getMinutes() const
{
  return minute;
}

double Time::getSeconds() const
{
  return second;
}

double Time::timeInHours() const
{
  double result;
  result = hour + (minute / 60) + (second / 3600);
  return result;
}

double Time::timeInMinutes() const
{
  double result;
  result = (hour * 60) + minute + (second / 60);
  return result;
}

double Time::timeInSeconds() const
{
  double result;
  result = (hour * 3600) + (minute * 60) + second;
  return result;
}
