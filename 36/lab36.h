#ifndef LAB36_H
#define LAB36_H

#include <iostream>
#include <d_matrix.h>

using namespace std;

class Spiral
{
  // Overloaded output operator - displays the two-dimensional matrix
  // data of spiral row-by-row to output stream out.  The columns of
  // the display should align on the right, and there should be one
  // space separating the columns.  The columns should all be of the
  // same width, equal to the width of the largest element.
  friend ostream& operator<<(ostream& out, const Spiral& spiral);

 public:
  // Member function Initialize resizes the two-dimensional matrix
  // data to be n rows by n columns and then initializes each element
  // to 0
  void initialize(int n);

  // Populates the two-dimensional matrix data as described in the lab
  // handout
  void build();

 private:
  matrix<uint> data;
};

#endif
