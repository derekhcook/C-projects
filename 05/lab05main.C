#include <lab05.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  Rational first(1, -2), second(-3, 0), result;

  cout << boolalpha;
  first.print(cout);
  cout << ' ';
  second.print(cout);
  cout << ' ';
  result.print(cout);
  cout << endl;

  while (first.read(cin) && second.read(cin))
  {
    first.print(cout);
    cout << " == ";
    second.print(cout);
    cout << " = " << first.isEqualTo(second) << endl;

    first.print(cout);
    cout << " != ";
    second.print(cout);
    cout << " = " << first.isNotEqualTo(second) << endl;

    first.print(cout);
    cout << " <  ";
    second.print(cout);
    cout << " = " << first.isLessThan(second) << endl;

    first.print(cout);
    cout << " <= ";
    second.print(cout);
    cout << " = " << first.isLessThanOrEqualTo(second) << endl;

    first.print(cout);
    cout << " >  ";
    second.print(cout);
    cout << " = " << first.isGreaterThan(second) << endl;

    first.print(cout);
    cout << " >= ";
    second.print(cout);
    cout << " = " << first.isGreaterThanOrEqualTo(second) << endl;
  }

  return EXIT_SUCCESS;
}
