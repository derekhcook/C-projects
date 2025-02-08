#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

// printBase32 is a recursive function that writes the base32
// representation of num to output stream os
void printBase32(int num, ostream& os);

int main()
{
  int num;

  while (cin >> num)
  {
    cout << right << setw(11) << num << " base 10 = ";
    if (num != 0)
      printBase32(num, cout);
    else
      cout << 0;
    cout << " base 32" << endl;
  }

  return EXIT_SUCCESS;
}
