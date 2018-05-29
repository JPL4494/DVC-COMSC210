/************************************
Lab 3b, const And Constructors, Part 2
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#ifndef TIME_H
#define TIME_H

class Time
{
  double hour;
  double minute;
  double second;

public:
  Time();
  Time(const double&,const double&,const double&);
  void setHours(const double&);
  void setMinutes(const double&);
  void setSeconds(const double&);

  double getHours() const;
  double getMinutes() const;
  double getSeconds() const;

  double timeInHours() const;
  double timeInMinutes() const;
  double timeInSeconds() const;
};

#endif // TIME_H
