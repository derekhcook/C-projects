#include <iostream>
#include <cstdlib>

using namespace std;

int countOneBits(int);

int main()
{
  int i, count;

  while (cin >> i)
  {
    count = countOneBits(i);
    cout << i << " has " << count
         << (count == 1 ? " bit" : " bits")
         << " equal to 1 in its internal binary "
         << "representation" << endl;
  }

  return EXIT_SUCCESS;
}
