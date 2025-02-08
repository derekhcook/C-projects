#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void insertComma(unsigned long num, ostream& os);

int main()
{
  unsigned long ul;

  while (cin >> ul)
  {
    cout << setw(10) << ul << " = ";
    insertComma(ul, cout);
    cout << endl;
  }

  return EXIT_SUCCESS;
}
