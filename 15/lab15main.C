#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

// printQuaternary is a recursive function that writes the quaternary
// representation of num to output stream os
void printQuaternary(int num, ostream& os);

int main()
{
  int num;

  while (cin >> num)
  {
    cout << right << setw(11) << num << " base 10 = ";
    if (num != 0)
      printQuaternary(num, cout);
    else
      cout << 0;
    cout << " base 4" << endl;
  }

  return EXIT_SUCCESS;
}
