#include <lab07.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  Rational first(1, -2), second(-3, 0), result;

  cout << boolalpha;
  cout << "first = " << first << " second = " << second
       << " result = " << result << endl;

  while (cin >> first >> second)
  {
    cout << "first = " << first;
    result = -first;
    result.reduce();
    cout << "  -first = " << result << endl;

    cout << first << " + " << second << " = " << first + second << endl;
    cout << first << " - " << second << " = " << first - second << endl;
    cout << first << " * " << second << " = " << first * second << endl;
    cout << first << " / " << second << " = " << first / second << endl;

    cout << first << " == " << second << " = " << (first == second) << endl;
    cout << first << " != " << second << " = " << (first != second) << endl;
    cout << first << " <  " << second << " = " << (first <  second) << endl;
    cout << first << " <= " << second << " = " << (first <= second) << endl;
    cout << first << " >  " << second << " = " << (first >  second) << endl;
    cout << first << " >= " << second << " = " << (first >= second) << endl;
  }

  return EXIT_SUCCESS;
}
