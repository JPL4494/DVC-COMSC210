/************************************
Lab 2a, Writing Overloading Operators
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include "Fraction.h"

bool operator> (const Fraction& f1,const Fraction& f2)
{
  double one, two;

  one = f1.numerator / f1.denominator;
  two = f2.numerator / f2.denominator;

  if(one > two)return true;
  else return false;
}

Fraction Fraction::operator+(const Fraction& f) const
{
  Fraction result;
  Fraction t1, t2;
  if(denominator != f.denominator)
  {
    int temp;
    temp = denominator;
    t2.denominator = denominator * f.denominator;
    t1.numerator = numerator * f.denominator;

    t2.numerator = f.numerator * temp;
  }
  else
  {
    t1.numerator = numerator;
    t2.numerator = f.numerator;
    t2.denominator = denominator;
  }

  result.numerator = t1.numerator + t2.numerator;
  result.denominator = t2.denominator;
  return result;
}

Fraction Fraction::operator*(const Fraction& f) const
{
  Fraction result;

  result.numerator = f.numerator * numerator;
  result.denominator = f.denominator * denominator;

  return result;
}

Fraction operator*(const Fraction& f,const int& i)
{
  Fraction result;

  result.numerator = f.numerator * i;
  result.denominator = f.denominator;

  return result;
}

Fraction operator*(const int& i,const Fraction& f)
{
  Fraction result;

  result.numerator = f.numerator * i;
  result.denominator = f.denominator;

  return result;
}
