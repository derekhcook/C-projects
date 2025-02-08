// Derek Cook
// Cs 2336
// Lab 35

#include <d_matrix.h>

using namespace std;

bool isIdentityMatrix(const matrix<int>& mat)
{
    for (int r = 0; r < mat.rows(); ++r)
    {
        for (int c = 0; c < mat.rows(); ++c)
        {
            if (r == c && mat[r][c] != 1)
            {
                return false;
            }
            else if (r != c && mat[r][c] != 0)
            {
                return false;
            }
        }
    }
    return true;
}