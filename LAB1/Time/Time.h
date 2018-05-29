/************************************
Lab 1b, More Class Programming And Testing
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
  void setHours(double);
  void setMinutes(double);
  void setSeconds(double);

  double getHours() const;
  double getMinutes() const;
  double getSeconds() const;

  double timeInHours() const;
  double timeInMinutes() const;
  double timeInSeconds() const;
};

#endif // TIME_H
