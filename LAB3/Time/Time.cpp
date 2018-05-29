/************************************
Lab 3b, const And Constructors, Part 2
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include "Time.h"

Time::Time()
{
  hour = 0;
  minute = 0;
  second = 0;
}

Time::Time(const double& h, const double& m, const double& s)
{
  hour = h;
  minute = m;
  second = s;
}

void Time::setHours(const double& h)
{
  hour = h;
}

void Time::setMinutes(const double& m)
{
  minute = m;
}

void Time::setSeconds(const double& s)
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
