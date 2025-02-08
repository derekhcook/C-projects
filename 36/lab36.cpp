// Derek Cook
// Cs 2336
// Lab 36

#include <lab36.h>
#include <string>
#include <iomanip>

// Overloaded output operator - displays the two-dimensional matrix
// data of spiral row-by-row to output stream out.  The columns of
// the display should align on the right, and there should be one
// space separating the columns.  The columns should all be of the
// same width, equal to the width of the largest element.
/*friend*/ ostream& operator<<(ostream& out, const Spiral& spiral)
{
    int n = spiral.data.rows();
    int width = to_string(n * n).length();

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j == 0)
				out << setw(width) << spiral.data[i][j];
			else
				out << setw(width + 1) << spiral.data[i][j];
        }
        out << endl;
    }
    return out;
}

// Member function Initialize resizes the two-dimensional matrix
// data to be n rows by n columns and then initializes each element
// to 0
void Spiral::initialize(int n)
{
    data.resize(n, n);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            data[i][j] = 0; 
}

// Populates the two-dimensional matrix data as described in the lab
// handout
void Spiral::build()
{
    int i, g = 0, k = 0, n = data.rows();
	
	while (k <= (n * n + k))
	{
		for (i = g; i < n; ++i)
		{
			data[g][i] = ++k;
		}
		
		for (i = g + 1; i < n; ++i)
		{
			data[i][n - 1] = ++k;
		}
		
		for (i = n - 2; i >= g; --i)
		{
			data[n - 1][i] = ++k;
		}
		
		for (i = n - 2; i > g; --i)
		{
			data[i][g] = ++k;
		}
		
		++g;
		n -= 1;
	}

	
}