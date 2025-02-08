#include <iostream>
#include <d_matrix.h>

using namespace std;

bool isIdentityMatrix(const matrix<int>& mat);
istream& operator>>(istream& in, matrix<int>& mat);
ostream& operator<<(ostream& out, const matrix<int>& mat);

int main()
{
  int n, count = 0;
  matrix<int> mat;

  while (cin >> n)
  {
    mat.resize(n, n);
    cin >> mat;
    cout << mat << "Matrix #" << ++count
         << (isIdentityMatrix(mat) ? " is " : " is not ")
         << "an identity matrix" << endl;
  }

  return 0;
}

istream& operator>>(istream& in, matrix<int>& mat)
{
  int n = mat.rows(), i, j;

  for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j)
      in >> mat[i][j];

  return in;
}

ostream& operator<<(ostream& out, const matrix<int>& mat)
{
  int n = mat.rows(), i, j;

  for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j)
      out << mat[i][j] << (j < n - 1 ? ' ' : '\n');

  return out;
}
