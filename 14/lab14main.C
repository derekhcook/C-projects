#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

// printBinary is a recursive function that writes the binary
// representation of num to output stream os
void printBinary(int num, ostream& os);

int main()
{
  int num;

  while (cin >> num)
  {
    cout << right << setw(11) << num << " base 10 = ";
    if (num != 0)
      printBinary(num, cout);
    else
      cout << 0;
    cout << " base 2" << endl;
  }

  return EXIT_SUCCESS;
}
