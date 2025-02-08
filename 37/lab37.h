#ifndef LAB37_H
#define LAB37_H

#include <iostream>
#include <d_matrix.h>

using namespace std;

class Sudoku
{
  // Overloaded output operator - displays puzzle row-by-row to output
  // stream out.  The elements in a row should be separated by one
  // blank space.
  friend ostream& operator<<(ostream& out, const Sudoku& puzzle);

  // Overloaded input operator - initializes puzzle from input stream
  // in.  The function should read four four-digit unsigned
  // integers. The first unsigned integer is used to initialize the
  // elements of the first row of the puzzle, the second the second,
  // etc. The least significant digit of the four-digit number is used
  // to initialize the last element in the row, the next-to-least the
  // next-to-last, etc.
  friend istream& operator>>(istream& in, Sudoku& puzzle);

 public:
  // default constructor - resizes puzzle to have four rows and four
  // columns
  Sudoku();

  // Returns true if puzzle represents a valid sudoku game board as
  // described in the lab handout
  bool isValid() const;

 private:
  matrix<uint> gameBoard;
};

#endif
