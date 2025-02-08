#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

// printHexadecimal is a recursive function that writes the hexadecimal
// representation of num to output stream os
void printHexadecimal(int num, ostream& os);

int main()
{
  int num;

  while (cin >> num)
  {
    cout << right << setw(11) << num << " base 10 = ";
    if (num != 0)
      printHexadecimal(num, cout);
    else
      cout << 0;
    cout << " base 16" << endl;
  }

  return EXIT_SUCCESS;
}
