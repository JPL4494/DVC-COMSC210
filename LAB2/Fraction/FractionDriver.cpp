/************************************
Lab 2a, Writing Overloading Operators
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include <iostream>

using namespace std;

#include <cassert>

#include "Fraction.h"
#include "Fraction.h"

int main()
{
  cout << "Lab 2a, Writing Overloading Operators" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << "Creating two fractions" << endl;

  Fraction f1, f2;

  f1.numerator = 1;
  f1.denominator = 2;
  f2.numerator = 3;
  f2.denominator = 4;

  cout << endl << "Checking creation of two fraction variables" << endl;
  cout << "Fraction one numerator expected: 1" << endl;
  cout << "Actual: " << f1.numerator << endl;
  cout << "Fraction one denominator expected: 2" << endl;
  cout << "Actual: " << f1.denominator << endl;

  cout << endl;

  cout << "Fraction two numerator expected: 3" << endl;
  cout << "Actual: " << f2.numerator << endl;
  cout << "Fraction one denominator expected: 4" << endl;
  cout << "Actual: " << f2.denominator << endl;

  cout << endl;

  cout << "Now checking addition function" << endl;
  Fraction add = f1 + f2;
  cout << "Verifying results" << endl;
  cout << "Numerator expected: 10" << endl;
  cout << "Actual:" << add.numerator << endl;
  cout << "Denominator expected: 8" << endl;
  cout << "Actual:" << add.denominator << endl;

  cout << endl;

  cout << "Now checking multiplication function with two fractions" << endl;
  Fraction m1 = f1 * f2;
  cout << "Verifying results" << endl;
  cout << "Numerator expected: 3" << endl;
  cout << "Actual:" << m1.numerator << endl;
  cout << "Denominator expected: 8" << endl;
  cout << "Actual:" << m1.denominator << endl;

  cout << endl;

  cout << "Now checking multiplication function with a fraction and integer" << endl;
  Fraction m2 = f1 * 4;
  cout << "Verifying results" << endl;
  cout << "Numerator expected: 4" << endl;
  cout << "Actual:" << m2.numerator << endl;
  cout << "Denominator expected: 2" << endl;
  cout << "Actual:" << m2.denominator << endl;

  cout << endl;

  cout << "Now checking multiplication function with an integer and fraction" << endl;
  Fraction m3 = 3 * f2;
  cout << "Verifying results" << endl;
  cout << "Numerator expected: 9" << endl;
  cout << "Actual:" << m3.numerator << endl;
  cout << "Denominator expected: 4" << endl;
  cout << "Actual:" << m3.denominator << endl;

  cout << endl;

  cout << "Now checking greater than function, expected true" << endl;
  cout << "Actual: ";
  if(f2 > f1)cout << "true" << endl;
  else cout << "false" << endl;

  {
    cout << endl << "Copying using inline copy" << endl;
    Fraction copy = f1;
    cout << "Now checking copy using assert functions" << endl;
    assert(copy.numerator == f1.numerator);
    assert(copy.denominator == f1.denominator);
    cout << "Passed assert test" << endl;
  }

  {
    cout << endl << "Copying using after declaration copy" << endl;
    Fraction copy;
    copy = f2;
    cout << "Now checking copy using assert functions" << endl;
    assert(copy.numerator == f2.numerator);
    assert(copy.denominator == f2.denominator);
    cout << "Passed assert test" << endl;
  }

  cout << endl << endl;
}
