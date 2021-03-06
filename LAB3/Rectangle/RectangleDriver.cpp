/************************************
Lab 3c, const And Constructors, Part 3
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include <iostream>

using namespace std;

#include <cassert>

#include "Fraction.h"

#include "Rectangle.h"
#include "Rectangle.h"

int main()
{
  cout << "Lab 3c, const And Constructors, Part 3" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << "Creating two rectangles using fractions and floats" << endl;
  Fraction l1,w1;

  l1.numerator = 1;
  l1.denominator = 2;
  w1.numerator = 5;
  w1.denominator = 4;

  Rectangle<Fraction> r1;
  r1.setLength(l1);
  r1.setWidth(w1);
  Rectangle<int> r2(3,1);

  cout << endl << "Checking creation of two rectangles" << endl;
  cout << "Checking rectangle one length, expected: 1 / 2" << endl;
  cout << "Actual: " << r1.getLength().numerator << " / " << r1.getLength().denominator << endl;
  cout << "Checking rectangle one width, expected: 5 / 4" << endl;
  cout << "Actual: " << r1.getWidth().numerator << " / " << r1.getWidth().denominator << endl;

  cout << endl << "Checking rectangle one greater than function, expected false" << endl;
  cout << "Actual: ";
  if(r1.isLengthGreater()) cout << "true" << endl;
  else cout << "false" << endl;

  cout << "Checking perimeter function, expected 28 / 8" << endl;
  cout << "Actual: " << r1.perimeter().numerator << " / " << r1.perimeter().denominator << endl;
  cout << "Checking area function, expected 5 / 8" << endl;
  cout << "Actual: " << r1.area().numerator << " / " << r1.area().denominator << endl;

  cout << endl << "Checking rectangle two length, expected: 3" << endl;
  cout << "Actual: " << r2.getLength() << endl;
  cout << "Checking rectangle two width, expected: 1" << endl;
  cout << "Actual: " << r2.getWidth() << endl;
  cout << "Checking greater than function, expected true" << endl;
  cout << "Actual: ";
  if(r2.isLengthGreater()) cout << "true" << endl;
  else cout << "false" << endl;
  cout << "Checking perimeter function, expected 8" << endl;
  cout << "Actual: " << r2.perimeter() << endl;
  cout << "Checking area function, expected 3" << endl;
  cout << "Actual: " << r2.area() << endl;

  {
    cout << endl << "Copying using inline const copy" << endl;
    const Rectangle<int> copy = r2;
    cout << "Now checking copy using assert functions" << endl;
    assert(copy.getLength() == r2.getLength());
    assert(copy.getWidth() == r2.getWidth());
    assert(copy.isLengthGreater() == r2.isLengthGreater());
    assert(copy.perimeter() == r2.perimeter());
    assert(copy.area() == r2.area());
    cout << "Passed assert test" << endl;
  }

  {
    cout << endl << "Copying using after declaration copy" << endl;
    Rectangle<int> copy;
    copy = r2;
    cout << "Now checking copy using assert functions" << endl;
    assert(copy.getLength() == r2.getLength());
    assert(copy.getWidth() == r2.getWidth());
    assert(copy.isLengthGreater() == r2.isLengthGreater());
    assert(copy.perimeter() == r2.perimeter());
    assert(copy.area() == r2.area());
    cout << "Passed assert test" << endl;
  }

  cout << endl << endl;
}
