#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

// printOctal is a recursive function that writes the octal
// representation of num to output stream os
void printOctal(int num, ostream& os);

int main()
{
  int num;

  while (cin >> num)
  {
    cout << right << setw(11) << num << " base 10 = ";
    if (num != 0)
      printOctal(num, cout);
    else
      cout << 0;
    cout << " base 8" << endl;
  }

  return EXIT_SUCCESS;
}
