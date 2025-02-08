#include <iostream>
#include <lab37.h>

using namespace std;

int main()
{
  Sudoku sudokuPuzzle;
  uint i, n;

  cin >> dec >> n;
  for (i = 1; i <= n; ++i)
  {
    cin >> sudokuPuzzle;
    cout << sudokuPuzzle;
    cout << "Board #" << i << " is ";
    if (sudokuPuzzle.isValid())
      cout << "valid" << endl;
    else
      cout << "invalid" << endl;
  }

  return 0;
}
