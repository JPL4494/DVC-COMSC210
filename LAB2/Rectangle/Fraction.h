/************************************
Lab 2a, Writing Overloading Operators
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

struct Fraction
{
  double numerator;
  double denominator;

  friend bool operator> (const Fraction&,const Fraction&);
  Fraction operator+(const Fraction&) const;
  Fraction operator*(const Fraction&) const;
  friend Fraction operator*(const Fraction&,const int&);
  friend Fraction operator*(const int&,const Fraction&);
};

#endif // FRACTION_H_INCLUDED
