// Derek Cook
// Cs 2336
// Lab 37

#include <lab37.h>

// Overloaded output operator - displays puzzle row-by-row to output
// stream out.  The elements in a row should be separated by one
// blank space.
/*friend*/ ostream& operator<<(ostream& out, const Sudoku& puzzle)
{
	int n = puzzle.gameBoard.rows();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			out << puzzle.gameBoard[i][j] << ' ';
		}
		out << endl;
	}

	return out;
}

// Overloaded input operator - initializes puzzle from input stream
// in.  The function should read four four-digit unsigned
// integers. The first unsigned integer is used to initialize the
// elements of the first row of the puzzle, the second the second,
// etc. The least significant digit of the four-digit number is used
// to initialize the last element in the row, the next-to-least the
// next-to-last, etc.
/*friend*/ istream& operator>>(istream& in, Sudoku& puzzle)
{
	int n = puzzle.gameBoard.rows(), num;
	for (int i = 0; i < n; ++i)
	{
		in >> num;
		for (int j = n - 1; j >= 0; --j)
		{
			puzzle.gameBoard[i][j] = num % 10;
			num /= 10;
		}
	}

	return in;
}

// default constructor - resizes puzzle to have four rows and four
// columns
Sudoku::Sudoku()
{
	gameBoard.resize(4, 4);
}

bool Sudoku::isValid() const
{
	int one, two, three, four, r = gameBoard.rows();
	for (int i = 0; i < r; i++)
	{
		one = 0, two = 0, three = 0, four = 0;
		for (int j = 0; j < r; j++)
		{
			if (gameBoard[i][j] == 1)
			{
				one++;
			}
			else if (gameBoard[i][j] == 2)
			{
				two++;
			}
			else if (gameBoard[i][j] == 3)
			{
				three++;
			}
			else if (gameBoard[i][j] == 4)
			{
				four++;
			}
		}
		if (one != 1 || two != 1 || three != 1 || four != 1)
			return false;
	}
	for (int i = 0; i < r; i++)
	{
		one = 0, two = 0, three = 0, four = 0;
		for (int j = 0; j < r; j++)
		{
			if (gameBoard[j][i] == 1)
			{
				one++;
			}
			else if (gameBoard[j][i] == 2)
			{
				two++;
			}
			else if (gameBoard[j][i] == 3)
			{
				three++;
			}
			else if (gameBoard[j][i] == 4)
			{
				four++;
			}
		}
		if (one != 1 || two != 1 || three != 1 || four != 1)
			return false;
	}
	for (int num = 0; num < r; num++) 
	{
		one = 0, two = 0, three = 0, four = 0;
		int hiMotl, check = 0;
		if (num % 2 == 0)
			hiMotl = 0; 
		else 
			hiMotl = 2;
		for (int i = hiMotl; i < hiMotl + 2; i++) 
		{
			for (int j = hiMotl; j < hiMotl + 2; j++) 
			{
				if (gameBoard[i][j] == 1)
				{
					one++;
					check++;
				}
				else if (gameBoard[i][j] == 2)
				{
					two++;
					check++;
				}
				else if (gameBoard[i][j] == 3)
				{
					three++;
					check++;
				}
				else if (gameBoard[i][j] == 4)
				{
					four++;
					check++;
				}
			}
			if (check != 4)
					i = hiMotl;
		}
		
		if (one != 1 || two != 1 || three != 1 || four != 1)
			return false;
	}

	return true;
}
